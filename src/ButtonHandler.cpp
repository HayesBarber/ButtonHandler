#include "ButtonHandler.h"

Button::Button()
    : _pin(-1),
      _buttonState(HIGH),
      _lastButtonState(HIGH), 
      _lastDebounceTime(0),
      _debounceDelay(50),
      _callback(nullptr) {}
