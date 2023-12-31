#include <platform/mt_i2c.h>
#include <platform/mt_gpio.h>

/******************************internal API********************************************************/
static inline void i2c_writel(mt_i2c * i2c, U8 offset, U16 value)
{
	//__raw_writew(value, (i2c->base) + (offset));
	mt_reg_sync_writel(value, (i2c->base) + (offset));
}

static inline U32 i2c_readl(mt_i2c * i2c, U8 offset)
{
	return DRV_Reg32((i2c->base) + (offset));
}
/***********************************declare  API**************************/
static void mt_i2c_clock_enable(mt_i2c *i2c);
static void mt_i2c_clock_disable(mt_i2c *i2c);

/***********************************I2C common Param **************************/
volatile U32 I2C_TIMING_REG_BACKUP[7]= {0};

/***********************************common API********************************************************/
/*Set i2c port speed*/
S32 i2c_set_speed(mt_i2c *i2c)
{
	S32 ret = 0;
	static S32 mode = 0;
	static U32 khz = 0;
	//U32 base = i2c->base;
	U16 step_cnt_div = 0;
	U16 sample_cnt_div = 0;
	U32 tmp, sclk, hclk = i2c->clk;
	U16 max_step_cnt_div = 0;
	U32 diff, min_diff = i2c->clk;
	U16 sample_div = MAX_SAMPLE_CNT_DIV;
	U16 step_div = 0;
	U16 i2c_timing_reg = 0;
	//I2CFUC();
	//I2CLOG("i2c_set_speed=================\n");
	//compare the current mode with the latest mode
	i2c_timing_reg = i2c_readl(i2c, OFFSET_TIMING);
	if ((mode == i2c->mode) && (khz == i2c->speed)&&(i2c_timing_reg == I2C_TIMING_REG_BACKUP[i2c->id])) {
		//I2CLOG(" set sclk to %ldkhz\n", i2c->speed);
		//return 0;
	}
	mode = i2c->mode;
	khz = i2c->speed;

	max_step_cnt_div = (mode == HS_MODE) ? MAX_HS_STEP_CNT_DIV : MAX_STEP_CNT_DIV;
	step_div = max_step_cnt_div;

	if ((mode == FS_MODE && khz > MAX_FS_MODE_SPEED) || (mode == HS_MODE && khz > MAX_HS_MODE_SPEED)) {
		I2CERR(" the speed is too fast for this mode.\n");
		ret = -EINVAL_I2C;
		goto end;
	}
	//I2CERR("first:khz=%d,mode=%d sclk=%d,min_diff=%d,max_step_cnt_div=%d\n",khz,mode,sclk,min_diff,max_step_cnt_div);
	/*Find the best combination*/
	for (sample_cnt_div = 1; sample_cnt_div <= MAX_SAMPLE_CNT_DIV; sample_cnt_div++) {
		for (step_cnt_div = 1; step_cnt_div <= max_step_cnt_div; step_cnt_div++) {
			sclk = (hclk >> 1) / (sample_cnt_div * step_cnt_div);
			if (sclk > khz)
				continue;
			diff = khz - sclk;
			if (diff < min_diff) {
				min_diff = diff;
				sample_div = sample_cnt_div;
				step_div = step_cnt_div;
			}
		}
	}
	sample_cnt_div = sample_div;
	step_cnt_div = step_div;
	sclk = hclk / (2 * sample_cnt_div * step_cnt_div);
	//I2CERR("second:sclk=%d khz=%d,i2c->speed=%d hclk=%d sample_cnt_div=%d,step_cnt_div=%d.\n",sclk,khz,i2c->speed,hclk,sample_cnt_div,step_cnt_div);
	if (sclk > khz) {
		I2CERR("%s mode: unsupported speed (%dkhz)\n",(mode == HS_MODE) ? "HS" : "ST/FT", khz);
		ret = -ENOTSUPP_I2C;
		goto end;
	}

	step_cnt_div--;
	sample_cnt_div--;

	//spin_lock(&i2c->lock);

	if (mode == HS_MODE) {
		/*Set the high speed timing control register*/
		tmp = i2c_readl(i2c, OFFSET_TIMING) & ~((0x7 << 8) | (0x3f << 0));
		tmp = (0 & 0x7) << 8 | (16 & 0x3f) << 0 | tmp;
		i2c->timing_reg = tmp;
		//i2c_writel(i2c, OFFSET_TIMING, tmp);
		I2C_TIMING_REG_BACKUP[i2c->id] = tmp;

		/*Set the high speed mode register*/
		tmp = i2c_readl(i2c, OFFSET_HS) & ~((0x7 << 12) | (0x7 << 8));
		tmp = (sample_cnt_div & 0x7) << 12 | (step_cnt_div & 0x7) << 8 | tmp;
		/*Enable the high speed transaction*/
		tmp |= 0x0001;
		i2c->high_speed_reg = tmp;
		//i2c_writel(i2c, OFFSET_HS, tmp);
	} else {
		/*Set non-highspeed timing*/
		tmp = i2c_readl(i2c, OFFSET_TIMING) & ~((0x7 << 8) | (0x3f << 0));
		tmp = (sample_cnt_div & 0x7) << 8 | (step_cnt_div & 0x3f) << 0 | tmp;
		i2c->timing_reg = tmp;
		I2C_TIMING_REG_BACKUP[i2c->id] = tmp;
		//i2c_writel(i2c, OFFSET_TIMING, tmp);
		/*Disable the high speed transaction*/
		//I2CERR("NOT HS_MODE============================1\n");
		tmp = i2c_readl(i2c, OFFSET_HS) & ~(0x0001);
		//I2CERR("NOT HS_MODE============================2\n");
		i2c->high_speed_reg = tmp;
		//i2c_writel(i2c, OFFSET_HS, tmp);
		//I2CERR("NOT HS_MODE============================3\n");
	}
	//spin_unlock(&i2c->lock);
end:
	return ret;
}

