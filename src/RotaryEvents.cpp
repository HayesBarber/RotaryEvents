#include "RotaryEvents.h"

RotaryEvents::RotaryEvents() : _onRotateLeft(nullptr), _onRotateRight(nullptr) {}

RotaryEvents& RotaryEvents::getInstance() {
  static RotaryEvents instance;
  return instance;
}

void RotaryEvents::init(void (*onRotateLeft)(), void (*onRotateRight)()) {
  _onRotateLeft = onRotateLeft;
  _onRotateRight = onRotateRight;
}
