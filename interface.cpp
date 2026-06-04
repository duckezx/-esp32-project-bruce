#include "pins_arduino.h"
#include <Arduino.h>

// ESP32-WROOM Board Initialization
// Support for 5-Key Analog Keyboard Module on D34 (GPIO 34)

static uint16_t lastButtonValue = 0;
static uint32_t lastButtonTime = 0;
static const uint32_t BTN_DEBOUNCE_MS = 50;

void boardInit() {
    // Configure ADC for analog keyboard
    #ifdef ANALOG_BTN_ENABLED
    analogSetAttenuation(ADC_11db);  // 0-3.3V range
    analogSetWidth(12);              // 12-bit resolution (0-4095)
    #endif
    
    // I2C is initialized by LovyanGFX library
}

// Read analog keyboard value with debouncing
uint16_t readAnalogButton() {
    #ifdef ANALOG_BTN_ENABLED
    uint32_t now = millis();
    
    // Debounce: only read every 50ms
    if (now - lastButtonTime < BTN_DEBOUNCE_MS) {
        return lastButtonValue;
    }
    
    // Read analog value from D34 (GPIO 34 / ADC1_6)
    uint16_t rawValue = analogRead(D34);
    lastButtonValue = rawValue;
    lastButtonTime = now;
    
    return rawValue;
    #else
    return 0;
    #endif
}

// Determine which button was pressed based on analog value
int getButtonPressed() {
    #ifdef ANALOG_BTN_ENABLED
    uint16_t adcValue = readAnalogButton();
    
    // Button detection with hysteresis
    if (adcValue < BTN_DOWN_THRESHOLD + BTN_HYSTERESIS) {
        return 1;  // DOWN button
    }
    else if (adcValue < BTN_SELECT_THRESHOLD + BTN_HYSTERESIS) {
        return 2;  // SELECT button
    }
    else if (adcValue < BTN_UP_THRESHOLD + BTN_HYSTERESIS) {
        return 3;  // UP button
    }
    else if (adcValue < BTN_BACK_THRESHOLD + BTN_HYSTERESIS) {
        return 4;  // BACK button
    }
    else if (adcValue < BTN_OK_THRESHOLD + BTN_HYSTERESIS) {
        return 5;  // OK/ENTER button
    }
    #endif
    
    return 0;  // No button pressed
}
