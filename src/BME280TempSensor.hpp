#include "HomeSpan.h"
#include "BME280Sensor.hpp"

class BME280TempSensor :  Service::TemperatureSensor, BME280Sensor {
    public:
    BME280TempSensor(int pins) : Service::TemperatureSensor(), BME280Sensor(pins, "Temp: ", new Characteristic::CurrentTemperature(-10.f))
    {
    };

    void loop() {
        BME280Sensor::loop();
    }

    private:
    double readValue() override {
        return bme_.readTemperature();
    };
};