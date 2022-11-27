#include "HomeSpan.h"
#include "BME280Sensor.hpp"

class BME280HumiditySensor :  Service::HumiditySensor, BME280Sensor {
    public:
    BME280HumiditySensor(int pins) : Service::HumiditySensor(), BME280Sensor(pins, "Humidity: ", new Characteristic::CurrentRelativeHumidity(0))
    {
    };

    void loop() {
        BME280Sensor::loop();
    }

    private:
    double readValue() override {
        return bme_.readHumidity();
    };
};