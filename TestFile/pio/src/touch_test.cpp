// This is the Touch Test for ESP32 Marauder

#include <SPI.h>
#include <XPT2046_Touchscreen.h>
// A library for interfacing with the touch screen
//
// Can be installed from the library manager (Search for "XPT2046")
//https://github.com/PaulStoffregen/XPT2046_Touchscreen

#include <TFT_eSPI.h>
// A library for interfacing with LCD displays
//
// Can be installed from the library manager (Search for "TFT_eSPI")
//https://github.com/Bodmer/TFT_eSPI


// ----------------------------
// Touch Screen pins defined in platformio.ini
// ----------------------------

// The CYD touch uses some non default
// SPI pins

/*
CYD IRQ 36 --> ESPMarauder IRQ is connected to VCC
CYD MOSI 32 --> ESPMarauder MOSI (23)
CYD MISO 39 --> ESPMarauder MISO (19)
CYD CLK 25 --> ESPMarauder CLK  (18)
CYD CS 33 --> ESPMarauder CHIP_SELECT   (21)
*/
#if defined(MARAUDER)
// marauder use HSPI ports to communicate with touch driver and TFT display
#define XPT2046_IRQ 255
#define XPT2046_MOSI TFT_MOSI
#define XPT2046_MISO TFT_MISO
#define XPT2046_CLK TFT_SCLK
#define XPT2046_CS TOUCH_CS
#elif defined(CYD)
// Cheap yellow display uses HSPI ports to communicate with TFT display and
// VSPI ports to communicate with touch driver
// see here : https://randomnerdtutorials.com/esp32-cheap-yellow-display-cyd-pinout-esp32-2432s028r/
#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33
#else
#error "Please define MARAUDER or CYD"
#endif

SPIClass mySpi = SPIClass(VSPI);
XPT2046_Touchscreen ts(XPT2046_CS, XPT2046_IRQ);
TFT_eSPI tft = TFT_eSPI();

void setup() {
    Serial.begin(115200);

#if defined(MARAUDER)
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, LOW); // backlight OFF
    // Preset SPI CS pins to avoid bus conflicts
    digitalWrite(TFT_CS, HIGH);
#endif

    // Start the SPI for the touch screen and init the TS library
    mySpi.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
    ts.begin(mySpi);
    ts.setRotation(1);

    // Start the tft display and set it to black
    tft.init();
    tft.setRotation(1); //This is the display in landscape

    // Clear the screen before writing to it
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);

    int x = 320 / 2; // center of display
    int y = 100;
    int fontSize = 2;
    tft.drawCentreString("Touch Screen to Start", x, y, fontSize);

#if defined(MARAUDER)
    digitalWrite(TFT_BL, HIGH);
#endif
}

void printTouchToSerial(TS_Point p) {
    Serial.print("Pressure = ");
    Serial.print(p.z);
    Serial.print(", x = ");
    Serial.print(p.x);
    Serial.print(", y = ");
    Serial.print(p.y);
    Serial.println();
}

void printTouchToDisplay(TS_Point p) {

    // Clear screen first
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);

    int x = 320 / 2; // center of display
    int y = 100;
    int fontSize = 2;

    String temp = "Pressure = " + String(p.z);
    tft.drawCentreString(temp, x, y, fontSize);

    y += 16;
    temp = "X = " + String(p.x);
    tft.drawCentreString(temp, x, y, fontSize);

    y += 16;
    temp = "Y = " + String(p.y);
    tft.drawCentreString(temp, x, y, fontSize);
}

void loop() {
    if (ts.tirqTouched() && ts.touched()) {
        TS_Point p = ts.getPoint();
        printTouchToSerial(p);
        printTouchToDisplay(p);
        delay(100);

    }
}
