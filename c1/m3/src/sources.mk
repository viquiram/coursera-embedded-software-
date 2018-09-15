#*****************************************************************************
# Copyright (C) 2018 by Viviana Quirama
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are
# permitted to modify this and use it to learn about the field of embedded
# software. The author is not liable for any misuse of this material.
#
#*****************************************************************************

# Add your Source files to this variable
SOURCES = main.c \
	  memory.c

# Add your include paths to this variable
INCLUDES = -I../include/common

ifeq ($(PLATFORM),MSP432)
	SOURCES += interrupts_msp432p401r_gcc.c \
        startup_msp432p401r_gcc.c \
        system_msp432p401r.c

	INCLUDES += -I../include/CMSIS \
        -I../include/msp432
endif
