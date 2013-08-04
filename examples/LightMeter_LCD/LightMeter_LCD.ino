#include <Wire.h>
#include <AS_BH1750.h>
#include <LiquidCrystal.h>

/* 
 * Clock_LCD
 * 
 * Author: Alexander Schulz 
 * Version 1.2
 * Datum: 05.08.2013
 * 
 * Das Programm benutzt den RTC DS1307 und
 * zeigt die Zeit auf einem 16x2-Symbol-LCD.
 * 
 * Verdrahtung (UNO, Nano...)
 * 
 * BH1750:
 *     Sensor SCL pin an A5
 *     Sensor SDA pin an A4
 *     Sensor VDD pin an 5V
 *     Sensor GND pin an GND
 *     Sensor ADDR pin frei
 *  
 * LCD in 4-Bit-Modus:
 *     LCD RS pin an digital pin 8
 *     LCD RW pin an digital pin 13
 *     LCD Enable pin an digital pin 9
 *     LCD D4 pin an digital pin 4
 *     LCD D5 pin an digital pin 5
 *     LCD D6 pin an digital pin 6
 *     LCD D7 pin an digital pin 7
 */

AS_BH1750 lightMeter;

// Setup LCD-Shield
LiquidCrystal lcd(8, 13, 9, 4, 5, 6, 7);

void setup() {
  // Display initialisieren
  lcd.clear(); 
  lcd.begin(16, 2); // 16x2 Zeichen
  lcd.setCursor(0,0); 
  lcd.print("LightMeter v1.0"); 
  lcd.setCursor(0,1); 
  lcd.print("Initializing..."); 
  delay(1000);
  lcd.clear();

  if(!lightMeter.begin()){
    // Prüfen, ob Sensor vorhanden ist
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print("BH1750 not found");
    lcd.setCursor(0,1); 
    lcd.print("check wiring!");
    while (1) {
      delay(1000);
    }
  }

}

void loop() {
  // Textvariablen
  char clux[9];

  // Werte auslesen und aufbereiten
  float lux = lightMeter.readLightLevel();
  dtostrf(lux, 8, 1, clux);

  lcd.setCursor(0,0); 
  lcd.print("Light level: ");
  lcd.setCursor(5,1); 
  lcd.print(clux);
  lcd.print(" lx");

  delay(500);
}



