#include <platform/mt_typedefs.h>
#include <platform/mt_reg_base.h>
#include <platform/mt_pmic.h>
#include <platform/mt_gpt.h>
#include <platform/mt_pmic_wrap_init.h>
#include <printf.h>
#include <platform/upmu_hw.h>
#include <platform/upmu_common.h>
#include <platform/mt6311.h>

//==============================================================================
// Global variable
//==============================================================================
int Enable_PMIC_LOG = 1;

CHARGER_TYPE g_ret = CHARGER_UNKNOWN;
int g_charger_in_flag = 0;
int g_first_check=0;

extern int g_R_BAT_SENSE;
extern int g_R_I_SENSE;
extern int g_R_CHARGER_1;
extern int g_R_CHARGER_2;

//==============================================================================
// PMIC-AUXADC related define
//==============================================================================
#define VOLTAGE_FULL_RANGE     	1800
#define ADC_PRECISE		32768 	// 15 bits

//==============================================================================
// PMIC-AUXADC global variable
//==============================================================================
kal_int32 count_time_out=10000;

//==============================================================================
// PMIC access API
//==============================================================================
U32 pmic_read_interface (U32 RegNum, U32 *val, U32 MASK, U32 SHIFT)
{

    U32 return_value = 0;    
    U32 pmic_reg = 0;
    U32 rdata;    

    //mt_read_byte(RegNum, &pmic_reg);
    return_value= pwrap_wacs2(0, (RegNum), 0, &rdata);
    pmic_reg=rdata;
    if(return_value!=0)
    {   
        dprintf(INFO, "[pmic_read_interface] Reg[%x]= pmic_wrap read data fail\n", RegNum);
        return return_value;
    }
    //dprintf(INFO, "[pmic_read_interface] Reg[%x]=0x%x\n", RegNum, pmic_reg);
    
    pmic_reg &= (MASK << SHIFT);
    *val = (pmic_reg >> SHIFT);    
    //dprintf(INFO, "[pmic_read_interface] val=0x%x\n", *val);

    return return_value;
}

U32 pmic_config_interface (U32 RegNum, U32 val, U32 MASK, U32 SHIFT)
{
    U32 return_value = 0;    
    U32 pmic_reg = 0;
    U32 rdata;

    //1. mt_read_byte(RegNum, &pmic_reg);
    return_value= pwrap_wacs2(0, (RegNum), 0, &rdata);
    pmic_reg=rdata;    
    if(return_value!=0)
    {   
        dprintf(INFO, "[pmic_config_interface] Reg[%x]= pmic_wrap read data fail\n", RegNum);
        return return_value;
    }
    //dprintf(INFO, "[pmic_config_interface] Reg[%x]=0x%x\n", RegNum, pmic_reg);
    
    pmic_reg &= ~(MASK << SHIFT);
    pmic_reg |= (val << SHIFT);

    //2. mt_write_byte(RegNum, pmic_reg);
    return_value= pwrap_wacs2(1, (RegNum), pmic_reg, &rdata);
    if(return_value!=0)
    {   
        dprintf(INFO, "[pmic_config_interface] Reg[%x]= pmic_wrap read data fail\n", RegNum);
        return return_value;
    }
    //dprintf(INFO, "[pmic_config_interface] write Reg[%x]=0x%x\n", RegNum, pmic_reg);    

#if 0
    //3. Double Check    
    //mt_read_byte(RegNum, &pmic_reg);
    return_value= pwrap_wacs2(0, (RegNum), 0, &rdata);
    pmic_reg=rdata;    
    if(return_value!=0)
    {   
        dprintf(INFO, "[pmic_config_interface] Reg[%x]= pmic_wrap write data fail\n", RegNum);
        return return_value;
    }
    dprintf(INFO, "[pmic_config_interface] Reg[%x]=0x%x\n", RegNum, pmic_reg);
#endif    

    return return_value;
}


void upmu_set_reg_value(kal_uint32 reg, kal_uint32 reg_val)
{
    U32 ret=0;
    
    ret=pmic_config_interface(reg, reg_val, 0xFFFF, 0x0); 
    if(ret !=0)
    {
    }
}

//==============================================================================
// PMIC Usage APIs
//==============================================================================
U32 get_mt6350_pmic_chip_version (void)
{
    U32 ret=0;
    U32 val=0;

    ret=pmic_read_interface( (U32)(MT6350_CID),
                           (&val),
                           (U32)(MT6350_PMIC_CID_MASK),
                           (U32)(MT6350_PMIC_CID_SHIFT)
	                       );                                                      
    if(ret!=0) dprintf(INFO, "%d", ret);
    return val;
}

