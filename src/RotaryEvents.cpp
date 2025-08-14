#include "RotaryEvents.h"

RotaryEvents::RotaryEvents()
  : _onRotateLeft(nullptr), _onRotateRight(nullptr),
    _encoderClk(0), _encoderDt(0), _state(0), _oldState(0), _stepCounter(0) {}

RotaryEvents& RotaryEvents::getInstance() {
  static RotaryEvents instance;
  return instance;
}

void RotaryEvents::init(uint8_t encoderClk, uint8_t encoderDt, void (*onRotateLeft)(), void (*onRotateRight)()) {
  _encoderClk = encoderClk;
  _encoderDt = encoderDt;
  _onRotateLeft = onRotateLeft;
  _onRotateRight = onRotateRight;
}
