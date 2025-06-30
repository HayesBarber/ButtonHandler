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

void Button::update() {
    if (_pin == -1) {
        Serial.println("ERROR: Button pin not initialized.");
        abort();
    }

    int reading = digitalRead(_pin);
    unsigned long currentTime = millis();

    if (reading != _lastButtonState) {
        _lastDebounceTime = currentTime;
    }

    bool hasDebounced = (currentTime - _lastDebounceTime) > _debounceDelay;

    if (hasDebounced && reading != _buttonState) {
        _buttonState = reading;

        if (_buttonState == LOW) {
            _callback(_pin);
        }
    }

    _lastButtonState = reading;
}
