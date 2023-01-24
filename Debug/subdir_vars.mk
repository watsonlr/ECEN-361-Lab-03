################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../MSP_EXP432P401R_NoRTOS.cmd 

SYSCFG_SRCS += \
../uartecho.syscfg 

C_SRCS += \
../scheduler.c \
./syscfg/ti_drivers_config.c 

GEN_FILES += \
./syscfg/ti_drivers_config.c 

GEN_MISC_DIRS += \
./syscfg/ 

C_DEPS += \
./scheduler.d \
./syscfg/ti_drivers_config.d 

OBJS += \
./scheduler.obj \
./syscfg/ti_drivers_config.obj 

GEN_MISC_FILES += \
./syscfg/ti_drivers_config.h \
./syscfg/syscfg_c.rov.xs 

GEN_MISC_DIRS__QUOTED += \
"syscfg/" 

OBJS__QUOTED += \
"scheduler.obj" \
"syscfg/ti_drivers_config.obj" 

GEN_MISC_FILES__QUOTED += \
"syscfg/ti_drivers_config.h" \
"syscfg/syscfg_c.rov.xs" 

C_DEPS__QUOTED += \
"scheduler.d" \
"syscfg/ti_drivers_config.d" 

GEN_FILES__QUOTED += \
"syscfg/ti_drivers_config.c" 

C_SRCS__QUOTED += \
"../scheduler.c" \
"./syscfg/ti_drivers_config.c" 

SYSCFG_SRCS__QUOTED += \
"../uartecho.syscfg" 


