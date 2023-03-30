#!/bin/sh

export PICO_SDK_PATH=../../pico-sdk

# change this line to point to the dev toolchain:
export SOME_BIN_DIR=$HOME/this/dir/bin

# example (assembler binary in the dev toolchain):
# '$HOME/this/dir/bin/arm-none-eabi-as'

cmake .. -D"PICO_BOARD=pico" -D"PICO_TOOLCHAIN_PATH=$SOME_BIN_DIR"

exit 0

# this script was added 30 March 2023 and is temporary.

# It's an edit of a more stable script that's been in this
# repository for a while.

#END.
