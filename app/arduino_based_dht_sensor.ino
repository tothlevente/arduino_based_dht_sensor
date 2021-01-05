/*
          
    Arduino DHT sensor
    Created by: Tóth Levente | 2021 |
          
    For more information please read the project documentations.
    https://github.com/tothlevente/arduino-dht-sensor
          
*/

#include <dhtnew.h>

DHTNEW dhtSensor(6);

const int greenLedPin = 8;
const int blueLedPin = 9;

int dhtSensorHumidity;
int dhtSensorTemperature;

//--------------------------
int dhtReadingPeriod = 2000;
int dhtHumOffset = 10;
int dhtTempOffset = -1.5;
//--------------------------

void setup()
{

  Serial.begin(9600);

  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);

  dhtSensor.setHumOffset(dhtHumOffset);
  dhtSensor.setTempOffset(dhtTempOffset);
}

void loop()
{
  digitalWrite(greenLedPin, HIGH);

  if (millis() - dhtSensor.lastRead() > dhtReadingPeriod)
  {
    read_sensor_data();
  }
}

void read_sensor_data()
{
  digitalWrite(blueLedPin, HIGH);
  
  dhtSensor.read();
  dhtSensorHumidity = dhtSensor.humidity;
  dhtSensorTemperature = dhtSensor.temperature;

  Serial.print("Humidity: ");
  Serial.println(dhtSensorHumidity, 1);

  Serial.print("Temperature: ");
  Serial.println(dhtSensorTemperature, 1);
  
  digitalWrite(blueLedPin, LOW);
}
