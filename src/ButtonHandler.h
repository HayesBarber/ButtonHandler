#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

/**
 * Represents a debounced digital button.
 */
class Button {
public:
    /**
     * Constructs a new Button instance.
     */
    Button();

    /**
     * Initializes the button on a specified GPIO pin.
     * 
     * The pin will be configured as INPUT_PULLUP.
     * 
     * @param pin GPIO pin number.
     * @param callback Function to call when the button is pressed (goes LOW).
     */
    void init(int pin, void (*callback)(int));

    /**
     * Should be called regularly in the loop() to update button state.
     * Triggers callback if the button press is valid and debounced.
     */
    void update();

private:
    int _pin;
    int _buttonState;
    int _lastButtonState;
    unsigned long _lastDebounceTime;
    unsigned long _debounceDelay;
    void (*_callback)(int);
};

#endif
