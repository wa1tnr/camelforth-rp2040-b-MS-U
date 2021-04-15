# add_library(pico-LED pico-LED.c)
# target_link_libraries(pico-LED pico_stdlib)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

include_directories(../../include)
add_library(pico-LED pico-LED.c)
target_link_libraries(pico-LED pico_stdlib)
