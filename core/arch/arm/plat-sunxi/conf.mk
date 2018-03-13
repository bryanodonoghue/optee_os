PLATFORM_FLAVOR ?= sun8i_h2_plus_bananapi_m2_zero

sun8i_h2_plus_flavorlist = sun8i_h2_plus_bananapi_m2_zero

ifneq (,$(filter $(PLATFORM_FLAVOR),$(sun8i_h2_plus_flavorlist)))
include core/arch/arm/cpu/cortex-a7.mk
$(call force,CFG_SUN8I_H2_PLUS,y)
endif

ta-targets = ta_arm32
ifeq ($(CFG_ARM64_core),y)
$(call force,CFG_WITH_LPAE,y)
ta-targets += ta_arm64
else
$(call force,CFG_ARM32_core,y)
endif

ifeq ($(filter y,$(CFG_SUN8I_H2_PLUS)),y)
$(call force,CFG_GENERIC_BOOT,y)
$(call force,CFG_GIC,y)
$(call force,CFG_SUNXI_UART,y)
$(call force,CFG_PM_STUBS,y)
$(call force,CFG_SECURE_TIME_SOURCE_CNTPCT,y)
$(call force,CFG_WITH_LPAE,n)
$(call force,CFG_WITH_PAGER,n)
endif

ifneq (,$(filter $(PLATFORM_FLAVOR),sun8i_h2_plus_bananapi_m2_zero))
CFG_CRYPTO_SIZE_OPTIMIZATION ?= n
CFG_NUM_THREADS ?= 4
CFG_CRYPTO_WITH_CE ?= n
CFG_WITH_STACK_CANARIES ?= y
#CFG_BOOT_SYNC_CPU ?= y
CFG_BOOT_SECONDARY_REQUEST ?= y
CFG_TEE_CORE_EMBED_INTERNAL_TESTS ?= y
CFG_WITH_STACK_CANARIES ?= y
CFG_WITH_STATS ?= y
CFG_NS_ENTRY_ADDR ?= 0x42000000
CFG_DT ?= y
endif

arm32-platform-cflags += -Wno-error=cast-align
arm64-platform-cflags += -Wno-error=cast-align
