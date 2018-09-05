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

# Architectures Specific Flags (MSP432)
LINKER_FILE := ../msp432p401r.lds
CPU := cortex-m4
ARCH := thumb
ARM_ARCH := armv7e-m
FLOAT_ABI := hard
FPU := fpv4-sp-d16
SPECS := nosys.specs
CROSS_COMPILE := arm-none-eabi-
GCC_INCLUDE_DIR := /usr/lib/arm-none-eabi/include
CMSIS_INCLUDE_DIR := ../include/CMSIS
MSP432_INCLUDE_DIR := ../include/msp432

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
	CC := $(CROSS_COMPILE)$(CC)
	LD := $(CROSS_COMPILE)$(LD)
	DUMP := $(CROSS_COMPILE)$(DUMP)
	SIZE := $(CROSS_COMPILE)$(SIZE)
	CFLAGS += -mcpu=$(CPU) -m$(ARCH) -march=$(ARM_ARCH) \
	-mfloat-abi=$(FLOAT_ABI) -mfpu=$(FPU) \
	--specs=$(SPECS)
	LDFLAGS += -T $(LINKER_FILE) -mcpu=$(CPU) -m$(ARCH) \
	-march=$(ARM_ARCH) -mfloat-abi=$(FLOAT_ABI) -mfpu=$(FPU) \
	--specs=$(SPECS)
	SOURCES += interrupts_msp432p401r_gcc.c \
	startup_msp432p401r_gcc.c \
	system_msp432p401r.c
	INCLUDES += -I$(GCC_INCLUDE_DIR) \
	-I$(CMSIS_INCLUDE_DIR) \
	-I$(MSP432_INCLUDE_DIR)
endif

PREP := $(SOURCES:.c=.i)
ASM := $(SOURCES:.c=.s)
OBJS := $(SOURCES:.c=.o)
DEP := $(SOURCES:.c=.d)

%.i : %.c
	$(CC) $(CPPFLAGS) $< > $@ -D$(PLATFORM) -I$(INCLUDES)

%.asm : $(ASM)
	$(CC) -c $^ $(CFLAGS)
	$(CC) $(OBJS) -o $(TARGET).out $(LDFLAGS)
	$(DUMP) -d $(TARGET).out > $(TARGET).dump
	for f in *.s; do mv -- "$$f" "$${f%.s}.asm"; done

$(ASM) : %.s : %.c
	$(CC) $< -S -o $@ $(CFLAGS) -D$(PLATFORM) -I$(INCLUDES)

$(OBJS) : %.o : %.c
	$(CC) -c $< $(CFLAGS) -D$(PLATFORM) -I$(INCLUDES)

$(DEP) : %.d : %.c
	$(CC) -M $< -MF $@ -D$(PLATFORM) -I$(INCLUDES)

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(OBJS) $(DEP)
	$(CC) $(OBJS) -o $(TARGET).out $(LDFLAGS)
	$(SIZE) -Ad $(TARGET).out

.PHONY: clean
clean:
	rm -f *.i *.d *.s *.asm *.o \
	$(TARGET).out $(TARGET).map $(TARGET).dump
