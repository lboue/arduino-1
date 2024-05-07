/*
 * This file is part of the Silicon Labs Arduino Core
 *
 * The MIT License (MIT)
 *
 * Copyright 2024 Silicon Laboratories Inc. www.silabs.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "Arduino.h"
#include "pinDefinitions.h"

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration)
{
  PinName pin_name = pinToPinName(_pin);
  if (pin_name == PIN_NAME_NC) {
    return;
  }
  Serial.println("qui tutto ok");
  tone(pin_name, frequency, duration);
}

void tone(PinName pin, unsigned int frequency, unsigned long duration)
{
  PWM.frequency_mode(pin, frequency);
  if (duration == 0) {
    return;
  }
  uint32_t tone_end_time = millis() + duration;
  while (millis() < tone_end_time) {
    yield();
  }
  noTone(pin);
}

void noTone(uint8_t _pin)
{
  PinName pin_name = pinToPinName(_pin);
  if (pin_name == PIN_NAME_NC) {
    return;
  }
  noTone(pin_name);
}

void noTone(PinName pin)
{
  PWM.frequency_mode(pin, 0);
}
