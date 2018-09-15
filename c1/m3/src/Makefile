#*****************************************************************************
# Copyright (C) 2018 by Viviana Quirama
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. The author is not liable for any misuse of this material.
#
#*****************************************************************************

#-----------------------------------------------------------------------------
# Simple makefile for the host environment and the target embedded system
# MSP432
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#
#      <FILE>.i    - Generates the preprocessed output for all c-program
#                    implementation files
#
#      <FILE>.asm  - Generates the assembly output for all c-program
#                    implementation files and the final output executable
#
#      <FILE>.o    - Generates the objects files for all c-program
#                    implementation files, but DO NOT link
#
#      compile-all - Compiles all object files, but DO NOT link
#
#      build       - Compiles all object files and link into a final
#                    executable
#
#      clean       - Removes all compiled objects, preprocessed outputs,
#                    assembly outputs, executable files and build output files

#
# Platform Overrides:
#
#      MSP432      - MSP432 embedded system
#
#      HOST        - Host environment
#
#-----------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM ?= HOST

# Compiler Flags and Defines
TARGET := c1m2
CC := gcc
LD := ld
DUMP := objdump
SIZE := size
LDFLAGS := -Wl,-Map=$(TARGET).map
CFLAGS := -Wall -Werror -g -O0 -std=c99
CPPFLAGS := -E

ifeq ($(PLATFORM),MSP432)
	# Architectures Specific Flags
	LINKER_FILE := ../msp432p401r.lds
	CPU := cortex-m4
	ARCH := thumb
	ARM_ARCH := armv7e-m
	FLOAT_ABI := hard
	FPU := fpv4-sp-d16
	SPECS := nosys.specs
	PLATFORM_FLAGS = -mcpu=$(CPU) -m$(ARCH) -march=$(ARM_ARCH) \
        -mfloat-abi=$(FLOAT_ABI) -mfpu=$(FPU) \
        --specs=$(SPECS)

	CROSS_COMPILE := arm-none-eabi-
	CC := $(CROSS_COMPILE)$(CC)
	LD := $(CROSS_COMPILE)$(LD)
	DUMP := $(CROSS_COMPILE)$(DUMP)
	SIZE := $(CROSS_COMPILE)$(SIZE)
	CFLAGS += $(PLATFORM_FLAGS)
	LDFLAGS += -T $(LINKER_FILE) $(PLATFORM_FLAGS)
endif

PREP := $(SOURCES:.c=.i)
S := $(SOURCES:.c=.s)
ASM := $(SOURCES:.c=.asm)
OBJS := $(SOURCES:.c=.o)
DEP := $(SOURCES:.c=.d)

%.i : %.c
	$(CC) $(CPPFLAGS) $< > $@ -D$(PLATFORM) $(INCLUDES)

%.asm : $(S) $(TARGET)
	$(DUMP) -S $(TARGET).out > $(TARGET).asm
	for f in $(S); do mv -- "$$f" "$${f%.s}.asm"; done

$(S) : %.s : %.c
	$(CC) $< -S -o $@ $(CFLAGS) -D$(PLATFORM) $(INCLUDES)

$(OBJS) : %.o : %.c
	$(CC) -c $< $(CFLAGS) -D$(PLATFORM) $(INCLUDES)

$(DEP) : %.d : %.c
	$(CC) -M $< -MF $@ -D$(PLATFORM) $(INCLUDES)

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $(TARGET).out $(LDFLAGS)

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(DEP) $(TARGET)
	$(SIZE) -Ad $(TARGET).out

.PHONY: clean
clean:
	rm -f *.i *.d *.s *.asm *.o \
	$(TARGET).out $(TARGET).map $(TARGET).asm
