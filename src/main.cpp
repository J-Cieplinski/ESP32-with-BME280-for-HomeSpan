#include <Arduino.h>

void setup() {
    Serial.begin(9600);
    pinMode(2, OUTPUT);
}

void loop() {
    Serial.println("Hello World");
    delay(1000);
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
}