kal_uint32 mt6350_upmu_get_rgs_chrdet(void)
{
        kal_uint32 ret=0;
        kal_uint32 val=0;

        ret=pmic_read_interface((kal_uint32)(MT6350_CHR_CON0),
                                (&val),
                                (kal_uint32)(MT6350_PMIC_RGS_CHRDET_MASK),
                                (kal_uint32)(MT6350_PMIC_RGS_CHRDET_SHIFT)
                                );

        if(ret !=0)
        {
        }
        return val;
}

kal_bool upmu_is_chr_det(void)
{
	U32 tmp32 = 0;
	tmp32 = mt6350_upmu_get_rgs_chrdet();
	if(tmp32 == 0)
	{
		return KAL_FALSE;
	}
	else
	{
		return KAL_TRUE;
	}
}

kal_bool pmic_chrdet_status(void)
{
    if( upmu_is_chr_det() == KAL_TRUE )    
    {
        #ifndef USER_BUILD
        dprintf(INFO, "[pmic_chrdet_status] Charger exist\r\n");
        #endif
        
        return KAL_TRUE;
    }
    else
    {
        #ifndef USER_BUILD
        dprintf(INFO, "[pmic_chrdet_status] No charger\r\n");
        #endif
        
        return KAL_FALSE;
    }
}

int pmic_detect_powerkey(void)
{
    U32 ret=0;
    U32 val=0;

    ret=pmic_read_interface( (U32)(MT6350_CHRSTATUS),
                             (&val),
                             (U32)(MT6350_PMIC_PWRKEY_DEB_MASK),
                             (U32)(MT6350_PMIC_PWRKEY_DEB_SHIFT)
                             );

    if(Enable_PMIC_LOG>1) 
        dprintf(INFO, "%d", ret);

    if (val==1){
        #ifndef USER_BUILD
        dprintf(INFO, "LK pmic powerkey Release\n");
        #endif
        
        return 0;
    }else{
        #ifndef USER_BUILD
        dprintf(INFO, "LK pmic powerkey Press\n");
        #endif
        
        return 1;
    }
}

int pmic_detect_homekey(void)
{
        U32 ret=0;
        U32 val=0;

        ret=pmic_read_interface( (U32)(MT6350_CHRSTATUS),
                             (&val),
                             (U32)(MT6350_PMIC_FCHRKEY_DEB_MASK),
                             (U32)(MT6350_PMIC_FCHRKEY_DEB_SHIFT)
                             );

        if(Enable_PMIC_LOG>1) 
        	dprintf(INFO, "%d", ret);
        
        if (val==1){
        	#ifndef USER_BUILD
        	dprintf(INFO, "LK pmic HOMEKEY Release\n");
        	#endif

        	return 0;
        }else{
        	#ifndef USER_BUILD
        	dprintf(INFO, "LK pmic HOMEKEY Press\n");
        	#endif

        	return 1;
        }
	return val;
}

kal_uint32 upmu_get_reg_value(kal_uint32 reg)
{
	U32 ret=0;
	U32 temp_val=0;

	ret=pmic_read_interface(reg, &temp_val, 0xFFFF, 0x0);

	if(Enable_PMIC_LOG>1) 
		dprintf(INFO, "%d", ret);

	return temp_val;
}

void PMIC_DUMP_ALL_Register(void)
{
        U32 i=0;
        U32 ret=0;
        U32 reg_val=0;
        
        for (i=0;i<0x800;i++)
        {
        	ret=pmic_read_interface(i,&reg_val,0xFFFF,0);
        	printf("Reg[0x%x]=0x%x, %d\n", i, reg_val, ret);
        }
}

//==============================================================================
// PMIC Init Code
//==============================================================================
void PMIC_INIT_SETTING_V1(void)
{
    //dprintf(INFO, "[LK_PMIC_INIT_SETTING_V1] Done\n");
}

void PMIC_CUSTOM_SETTING_V1(void)
{
    //dprintf(INFO, "[LK_PMIC_CUSTOM_SETTING_V1] Done\n");
}

U32 pmic_init (void)
{
        U32 ret_code = PMIC_TEST_PASS;
        
        dprintf(CRITICAL, "[pmic_init] LK Start..................\n");    
        dprintf(CRITICAL, "[pmic_init] MT6350 CHIP Code = 0x%x\n", get_mt6350_pmic_chip_version());    
        
        pmic_set_register_value(PMIC_RG_CHRIND_ON, 0);
        PMIC_INIT_SETTING_V1();
        PMIC_CUSTOM_SETTING_V1();
        
        #if 1
        // mt6311_driver_probe();
        #endif
        
        pmic_detect_powerkey();
        dprintf(CRITICAL, "[pmic_init] Done\n");
        
        return ret_code;
}

