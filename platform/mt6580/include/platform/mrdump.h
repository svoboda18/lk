#if !defined (__MRDUMP_H__)
#define __MRDUMP_H__

#include <sys/types.h>

#define RAM_CONSOLE_ADDR 0x0010DC00

#define RAM_CONSOLE_SIG (0x43474244) /* DBGC */

#define NR_CPUS 4
#define TASK_COMM_LEN 16

struct ram_console_buffer {
	uint32_t    sig;
	uint32_t    start;
	uint32_t    size;

	uint8_t     hw_status;
	uint8_t	    fiq_step;
	uint8_t     reboot_mode;
	uint8_t     __pad2;
	uint8_t     __pad3;

	uint32_t    bin_log_count;

	uint32_t    last_irq_enter[NR_CPUS];
	uint64_t    jiffies_last_irq_enter[NR_CPUS];

	uint32_t    last_irq_exit[NR_CPUS];
	uint64_t    jiffies_last_irq_exit[NR_CPUS];

	uint64_t    jiffies_last_sched[NR_CPUS];
	char        last_sched_comm[NR_CPUS][TASK_COMM_LEN];

	uint8_t     hotplug_data1[NR_CPUS];
	uint8_t     hotplug_data2[NR_CPUS];

	void        *kparams;

 	uint8_t     data[0];
};

struct mrdump_regset
{

    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    
    uint32_t fp; /* r11 */
    uint32_t r12;
    uint32_t sp; /* r13 */
    uint32_t lr; /* r14 */
    uint32_t pc; /* r15 */
    
    uint32_t cpsr;
};

struct mrdump_regpair {
    uint32_t addr;
    uint32_t val;
};

int aee_kdump_detection(void);

void mrdump_run(const struct mrdump_regset *per_cpu_regset, const struct mrdump_regpair *regpairs);

#endif
