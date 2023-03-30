if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

# include_directories(../../include)
add_library(asmword asmword.c asmword.S)
target_link_libraries(asmword pico_stdlib)