//==============================================================================
// PMIC API for LK : AUXADC
//==============================================================================

void pmic_auxadc_init(void)
{
}
#if 0
kal_uint32  pmic_is_auxadc_ready(kal_int32 channel_num, upmu_adc_chip_list_enum chip_num, upmu_adc_user_list_enum user_num)
{
}

kal_uint32  pmic_get_adc_output(kal_int32 channel_num, upmu_adc_chip_list_enum chip_num, upmu_adc_user_list_enum user_num)
{
}

kal_uint32 PMIC_IMM_RequestAuxadcChannel(upmu_adc_chl_list_enum dwChannel)
{

}

int PMIC_IMM_GetChannelNumber(upmu_adc_chl_list_enum dwChannel)
{
	kal_int32 channel_num;
	channel_num = (dwChannel & (AUXADC_CHANNEL_MASK << AUXADC_CHANNEL_SHIFT)) >> AUXADC_CHANNEL_SHIFT ;
	
	return channel_num;	
}

upmu_adc_chip_list_enum PMIC_IMM_GetChipNumber(upmu_adc_chl_list_enum dwChannel)
{
	upmu_adc_chip_list_enum chip_num;
	chip_num = (upmu_adc_chip_list_enum)(dwChannel & (AUXADC_CHIP_MASK << AUXADC_CHIP_SHIFT)) >> AUXADC_CHIP_SHIFT ;
	
	return chip_num;	
}

