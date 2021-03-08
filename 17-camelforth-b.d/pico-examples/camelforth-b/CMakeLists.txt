add_executable(camelforth-b
        camelforth-b.c
        )

# Sat Feb 27 23:45:07 UTC 2021

target_compile_definitions(camelforth-b PRIVATE
    # PICO_DEFAULT_BINARY_TYPE=no_flash # was: copy_to_ram
    NO_FLASH_CMAKE=-1
    # NO_FLASH_CMAKE=-1
)

target_link_libraries(camelforth-b forth pico-LED hardware_flash pico_stdlib)

# pico_set_binary_type(camelforth-b copy_to_ram)
# pico_set_binary_type(camelforth-b copy_to_ram)
# pico_set_binary_type(camelforth-b no_flash)
pico_set_binary_type(camelforth-b no_flash)

pico_enable_stdio_usb(camelforth-b 1)
pico_enable_stdio_uart(camelforth-b 1) # was zero

pico_add_extra_outputs(camelforth-b)

example_auto_set_url(camelforth-b)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

add_subdirectory(forth)
add_subdirectory(pico-hw)
