/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * Copyright 2017 NXP
 *
 */
#ifndef __VERSION_REGS_H__
#define __VERSION_REGS_H__

/*
 * HW revision/version
 */
/* CHA Revision Number */
#define CRNR_MS		(0x0FA0)
#define CRNR_LS		(0x0FA4)

#define BS_CRNR_MS_JRRN		(28)
#define BM_CRNR_MS_JRRN		(0xF << BS_CRNR_MS_JRRN)
#define BS_CRNR_MS_DECORN	(24)
#define BM_CRNR_MS_DECORN	(0xF << BS_CRNR_MS_DECORN)

#define BS_CRNR_LS_PKRN		(28)
#define BM_CRNR_LS_PKRN		(0xF << BS_CRNR_LS_PKRN)
#define BS_CRNR_LS_RNGRN	(16)
#define BM_CRNR_LS_RNGRN	(0xF << BS_CRNR_LS_RNGRN)
#define BS_CRNR_LS_MDRN		(12)
#define BM_CRNR_LS_MDRN		(0xF << BS_CRNR_LS_MDRN)
#define BS_CRNR_LS_ARC4RN	(8)
#define BM_CRNR_LS_ARC4RN	(0xF << BS_CRNR_LS_ARC4RN)
#define BS_CRNR_LS_DESRN	(4)
#define BM_CRNR_LS_DESRN	(0xF << BS_CRNR_LS_DESRN)
#define BS_CRNR_LS_AESRN	(0)
#define BM_CRNR_LS_AESRN	(0xF << BS_CRNR_LS_AESRN)

/* Compile Time Parameters */
#define CTPR_MS		(0x0FA8)
#define CTPR_LS		(0x0FAC)

#define BS_CTPR_MS_AXI_PIPE_DEPTH	(28)
#define BM_CTPR_MS_AXI_PIPE_DEPTH	(0xF << BS_CTPR_MS_AXI_PIPE_DEPTH)
#define BS_CTPR_MS_AXI_MID		(27)
#define BM_CTPR_MS_AXI_MID		(0x1 << BS_CTPR_MS_AXI_MID)
#define BS_CTPR_MS_AXI_PRI		(26)
#define BM_CTPR_MS_AXI_PRI		(0x1 << BS_CTPR_MS_PRI)
#define BS_CTPR_MS_QI			(25)
#define BM_CTPR_MS_QI			(0x1 << BS_CTPR_MS_QI)
#define BS_CTPR_MS_ACC_CTL		(24)
#define BM_CTPR_MS_ACC_CTL		(0x1 << BS_CTPR_MS_ACC_CTL)
#define BS_CTPR_MS_C1C2			(23)
#define BM_CTPR_MS_C1C2			(0x1 << BS_CTPR_MS_C1C2)
#define BS_CTPR_MS_PC			(21)
#define BM_CTPR_MS_PC			(0x1 << BS_CTPR_MS_PC)
#define BS_CTPR_MS_DECO_WD		(20)
#define BM_CTPR_MS_DECO_WD		(0x1 << BS_CTPR_MS_DECO_WD)
#define BS_CTPR_MS_PM_EVT_BUS		(19)
#define BM_CTPR_MS_PM_EVT_BUS		(0x1 << BS_CTPR_MS_PM_EVT_BUS)
#define BS_CTPR_MS_SG8			(18)
#define BM_CTPR_MS_SG8			(0x1 << BS_CTPR_MS_SG8)
#define BS_CTPR_MS_MCFG_PS		(17)
#define BM_CTPR_MS_MCFG_PS		(0x1 << BS_CTPR_MS_MCFG_PS)
#define BS_CTPR_MS_MCFG_BURST		(16)
#define BM_CTPR_MS_MCFG_BURST		(0x1 << BS_CTPR_MS_MCFG_BURST)
#define BS_CTPR_MS_IP_CLK		(14)
#define BM_CTPR_MS_IP_CLK		(0x1 << BS_CTPR_MS_IP_CLK)
#define BS_CTPR_MS_DPAA2		(13)
#define BM_CTPR_MS_DPAA2		(0x1 << BS_CTPR_MS_DPAA2)
#define BS_CTPR_MS_AI_INCL		(11)
#define BM_CTPR_MS_AI_INCL		(0x1 << BS_CTPR_MS_AI_INCL)
#define BS_CTPR_MS_RNG_I		(8)
#define BM_CTPR_MS_RNG_I		(0x7 << BS_CTPR_MS_RNG_I)
#define BS_CTPR_MS_REG_PG_SIZE		(4)
#define BM_CTPR_MS_REG_PG_SIZE		(0x1 << BS_CTPR_MS_REG_PG_SIZE)
#define BS_CTPR_MS_VIRT_EN_POR_VALUE	(1)
#define BM_CTPR_MS_VIRT_EN_POR_VALUE	(0x1 << BS_CTPR_MS_VIRT_EN_POR_VALUE)
#define BS_CTPR_MS_VIRT_EN_INCL		(0)
#define BM_CTPR_MS_VIRT_EN_INCL		(0x1 << BS_CTPR_MS_VIRT_EN_INCL)

