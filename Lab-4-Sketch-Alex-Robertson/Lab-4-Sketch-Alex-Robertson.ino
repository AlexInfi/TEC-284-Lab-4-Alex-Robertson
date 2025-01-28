#include <U8x8lib.h>

#include <DHT.h>
#include <Grove_Temperature_And_Humidity_Sensor.h>

U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

// Tells the Arduino that there is a DHT-11 sensor at pin 3
DHT dht(3, DHT11);

void setup() {
  dht.begin();
  u8x8.begin();
  u8x8.setFlipMode(1);
  u8x8.clear();

  // Sets LED pin for alarm
  pinMode(4, OUTPUT);
}

void loop() {
  // Sets a tempValue variable equal to the values from the Arduino temp reader
  float tempValue = dht.readTemperature();
  // Sets a humidityValue variable equal to the values from the Arduino humidity reader
  float humidityValue = dht.readHumidity();
  u8x8.setFont(u8x8_font_chroma48medium8_r);

  // Sets cursor to top right and prints the temperature value to the screen
  u8x8.setCursor(0, 0);
  u8x8.print("Temp: ");
  u8x8.print(tempValue * 2 + 30);   // Converts the Celsius value to Farenheit

  // Resets cursor to be below previous line, then prints humidity value to the screen
  u8x8.setCursor(0, 10);
  u8x8.print("Humidity: ");
  u8x8.print(humidityValue);
  u8x8.print("%");

  while (humidityValue >= 70.00) {
    // Sets the LED to be on and the tone to sound
    digitalWrite(4, HIGH);
    tone(5, 1000);
    // Waits one second
    delay(1000);

    // Sets the LED off and turns off the tone
    digitalWrite(4, LOW);
    noTone(5);
    // Waits another second
    delay(1000);
  }
}
