#pragma once

#include <Arduino.h>

class RotaryEvents {
public:
  static RotaryEvents& getInstance();
  void init(void (*onRotateLeft)(), void (*onRotateRight)());

private:
  RotaryEvents();
  RotaryEvents(const RotaryEvents&) = delete;
  RotaryEvents& operator=(const RotaryEvents&) = delete;

  void (*_onRotateLeft)();
  void (*_onRotateRight)();
};
