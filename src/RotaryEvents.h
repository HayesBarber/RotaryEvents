#pragma once

#include <Arduino.h>

class RotaryEvents {
public:
  static RotaryEvents &getInstance();
  void init(uint8_t encoderClk, uint8_t encoderDt, void (*onRotateLeft)(),
            void (*onRotateRight)());

private:
  RotaryEvents();
  RotaryEvents(const RotaryEvents &) = delete;
  RotaryEvents &operator=(const RotaryEvents &) = delete;
  static void encoderInterrupt();
  void handleEncoder();

  void (*_onRotateLeft)();
  void (*_onRotateRight)();

  uint8_t _encoderClk;
  uint8_t _encoderDt;
  int _state;
  int _oldState;
  int _stepCounter;
};