#define BS_CTPR_LS_SPLIT_KEY		(14)
#define BM_CTPR_LS_SPLIT_KEY		(0x1 << BS_CTPR_LS_SPLIT_KEY)
#define BS_CTPR_LS_MAN_PROT		(13)
#define BM_CTPR_LS_MAN_PROT		(0x1 << BS_CTPR_LS_MAN_PROT)
#define BS_CTPR_LS_DBL_CRC		(12)
#define BM_CTPR_LS_DBL_CRC		(0x1 << BS_CTPR_LS_DBL_CRC)
#define BS_CTPR_LS_P3G_LTE		(11)
#define BM_CTPR_LS_P3G_LTE		(0x1 << BS_CTPR_LS_P3G_LTE)
#define BS_CTPR_LS_RSA			(10)
#define BM_CTPR_LS_RSA			(0x1 << BS_CTPR_LS_RSA)
#define BS_CTPR_LS_MACSEC		(9)
#define BM_CTPR_LS_MACSEC		(0x1 << BS_CTPR_LS_MACSEC)
#define BS_CTPR_LS_TLS_PRF		(8)
#define BM_CTPR_LS_TLS_PRF		(0x1 << BS_CTPR_LS_TLS_PRF)
#define BS_CTPR_LS_SSL_TLS		(7)
#define BM_CTPR_LS_SSL_TLS		(0x1 << BS_CTPR_LS_SSL_TLS)
#define BS_CTPR_LS_IKE			(6)
#define BM_CTPR_LS_IKE			(0x1 << BS_CTPR_LS_IKE)
#define BS_CTPR_LS_IPSEC		(5)
#define BM_CTPR_LS_IPSEC		(0x1 << BS_CTPR_LS_IPSEC)
#define BS_CTPR_LS_SRTP			(4)
#define BM_CTPR_LS_SRTP			(0x1 << BS_CTPR_LS_SRTP)
#define BS_CTPR_LS_WIMAX		(3)
#define BM_CTPR_LS_WIMAX		(0x1 << BS_CTPR_LS_WIMAX)
#define BS_CTPR_LS_WIFI			(2)
#define BM_CTPR_LS_WIFI			(0x1 << BS_CTPR_LS_WIFI)
#define BS_CTPR_LS_BLOB			(1)
#define BM_CTPR_LS_BLOB			(0x1 << BS_CTPR_LS_BLOB)
#define BS_CTPR_LS_KG_DS		(0)
#define BM_CTPR_LS_KG_DS		(0x1 << BS_CTPR_LS_KG_DS)

/* Secure Memory Version ID */
#define SMVID_MS	(0x0FD8)
#define SMVID_LS	(0x0FDC)

#define BS_SMVID_MS_MAX_NPAG	(16)
#define BM_SMVID_MS_MAX_NPAG	(0x3FF << BS_SMVID_MS_MAX_NPAG)
#define BS_SMVID_MS_NPRT	(12)
#define BM_SMVID_MS_NPRT	(0xF << BS_SMVID_MS_NPRT)
#define BS_SMVID_MS_NPAG	(0)
#define BM_SMVID_MS_NPAG	(0x3FF << BS_SMVID_MS_NPAG)

