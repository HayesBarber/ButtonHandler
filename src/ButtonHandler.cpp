#include "ButtonHandler.h"

Button::Button()
    : _pin(-1),
      _buttonState(HIGH),
      _lastButtonState(HIGH), 
      _lastDebounceTime(0),
      _debounceDelay(50),
      _callback(nullptr) {}

void Button::init(int pin, void (*callback)(int)) {
    _pin = pin;
    _callback = callback;
    pinMode(_pin, INPUT_PULLUP);
    Serial.printf("Pin %d is now pulled up and ready for button presses\n", _pin);
}
