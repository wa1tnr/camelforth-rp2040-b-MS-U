#!/bin/sh
# cmake -D"PICO_BOARD=myboard" ..

# $ sh ./run_cmake_feather.sh

# may do this on the command line or run this script
# example only - may be applied to any board.

 cmake -D"PICO_BOARD=adafruit_feather_rp2040" ..  # dont miss the dot dot

# ls ../../pico-sdk/src/boards/include/boards/adafruit_feather_rp2040.h
#END.
