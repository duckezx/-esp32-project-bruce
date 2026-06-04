# Guia de Compilação - Bruce ESP32 OLED SSD1306

## 📋 Pré-requisitos

### 1. Instalar PlatformIO
```bash
# Via pip
pip install platformio

# Ou via VS Code
# Extension: PlatformIO IDE
```

### 2. Clonar Bruce Official
```bash
git clone https://github.com/BruceDevices/firmware.git
cd firmware
```

### 3. Copiar Configuração para ESP32 OLED
```bash
# Copie os arquivos deste projeto para o repo do Bruce
cp platformio.ini <bruce-firmware-path>/
cp pins_arduino.h <bruce-firmware-path>/boards/esp32-oled-ssd1306/
```

## 🔧 Compilação

### Build Padrão
```bash
pio run -e esp32-oled-ssd1306
```

### Build com Versão LITE (menos recursos)
```bash
pio run -e esp32-oled-ssd1306 --define LITE_VERSION=1
```

### Build Otimizado (menor tamanho)
```bash
pio run -e esp32-oled-ssd1306 -O
```

### Clean & Rebuild
```bash
pio run -e esp32-oled-ssd1306 -t clean
pio run -e esp32-oled-ssd1306
```

## 📤 Upload para ESP32

### Método 1: PlatformIO Upload
```bash
pio run -e esp32-oled-ssd1306 -t upload
```

### Método 2: Web Flasher
1. Acesse: https://web.esptool.io/
2. Clique em "Connect"
3. Selecione a porta COM do ESP32
4. Selecione o arquivo `.bin` gerado
5. Clique em "Program"

### Método 3: Manual com esptool.py
```bash
# Instalar esptool
pip install esptool

# Flash
esptool.py --port /dev/ttyUSB0 write_flash 0x1000 .pio/build/esp32-oled-ssd1306/firmware.bin
```

## 🔍 Monitor Serial

```bash
# Verificar saída do dispositivo
pio device monitor -e esp32-oled-ssd1306

# Velocidade: 115200 baud
```

## 🐛 Solução de Problemas

### Erro: "platform-espressif32" not found
```bash
pio platform install espressif32
pio lib update
```

### Erro: "flash size" problem
```bash
# Checar tamanho de flash
esptool.py --port /dev/ttyUSB0 flash_id

# Usar versão LITE se flash < 4MB
```

### Display não funciona
1. Verificar pinagem SDA=21, SCL=22
2. Confirmar endereço I2C: 0x3C ou 0x3D
3. Testar velocidade I2C reduzida em platformio.ini

### Memory error durante compilação
```bash
# Limpar cache
pio run -e esp32-oled-ssd1306 -t clean
rm -rf .pio
```

## 📊 Verificar Compilação

### Tamanho da imagem
```bash
# Após compilação bem-sucedida
ls -lh .pio/build/esp32-oled-ssd1306/firmware.bin
```

### Limite de tamanho
- **Flash 4MB**: máx ~3.8MB
- **Flash 8MB**: máx ~7.8MB
- **Flash 16MB**: máx ~15.8MB

## ✅ Verificação Final

1. **Compilou sem erros**: ✓
2. **Upload bem-sucedido**: ✓
3. **Display aparece**: ✓
4. **Menu Bruce funciona**: ✓

## 📚 Referências

- Bruce Oficial: https://github.com/BruceDevices/firmware
- PlatformIO Docs: https://docs.platformio.org/
- ESP32 Pinout: https://esp32.io/
- SSD1306 Library: https://github.com/lovyan03/LovyanGFX

---

**Desenvolvido por**: @duckezx  
**Última atualização**: 2026-06-04
