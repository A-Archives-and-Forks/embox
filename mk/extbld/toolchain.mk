
include mk/flags.mk
include $(SRCGEN_DIR)/image.rule.mk

# Ignore warning options and -MMD -MP
EMBOX_IMPORTED_CPPFLAGS := $(filter-out -MMD -MP -W%,$(EMBOX_EXPORT_CPPFLAGS))
EMBOX_IMPORTED_CPPFLAGS += $(filter -Wa$(,)% -Wp$(,)% -Wl$(,)%,$(EMBOX_EXPORT_CPPFLAGS))

# Ignore warning options and -std=<standard>
EMBOX_IMPORTED_CFLAGS   := $(filter-out -std=% -W%,$(CFLAGS))
EMBOX_IMPORTED_CFLAGS   += $(filter -Wa$(,)% -Wp$(,)% -Wl$(,)%,$(CFLAGS))

# Only machine-dependent options
EMBOX_IMPORTED_M_CFLAGS := $(filter -m% -EL -EB,$(CFLAGS))
ifeq ($(COMPILER),clang)
EMBOX_IMPORTED_M_CFLAGS += $(filter --target=%,$(subst -target ,--target=,$(strip $(CFLAGS))))
endif

# Ignore warning options and -std=<standard>
EMBOX_IMPORTED_CXXFLAGS := $(filter-out -std=% -W%,$(CXXFLAGS))
EMBOX_IMPORTED_CXXFLAGS += $(filter -Wa$(,)% -Wp$(,)% -Wl$(,)%,$(CXXFLAGS))

# Only -static -nostdlib -z<arg> and machine-dependent options
EMBOX_IMPORTED_LDFLAGS  := $(filter -static -nostdlib -EL -EB,$(LDFLAGS))
EMBOX_IMPORTED_LDFLAGS  += $(addprefix -Wl$(,),$(filter -z%,$(subst -z ,-z,$(strip $(LDFLAGS)))))
EMBOX_IMPORTED_LDFLAGS  += $(addprefix -Wl$(,),$(filter -m%,$(subst -m ,-m,$(strip $(LDFLAGS)))))

# In GCC 14 some warnings are reported as errors. Downgrade these errors to warnings.
ifeq ($(COMPILER),gcc)
ifeq ($(shell expr $(GCC_VERSION_MAJOR) \>= 14), 1)
EMBOX_IMPORTED_CFLAGS   += -fpermissive
EMBOX_IMPORTED_CXXFLAGS += -fpermissive
endif
endif

ifeq ($(ARCH),microblaze)
# microblaze compiler wants vendor's xillinx.ld if no lds provided from command line.
# Make it happy with empty lds
_empty_lds_hack:=$(abspath $(SRCGEN_DIR))/empty.lds
$(shell touch $(_empty_lds_hack))
EMBOX_IMPORTED_LDFLAGS += -T $(_empty_lds_hack)
endif

# Enable garbage collection of unused input sections
EMBOX_IMPORTED_LDFLAGS_FULL := -Wl,--gc-sections

LD_DISABLE_RELAXATION ?= n
ifeq ($(LD_DISABLE_RELAXATION),y)
EMBOX_IMPORTED_LDFLAGS_FULL += -Wl,--no-relax
else
EMBOX_IMPORTED_LDFLAGS_FULL += -Wl,--relax
endif

