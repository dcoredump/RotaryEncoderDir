// -----
// RotaryEncoderDir.h - Library for using rotary encoders.
// This class is implemented for use with the Arduino environment.
// Copyright (c) by Matthias Hertel, http://www.mathertel.de
// This work is licensed under a BSD style license. See http://www.mathertel.de/License.aspx
// More information on: http://www.mathertel.de/Arduino
// -----
// 18.01.2014 created by Matthias Hertel
// 19.04.2018 direction code added by Holger Wirtz
// -----

#ifndef RotaryEncoderDir_h
#define RotaryEncoderDir_h

#include "Arduino.h"

#define LATCHSTATE 3

class RotaryEncoderDir
{
public:
  // ----- Constructor -----
  RotaryEncoderDir(int pin1, int pin2);
  
  // retrieve the current position
  long  getPosition();

  // adjust the current position
  void setPosition(long newPosition);

  // check if a change occured
  uint8_t hasChanged(void);

  // call this function every some milliseconds or by using an interrupt for handling state changes of the rotary encoder.
  void tick(void);

private:
  int _pin1, _pin2; // Arduino pins used for the encoder. 
  
  int8_t _oldState;
  
  long _position;     // Internal position (4 times _positionExt)
  long _positionExt;  // External position

  uint8_t _hasChanged;
};

#endif

// End
