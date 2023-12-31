#include <debug.h>	/* for dprintf() */
#include <dev/aee_platform_debug.h> /* for CALLBACK type*/
#include <platform/mt_typedefs.h> /* for u64 type */
#include <platform/plat_atf_dbg_info.h>
//#include <sys/types.h>	/* for u64 types */

void atf_log_init(void)
{
	plat_atf_log_get = NULL;
	plat_atf_crash_get = NULL;
	plat_atf_raw_log_get = NULL;
	plat_atf_rdump_get = NULL;

	dprintf(CRITICAL, "LK Dump: atf_log_init empty function\n");
}

