################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Users/lynnrwatson/Library/CloudStorage/OneDrive-BYU-Idaho/2023_Winter/ECEN-361-Winter23/NewLabs/lab-03-scaffoldingworking" --include_path="/Users/lynnrwatson/Library/CloudStorage/OneDrive-BYU-Idaho/2023_Winter/ECEN-361-Winter23/NewLabs/lab-03-scaffoldingworking/Debug" --include_path="/Users/lynnrwatson/Downloads/simplelink_msp432p4_sdk_3_40_01_02/source" --include_path="/Users/lynnrwatson/Downloads/simplelink_msp432p4_sdk_3_40_01_02/source/third_party/CMSIS/Include" --include_path="/Users/lynnrwatson/Downloads/simplelink_msp432p4_sdk_3_40_01_02/kernel/nortos" --include_path="/Users/lynnrwatson/Downloads/simplelink_msp432p4_sdk_3_40_01_02/kernel/nortos/posix" --include_path="/Applications/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --advice:power=none -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="/Users/lynnrwatson/Library/CloudStorage/OneDrive-BYU-Idaho/2023_Winter/ECEN-361-Winter23/NewLabs/lab-03-scaffoldingworking/Debug/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-2009427375: ../uartecho.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"/Applications/ti/ccs1210/ccs/utils/sysconfig_1.14.0/sysconfig_cli.sh" -s "/Users/lynnrwatson/Downloads/simplelink_msp432p4_sdk_3_40_01_02/.metadata/product.json" --script "/Users/lynnrwatson/Library/CloudStorage/OneDrive-BYU-Idaho/2023_Winter/ECEN-361-Winter23/NewLabs/lab-03-scaffoldingworking/uartecho.syscfg" -o "syscfg" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_drivers_config.c: build-2009427375 ../uartecho.syscfg
syscfg/ti_drivers_config.h: build-2009427375
syscfg/syscfg_c.rov.xs: build-2009427375
syscfg/: build-2009427375

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Users/lynnrwatson/Library/CloudStorage/OneDrive-BYU-Idaho/2023_Winter/ECEN-361-Winter23/NewLabs/lab-03-scaffoldingworking" --include_path="/Users/lynnrwatson/Library/CloudStorage/OneDrive-BYU-Idaho/2023_Winter/ECEN-361-Winter23/NewLabs/lab-03-scaffoldingworking/Debug" --include_path="/Users/lynnrwatson/Downloads/simplelink_msp432p4_sdk_3_40_01_02/source" --include_path="/Users/lynnrwatson/Downloads/simplelink_msp432p4_sdk_3_40_01_02/source/third_party/CMSIS/Include" --include_path="/Users/lynnrwatson/Downloads/simplelink_msp432p4_sdk_3_40_01_02/kernel/nortos" --include_path="/Users/lynnrwatson/Downloads/simplelink_msp432p4_sdk_3_40_01_02/kernel/nortos/posix" --include_path="/Applications/ti/ccs1210/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --advice:power=none -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="/Users/lynnrwatson/Library/CloudStorage/OneDrive-BYU-Idaho/2023_Winter/ECEN-361-Winter23/NewLabs/lab-03-scaffoldingworking/Debug/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


