#pragma once

#include <Arduino.h>

/**
 * @class RotaryEvents
 * @brief Singleton class to handle rotary encoder events and trigger callbacks.
 *
 * Provides a way to register a rotary encoder and receive
 * callbacks when the encoder is rotated left or right. The class supports
 * a configurable step threshold to control sensitivity.
 */
class RotaryEvents {
public:
  /**
   * @brief Get the singleton instance of RotaryEvents.
   * @return Reference to the RotaryEvents singleton.
   */
  static RotaryEvents &getInstance();

  /**
   * @brief Initialize the rotary encoder pins and callbacks.
   * @param encoderClk The GPIO pin number connected to the encoder CLK.
   * @param encoderDt The GPIO pin number connected to the encoder DT.
   * @param onRotateLeft Callback function to invoke on counter-clockwise
   * rotation.
   * @param onRotateRight Callback function to invoke on clockwise rotation.
   * @param stepThreshold Number of steps before a callback is triggered.
   *
   * This method must be called once before using the encoder. It also
   * sets up the interrupt on the CLK pin to detect rotations.
   */
  void init(uint8_t encoderClk, uint8_t encoderDt, void (*onRotateLeft)(),
            void (*onRotateRight)(), int stepThreshold);

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
  int _stepThreshold;
};