#define BS_SMVID_LS_PSIZ	(16)
#define BM_SMVID_LS_PSIZ	(0x7 << BS_SMVID_LS_PSIZ)
#define BS_SMVID_LS_SMJV	(8)
#define BM_SMVID_LS_SMJV	(0xFF << BS_SMVID_LS_SMJV)
#define BS_SMVID_LS_SMNV	(0)
#define BM_SMVID_LS_SMNV	(0xFF << BS_SMVID_LS_SMNV)

/* Minimum SM Version ID requiring v2 SM register mapping */
#define SMVID_V2		(0x0105)

/* RTIC Version ID */
#define RVID			(0x0FE0)

#define BS_RVID_MD		(27)
#define BM_RVID_MD		(0x1 << BS_RVID_MD)
#define BS_RVID_MC		(26)
#define BM_RVID_MC		(0x1 << BS_RVID_MC)
#define BS_RVID_MB		(25)
#define BM_RVID_MB		(0x1 << BS_RVID_MB)
#define BS_RVID_MA		(24)
#define BM_RVID_MA		(0x1 << BS_RVID_MA)
#define BS_RVID_MBL		(20)
#define BM_RVID_MBL		(0x1 << BS_RVID_MBL)
#define BS_RVID_SHA_512		(19)
#define BM_RVID_SHA_512		(0x1 << BS_RVID_SHA_512)
#define BS_RVID_SHA_256		(17)
#define BM_RVID_SHA_256		(0x1 << BS_RVID_SHA_256)
#define BS_RVID_RMJV		(8)
#define BM_RVID_RMJV		(0xFF << BS_RVID_RMJV)
#define BS_RVID_RMNV		(0)
#define BM_RVID_RMNV		(0xFF << BS_RVID_RMNV)

/* CHA Cluster Block Version ID */
#define CCBVID		(0x0FE4)

#define BS_CCBVID_CAAM_ERA	(24)
#define BM_CCBVID_CAAM_ERA	(0xFF << BS_CCBVID_CAAM_ERA)
#define BS_CCBVID_AMJV		(8)
#define BM_CCBVID_AMJV		(0xFF << BS_CCBVID_AMJV)
#define BS_CCBVID_AMNV		(0)
#define BM_CCBVID_AMNV		(0xFF << BS_CCBVID_AMNV)

/* CHA Version ID */
#define CHAVID_MS	(0x0FE8)
#define CHAVID_LS	(0x0FEC)

#define BS_CHAVID_MS_JRVID	(28)
#define BM_CHAVID_MS_JRVID	(0xF << BS_CHAVID_MS_JRVID)
#define BS_CHAVID_MS_DECOVID	(24)
#define BM_CHAVID_MS_DEOCVID	(0xF << BS_CHAVID_MS_DECOVID)

#define BS_CHAVID_LS_PKVID	(28)
#define BM_CHAVID_LS_PKVID	(0xF << BS_CHAVID_LS_PKVID)
#define BS_CHAVID_LS_RNGVID	(16)
#define BM_CHAVID_LS_RNGVID	(0xF << BS_CHAVID_LS_RNGVID)
#define BS_CHAVID_LS_MDVID	(12)
#define BM_CHAVID_LS_MDVID	(0xF << BS_CHAVID_LS_MDVID)
#define BS_CHAVID_LS_ARC4VID	(8)
#define BM_CHAVID_LS_ARC4VID	(0xF << BS_CHAVID_LS_ARC4VID)
#define BS_CHAVID_LS_DESVID	(4)
#define BM_CHAVID_LS_DESVID	(0xF << BS_CHAVID_LS_DESVID)
#define BS_CHAVID_LS_AESVID	(0)
#define BM_CHAVID_LS_AESVID	(0xF << BS_CHAVID_LS_AESVID)

#define CHAVID_LS_MDVID_LP256	(0x0 << BS_CHAVID_LS_MDVID)
#define CHAVID_LS_MDVID_LP512	(0x1 << BS_CHAVID_LS_MDVID)
#define CHAVID_LS_MDVID_MD512	(0x2 << BS_CHAVID_LS_MDVID)
#define CHAVID_LS_MDVID_HP512	(0x3 << BS_CHAVID_LS_MDVID)

