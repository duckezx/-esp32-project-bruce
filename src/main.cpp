#include <Arduino.h>
#include "config/pins_config.h"
#include "hardware/display.h"
#include "hardware/buttons.h"

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("\n\n=== Bruce ESP32-WROOM SSD1306 Iniciando ===");
    
    // Initialize display
    initDisplay();
    
    // Initialize buttons
    initButtons();
    
    Serial.println("✓ Inicialização completa!");
}

void loop() {
    // Handle button input
    int buttonPressed = getButtonPressed();
    
    if (buttonPressed > 0) {
        Serial.printf("Botão pressionado: %d\n", buttonPressed);
        handleButtonInput(buttonPressed);
    }
    
    delay(10);
}