void _i2c_dump_info(mt_i2c *i2c)
{
	//I2CFUC();
	I2CERR("I2C structure:\n"
	       I2CTAG"Clk=%d,Id=%d,Mode=%x,St_rs=%x,Dma_en=%x,Op=%x,Poll_en=%x,Irq_stat=%x\n"
	       I2CTAG"Trans_len=%x,Trans_num=%x,Trans_auxlen=%x,Data_size=%x,speed=%d\n",
	       //,Trans_stop=%u,Trans_comp=%u,Trans_error=%u\n"
	       i2c->clk,i2c->id,i2c->mode,i2c->st_rs,i2c->dma_en,i2c->op,i2c->poll_en,i2c->irq_stat,
	       i2c->trans_data.trans_len,i2c->trans_data.trans_num,i2c->trans_data.trans_auxlen,i2c->trans_data.data_size,i2c->speed);
	// atomic_read(&i2c->trans_stop),atomic_read(&i2c->trans_comp),atomic_read(&i2c->trans_err),

	I2CERR("base address 0x%x\n", i2c->base);
	I2CERR("I2C register:\n"
	       I2CTAG"SLAVE_ADDR=%x,INTR_MASK=%x,INTR_STAT=%x,CONTROL=%x,TRANSFER_LEN=%x\n"
	       I2CTAG"TRANSAC_LEN=%x,DELAY_LEN=%x,TIMING=%x,START=%x,FIFO_STAT=%x\n"
	       I2CTAG"IO_CONFIG=%x,HS=%x,DCM_EN=%x,DEBUGSTAT=%x,EXT_CONF=%x,TRANSFER_LEN_AUX=%x\n",
	       (i2c_readl(i2c, OFFSET_SLAVE_ADDR)),
	       (i2c_readl(i2c, OFFSET_INTR_MASK)),
	       (i2c_readl(i2c, OFFSET_INTR_STAT)),
	       (i2c_readl(i2c, OFFSET_CONTROL)),
	       (i2c_readl(i2c, OFFSET_TRANSFER_LEN)),
	       (i2c_readl(i2c, OFFSET_TRANSAC_LEN)),
	       (i2c_readl(i2c, OFFSET_DELAY_LEN)),
	       (i2c_readl(i2c, OFFSET_TIMING)),
	       (i2c_readl(i2c, OFFSET_START)),
	       (i2c_readl(i2c, OFFSET_FIFO_STAT)),
	       (i2c_readl(i2c, OFFSET_IO_CONFIG)),
	       (i2c_readl(i2c, OFFSET_HS)),
	       (i2c_readl(i2c, OFFSET_DCM_EN)),
	       (i2c_readl(i2c, OFFSET_DEBUGSTAT)),
	       (i2c_readl(i2c, OFFSET_EXT_CONF)),
	       (i2c_readl(i2c, OFFSET_TRANSFER_LEN_AUX)));
	/*
	I2CERR("DMA register:\nINT_FLAG %x\nCON %x\nTX_MEM_ADDR %x\nRX_MEM_ADDR %x\nTX_LEN %x\nRX_LEN %x\nINT_EN %x\nEN %x\n",
	    (__raw_readl(i2c->pdmabase+OFFSET_INT_FLAG)),
	    (__raw_readl(i2c->pdmabase+OFFSET_CON)),
	    (__raw_readl(i2c->pdmabase+OFFSET_TX_MEM_ADDR)),
	    (__raw_readl(i2c->pdmabase+OFFSET_RX_MEM_ADDR)),
	    (__raw_readl(i2c->pdmabase+OFFSET_TX_LEN)),
	    (__raw_readl(i2c->pdmabase+OFFSET_RX_LEN)),
	    (__raw_readl(i2c->pdmabase+OFFSET_S32_EN)),
	    (__raw_readl(i2c->pdmabase+OFFSET_EN)));
	*/
	return;
}
static S32 _i2c_deal_result(mt_i2c *i2c)
{
	long tmo = 1;
	U16 data_size = 0;
	U8 *ptr = i2c->msg_buf;
	BOOL TRANSFER_ERROR = FALSE;
	S32 ret = i2c->msg_len;
	long tmo_poll = 0xffff;
	//I2CFUC();
	//addr_reg = i2c->read_flag ? ((i2c->addr << 1) | 0x1) : ((i2c->addr << 1) & ~0x1);

	if (i2c->poll_en) {
		/*master read && poll mode*/
		for (;;) {
			/*check the interrupt status register*/
			i2c->irq_stat = i2c_readl(i2c, OFFSET_INTR_STAT);
			//I2CLOG("irq_stat = 0x%x\n", i2c->irq_stat);
			if (i2c->irq_stat & (I2C_HS_NACKERR | I2C_ACKERR )) {
				//transfer error
				//atomic_set(&i2c->trans_stop, 1);
				//spin_lock(&i2c->lock);
				/*Clear interrupt status,write 1 clear*/
				//i2c_writel(i2c, OFFSET_INTR_STAT, (I2C_HS_NACKERR | I2C_ACKERR));
				TRANSFER_ERROR = TRUE;
				tmo = 1;
				//spin_unlock(&i2c->lock);
				break;
			} else if (i2c->irq_stat & I2C_TRANSAC_COMP) {
				//transfer complete
				tmo = 1;
				break;
			}
			tmo_poll--;
			if (tmo_poll == 0) {
				tmo = 0;
				break;
			}
		}
	} else { /*Interrupt mode,wait for interrupt wake up*/
		//tmo = wait_event_timeout(i2c->wait,atomic_read(&i2c->trans_stop), tmo);
	}

	//I2CLOG("tmo = 0x%x\n", tmo);
	/*Check the transfer status*/
	if (!(tmo == 0) && TRANSFER_ERROR == FALSE) {
		/*Transfer success ,we need to get data from fifo*/
		if ((!i2c->dma_en) && (i2c->op == I2C_MASTER_RD || i2c->op == I2C_MASTER_WRRD)) {
			/*only read mode or write_read mode and fifo mode need to get data*/
			data_size = (i2c_readl(i2c, OFFSET_FIFO_STAT) >> 4) & 0x000F;
			//I2CLOG("data_size=%d\n",data_size);
			while (data_size--) {
				*ptr = i2c_readl(i2c, OFFSET_DATA_PORT);
#ifdef I2C_EARLY_PORTING
				I2CLOG("addr %x read byte = 0x%x\n", i2c->addr, *ptr);
#endif
				ptr++;
			}
		}
	} else {
		/*Timeout or ACKERR*/
		if (tmo == 0) {
			I2CERR("id=%d,addr: %x, transfer timeout\n", i2c->id, i2c->addr);
			ret = -ETIMEDOUT_I2C;
		} else {
			I2CERR("id=%d,addr: %x, transfer error\n", i2c->id, i2c->addr);
			ret = -EREMOTEIO_I2C;
		}
		if (i2c->irq_stat & I2C_HS_NACKERR)
			I2CERR("I2C_HS_NACKERR\n");
		if (i2c->irq_stat & I2C_ACKERR)
			I2CERR("I2C_ACKERR\n");
		if (i2c->filter_msg == FALSE) { //TEST
			_i2c_dump_info(i2c);
		}

		//spin_lock(&i2c->lock);
		/*Reset i2c port*/
		i2c_writel(i2c, OFFSET_SOFTRESET, 0x0001);
		/*Set slave address*/
		i2c_writel(i2c, OFFSET_SLAVE_ADDR, 0x0000);
		/*Clear interrupt status*/
		i2c_writel(i2c, OFFSET_INTR_STAT, (I2C_HS_NACKERR | I2C_ACKERR | I2C_TRANSAC_COMP));
		/*Clear fifo address*/
		i2c_writel(i2c, OFFSET_FIFO_ADDR_CLR, 0x0001);

		//spin_unlock(&i2c->lock);
	}
	return ret;
}


