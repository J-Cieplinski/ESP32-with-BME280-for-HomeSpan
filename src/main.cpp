#include "HomeSpan.h"
#include "BME280TempSensor.hpp"
#include "BME280HumiditySensor.hpp"

void setup() {
    Serial.begin(115200);
    homeSpan.setLogLevel(1);
    homeSpan.enableOTA();
    homeSpan.begin(Category::Sensors, "ESP32");

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