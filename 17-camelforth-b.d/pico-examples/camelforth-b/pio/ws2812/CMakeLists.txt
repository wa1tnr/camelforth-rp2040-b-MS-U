# add_executable(pio_ws2812)

# generate the header file into the source tree as it is included in the RP2040 datasheet
# pico_generate_pio_header(pio_ws2812 ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)

# target_sources(pio_ws2812 PRIVATE ws2812.c)

# target_link_libraries(pio_ws2812 PRIVATE pico_stdlib hardware_pio)
# pico_add_extra_outputs(pio_ws2812)

# add url via pico_set_program_url
# example_auto_set_url(pio_ws2812)

# Additionally generate python and hex pioasm outputs for inclusion in the RP2040 datasheet
# add_custom_target(pio_ws2812_datasheet DEPENDS ${CMAKE_CURRENT_LIST_DIR}/generated/ws2812.py)
# add_custom_command(OUTPUT ${CMAKE_CURRENT_LIST_DIR}/generated/ws2812.py
#        DEPENDS ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio
#        COMMAND Pioasm -o python ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio ${CMAKE_CURRENT_LIST_DIR}/generated/ws2812.py
#        )
# add_dependencies(pio_ws2812 pio_ws2812_datasheet)

add_library(ws2812 ws2812.c pico-RGB.c)
pico_generate_pio_header(ws2812 ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_LIST_DIR}/generated)
target_link_libraries(ws2812 PRIVATE pico_stdlib hardware_pio)