# Escape backticks to prevent command substitution (for example `pwd`).
escape_backticks = $(strip $(subst `,\`,$1))
EMBOX_IMPORTED_CFLAGS := $(call escape_backticks,$(EMBOX_IMPORTED_CFLAGS))
EMBOX_IMPORTED_CXXFLAGS := $(call escape_backticks,$(EMBOX_IMPORTED_CXXFLAGS))

embox_gcc   := $(EMBOX_GCC) $(EMBOX_GXX)
embox_clang := $(EMBOX_CLANG) $(EMBOX_CLANGXX)

$(embox_gcc) $(embox_clang) : imported_cppflags := $(EMBOX_IMPORTED_CPPFLAGS)
$(embox_gcc) $(embox_clang) : imported_cflags   := $(EMBOX_IMPORTED_CFLAGS)
$(embox_gcc) $(embox_clang) : imported_m_cflags := $(EMBOX_IMPORTED_M_CFLAGS)
$(embox_gcc) $(embox_clang) : imported_cxxflags := $(EMBOX_IMPORTED_CXXFLAGS)
$(embox_gcc) $(embox_clang) : imported_ldflags  := $(EMBOX_IMPORTED_LDFLAGS)

$(embox_gcc) $(embox_clang) : imported_ldflags_full := $(EMBOX_IMPORTED_LDFLAGS_FULL)
# Use `main` as the explicit symbol for beginning execution of your program.
# If there is no --entry=main flag, the test function section
# will be discarded during garbage collection. This flag is needed to check
# the implementation of functions by `configure` scripts
$(embox_gcc) $(embox_clang) : imported_ldflags_full += -Wl,--entry=main
$(embox_gcc) $(embox_clang) : imported_ldflags_full += -Wl,-T,$(OBJ_DIR)/image.lds
$(embox_gcc) $(embox_clang) : imported_ldflags_full += -Wl,--defsym=__symbol_table=0
$(embox_gcc) $(embox_clang) : imported_ldflags_full += -Wl,--defsym=__symbol_table_size=0
$(embox_gcc) $(embox_clang) : imported_ldflags_full += $(OBJ_DIR)/embox-1.o
$(embox_gcc) $(embox_clang) : imported_ldflags_full += -Wl,--start-group
$(embox_gcc) $(embox_clang) : imported_ldflags_full += $(__image_ld_libs1)
$(embox_gcc) $(embox_clang) : imported_ldflags_full += -Wl,--end-group

embox_binutils  := \
	$(TOOLCHAIN_DIR)/embox-ar \
	$(TOOLCHAIN_DIR)/embox-ranlib \
	$(TOOLCHAIN_DIR)/embox-nm \
	$(TOOLCHAIN_DIR)/embox-size

ifdef DIST_GEN
dist_gcc      := $(subst $(TOOLCHAIN_DIR),$(DIST_BIN_DIR),$(embox_gcc))
dist_clang    := $(subst $(TOOLCHAIN_DIR),$(DIST_BIN_DIR),$(embox_clang))
dist_binutils := $(subst $(TOOLCHAIN_DIR),$(DIST_BIN_DIR),$(embox_binutils))

$(dist_gcc) $(dist_clang) : imported_cppflags := \
	$(filter-out -I%,$(subst -I ,-I,$(strip $(EMBOX_IMPORTED_CPPFLAGS)))) \
	-I\$${EMBOX_DIST_INC_DIR}

$(dist_gcc) $(dist_clang) : imported_cflags   := $(EMBOX_IMPORTED_CFLAGS)
$(dist_gcc) $(dist_clang) : imported_m_cflags := $(EMBOX_IMPORTED_M_CFLAGS)
$(dist_gcc) $(dist_clang) : imported_cxxflags := $(EMBOX_IMPORTED_CXXFLAGS)
$(dist_gcc) $(dist_clang) : imported_ldflags  := $(EMBOX_IMPORTED_LDFLAGS)

$(dist_gcc) $(dist_clang) : imported_ldflags_full := $(EMBOX_IMPORTED_LDFLAGS_FULL)
$(dist_gcc) $(dist_clang) : imported_ldflags_full += -Wl,-T,\$${EMBOX_DIST_LIB_DIR}/image.lds
$(dist_gcc) $(dist_clang) : imported_ldflags_full += \$${EMBOX_DIST_LIB_DIR}/embox.o
$(dist_gcc) $(dist_clang) : imported_ldflags_full += \$${EMBOX_DIST_LIB_DIR}/embox.a
else
dist_gcc      :=
dist_clang    :=
dist_binutils :=
endif # DIST_GEN

all_toolchain := $(embox_binutils) $(dist_binutils)

ifeq ($(COMPILER),gcc)
all_toolchain += $(embox_gcc) $(dist_gcc)
endif

ifeq ($(COMPILER),clang)
all_toolchain += $(embox_clang) $(dist_clang)
endif

.PHONY : all
all : $(all_toolchain)

$(all_toolchain) : $(MKGEN_DIR)/build.mk $(MKGEN_DIR)/image.rule.mk
$(all_toolchain) : | $(TOOLCHAIN_DIR)

$(TOOLCHAIN_DIR) :
	@$(MKDIR) $@

$(embox_gcc) $(embox_clang) $(dist_gcc) $(dist_clang) :
	@COMPILER="$(COMPILER)" \
		EMBOX_IMPORTED_CPPFLAGS="$(imported_cppflags)" \
		EMBOX_IMPORTED_CFLAGS="$(imported_cflags)" \
		EMBOX_IMPORTED_M_CFLAGS="$(imported_m_cflags)" \
		EMBOX_IMPORTED_CXXFLAGS="$(imported_cxxflags)" \
		EMBOX_IMPORTED_LDFLAGS="$(imported_ldflags)" \
		EMBOX_IMPORTED_LDFLAGS_FULL="$(imported_ldflags_full)" \
		$(ROOT_DIR)/mk/extbld/gen_compilers.sh > $@
	@chmod +x $@

$(embox_binutils) $(dist_binutils) :
	@$(ROOT_DIR)/mk/extbld/gen_binutils.sh > $@
	@chmod +x $@
