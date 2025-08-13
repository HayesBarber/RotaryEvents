#include "RotaryEvents.h"

RotaryEvents::RotaryEvents() : _onRotateLeft(nullptr), _onRotateRight(nullptr) {}

void RotaryEvents::init(void (*onRotateLeft)(), void (*onRotateRight)()) {
  _onRotateLeft = onRotateLeft;
  _onRotateRight = onRotateRight;
}
