#ifndef BME280SENSOR_HPP
#define BME280SENSOR_HPP

#include "HomeSpan.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

class BME280Sensor {
    public:
    BME280Sensor(int pins, const std::string& chracteristicName, SpanCharacteristic* characteristic) : pins_(pins), characteristicValue_(-10.f), timer(0),
        fault_(new Characteristic::StatusFault(1)), chracteristicName_(chracteristicName), characteristic_(characteristic)
    {
        characteristic_->setRange(-50, 100);
        auto status = bme_.begin(pins_);
        pinMode(BUILTIN_LED, OUTPUT);
        digitalWrite(BUILTIN_LED, HIGH);


        if(!status) {
            LOG1("Could not find a valid BME280 sensor");
            while(1) {
                digitalWrite(BUILTIN_LED, HIGH);
                delay(500);
                digitalWrite(BUILTIN_LED, LOW);
            }
        } else {
            LOG1("Found a valid BME280 sensor");
            fault_->setVal(0);
            digitalWrite(BUILTIN_LED, LOW);
            characteristicValue_ = readValue();
            characteristic_->setVal(characteristicValue_);
        }
    };

    void loop() {
        if(millis() - timer > 5000) {
            timer = millis();

            characteristicValue_ = readValue();
            if(abs(characteristic_->getVal<double>() - characteristicValue_) > 0.5) {
                characteristic_->setVal(characteristicValue_);
                LOG1("\n");
                LOG1(chracteristicName_.c_str());
                LOG1(characteristicValue_);
            }
        }
    }

    protected:
    static constexpr int BUILTIN_LED {2};
    int pins_;
    double characteristicValue_;
    uint32_t timer;
    Adafruit_BME280 bme_;
    SpanCharacteristic* characteristic_;
    SpanCharacteristic* fault_;
    std::string chracteristicName_;

    virtual double readValue() {return 0;};
};

#endif // BME280SENSOR_HPP
