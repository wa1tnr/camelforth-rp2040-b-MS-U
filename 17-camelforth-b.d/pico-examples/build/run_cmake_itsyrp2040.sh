#!/bin/sh
# cd pico-examples/build # just to establish where this is

# cmake .. -D"PICO_BOARD=adafruit_itsybitsy_rp2040" -D"BOOT2_GENERIC_CF_LOCAL=1"
cmake .. -D"PICO_BOARD=adafruit_itsybitsy_rp2040"

exit 0 # do not continue.  Exits this script on all pathways through it.

# the 'exit 0' protects this code from being executed:

# standard build: RPi Pico 2040 target board:
cmake .. -D"PICO_BOARD=pico"

# Adafruit Feather RP2040, March 2021:
cmake .. -D"PICO_BOARD=adafruit_feather_rp2040" -D"BOOT2_GENERIC_CF_LOCAL=1"

# ls ../../pico-sdk/src/boards/include/boards/adafruit_feather_rp2040.h

# Raspberry Pi Pico RP2040 is just 'pico' here:
cmake -D"PICO_BOARD=pico" .. >> ./build.log 2>&1 ; date

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
