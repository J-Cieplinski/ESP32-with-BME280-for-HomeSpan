#include "HomeSpan.h"

class OnBoardLed : Service::LightBulb  {
    public:
    OnBoardLed(int ledPin) : Service::LightBulb(), ledPin_(ledPin),
        power_(new Characteristic::On())
    {
        pinMode(ledPin_, OUTPUT);
    };

    bool update() {
        digitalWrite(ledPin_, power_->getNewVal());

        return true;
    }

    private:
    int ledPin_;
    SpanCharacteristic* power_;
};