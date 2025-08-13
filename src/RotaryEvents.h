#pragma once

#include <Arduino.h>

class RotaryEvents {
public:
  RotaryEvents();
  void init(void (*onRotateLeft)(), void (*onRotateRight)());

private:
  void (*onRotateLeft)();
  void (*onRotateRight)();
};
