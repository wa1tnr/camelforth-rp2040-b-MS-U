add_executable(camelforth-b
        camelforth-b.c
        )

# include_directories(../../pico-sdk/src/rp2_common/pico_fix/rp2040_usb_device_enumeration)

# Sat Feb 27 23:45:07 UTC 2021

target_compile_definitions(camelforth-b PRIVATE
    _PICO_FIX_RP2040_USB_DEVICE_ENUMERATION_H=-1
    # enable this flag only for no_flash compile:
    # NO_FLASH_CMAKE=-1
    # NO_FLASH_CMAKE=-1
)

# pico_add_impl_library(pico_fix_rp2040_usb_device_enumeration)
# 11 May 00:40z trying PRIVATE on line below first time ever
# target_link_libraries(camelforth-b PRIVATE forth pico-LED ws2812 hardware_flash pico_stdlib)
target_link_libraries(camelforth-b PRIVATE forth pico-LED ws2812 hardware_flash pico_fix_rp2040_usb_device_enumeration pico_stdlib)

# pico_set_binary_type(camelforth-b copy_to_ram)
pico_set_binary_type(camelforth-b copy_to_ram)
# pico_set_binary_type(camelforth-b no_flash)
# pico_set_binary_type(camelforth-b no_flash)

pico_enable_stdio_usb(camelforth-b 1)
pico_enable_stdio_uart(camelforth-b 1) # was zero

pico_add_extra_outputs(camelforth-b)

example_auto_set_url(camelforth-b)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

add_subdirectory(forth)
add_subdirectory(pico-hw)
add_subdirectory(pio)
