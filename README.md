# Bruce ESP32 OLED SSD1306 - Projeto de Setup Oficial

## Descrição
Configuração completa do firmware Bruce para ESP32 com display OLED SSD1306 (128x64).

## Hardware Necessário
- **ESP32-WROOM** ou **ESP32-DevKit**
- **Display OLED SSD1306** 128x64 (I2C)
- **Cabo USB** para programação
- (Opcional) Módulos IR, RF, etc.

## Pinagem Padrão

### Display OLED SSD1306 (I2C)
```
SSD1306 → ESP32
VCC     → 3.3V
GND     → GND
SDA     → GPIO 21
SCL     → GPIO 22
```

### Botão
```
Button Boot → GPIO 0 (Built-in)
```

### IR (Infrared)
```
IR TX → GPIO 12
IR RX → GPIO 14
```

### RF (Radio Frequency) - Opcional
```
RF TX → GPIO 5
RF RX → GPIO 4
```

### SPI - Módulos de RF/SD
```
SCK  → GPIO 18
MOSI → GPIO 23
MISO → GPIO 19
SS   → GPIO 5
```

## Requisitos de Software

### Instalação
1. Clone o repositório oficial do Bruce
2. Ou use este projeto como base

### Dependências PlatformIO
```
- espressif32 (55.03.36)
- Arduino Framework
- LovyanGFX (Display driver)
- All Bruce dependencies from BruceDevices/firmware
```

### Bibliotecas Principais
```
- LovyanGFX @ ^1.2.7 (Display)
- IRremoteESP8266 (Infrared)
- RadioLib @ ^7.4.0 (RF modules)
- FastLED @^3.10.3 (LED control)
- NimBLE-Arduino@2.5 (Bluetooth)
- SimpleCLI (Command interface)
```

## Build & Flash

### Compilar
```bash
pio run -e esp32-oled-ssd1306
```

### Fazer Upload
```bash
pio run -e esp32-oled-ssd1306 -t upload
```

### Monitor Serial
```bash
pio device monitor -e esp32-oled-ssd1306
```

## Configuração para Compilação

O arquivo `platformio.ini` está configurado com:

1. **Environment**: `esp32-oled-ssd1306`
2. **Board**: `esp32dev`
3. **Partição**: `default_16MB.csv`
4. **Display**: SSD1306 via I2C com LovyanGFX
5. **Flags**: Otimizadas para Bruce firmware

## Personalizações

### Mudar Pinagem do Display
Edite `platformio.ini` e altere:
```ini
-D TFT_SDA=21      ; SDA pin
-D TFT_SCL=22      ; SCL pin
-D TFT_ADDR=0x3C   ; I2C address (0x3C ou 0x3D)
```

### Mudar Velocidade I2C
```ini
-D TFT_I2C_WRITE=400000    ; 400 kHz
```

### Ativar/Desativar Recursos
```ini
-D LITE_VERSION=1          ; Versão leve (menos recursos)
```

## Solução de Problemas

### Display não aparece
- Verifique a pinagem SDA (GPIO 21) e SCL (GPIO 22)
- Confirme o endereço I2C: 0x3C ou 0x3D
- Teste a velocidade I2C em 100000 Hz

### Erro de compilação
- Limpe a cache: `pio run -e esp32-oled-ssd1306 -t clean`
- Atualize as libs: `pio lib update`

### Problema de flash insuficiente
- Use versão LITE: `-DLITE_VERSION=1`
- Remova recursos não utilizados

## Links Úteis

- **Bruce Oficial**: https://github.com/BruceDevices/firmware
- **LovyanGFX**: https://github.com/lovyan03/LovyanGFX
- **PlatformIO**: https://platformio.org
- **ESP32 Docs**: https://docs.espressif.com/

## Status

✅ PlatformIO configurado  
✅ Display OLED SSD1306 suportado  
✅ Bruce firmware integrável  
✅ Pinagem otimizada  
⏳ Em desenvolvimento

## Licença

AGPL-3.0 (conforme Bruce Devices)

---

**Desenvolvido por**: @duckezx  
**Data**: 2026-06-04  
**Versão**: 1.0-setup
