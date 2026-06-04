; Configuração de pinos para ESP32 com Display OLED SSD1306
; Baseado no Bruce Devices Official Firmware
; Para: ESP32-WROOM / ESP32-DevKit

#ifndef PINS_ARDUINO_H
#define PINS_ARDUINO_H

// ============================================================================
// DISPLAY OLED SSD1306 CONFIGURATION
// ============================================================================

// I2C Communication (OLED Display)
#define I2C_SDA     21      // GPIO 21 - I2C Data Line
#define I2C_SCL     22      // GPIO 22 - I2C Clock Line
#define I2C_ADDR    0x3C    // SSD1306 I2C Address (0x3C or 0x3D)

// ============================================================================
// BUTTON CONFIGURATION
// ============================================================================

#define BTN_PIN     0       // GPIO 0 - Boot Button
#define BTN_ACT     LOW     // Active Low
#define BTN_ALIAS   "Boot"

// ============================================================================
// LED CONFIGURATION (Optional)
// ============================================================================

#define LED_PIN     -1      // Not used
#define LED_ON      HIGH

// ============================================================================
// IR (INFRARED) CONFIGURATION
// ============================================================================

#define IR_TX_PIN   12      // GPIO 12 - IR Transmitter
#define IR_RX_PIN   14      // GPIO 14 - IR Receiver
#define TXLED       12
#define RXLED       14

// ============================================================================
// RF (RADIO FREQUENCY) CONFIGURATION - Optional
// ============================================================================

#define RF_TX_PIN   5       // GPIO 5 - RF Transmitter
#define RF_RX_PIN   4       // GPIO 4 - RF Receiver

// ============================================================================
// SPI CONFIGURATION (for RF modules, SD card, etc)
// ============================================================================

#define SPI_SCK_PIN     18  // GPIO 18 - Serial Clock
#define SPI_MOSI_PIN    23  // GPIO 23 - Master Out Slave In
#define SPI_MISO_PIN    19  // GPIO 19 - Master In Slave Out
#define SPI_SS_PIN      5   // GPIO 5  - Slave Select

// ============================================================================
// POWER AND ANALOG CONFIGURATION
// ============================================================================

#define BAT_PIN     -1      // ADC pin for battery (if available)
#define POWER_PIN   -1      // Power control pin

// ============================================================================
// AUDIO CONFIGURATION (Optional)
// ============================================================================

#define SPEAKER_PIN -1      // Not used in basic setup
#define MIC_PIN     -1      // Not used in basic setup

// ============================================================================
// DISPLAY RESOLUTION
// ============================================================================

#define SCREEN_WIDTH    128
#define SCREEN_HEIGHT   64
#define ROTATION        0   // 0=Portrait, 1=90°, 2=180°, 3=270°

#endif // PINS_ARDUINO_H