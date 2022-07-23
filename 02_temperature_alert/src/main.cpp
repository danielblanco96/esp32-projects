#include "Arduino.h"
#include <Wire.h>
#include "Adafruit_MCP9808.h"

const int ALERT_LED_PIN = 23;
const double ALERT_TEMP = 31;

Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

double getTemperature() {
  tempsensor.wake();

  float temp = tempsensor.readTempC();
  tempsensor.shutdown_wake(1);

  return temp;
}

void updateAlert(double temp) {
  if(temp > ALERT_TEMP) {
    digitalWrite(ALERT_LED_PIN, HIGH);
  } else {
    digitalWrite(ALERT_LED_PIN, LOW);
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial); //waits for serial terminal to be open, necessary in newer arduino boards.
  Serial.println("Temperature alert example setup!");
  
  pinMode(ALERT_LED_PIN, OUTPUT);
  if (!tempsensor.begin(0x18)) {
    Serial.println("Couldn't find MCP9808! Check your connections and verify the address is correct.");
    while (1);
  }
    
  Serial.println("Found MCP9808!");

  tempsensor.setResolution(1);
}

void loop() {
  double temp = getTemperature();
  Serial.print("Temp: "); 
  Serial.print(temp, 4); Serial.println("*C"); 
  updateAlert(temp);
  delay(1000);
}