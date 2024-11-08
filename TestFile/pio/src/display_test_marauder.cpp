//
// Created by LSC on 08.11.2024.
//

#include "Arduino.h"
/* Define the pins to which the display is connected */
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library

void setup(void) {
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, LOW); // backlight OFF

    // Preset SPI CS pins to avoid bus conflicts
    digitalWrite(TFT_CS, HIGH);

    Serial.begin(115200);
    Serial.println("ESP-IDF version is: " + String(esp_get_idf_version()));

    tft.init();
    tft.setRotation(0); // Portrait
    tft.setCursor(0, 0);
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);

    tft.drawCentreString("Testing", TFT_WIDTH/2, TFT_HEIGHT * 0.33, 1);
    tft.drawCentreString("Display", TFT_WIDTH/2, TFT_HEIGHT * 0.5, 1);

    digitalWrite(TFT_BL, HIGH); // backlight ON
    Serial.println("Finishing setup");
}

void loop(void) {
    delay(1000);
    Serial.println("Looping");
}
