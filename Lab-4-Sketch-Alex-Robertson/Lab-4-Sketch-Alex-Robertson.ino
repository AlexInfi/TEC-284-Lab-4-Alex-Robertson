#include <U8x8lib.h>

#include <DHT.h>
#include <Grove_Temperature_And_Humidity_Sensor.h>

U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

void setup() {
u8x8.begin();
u8x8.setFlipMode(1);
u8x8.clear();
}

void loop() {
u8x8.setFont(u8x8_font_chroma48medium8_r);
u8x8.setCursor(0, 0);
u8x8.print("Hello World!");
}
