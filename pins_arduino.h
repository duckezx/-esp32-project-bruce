#ifndef PINS_ARDUINO_H_
#define PINS_ARDUINO_H_

#define DEVICE_NAME "ESP32-WROOM SSD1306"

// ============================================================================
// DISPLAY - SSD1306 I2C OLED (128x64)
// ============================================================================
#define HAS_SCREEN 1
#define USE_LOVYANGFX 1

#define LOVYAN_PANEL Panel_SSD1306
#define LOVYAN_BUS Bus_I2C
#define LOVYAN_I2C_BUS 1

#define TFT_I2C_PORT 0
#define TFT_I2C_WRITE 400000
#define TFT_I2C_READ 400000
#define TFT_SDA 21
#define TFT_SCL 22
#define TFT_ADDR 0x3C

#define TFT_WIDTH 128
#define TFT_HEIGHT 64
#define ROTATION 0

// ============================================================================
// BUTTONS - 5-Key Analog Keyboard Module on D34 (ADC1_6)
// ============================================================================
#define HAS_BTN 1
#define BTN_PIN D34  // ADC input for analog keyboard (GPIO 34)
#define BTN_ACT LOW // Active low for analog buttons
#define ANALOG_BTN_ENABLED 1

// Analog threshold values for 5-button keyboard (ADC 0-4095)
// Adjust these based on your specific keyboard module
#define BTN_DOWN_THRESHOLD 100      // Button 1 - DOWN (0-200mV ~ 0-200)
#define BTN_SELECT_THRESHOLD 650    // Button 2 - SELECT (600-700mV ~ 600-700)
#define BTN_UP_THRESHOLD 1300       // Button 3 - UP (1200-1400mV ~ 1200-1400)
#define BTN_BACK_THRESHOLD 1950     // Button 4 - BACK (1900-2000mV ~ 1900-2000)
#define BTN_OK_THRESHOLD 2550       // Button 5 - OK/ENTER (2500-2600mV ~ 2500-2600)

// ADC Hysteresis (deadzone to avoid bouncing)
#define BTN_HYSTERESIS 100

// ============================================================================
// GROVE I2C PINS
// ============================================================================
#define GROVE_SDA 21
#define GROVE_SCL 22

// ============================================================================
// LED and BUZZER
// ============================================================================
#define LED -1
#define BUZZ_PIN -1

// ============================================================================
// IR MODULE (optional)
// ============================================================================
#define IR_TX_PINS '{{"GPIO14",14},{"GPIO15",15},{"GPIO16",16},{"GPIO17",17},{"GPIO18",18},{"GPIO19",19}}'
#define IR_RX_PINS '{{"GPIO35",35},{"GPIO36",36},{"GPIO39",39},{"GPIO4",4},{"GPIO14",14},{"GPIO15",15}}'
#define TXLED -1
#define RXLED -1

// ============================================================================
// RF MODULE (optional)
// ============================================================================
#define RF_TX_PINS '{{"GPIO14",14},{"GPIO15",15},{"GPIO16",16},{"GPIO17",17},{"GPIO18",18},{"GPIO19",19}}'
#define RF_RX_PINS '{{"GPIO35",35},{"GPIO36",36},{"GPIO39",39},{"GPIO4",4},{"GPIO14",14},{"GPIO15",15}}'

// ============================================================================
// CC1101 SPI (optional)
// ============================================================================
#define CC1101_GDO0_PIN 2
#define CC1101_SS_PIN 5
#define CC1101_MOSI_PIN 23
#define CC1101_SCK_PIN 18
#define CC1101_MISO_PIN 19

// ============================================================================
// NRF24 SPI (optional)
// ============================================================================
#define NRF24_CE_PIN 4
#define NRF24_SS_PIN 5
#define NRF24_MOSI_PIN 23
#define NRF24_SCK_PIN 18
#define NRF24_MISO_PIN 19

// ============================================================================
// STANDARD SPI
// ============================================================================
#define SPI_SCK_PIN 18
#define SPI_MOSI_PIN 23
#define SPI_MISO_PIN 19
#define SPI_SS_PIN 5

// ============================================================================
// SERIAL/UART
// ============================================================================
#define SERIAL_TX 1
#define SERIAL_RX 3
#define GPS_SERIAL_TX SERIAL_TX
#define GPS_SERIAL_RX SERIAL_RX

// ============================================================================
// SD CARD (optional)
// ============================================================================
#define SDCARD_CS 5
#define SDCARD_SCK SPI_SCK_PIN
#define SDCARD_MISO SPI_MISO_PIN
#define SDCARD_MOSI SPI_MOSI_PIN

#endif // PINS_ARDUINO_H_