void _i2c_write_reg(mt_i2c *i2c)
{
	U8 *ptr = i2c->msg_buf;
	U32 data_size = i2c->trans_data.data_size;
	U32 addr_reg = 0;
	//I2CFUC();

	i2c_writel(i2c, OFFSET_CONTROL, i2c->control_reg);

	/*set start condition */
	if (i2c->speed <= 100) {
		i2c_writel(i2c, OFFSET_EXT_CONF, 0x8001);
	} else {
		i2c_writel(i2c, OFFSET_EXT_CONF, 0x1800);
	}
	//set timing reg
	i2c_writel(i2c, OFFSET_TIMING, i2c->timing_reg);
	i2c_writel(i2c, OFFSET_HS, i2c->high_speed_reg);

	if (0 == i2c->delay_len)
		i2c->delay_len = 2;
	if (~i2c->control_reg & I2C_CONTROL_RS) { // bit is set to 1, i.e.,use repeated stop
		i2c_writel(i2c, OFFSET_DELAY_LEN, i2c->delay_len);
	}

	/*Set ioconfig*/
	if (i2c->pushpull) {
		i2c_writel(i2c, OFFSET_IO_CONFIG, 0x0000);
	} else {
		i2c_writel(i2c, OFFSET_IO_CONFIG, 0x0003);
	}

	/*Set slave address*/

	addr_reg = i2c->read_flag ? ((i2c->addr << 1) | 0x1) : ((i2c->addr << 1) & ~0x1);
	i2c_writel(i2c, OFFSET_SLAVE_ADDR, addr_reg);
	/*Clear interrupt status*/
	i2c_writel(i2c, OFFSET_INTR_STAT, (I2C_HS_NACKERR | I2C_ACKERR | I2C_TRANSAC_COMP));
	/*Clear fifo address*/
	i2c_writel(i2c, OFFSET_FIFO_ADDR_CLR, 0x0001);
	/*Setup the interrupt mask flag*/
	if (i2c->poll_en)
		i2c_writel(i2c, OFFSET_INTR_MASK, i2c_readl(i2c, OFFSET_INTR_MASK) & ~(I2C_HS_NACKERR | I2C_ACKERR | I2C_TRANSAC_COMP)); /*Disable interrupt*/
	else
		i2c_writel(i2c, OFFSET_INTR_MASK, i2c_readl(i2c, OFFSET_INTR_MASK) | (I2C_HS_NACKERR | I2C_ACKERR | I2C_TRANSAC_COMP)); /*Enable interrupt*/
	/*Set transfer len */
	i2c_writel(i2c, OFFSET_TRANSFER_LEN, i2c->trans_data.trans_len & 0xFFFF);
	i2c_writel(i2c, OFFSET_TRANSFER_LEN_AUX, i2c->trans_data.trans_auxlen & 0xFFFF);
	/*Set transaction len*/
	i2c_writel(i2c, OFFSET_TRANSAC_LEN, i2c->trans_data.trans_num & 0xFF);

	/*Prepare buffer data to start transfer*/

	if (i2c->dma_en) {
		/* Reset I2C DMA status */
		mt_reg_sync_writel(0x0001, i2c->pdmabase + OFFSET_RST);
		if (I2C_MASTER_RD == i2c->op) {
			mt_reg_sync_writel(0x0000, i2c->pdmabase + OFFSET_INT_FLAG);
			mt_reg_sync_writel(0x0001, i2c->pdmabase + OFFSET_CON);
			mt_reg_sync_writel((U32)i2c->msg_buf, i2c->pdmabase + OFFSET_RX_MEM_ADDR);
			mt_reg_sync_writel(i2c->trans_data.data_size, i2c->pdmabase + OFFSET_RX_LEN);
		} else if (I2C_MASTER_WR == i2c->op) {
			mt_reg_sync_writel(0x0000, i2c->pdmabase + OFFSET_INT_FLAG);
			mt_reg_sync_writel(0x0000, i2c->pdmabase + OFFSET_CON);
			mt_reg_sync_writel((U32)i2c->msg_buf, i2c->pdmabase + OFFSET_TX_MEM_ADDR);
			mt_reg_sync_writel(i2c->trans_data.data_size, i2c->pdmabase + OFFSET_TX_LEN);
		} else {
			mt_reg_sync_writel(0x0000, i2c->pdmabase + OFFSET_INT_FLAG);
			mt_reg_sync_writel(0x0000, i2c->pdmabase + OFFSET_CON);
			mt_reg_sync_writel((U32)i2c->msg_buf, i2c->pdmabase + OFFSET_TX_MEM_ADDR);
			mt_reg_sync_writel((U32)i2c->msg_buf, i2c->pdmabase + OFFSET_RX_MEM_ADDR);
			mt_reg_sync_writel(i2c->trans_data.trans_len, i2c->pdmabase + OFFSET_TX_LEN);
			mt_reg_sync_writel(i2c->trans_data.trans_auxlen, i2c->pdmabase + OFFSET_RX_LEN);
		}
		mt_reg_sync_writel(0x0001, i2c->pdmabase + OFFSET_EN);
	} else {
		/*Set fifo mode data*/
		if (I2C_MASTER_RD == i2c->op) {
			/*do not need set fifo data*/
		} else {
			/*both write && write_read mode*/
			while (data_size--) {
				i2c_writel(i2c, OFFSET_DATA_PORT, *ptr);
				//dev_info(i2c->dev, "addr %.2x write byte = 0x%.2X\n", addr, *ptr);
				ptr++;
			}
		}
	}
	/*Set trans_data*/
	i2c->trans_data.data_size = data_size;

}
S32 _i2c_get_transfer_len(mt_i2c *i2c)
{
	S32 ret = I2C_OK;
	u16 trans_num = 0;
	u16 data_size = 0;
	u16 trans_len = 0;
	u16 trans_auxlen = 0;
	//I2CFUC();
	/*Get Transfer len and transaux len*/
	if (FALSE == i2c->dma_en) {
		/*non-DMA mode*/
		if (I2C_MASTER_WRRD != i2c->op) {
			trans_len = (i2c->msg_len) & 0xFFFF;
			trans_num = (i2c->msg_len >> 16) & 0xFF;
			if (0 == trans_num)
				trans_num = 1;
			trans_auxlen = 0;
			data_size = trans_len*trans_num;

			if (!trans_len || !trans_num || trans_len*trans_num > I2C_FIFO_SIZE) {
				I2CERR(" non-WRRD transfer length is not right. trans_len=%x, tans_num=%x, trans_auxlen=%x\n", trans_len, trans_num, trans_auxlen);
				ret = -EINVAL_I2C;
			}
		} else {
			trans_len = (i2c->msg_len) & 0xFFFF;
			trans_auxlen = (i2c->msg_len >> 16) & 0xFFFF;
			trans_num = 2;
			data_size = trans_len;
			if (!trans_len || !trans_auxlen || trans_len > I2C_FIFO_SIZE || trans_auxlen > I2C_FIFO_SIZE) {
				I2CERR(" WRRD transfer length is not right. trans_len=%x, tans_num=%x, trans_auxlen=%x\n", trans_len, trans_num, trans_auxlen);
				ret = -EINVAL_I2C;
			}
		}
	} else {
		/*DMA mode*/
		if (I2C_MASTER_WRRD != i2c->op) {
			trans_len = (i2c->msg_len) & 0xFFFF;
			trans_num = (i2c->msg_len >> 16) & 0xFF;
			if (0 == trans_num)
				trans_num = 1;
			trans_auxlen = 0;
			data_size = trans_len*trans_num;

			if (!trans_len || !trans_num || trans_len > MAX_DMA_TRANS_SIZE || trans_num > MAX_DMA_TRANS_NUM) {
				I2CERR(" DMA non-WRRD transfer length is not right. trans_len=%x, tans_num=%x, trans_auxlen=%x\n", trans_len, trans_num, trans_auxlen);
				ret = -EINVAL_I2C;
			}
		} else {
			trans_len = (i2c->msg_len) & 0xFFFF;
			trans_auxlen = (i2c->msg_len >> 16) & 0xFFFF;
			trans_num = 2;
			data_size = trans_len;
			if (!trans_len || !trans_auxlen || trans_len > MAX_DMA_TRANS_SIZE || trans_auxlen > MAX_DMA_TRANS_NUM) {
				I2CERR(" DMA WRRD transfer length is not right. trans_len=%x, tans_num=%x, trans_auxlen=%x\n", trans_len, trans_num, trans_auxlen);
				ret = -EINVAL_I2C;
			}
		}
	}

	i2c->trans_data.trans_num = trans_num;
	i2c->trans_data.trans_len = trans_len;
	i2c->trans_data.data_size = data_size;
	i2c->trans_data.trans_auxlen = trans_auxlen;

	return ret;
}
S32 _i2c_transfer_interface(mt_i2c *i2c)
{
	S32 return_value = 0;
	S32 ret = 0;
	U8 *ptr = i2c->msg_buf;
	//I2CFUC();

	if (i2c->dma_en) {
		if (i2c->pdmabase == 0) {
			I2CERR(" I2C%d doesnot support DMA mode!\n", i2c->id);
			ret = -EINVAL_I2C;
			goto err;
		}
		if ((U32)ptr > DMA_ADDRESS_HIGH) {
			I2CERR(" DMA mode should use physical buffer address!\n");
			ret = -EINVAL_I2C;
			goto err;
		}
	}
	i2c->irq_stat = 0;

	return_value = _i2c_get_transfer_len(i2c);
	if (return_value < 0) {
		I2CERR("_i2c_get_transfer_len fail,return_value=%d\n", return_value);
		ret =-EINVAL_I2C;
		goto err;
	}
	//get clock
	i2c->clk = I2C_CLK_RATE;

	return_value = i2c_set_speed(i2c);
	if (return_value < 0) {
		I2CERR("i2c_set_speed fail,return_value=%d\n", return_value);
		ret = -EINVAL_I2C;
		goto err;
	}
	/*Set Control Register*/
	i2c->control_reg = I2C_CONTROL_ACKERR_DET_EN | I2C_CONTROL_CLK_EXT_EN;
	if (i2c->dma_en) {
		i2c->control_reg |= I2C_CONTROL_DMA_EN;
	}
	if (I2C_MASTER_WRRD == i2c->op)
		i2c->control_reg |= I2C_CONTROL_DIR_CHANGE;

	if (HS_MODE == i2c->mode || (i2c->trans_data.trans_num > 1 && I2C_TRANS_REPEATED_START == i2c->st_rs)) {
		i2c->control_reg |= I2C_CONTROL_RS;
	}

	//spin_lock(&i2c->lock);
	_i2c_write_reg(i2c);

	/*Start the transfer*/
	i2c_writel(i2c, OFFSET_START, 0x0001);
	//spin_unlock(&i2c->lock);
	ret = _i2c_deal_result(i2c);
err:

	return ret;
}
S32 _i2c_check_para(mt_i2c *i2c)
{
	S32 ret = 0;
	//I2CFUC();
	if (i2c->addr == 0) {
		I2CERR("addr is invalid.\n");
		ret = -EINVAL_I2C;
		goto err;
	}

	if (i2c->msg_buf == NULL) {
		I2CERR("data buffer is NULL.\n");
		ret = -EINVAL_I2C;
		goto err;
	}
err:
	return ret;

}
void _config_mt_i2c(mt_i2c *i2c)
{
	//I2CFUC();
	switch (i2c->id) {
		case I2C0:
			i2c->base = I2C0_BASE;
			break;
		case I2C1:
			i2c->base = I2C1_BASE;
			break;
		case I2C2:
			i2c->base = I2C2_BASE;
			break;
		case I2C_APPM:
			i2c->base = I2C3_BASE;
			break;
		case I2C3:
			i2c->base = I2C4_BASE;
			break;
		default:
			I2CERR("invalid para: i2c->id=%d\n", i2c->id);
			break;
	}
	if (i2c->st_rs == I2C_TRANS_REPEATED_START)
		i2c->st_rs = I2C_TRANS_REPEATED_START;
	else
		i2c->st_rs = I2C_TRANS_STOP;
#if 0
	if (i2c->dma_en == TRUE)
		i2c->dma_en = TRUE;
	else
		i2c->dma_en = FALSE;
#else
	i2c->dma_en = FALSE;
#endif
	i2c->poll_en = TRUE;

	if (i2c->filter_msg == TRUE)
		i2c->filter_msg = TRUE;
	else
		i2c->filter_msg = FALSE;

	///*Set device speed,set it before set_control register
	if (0 == i2c->speed) {
		i2c->mode = ST_MODE;
		i2c->speed = MAX_ST_MODE_SPEED;
	} else {
		if (i2c->mode == HS_MODE)
			i2c->mode = HS_MODE;
		else
			i2c->mode = FS_MODE;
	}

	/*Set ioconfig*/
	if (i2c->pushpull == TRUE)
		i2c->pushpull = TRUE;
	else
		i2c->pushpull = FALSE;

}

