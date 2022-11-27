#include "HomeSpan.h"
#include "BME280TempSensor.hpp"
#include "BME280HumiditySensor.hpp"

void setup() {
    Serial.begin(115200);
    homeSpan.setLogLevel(1);
    Serial.begin(9600);
    pinMode(2, OUTPUT);

    new SpanAccessory();
        new Service::AccessoryInformation();
            new Characteristic::Identify();
            new Characteristic::Name("Temp sensors");
        new BME280TempSensor(0x76);

    new SpanAccessory();
        new Service::AccessoryInformation();
            new Characteristic::Identify();
            new Characteristic::Name("Humidity sensors");
        new BME280HumiditySensor(0x76);
}

void loop() {
    homeSpan.poll();
}