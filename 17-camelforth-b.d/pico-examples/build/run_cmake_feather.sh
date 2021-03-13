#!/bin/sh
# cmake -D"PICO_BOARD=myboard" ..

# $ sh ./run_cmake_feather.sh

cmake -D"PICO_BOARD=adafruit_feather_rp2040" ..

# ls ../../pico-sdk/src/boards/include/boards/adafruit_feather_rp2040.h
#END.