/*-----------------------------------------------------------------------
 * new read interface: Read bytes
 *   mt_i2c:    I2C chip config, see mt_i2c_t.
 *   buffer:  Where to read/write the data.
 *   len:     How many bytes to read/write
 *   Returns: ERROR_CODE
 */
S32 i2c_read(mt_i2c *i2c, U8 *buffer, U32 len)
{
	S32 ret = I2C_OK;
#ifdef I2C_EARLY_PORTING
	I2CFUC();
#endif
	//read
	i2c->read_flag |= I2C_M_RD;
	i2c->op = I2C_MASTER_RD;
	i2c->msg_buf = buffer;
	i2c->msg_len = len;
	i2c->pdmabase = AP_DMA_BASE + 0x180 + (0x80*(i2c->id));
	ret = _i2c_check_para(i2c);
	if (ret< 0) {
		I2CERR(" _i2c_check_para fail\n");
		goto err;
	}

	_config_mt_i2c(i2c);
	//get the addr
	ret = _i2c_transfer_interface(i2c);

	if ((int)i2c->msg_len != ret) {
		I2CERR("read %d bytes fails,ret=%d.\n", i2c->msg_len, ret);
		ret = -1;
		return ret;
	} else {
		ret = I2C_OK;
		//I2CLOG("read %d bytes pass,ret=%d.\n", i2c->msg_len, ret);
	}
err:
	return ret;
}

