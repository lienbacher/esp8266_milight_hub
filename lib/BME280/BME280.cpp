# include <BME280.h>

BME280::BME280(Settings& settings)
  : settings(settings)
{
    Serial.println("constructing BME obj3ct");

    if(settings.hasBME280) {
        this->sensor = new Adafruit_BME280();
        Wire.begin(settings.sdaPin, settings.sclPin); 
        

        bool status = this->sensor->begin(0x76);
        if (!status) {  
            Serial.println("Could not find a valid BME280 sensor, check wiring!");
        } else {
            Serial.println("BME-280 initialized");
        }

        delay(100); // let sensor boot up  
    } else {
        Serial.println("bme280 is disabled");
    }
}

BME280::~BME280() {
    delete this->sensor;
}

float BME280::readTemperature() {
    return this->sensor->readTemperature();
}

float BME280::readHumidity() {
    return this->sensor->readHumidity();
}

float BME280::readPressure() {
    return (this->sensor->readPressure() / 100.0F);
}

/*
// bme280
  unsigned long timeSince = millis() - lastBME;
  
  if(settings.hasBME280 && timeSince > 2000) {
    Serial.print("Temperature = ");  
    Serial.print(bme.readTemperature());  
    Serial.println(" *C");  
    
    Serial.print("Pressure = ");  
    Serial.print(bme.readPressure() / 100.0F);  
    Serial.println(" hPa");  
    
    Serial.print("Humidity = ");  
    Serial.print(bme.readHumidity());  
    Serial.println(" %");  

    lastBME = millis();
  }
  */