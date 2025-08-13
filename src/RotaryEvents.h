#pragma once

#include <Arduino.h>

class RotaryEvents {
public:
  RotaryEvents();
  void init(void (*onRotateLeft)(), void (*onRotateRight)());

private:
  static RotaryEvents *instance;

  void (*onRotateLeft)();
  void (*onRotateRight)();
};