/*-----------------------------------------------------------------------
 * New write interface: Write bytes
 *   i2c:    I2C chip config, see mt_i2c_t.
 *   buffer:  Where to read/write the data.
 *   len:     How many bytes to read/write
 *   Returns: ERROR_CODE
 */
S32 i2c_write(mt_i2c *i2c, U8 *buffer, U32 len)
{
	S32 ret = I2C_OK;
#ifdef I2C_EARLY_PORTING
	I2CFUC();
#endif
	//write
	i2c->read_flag = !I2C_M_RD;
	i2c->op = I2C_MASTER_WR;
	i2c->msg_buf = buffer;
	i2c->msg_len = len;
	i2c->pdmabase = AP_DMA_BASE + 0x180 + (0x80*(i2c->id));
	ret = _i2c_check_para(i2c);
	if (ret< 0) {
		I2CERR(" _i2c_check_para fail\n");
		goto err;
	}

	_config_mt_i2c(i2c);
	//get the addr
	ret = _i2c_transfer_interface(i2c);

	if ((int)i2c->msg_len != ret) {
		I2CERR("Write %d bytes fails,ret=%d.\n", i2c->msg_len, ret);
		ret = -1;
		return ret;
	} else {
		ret = I2C_OK;
		//I2CLOG("Write %d bytes pass,ret=%d.\n", i2c->msg_len, ret);
	}
err:
	return ret;
}

