// -----
// RotaryEncoderDir.cpp - Library for using rotary encoders.
// This class is implemented for use with the Arduino environment.
// Copyright (c) by Matthias Hertel, http://www.mathertel.de
// This work is licensed under a BSD style license. See http://www.mathertel.de/License.aspx
// More information on: http://www.mathertel.de/Arduino
// Code removed for internal counting postition. Now only the direction is
// reported back.
// -----
// 18.01.2014 created by Matthias Hertel
// 17.06.2015 minor updates.
// 19.04.2018 direction code added by Holger Wirtz
// -----

#include "Arduino.h"
#include "RotaryEncoderDir.h"

// The array holds the values for the entries where a position was decremented,
// a 1 for the entries where the position was incremented
// and 0 in all the other (no change or not valid) cases.

const int8_t KNOBDIR[] = {
  0, -1,  1,  0,
  1,  0,  0, -1,
  -1,  0,  0,  1,
0,  1, -1,  0  };


// positions: [3] 1 0 2 [3] 1 0 2 [3]
// [3] is the positions where my rotary switch detends
// ==> right, count up
// <== left,  count down

// ----- Initialization and Default Values -----

RotaryEncoderDir::RotaryEncoderDir(int pin1, int pin2) {
  
  // Remember Hardware Setup
  _pin1 = pin1;
  _pin2 = pin2;
  
  // Setup the input pins
  pinMode(pin1, INPUT);
  digitalWrite(pin1, HIGH);   // turn on pullup resistor

  pinMode(pin2, INPUT);
  digitalWrite(pin2, HIGH);   // turn on pullup resistor

  // when not started in motion, the current state of the encoder should be 3
  _oldState = 3;

  // 0 means: no change detected;
  _hasChanged=0;

} // RotaryEncoderDir()

uint8_t RotaryEncoderDir::hasChanged(void) {
  int8_t temp=_hasChanged;

  _hasChanged=0;
  return(temp);
} // hasChanged()


void RotaryEncoderDir::tick(void)
{
  int sig1 = digitalRead(_pin1);
  int sig2 = digitalRead(_pin2);
  int8_t thisState = sig1 | (sig2 << 1);

  if (_oldState != thisState) {
    int8_t dir=KNOBDIR[thisState | (_oldState<<2)];
    if (thisState == LATCHSTATE)
    {
      if(dir>0)
	_hasChanged=1;
      else
	_hasChanged=-1;
    }
    
    _oldState = thisState;
  }
} // tick()

// End
