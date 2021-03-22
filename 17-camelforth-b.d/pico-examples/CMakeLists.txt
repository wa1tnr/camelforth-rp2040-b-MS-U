cmake_minimum_required(VERSION 3.12)

# Pull in PICO SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico_examples C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# if (0) # disable # change to '(1)' to enable
if ( BOOT2_GENERIC_CF_LOCAL ) # calling shell script establishes this
    if (NOT PICO_DEFAULT_BOOT_STAGE2_FILE)
        set(PICO_DEFAULT_BOOT_STAGE2_FILE "${PICO_SDK_PATH}/src/rp2_common/boot_stage2/boot2_generic_03h.S")
    # [  1%] Building ASM object pico-sdk/src/rp2_common/boot_stage2/CMakeFiles/bs2_default.dir/boot2_generic_03h.S.obj
    endif()
endif()

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()

include(example_auto_set_url.cmake)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

# Hardware-specific examples in subdirectories:
# add_subdirectory(cmake)
add_subdirectory(camelforth-b)
# add_subdirectory(system)