/*-----------------------------------------------------------------------
 * New write then read back interface: Write bytes then read bytes
 *   i2c:    I2C chip config, see mt_i2c_t.
 *   buffer:  Where to read/write the data.
 *   write_len:     How many bytes to write
 *   read_len:     How many bytes to read
 *   Returns: ERROR_CODE
 */
S32 i2c_write_read(mt_i2c *i2c, U8 *buffer, U32 write_len, U32 read_len)
{
	S32 ret = I2C_OK;
	//I2CFUC();
	//write and read
	i2c->op = I2C_MASTER_WRRD;
	i2c->read_flag = !I2C_M_RD;
	i2c->msg_buf = buffer;
	i2c->msg_len = ((read_len & 0xFFFF) << 16) | (write_len & 0xFFFF);
	i2c->pdmabase = AP_DMA_BASE + 0x180 + (0x80*(i2c->id));
	ret = _i2c_check_para(i2c);
	if (ret< 0) {
		I2CERR(" _i2c_check_para fail\n");
		goto err;
	}

	_config_mt_i2c(i2c);
	//get the addr
	ret = _i2c_transfer_interface(i2c);

	if ((int)i2c->msg_len != ret) {
		I2CERR("write_read 0x%x bytes fails,ret=%d.\n", i2c->msg_len, ret);
		ret = -1;
		return ret;
	} else {
		ret = I2C_OK;
		//I2CLOG("write_read 0x%x bytes pass,ret=%d.\n", i2c->msg_len, ret);
	}
err:
	return ret;
}

