#include <Arduino.h>

constexpr uint8_t LED_RED = 4;
constexpr uint8_t LED_BLUE = 5;
constexpr uint8_t BUTTON = 7;

void setup() {
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_BLUE, LOW);
    delay(1000);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, HIGH);
    delay(1000);



    // if (digitalRead(BUTTON) == HIGH)
    // {
    //     digitalWrite(LED_BLUE, HIGH);
    // } else {
    //     digitalWrite(LED_BLUE, LOW);
    // }
    
}