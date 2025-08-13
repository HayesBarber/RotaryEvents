#include "RotaryEvents.h"

RotaryEvents::RotaryEvents() : onRotateLeft(nullptr), onRotateRight(nullptr) {}

void RotaryEvents::init(void (*onRotateLeft)(), void (*onRotateRight)()) {
  this->onRotateLeft = onRotateLeft;
  this->onRotateRight = onRotateRight;
}
