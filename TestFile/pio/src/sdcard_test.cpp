//
// Created by LSC on 07.11.2024.
//
#include "Arduino.h"

// No specific libraries needed
#include "SD.h"

/* Following ports are used on ESP32 for SDCARD Access :
 * SD_CS - User defined pin GPIO12
 * SD_SCK - GPIO18
 * SD_MISO - GPIO19
 * SD_MOSI - GPIO23
 * */

#define SD_CS 12
bool SDCARD_OK = true;

void setup() {
    Serial.begin(115200);
    // put your setup code here, to run once:
    Serial.println("Testing SD Card");
    pinMode(SD_CS, OUTPUT);

    if(!SD.begin(SD_CS)) {
        Serial.println("Card Mount Failed");
        SDCARD_OK = false;
    } else {
        Serial.println("Card Mount Success");
    }
}

void loop() {
    // put your main code here, to run repeatedly
    delay(1000);
    if (SDCARD_OK) {
        Serial.println("SD Card OK and ready");
    }
    else {
        Serial.println("SD Card not OK... Try another card or check the connections");
    }
}
