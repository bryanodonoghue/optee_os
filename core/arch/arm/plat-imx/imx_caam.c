// SPDX-License-Identifier: BSD-2-Clause
/*
 * Copyright (C) 2019 Bryan O'Donoghue
 *
 * Bryan O'Donoghue <bryan.odonoghue@linaro.org>
 */

#include <io.h>
#include <imx_caam.h>
#include <kernel/generic_boot.h>
#include <platform_config.h>
#include <stdint.h>

void init_caam(void)
{
	struct imx_caam_ctrl *caam = (struct caam_ctrl *)CAAM_BASE;
	uint32_t reg;
	int i;

	for (i = 0; i < CAAM_NUM_JOB_RINGS; i++) {
		reg = io_read32((vaddr_t)&caam->jr[i].jrmidr_ms);
		reg |= JROWN_NS | JROWN_MID;
		io_write32((vaddr_t)&caam->jr[i].jrmidr_ms, reg);
	}
}
