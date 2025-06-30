# ButtonHandler

A lightweight C++ library for debounced digital button input on Arduino-compatible boards like the ESP32.

## Overview

ButtonHandler simplifies detecting clean button presses by handling debounce logic internally. It assumes buttons are wired to pull the pin LOW when pressed and configures the pin using `INPUT_PULLUP`.

## Features

- Debounce handling using a simple time-based method
- Callback support for button press events
- Easy to integrate into the Arduino `loop()`

## Usage

```cpp
#include <Arduino.h>
#include <ButtonHandler.h>

Button button;

void onPress(int pin) {
    Serial.printf("Button pressed on pin %d\n", pin);
}

void setup() {
    Serial.begin(9600);
    button.init(13, onPress);
}

void loop() {
    button.update();
}
```

## Requirements

- Arduino framework
- A microcontroller that supports `INPUT_PULLUP` (e.g., ESP32)