upmu_adc_user_list_enum PMIC_IMM_GetUserNumber(upmu_adc_chl_list_enum dwChannel)
{
	upmu_adc_user_list_enum user_num;
	user_num = (upmu_adc_user_list_enum)(dwChannel & (AUXADC_USER_MASK << AUXADC_USER_SHIFT)) >> AUXADC_USER_SHIFT ;
	
	return user_num;
}
#endif
//==============================================================================
// PMIC-AUXADC 
//==============================================================================
int PMIC_IMM_GetOneChannelValue(int dwChannel, int deCount, int trimd)
{
	kal_int32 ret_data;	
//	kal_int32 count=0;
	kal_int32 u4Sample_times = 0;
	kal_int32 u4channel=0;	
	kal_int32 adc_result_temp=0;
	kal_int32 r_val_temp=0;   
	kal_int32 adc_result=0;   
    	U32 adc_reg_val=0;
	
        /*
        0 : BATON2
        1 : CH6
        2 : THR SENSE2
        3 : THR SENSE1
        4 : VCDT
        5 : BATON1
        6 : ISENSE
        7 : BATSNS
        8 : ACCDET    
        */
        pmic_set_register_value(PMIC_RG_VBUF_EN, 1);

        //set 0
        pmic_read_interface(MT6350_AUXADC_CON22,&adc_reg_val, MT6350_PMIC_RG_AP_RQST_LIST_MASK, MT6350_PMIC_RG_AP_RQST_LIST_SHIFT);
        adc_reg_val = adc_reg_val & (~(1<<dwChannel));
        pmic_config_interface(MT6350_AUXADC_CON22,adc_reg_val, MT6350_PMIC_RG_AP_RQST_LIST_MASK, MT6350_PMIC_RG_AP_RQST_LIST_SHIFT);
        
        //set 1
        pmic_read_interface(MT6350_AUXADC_CON22,&adc_reg_val, MT6350_PMIC_RG_AP_RQST_LIST_MASK, MT6350_PMIC_RG_AP_RQST_LIST_SHIFT);
        adc_reg_val = adc_reg_val | (1<<dwChannel);
        pmic_config_interface(MT6350_AUXADC_CON22,adc_reg_val, MT6350_PMIC_RG_AP_RQST_LIST_MASK, MT6350_PMIC_RG_AP_RQST_LIST_SHIFT);

	do
	{
	    //count=0;
	    ret_data=0;

	    switch(dwChannel){         
	        case 0:    
	            while(mt6350_get_register_value(PMIC_RG_ADC_RDY_BATON2)!= 1 );
		    ret_data = mt6350_get_register_value(PMIC_RG_ADC_OUT_BATON2);
	            break;
	        case 1:
	            while(mt6350_get_register_value(PMIC_RG_ADC_RDY_CH6)!= 1 );
		    ret_data = mt6350_get_register_value(PMIC_RG_ADC_OUT_CH6);
	            break;
	        case 2:
	            while(mt6350_get_register_value(PMIC_RG_ADC_RDY_THR_SENSE2)!= 1 );
		    ret_data = mt6350_get_register_value(PMIC_RG_ADC_OUT_THR_SENSE2);				
	            break;				
	        case 3:
	            while(mt6350_get_register_value(PMIC_RG_ADC_RDY_THR_SENSE1)!= 1 );
		    ret_data = mt6350_get_register_value(PMIC_RG_ADC_OUT_THR_SENSE1);				
	            break;
	        case 4:
	            while(mt6350_get_register_value(PMIC_RG_ADC_RDY_VCDT)!= 1 );
		    ret_data = mt6350_get_register_value(PMIC_RG_ADC_OUT_VCDT);	
	            break;
	        case 5:
	            while(mt6350_get_register_value(PMIC_RG_ADC_RDY_BATON1)!= 1 );
		    ret_data = mt6350_get_register_value(PMIC_RG_ADC_OUT_BATON1);
	            break;
	        case 6:
	            while(mt6350_get_register_value(PMIC_RG_ADC_RDY_ISENSE)!= 1 );
		    ret_data = mt6350_get_register_value(PMIC_RG_ADC_OUT_ISENSE);
	            break;
	        case 7:
	            while(mt6350_get_register_value(PMIC_RG_ADC_RDY_BATSNS)!= 1 );
		    ret_data = mt6350_get_register_value(PMIC_RG_ADC_OUT_BATSNS);
	            break; 
	        case 8:
	            while(mt6350_get_register_value(PMIC_RG_ADC_RDY_CH5)!= 1 );
		    ret_data = mt6350_get_register_value(PMIC_RG_ADC_OUT_CH5);
	            break; 				
                
	        default:
	            dprintf(CRITICAL, "[AUXADC] Invalid channel value(%d,%d)\n", dwChannel, trimd);
	           
	            return -1;
	            break;
	    }

	    u4channel += ret_data;

	    u4Sample_times++;

	   // if (Enable_BATDRV_LOG == 1)
	    {
	        //debug
	        dprintf(CRITICAL, "[AUXADC] u4channel[%d]=%d.\n", 
	            dwChannel, ret_data);
	    }
	    
	}while (u4Sample_times < deCount);

    /* Value averaging  */ 
    adc_result_temp = u4channel / deCount;

    switch(dwChannel){         
        case 0:                
            r_val_temp = 1;           
            adc_result = (adc_result_temp*r_val_temp*VOLTAGE_FULL_RANGE)/ADC_PRECISE;
            break;
        case 1:    
            r_val_temp = 1;
            adc_result = (adc_result_temp*r_val_temp*VOLTAGE_FULL_RANGE)/ADC_PRECISE;
            break;
        case 2:    
            r_val_temp = 1;
            adc_result = (adc_result_temp*r_val_temp*VOLTAGE_FULL_RANGE)/ADC_PRECISE;
            break;
        case 3:    
            r_val_temp = 1;
            adc_result = (adc_result_temp*r_val_temp*VOLTAGE_FULL_RANGE)/ADC_PRECISE;
            break;
        case 4:    
            r_val_temp = 1;
            adc_result = (adc_result_temp*r_val_temp*VOLTAGE_FULL_RANGE)/ADC_PRECISE;
            break;
        case 5:    
            r_val_temp = 1;
            adc_result = (adc_result_temp*r_val_temp*VOLTAGE_FULL_RANGE)/ADC_PRECISE;
            break;
        case 6:    
            r_val_temp = 4;
            adc_result = (adc_result_temp*r_val_temp*VOLTAGE_FULL_RANGE)/ADC_PRECISE;
            break;
        case 7:    
            r_val_temp = 4;
            adc_result = (adc_result_temp*r_val_temp*VOLTAGE_FULL_RANGE)/ADC_PRECISE;
            break;    
        case 8:    
            r_val_temp = 1;
            adc_result = (adc_result_temp*r_val_temp*VOLTAGE_FULL_RANGE)/ADC_PRECISE;
            break;    			
        default:
            dprintf(CRITICAL, "[AUXADC] Invalid channel value(%d,%d)\n", dwChannel, trimd);

            return -1;
            break;
    }

        dprintf(CRITICAL, "[AUXADC] adc_result_temp=%d, adc_result=%d, r_val_temp=%d.\n", 
                adc_result_temp, adc_result, r_val_temp);

	
    return adc_result;
}

int get_bat_sense_volt(int times)
{
    return PMIC_IMM_GetOneChannelValue(VBAT_CHANNEL_NUMBER,times,1);
}

int get_i_sense_volt(int times)
{
    return PMIC_IMM_GetOneChannelValue(ISENSE_CHANNEL_NUMBER,times,1);
}

int get_charger_volt(int times)
{
    return PMIC_IMM_GetOneChannelValue(VCHARGER_CHANNEL_NUMBER,times,1);
}

int get_tbat_volt(int times)
{
    return PMIC_IMM_GetOneChannelValue(VBATTEMP_CHANNEL_NUMBER,times,1);
}
