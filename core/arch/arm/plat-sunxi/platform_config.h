/* SPDX-License-Identifier: BSD-2-Clause */
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

#ifndef PLATFORM_CONFIG_H
#define PLATFORM_CONFIG_H

/* Make stacks aligned to data cache line length */
#define STACK_ALIGNMENT		32

#ifdef CFG_WITH_PAGER
#error "Pager not supported for ARM64"
#endif
#ifdef CFG_WITH_LPAE
#error "LPAE not supported for platform sunxi"
#endif

/* 16550 UART */
#define CONSOLE_UART_BASE	0x01c28000 /* UART0 */
#define SUNXI_UART_REG_SIZE	0x400
#define GIC_BASE		0x01c80000
#define GICC_OFFSET		0x2000
#define GICD_OFFSET		0x1000
#define SMC_BASE		0x01c1e000
#define SUNXI_TZPC_BASE		0x01c23400
#define SUNXI_TZPC_REG_SIZE	0x400
#define SUNXI_CPUCFG_BASE		0x01f01c00
#define SUNXI_CPUCFG_REG_SIZE	0x400
#define SUNXI_PRCM_BASE		0x01f01400
#define SUNXI_PRCM_REG_SIZE	0x400
#define PRCM_CPU_SOFT_ENTRY_REG   (0x164)

/*
 * TEE/TZ RAM layout:
 *
 *  +-----------------------------------------+  <- CFG_DDR_TEETZ_RESERVED_START
 *  | TEETZ private RAM  |  TEE_RAM           |   ^
 *  |                    +--------------------+   |
 *  |                    |  TA_RAM            |   |
 *  +-----------------------------------------+   | CFG_DDR_TEETZ_RESERVED_SIZE
 *  |                    |      teecore alloc |   |
 *  |  TEE/TZ and NSec   |  PUB_RAM   --------|   |
 *  |   shared memory    |         NSec alloc |   |
 *  +-----------------------------------------+   v
 *
 *  TEE_RAM : 1MByte
 *  PUB_RAM : 1MByte
 *  TA_RAM  : all what is left (at least 2MByte !)
 */

#define DRAM0_BASE		0x40000000
#define DRAM0_SIZE		0x20000000

#define DDR_PHYS_START			DRAM0_BASE
#define DDR_SIZE			DRAM0_SIZE

#define CFG_DDR_START			DDR_PHYS_START
#define CFG_DDR_SIZE			DDR_SIZE

#define CFG_DDR_TEETZ_RESERVED_SIZE	0x04000000
#ifndef CFG_DDR_TEETZ_RESERVED_START
#define CFG_DDR_TEETZ_RESERVED_START	(DRAM0_BASE+DRAM0_SIZE-CFG_DDR_TEETZ_RESERVED_SIZE)
#endif

#define CFG_PUB_RAM_SIZE	(2 * 1024 * 1024)

#define TZDRAM_BASE		(CFG_DDR_TEETZ_RESERVED_START)
#define TZDRAM_SIZE		(CFG_DDR_TEETZ_RESERVED_SIZE-CFG_PUB_RAM_SIZE)

/* Below ARM-TF */
#define TEE_SHMEM_START		(CFG_DDR_TEETZ_RESERVED_START + TZDRAM_SIZE)
#define TEE_SHMEM_SIZE		CFG_PUB_RAM_SIZE

#define CFG_TEE_CORE_NB_CORE	4

#define TEE_RAM_VA_SIZE	(4 * 1024 * 1024)

#define TEE_RAM_PH_SIZE	TEE_RAM_VA_SIZE
#define TEE_RAM_START	TZDRAM_BASE

#define TA_RAM_START	ROUNDUP((TEE_RAM_START + TEE_RAM_VA_SIZE),			\
					CORE_MMU_DEVICE_SIZE)

#define TA_RAM_SIZE		ROUNDDOWN((TZDRAM_SIZE - TEE_RAM_VA_SIZE), \
					  CORE_MMU_DEVICE_SIZE)

#ifdef CFG_TEE_LOAD_ADDR
#define TEE_LOAD_ADDR			CFG_TEE_LOAD_ADDR
#else
#define TEE_LOAD_ADDR			TEE_RAM_START
#endif

#endif /* PLATFORM_CONFIG_H */
