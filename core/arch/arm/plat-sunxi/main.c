// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (c) 2014, Allwinner Technology Co., Ltd.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <console.h>
#include <io.h>
#include <drivers/gic.h>
#include <drivers/sunxi_uart.h>
#include <kernel/generic_boot.h>
#include <kernel/misc.h>
#include <kernel/panic.h>
#include <kernel/pm_stubs.h>
#include <mm/core_mmu.h>
#include <mm/core_memprot.h>
#include <mm/tee_pager.h>
#include <platform_config.h>
#include <stdint.h>
#include <sm/tee_mon.h>
#include <sm/optee_smc.h>
#include <tee/entry_fast.h>
#include <tee/entry_std.h>

#ifdef GIC_BASE
register_phys_mem(MEM_AREA_IO_SEC, GIC_BASE, CORE_MMU_DEVICE_SIZE);
#endif
#ifdef CONSOLE_UART_BASE
register_phys_mem(MEM_AREA_IO_NSEC,
		  CONSOLE_UART_BASE, SUNXI_UART_REG_SIZE);
#endif
#ifdef SUNXI_TZPC_BASE
register_phys_mem(MEM_AREA_IO_SEC, SUNXI_TZPC_BASE, SUNXI_TZPC_REG_SIZE);
#endif
#ifdef SUNXI_CPUCFG_BASE
register_phys_mem(MEM_AREA_IO_SEC, SUNXI_CPUCFG_BASE, SUNXI_CPUCFG_REG_SIZE);
#endif
#ifdef SUNXI_PRCM_BASE
register_phys_mem(MEM_AREA_IO_SEC, SUNXI_PRCM_BASE, SUNXI_PRCM_REG_SIZE);
#endif

static struct gic_data gic_data;
static TEE_Result tzpc_init(void);
void platform_sunxi_init(void);
void reset_secondary(void);
static void main_tee_entry_std(struct thread_smc_args *args);
static void main_tee_entry_fast(struct thread_smc_args *args);

static void main_fiq(void)
{
	panic();
}

static const struct thread_handlers handlers = {
	.std_smc = tee_entry_std,
	.fast_smc = tee_entry_fast,
	.nintr = main_fiq,
#if defined(CFG_WITH_ARM_TRUSTED_FW)
	.cpu_on = cpu_on_handler,
	.cpu_off = pm_do_nothing,
	.cpu_suspend = pm_do_nothing,
	.cpu_resume = pm_do_nothing,
	.system_off = pm_do_nothing,
	.system_reset = pm_do_nothing,
#else
	.cpu_on = pm_panic,
	.cpu_off = pm_panic,
	.cpu_suspend = pm_panic,
	.cpu_resume = pm_panic,
	.system_off = pm_panic,
	.system_reset = pm_panic,
#endif
};

static struct sunxi_uart_data console_data;

const struct thread_handlers *generic_boot_get_handlers(void)
{
	return &handlers;
}

void console_init(void)
{
#ifdef CFG_SUN8I_H2_PLUS
	sunxi_uart_init(&console_data, CONSOLE_UART_BASE);
	register_serial_console(&console_data.chip);
#endif
}

static TEE_Result tzpc_init(void)
{
	vaddr_t tzpc;
	
	tzpc = (vaddr_t)phys_to_virt(SUNXI_TZPC_BASE, MEM_AREA_IO_SEC);
	DMSG("SMTA_DECPORT0 = %x", read32(tzpc+0x04));
	DMSG("SMTA_DECPORT1 = %x", read32(tzpc+0x10));
	DMSG("SMTA_DECPORT2 = %x", read32(tzpc+0x1c));
	write32(0xbe, tzpc+0x08);
	write32(0xff, tzpc+0x14);
	write32(0x7f, tzpc+0x20);
	DMSG("SMTA_DECPORT0 = %x", read32(tzpc+0x04));
	DMSG("SMTA_DECPORT1 = %x", read32(tzpc+0x10));
	DMSG("SMTA_DECPORT2 = %x", read32(tzpc+0x1c));
	return TEE_SUCCESS;
}

driver_init(tzpc_init);

void main_init_gic(void)
{
	vaddr_t gicc_base;
	vaddr_t gicd_base;

	gicc_base = core_mmu_get_va(GIC_BASE + GICC_OFFSET, MEM_AREA_IO_SEC);
	gicd_base = core_mmu_get_va(GIC_BASE + GICD_OFFSET, MEM_AREA_IO_SEC);

	if (!gicc_base || !gicd_base)
		panic();

	/* Initialize GIC */
	gic_init(&gic_data, gicc_base, gicd_base);
	itr_init(&gic_data.chip);

	/* platform smp initialize */
	/* Be cool with non-secure */
	write32(0xff, gicc_base + 0x0004);
}

void main_secondary_init_gic(void)
{
	gic_cpu_init(&gic_data);
}
