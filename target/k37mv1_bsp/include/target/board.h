#ifndef __BOARD_H
#define __BOARD_H

#define CONFIG_CFB_CONSOLE
#ifndef MACH_FPGA_NO_DISPLAY
#define CFB_CONSOLE_ON
#endif

#define CONFIG_SYS_PROMPT               "LK> "
#define CONFIG_SYS_CBSIZE               256  		 /* Console I/O Buffer Size */

/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE               (CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)

//Project specific header file
#define CFG_DISPLAY_WIDTH       (DISP_GetScreenWidth())
#define CFG_DISPLAY_HEIGHT      (DISP_GetScreenHeight())
#define CFG_DISPLAY_BPP         (DISP_GetScreenBpp())

//#define CFG_POWER_CHARGING

#endif
