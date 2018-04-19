RotaryEncoderDir
================

A Library for the Arduino environment for using a rotary encoder as an input.
This one is based onto https://github.com/mathertel/RotaryEncoder, but has 
removed all internal position counting. Only a direction is reported via the
method hasChanged(): 0 -> not moved, 1 -> moved CW, -1 -> moved CCW.

