#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

constexpr uint8_t LED_RED = 4;
constexpr uint8_t LED_BLUE = 5;
constexpr uint8_t SWITCHER = 6;
constexpr uint8_t LED_PIN = 48; // Default pin for buildin LED
constexpr uint8_t LED_COUNT = 1;
constexpr uint32_t delayList[] = {100, 500, 1000, 10000};
constexpr uint8_t cycleTime = 3;



Adafruit_NeoPixel pixel(
    LED_COUNT,
    LED_PIN,
    NEO_GRB + NEO_KHZ800
);

void setup() {
    pixel.begin();
    pixel.setBrightness(100);
    pixel.clear();
    pixel.show();
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    pinMode(SWITCHER, OUTPUT);
    Serial.begin(115200);
    Serial.println("Enter number from 1 to 6 to choose mode: ");
}

void blinkBuildInLed() {
    uint32_t delayTime = random(1000, 5000);
    Serial.printf("Using 1 RGB LED with delay %u ms \n", delayTime);
    uint8_t cycle = 0;
    while (cycle < cycleTime)
    {
        pixel.setPixelColor(0, pixel.Color(255, 0, 0));
        pixel.show();
        delay(delayTime);
        pixel.setPixelColor(0, pixel.Color(0, 0, 255));
        pixel.show();
        delay(delayTime);
        pixel.clear();
        pixel.show();
        cycle++;
    }    
}

void blinkLedByOneGPIO() {
    uint32_t delayTime = random(1000, 5000);
    Serial.printf("Using 2 Led(Blue, Red) and GPIO/3.3 with delay %u ms \n", delayTime);
    uint8_t cycle = 0;
    while (cycle < cycleTime)
    {
        digitalWrite(SWITCHER, LOW);
        delay(delayTime);
        digitalWrite(SWITCHER, HIGH);
        delay(delayTime);
        cycle++;
    }
}

void blinkLedOnBreadBoard(uint32_t delayTime) {
    Serial.printf("Using 2 Led(Blue, Red) with delay %u ms \n", delayTime);
    uint8_t cycle = 0;
    while (cycle < cycleTime)
    {
        digitalWrite(LED_RED, HIGH);
        digitalWrite(LED_BLUE, LOW);
        delay(delayTime);
        digitalWrite(LED_RED, LOW);
        digitalWrite(LED_BLUE, HIGH);
        delay(delayTime);
        digitalWrite(LED_BLUE, LOW);
        cycle++;
    }
}

void loop() {
    if (Serial.available() > 0) {
        int choice = Serial.parseInt();
        if (choice >= 1 && choice <= 4) {
            uint32_t delaySec = delayList[choice - 1];
            blinkLedOnBreadBoard(delaySec);
        } 
        else if (choice == 5)
        {
            blinkBuildInLed();
        }
        else if (choice == 6)
        {
            blinkLedByOneGPIO();
        }
    }
}

