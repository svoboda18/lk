/* MediaTek Inc. (C) 2015. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */

#include <stdint.h>
#include <debug.h>

#include <load_vfy_boot.h>
#include <verified_boot_common.h>

#define SHA256_LENGTH 32
#define MTK_SIP_LK_ROOT_OF_TRUST_AARCH32    0x82000120

/* query verified boot state - g_boot_state */
extern unsigned int g_boot_state;
int sha256(unsigned char *data, unsigned long data_len, unsigned char *output_hash);
int sec_query_device_lock(int *lock_state);

static unsigned int smc_call(uint32_t function_id, uint32_t arg0, uint32_t arg1, uint32_t arg2, uint32_t arg3)
{
	unsigned int ret = 0;
	register uint32_t reg0 __asm__("r0") = function_id;
	register uint32_t reg1 __asm__("r1") = arg0;
	register uint32_t reg2 __asm__("r2") = arg1;
	register uint32_t reg3 __asm__("r3") = arg2;
	register uint32_t reg4 __asm__("r4") = arg3;

	__asm__ volatile ("smc 0" : "+r"(reg0),
		"+r"(reg1), "+r"(reg2), "+r"(reg3), "+r"(reg4));

	ret = reg0;
	return ret;
}

void send_root_of_trust_info(void)
{
	unsigned char public_key[PUBK_LEN] = {0};
	unsigned char public_key_hash[SHA256_LENGTH] = {0};
	int device_lock_state = 0;
	unsigned int os_version = 0;

	dprintf(INFO,"sending root of trust info...\n");

	/* read public key and generate SHA256(pubk) */
	if(sec_get_pubk(public_key, PUBK_LEN))
		dprintf(CRITICAL,"fail to get public key info\n");

	if(sha256(public_key, PUBK_LEN, public_key_hash))
		dprintf(CRITICAL,"fail to calculate public key hash\n");

	/* query device lock */
	if(sec_query_device_lock(&device_lock_state))
		dprintf(CRITICAL,"fail to get device lock state\n");

	/* query os version and patch level */
	os_version = get_os_version();
	if(os_version == 0)
		dprintf(CRITICAL,"fail to get os version and patch level\n");
#if 0
	for(int i=0; i<PUBK_LEN; i+=8)
		dprintf(CRITICAL,"public key [%d-%d] = 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n",
			i, i+7, public_key[i], public_key[i+1], public_key[i+2], public_key[i+3],
			public_key[i+4], public_key[i+5], public_key[i+6], public_key[i+7]);
	for(int i=0; i<SHA256_LENGTH; i+=8)
		dprintf(CRITICAL,"hash [%d-%d] = 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n",
			i, i+7, public_key_hash[i], public_key_hash[i+1], public_key_hash[i+2], public_key_hash[i+3],
			public_key_hash[i+4], public_key_hash[i+5], public_key_hash[i+6], public_key_hash[i+7]);
	dprintf(CRITICAL,"device lock state : %d\n", device_lock_state);
	dprintf(CRITICAL,"verified boot state : %d\n", g_boot_state);
	dprintf(CRITICAL,"os version : 0x%x\n", os_version);
#endif
	/* send to ARM-TF via SMC call */
	unsigned int *p_hash = (unsigned int *)public_key_hash;
	unsigned int smc_ret = 0;

	/* send info. and the sequence : pubk(32B), device state(4B), boot state(4B), os version(4B) */
	smc_ret |= smc_call(MTK_SIP_LK_ROOT_OF_TRUST_AARCH32, *(p_hash), *(p_hash+1), *(p_hash+2), *(p_hash+3));
	smc_ret |= smc_call(MTK_SIP_LK_ROOT_OF_TRUST_AARCH32, *(p_hash+4), *(p_hash+5), *(p_hash+6), *(p_hash+7));
	smc_ret |= smc_call(MTK_SIP_LK_ROOT_OF_TRUST_AARCH32, device_lock_state, g_boot_state, os_version, 0x0);
	if(smc_ret)
		dprintf(CRITICAL,"fail to send root of trust info. : 0x%x\n", smc_ret);

	/* to test if SMC call is locked after previous 3 calls */
	smc_ret = smc_call(MTK_SIP_LK_ROOT_OF_TRUST_AARCH32, 0x0, 0x0, 0x0, 0x0);
	if(!smc_ret)
		dprintf(CRITICAL,"Warning! root of trust smc call is not locked : 0x%x\n", smc_ret);
}
