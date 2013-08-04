/*

 Example of AS_BH1750 library usage.
 
 This example initalises the BH1750 object using the default
 high resolution mode and then makes a light level reading every second.
 
 Connection:
 VCC-5v
 GND-GND
 SCL-SCL(analog pin 5)
 SDA-SDA(analog pin 4)
 ADD-NC or GND
 
 */

#include <Wire.h>
#include <AS_BH1750.h>

AS_BH1750 sensor;

void setup(){
  Serial.begin(9600);
  delay(50);
  if(sensor.begin()) {
    Serial.println("Sensor initialized");
  } 
  else {
    Serial.println("Sensor not present");
  }
  
  /*if(sensor.isPresent()) {
    Serial.println("Sensor present");
  } 
  else {
    Serial.println("Sensor not present");
  }*/
}

void loop() {
  float lux = sensor.readLightLevel();
  Serial.print("Light level: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);
}


