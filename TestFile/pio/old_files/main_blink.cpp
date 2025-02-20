#include <Arduino.h>
#define CYD_LED_BLUE 17
#define CYD_LED_RED 4
#define CYD_LED_GREEN 16

void setup()
{
    Serial.begin(115200);

    pinMode(CYD_LED_RED, OUTPUT);
    pinMode(CYD_LED_GREEN, OUTPUT);
    pinMode(CYD_LED_BLUE, OUTPUT);
}

void loop()
{
    //Turn LED Off
    digitalWrite(CYD_LED_RED, HIGH); // The LEDs are "active low", meaning HIGH == off, LOW == on
    digitalWrite(CYD_LED_GREEN, HIGH);
    digitalWrite(CYD_LED_BLUE, HIGH);

    delay(1000);

    // Red LED
    digitalWrite(CYD_LED_RED, LOW);
    digitalWrite(CYD_LED_GREEN, HIGH);
    digitalWrite(CYD_LED_BLUE, HIGH);

    delay(1000);

    // Green LED
    digitalWrite(CYD_LED_RED, HIGH);
    digitalWrite(CYD_LED_GREEN, LOW);
    digitalWrite(CYD_LED_BLUE, HIGH);

    delay(1000);

    // Blue LED
    digitalWrite(CYD_LED_RED, HIGH);
    digitalWrite(CYD_LED_GREEN, HIGH);
    digitalWrite(CYD_LED_BLUE, LOW);

    delay(1000);
}
