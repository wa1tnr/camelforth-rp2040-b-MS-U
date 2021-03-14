#!/bin/sh
# cmake -D"PICO_BOARD=myboard" ..

# $ sh ./run_cmake_feather.sh

# example only - may be applied to any board.

 cmake -D"PICO_BOARD=adafruit_feather_rp2040" ..  # dont miss the dot dot

# ls ../../pico-sdk/src/boards/include/boards/adafruit_feather_rp2040.h

exit 0 # don't print the message below

# documentation follows - from Appendix D of the SDK doco

cat << _EOF


Building applications with a custom board configuration

The CMake system is what specifies which board configuration
is going to be used.

To create a new build based on a new board configuration
(we will use the myboard example from the previous section)
first create a new build folder under your project folder.

For our example we will use the pico-examples folder.

 $ cd pico-examples
 $ mkdir myboard_build
 $ cd myboard_build

then run cmake as follows:

 $ cmake -D"PICO_BOARD=myboard" .. # include the dot-dot path specifier

This will set up the system ready to build so you can simply
type 'make' in the myboard_build folder and the examples will
be built for your new board configuration.
_EOF

#END.