/* CHA Number */
#define CHANUM_MS	(0x0FF0)
#define CHANUM_LS	(0x0FF4)

#define BS_CHANUM_MS_JRNUM	(28)
#define BM_CHANUM_MS_JRNUM	(0xF << BS_CHANUM_MS_JRNUM)
#define BS_CHANUM_MS_DECONUM	(24)
#define BM_CHANUM_MS_DECONUM	(0xF << BS_CHANUM_MS_DECONUM)
#define BS_CHANUM_MS_ZANUM	(12)
#define BM_CHANUM_MS_ZANUM	(0xF << BS_CHANUM_MS_ZANUM)
#define BS_CHANUM_MS_ZENUM	(8)
#define BM_CHANUM_MS_ZENUM	(0xF << BS_CHANUM_MS_ZENUM)
#define BS_CHANUM_MS_SNW9NUM	(4)
#define BM_CHANUM_MS_SNW9NUM	(0xF << BS_CHANUM_MS_SNW9NUM)
#define BS_CHANUM_MS_CRCNUM	(0)
#define BM_CHANUM_MS_CRCNUM	(0xF << BS_CHANUM_MS_CRCNUM)

#define BS_CHANUM_LS_PKNUM	(28)
#define BM_CHANUM_LS_PKNUM	(0xF << BS_CHANUM_LS_PKNUM)
#define BS_CHANUM_LS_KASNUM	(24)
#define BM_CHANUM_LS_KASNUM	(0xF << BS_CHANUM_LS_KASNUM)
#define BS_CHANUM_LS_SNW8NUM	(20)
#define BM_CHANUM_LS_SNW8NUM	(0xF << BS_CHANUM_LS_SNW8NUM)
#define BS_CHANUM_LS_RNGNUM	(16)
#define BM_CHANUM_LS_RNGNUM	(0xF << BS_CHANUM_LS_RNGNUM)
#define BS_CHANUM_LS_MDNUM	(12)
#define BM_CHANUM_LS_MDNUM	(0xF << BS_CHANUM_LS_MDNUM)
#define BS_CHANUM_LS_ARC4NUM	(8)
#define BM_CHANUM_LS_ARC4NUM	(0xF << BS_CHANUM_LS_ARC4NUM)
#define BS_CHANUM_LS_DESNUM	(4)
#define BM_CHANUM_LS_DESNUM	(0xF << BS_CHANUM_LS_DESNUM)
#define BS_CHANUM_LS_AESNUM	(0)
#define BM_CHANUM_LS_AESNUM	(0xF << BS_CHANUM_LS_AESNUM)

/* CAAM Version ID */
#define CAAMVID_MS	(0x0FF8)
#define CAAMVID_LS	(0x0FFC)

#define BS_CAAMVID_MS_IP_ID	(16)
#define BM_CAAMVID_MS_IP_ID	(0xFFFF << BS_CAAMVID_MS_IP_ID)
#define BS_CAAMVID_MS_MAJ_REV	(8)
#define BM_CAAMVID_MS_MAJ_REV	(0xFF << BS_CAAMVID_MS_MAJ_REV)
#define BS_CAAMVID_MS_MIN_REV	(0)
#define BM_CAAMVID_MS_MIN_REV	(0xFF << BS_CAAMVID_MS_MIN_REV)

#define BS_CAAMVID_LS_COMPILE_OPT	(24)
#define BM_CAAMVID_LS_COMPILE_OPT	(0xFF << BS_CAAMVID_LS_COMPILE_OPT)
#define BS_CAAMVID_LS_INTG_OPT		(16)
#define BM_CAAMVID_LS_INTG_OPT		(0xFF << BS_CAAMVID_LS_INTG_OPT)
#define BS_CAAMVID_LS_ECO_REV		(8)
#define BM_CAAMVID_LS_ECO_REV		(0xFF << BS_CAAMVID_LS_ECO_REV)
#define BS_CAAMVID_LS_CONFIG_OPT	(0)
#define BM_CAAMVID_LS_CONFIG_OPT	(0xFF << BS_CAAMVID_LS_CONFIG_OPT)

#endif /* __VERSION_REGS_H__ */
