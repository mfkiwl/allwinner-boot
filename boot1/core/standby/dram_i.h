/*
*********************************************************************************************************
* File    : dram_i.h
* By      : Berg.Xing
* Date    : 2011-06-01
* Descript: dram csp for AW1623 chipset;
* Update  : date          auther      ver     notes
*     2011-06-01      			Berg        1.0     create file
*			2011-07-01			Berg        1.1     add extern function description
*			2011-08-05			Berg		1.2		add CPU_CFIG_REG in timer module
*********************************************************************************************************
*/
#ifndef __DRAM_I_H__
#define __DRAM_I_H__

#include "include.h"

#define DRAMC_IO_BASE       0x01c01000
#define DRAMC_MEM_SIZE      0x400

#define SDR_CCR				(DRAMC_IO_BASE + 0x00)
#define SDR_DCR				(DRAMC_IO_BASE + 0x04)
#define SDR_IOCR			(DRAMC_IO_BASE + 0x08)
#define SDR_CSR				(DRAMC_IO_BASE + 0x0c)
#define SDR_DRR				(DRAMC_IO_BASE + 0x10)
#define SDR_TPR0			(DRAMC_IO_BASE + 0x14)
#define SDR_TPR1			(DRAMC_IO_BASE + 0x18)
#define SDR_TPR2			(DRAMC_IO_BASE + 0x1c)
#define SDR_RSLR0			(DRAMC_IO_BASE + 0x4c)
#define SDR_RSLR1			(DRAMC_IO_BASE + 0x50)
#define SDR_RDQSGR			(DRAMC_IO_BASE + 0x5c)
#define SDR_ODTCR			(DRAMC_IO_BASE + 0x98)
#define SDR_DTR0			(DRAMC_IO_BASE + 0x9c)
#define SDR_DTR1			(DRAMC_IO_BASE + 0xa0)
#define SDR_DTAR			(DRAMC_IO_BASE + 0xa4)
#define SDR_ZQCR0			(DRAMC_IO_BASE + 0xa8)
#define SDR_ZQCR1			(DRAMC_IO_BASE + 0xac)
#define SDR_ZQSR			(DRAMC_IO_BASE + 0xb0)
#define SDR_IDCR			(DRAMC_IO_BASE + 0xb4)
#define SDR_MR				(DRAMC_IO_BASE + 0x1f0)
#define SDR_EMR				(DRAMC_IO_BASE + 0x1f4)
#define SDR_EMR2			(DRAMC_IO_BASE + 0x1f8)
#define SDR_EMR3  			(DRAMC_IO_BASE + 0x1fc)
#define SDR_DLLCR			(DRAMC_IO_BASE + 0x200)
#define SDR_DLLCR0			(DRAMC_IO_BASE + 0x204)
#define SDR_DLLCR1			(DRAMC_IO_BASE + 0x208)
#define SDR_DLLCR2			(DRAMC_IO_BASE + 0x20c)
#define SDR_DLLCR3			(DRAMC_IO_BASE + 0x210)
#define SDR_DLLCR4			(DRAMC_IO_BASE + 0x214)
#define SDR_DQTR0			(DRAMC_IO_BASE + 0x218)
#define SDR_DQTR1			(DRAMC_IO_BASE + 0x21c)
#define SDR_DQTR2			(DRAMC_IO_BASE + 0x220)
#define SDR_DQTR3			(DRAMC_IO_BASE + 0x224)
#define SDR_DQSTR0			(DRAMC_IO_BASE + 0x228)
#define SDR_DQSTR1			(DRAMC_IO_BASE + 0x22c)
#define SDR_CR				(DRAMC_IO_BASE + 0x230)
#define SDR_CFSR			(DRAMC_IO_BASE + 0x234)
#define SDR_APR  			(DRAMC_IO_BASE + 0x240)
#define SDR_LTR	  			(DRAMC_IO_BASE + 0x244)
#define SDR_HPCR			(DRAMC_IO_BASE + 0x250)
#define SDR_SCSR			(DRAMC_IO_BASE + 0x2e0)



#define mctl_read_w(n)      (*((volatile unsigned int *)(n)))
#define mctl_write_w(n,c)   (*((volatile unsigned int *)(n)) = (c))


//CCM register for dram
#define DRAM_CCM_BASE       0x01c20000
#define DRAM_CCM_MEMSIZE    0x400

#define DRAM_CCM_SDRAM_PLL_REG    (DRAM_CCM_BASE + 0x20)
#define DRAM_CCM_AHB_GATE_REG     (DRAM_CCM_BASE + 0x60)
#define DRAM_CCM_GPS_CLK_REG      (DRAM_CCM_BASE + 0xd0)
#define DRAM_CCM_SDRAM_CLK_REG    (DRAM_CCM_BASE + 0x100)


//TIMER register for system
#define DRAM_TIMER_BASE     0x01c20c00
#define TIMER_CPU_CFG_REG   (DRAM_TIMER_BASE + 0x13c)


extern void 	DRAMC_clock_output_en(__u32 on);
extern void 	DRAMC_set_autorefresh_cycle(__u32 clk);
extern int  	DRAMC_scan_readpipe(void);
extern unsigned DRAMC_get_dram_size(void);

extern void mctl_itm_disable(void);
extern void mctl_itm_enable(void);
extern void mctl_enable_dll0(void);
extern void mctl_enable_dllx(void);
extern void mctl_disable_dll(void);
extern void DRAMC_hostport_on_off(__u32 port_idx, __u32 on);

extern void mctl_ddr3_reset(void);
extern void mctl_set_drive(void);
extern void mctl_configure_hostport(void);

extern void standby_delay(int ms);

#endif  //__DRAM_REG_H__

