

#include <platform/spm.h>

int spm_mtcmos_ctrl_mdsys1(int state)
{
    int err = 0;
    volatile unsigned int val;
    unsigned long flags;
    int count = 0;

    if (state == STA_POWER_DOWN) {
        spm_write(TOPAXI_PROT_EN, spm_read(TOPAXI_PROT_EN) | MD1_PROT_MASK);
        while ((spm_read(TOPAXI_PROT_STA1) & MD1_PROT_MASK) != MD1_PROT_MASK) {
            count++;
            if(count>1000)
                break;
        }

        spm_write(SPM_MD_PWR_CON, spm_read(SPM_MD_PWR_CON) | MD_SRAM_PDN);

        spm_write(SPM_MD_PWR_CON, spm_read(SPM_MD_PWR_CON) | PWR_ISO);

        val = spm_read(SPM_MD_PWR_CON);
        val = (val & ~PWR_RST_B) | PWR_CLK_DIS;
        spm_write(SPM_MD_PWR_CON, val);

        spm_write(SPM_MD_PWR_CON, spm_read(SPM_MD_PWR_CON) & ~(PWR_ON | PWR_ON_2ND));

        while ((spm_read(SPM_PWR_STATUS) & MD1_PWR_STA_MASK)
                || (spm_read(SPM_PWR_STATUS_2ND) & MD1_PWR_STA_MASK)) {
        }

    } else {    /* STA_POWER_ON */
        
        spm_write(SPM_MD_PWR_CON, spm_read(SPM_MD_PWR_CON) | PWR_ON);
        spm_write(SPM_MD_PWR_CON, spm_read(SPM_MD_PWR_CON) | PWR_ON_2ND);

        while (!(spm_read(SPM_PWR_STATUS) & MD1_PWR_STA_MASK) 
                || !(spm_read(SPM_PWR_STATUS_2ND) & MD1_PWR_STA_MASK)) {
        }

        spm_write(SPM_MD_PWR_CON, spm_read(SPM_MD_PWR_CON) & ~PWR_CLK_DIS);
        spm_write(SPM_MD_PWR_CON, spm_read(SPM_MD_PWR_CON) & ~PWR_ISO);
        spm_write(SPM_MD_PWR_CON, spm_read(SPM_MD_PWR_CON) | PWR_RST_B);

        spm_write(SPM_MD_PWR_CON, spm_read(SPM_MD_PWR_CON) & ~MD_SRAM_PDN);

        spm_write(TOPAXI_PROT_EN, spm_read(TOPAXI_PROT_EN) & ~MD1_PROT_MASK);
        while (spm_read(TOPAXI_PROT_STA1) & MD1_PROT_MASK) {
        }
    }

    return err;
}


