//
// Created by LSC on 07.11.2024.
//

#include "Arduino.h"
#include <SPI.h>
#include <TFT_eSPI.h>

void setup() {
    Serial.begin(115200);
    Serial.println("Testing display_backlight");

    pinMode(TFT_BL, OUTPUT);
}

void loop() {
    Serial.print("TFF_CS_PIN number is: ");
    Serial.println(TFT_BL);

    digitalWrite(TFT_BL, HIGH);
    Serial.println("TFT_BL HIGH");
    delay(2000);

    digitalWrite(TFT_BL, LOW);
    Serial.println("TFT_CS LOW");
    delay(2000);
}
