# RotaryEvents

RotaryEvents is a lightweight Arduino singleton library to handle rotary encoder events and trigger callbacks. It supports configurable step thresholds for sensitivity and ensures callbacks are called only when the encoder has rotated the specified number of steps.

## Usage Example

```cpp
#include <RotaryEvents.h>

void onLeft() {
  Serial.println("Rotated Left");
}

void onRight() {
  Serial.println("Rotated Right");
}

void setup() {
  Serial.begin(9600);

  // Initialize encoder on pins 2 (CLK) and 3 (DT)
  RotaryEvents::getInstance().init(2, 3, onLeft, onRight, 2);
}

void loop() {
  // Main loop can be empty, interrupts handle the encoder
}
```