int i2c_hw_init(void)
{
	return 0;
}

//Test I2C
#ifdef I2C_EARLY_PORTING
int mt_i2c_test_eeprom(int id)
{
	U32 ret = 0;
	U32 len = 0;
	unsigned char write_byte[2], read_byte[2];
	struct mt_i2c_t i2c;

	i2c.id = id;
	i2c.addr = 0x50;
	i2c.mode = FS_MODE;
	i2c.speed = 100;
	//==================================================
	I2CLOG("test i2c write\n");
	write_byte[0] = 0x20;
	write_byte[1] = 0x55;
	len = 2;
	ret = i2c_write(&i2c, write_byte, len);
	if (I2C_OK != ret) {
		I2CERR("Write 2 bytes fails(%x).\n", ret);
		ret = -1;
		return ret;
	} else {
		I2CLOG("Write 2 bytes pass,these bytes are %x, %x.\n", write_byte[0], write_byte[1]);
	}

	mdelay(100);
	//==================================================
	I2CLOG("test i2c read\n");
	//1st:write addree 00,1byte(0x0A)
	write_byte[0] = 0x20;
	write_byte[1] = 0x0A;
	len = 1;
	ret = i2c_write(&i2c, write_byte, len);

	mdelay(100);

	read_byte[0] = 0x20;
	len = 1;
	ret = i2c_read(&i2c, read_byte, len);
	if ((I2C_OK != ret) && read_byte[0] == write_byte[1]) {
		I2CERR("read 2 bytes fails(%x).\n", ret);
		ret = -1;
		return ret;
	} else {
		I2CLOG("read 2 bytes pass,read_byte=%x,write_byte= %x.\n", read_byte[0], write_byte[1]);
	}

	mdelay(100);
	//==================================================
	I2CLOG("test i2c write_read\n");
	write_byte[0] = 0x20;
	// write_byte[1] = 0x34;
	len = ((1 & 0xFFFF) << 16) | (1 & 0xFFFF);
	ret = i2c_write_read(&i2c, write_byte, 1, 1);
	if (I2C_OK != ret) {
		I2CERR("Write 1 byte fails(ret=%x).\n", ret);
		ret = -1;
		return ret;
	} else {
		I2CLOG("Read 1 byte pass ,this byte is %x.\n", write_byte[0]);
		ret = 0;
	}
	return ret;
}

int mt_i2c_test(void)
{
	int ret;
	int i = 0;
	I2CFUC();
	for (i = 0; i < I2C_NR; i++) {
		ret = mt_i2c_test_eeprom(i);
		if (0 == ret) {
			I2CLOG("I2C%d,EEPROM test PASS!!\n", i);
		} else {
			I2CLOG("I2C%d,EEPROM test FAIL!!(%d)\n", i, ret);
		}
	}
	return 0;
}
#endif
