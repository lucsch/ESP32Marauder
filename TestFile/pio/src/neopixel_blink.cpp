//
// Created by LSC on 03.11.2024.
//
#include "Arduino.h"
#include "Adafruit_NeoPixel.h"

#define NEOPIXEL_PIN 25

Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
    strip.begin();
    strip.show();
    strip.setBrightness(50);
}

void loop() {
    strip.fill(strip.Color(255, 0, 0));
    strip.show();
    delay(500);
    strip.fill(strip.Color(0, 255, 0));
    strip.show();
    delay(500);
    strip.fill(strip.Color(0, 0, 255));
    strip.show();
    delay(500);
}