
#include <Wire.h>
#include <Settings.h>
#include <PubSubClient.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#ifndef _BME280_H
#define _BME280_H

#define SEALEVELPRESSURE_HPA (1015)

class BME280 {
public:
    BME280(Settings& settings);
    ~BME280();

    float readTemperature();
    float readHumidity();
    float readPressure();

private:
    Adafruit_BME280 *sensor; // I2C 

    Settings& settings;
    PubSubClient* mqttClient;
    
  
};

#endif