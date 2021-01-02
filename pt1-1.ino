#include <Wire.h>
#include <Adafruit_INA219.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include "SdFat.h"
SdFat SD;

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
Adafruit_INA219 ina219;
const int chipSelect = 10;

unsigned long previousMillis = 0;
File TimeFile;
File cout;
File CurFile;
int x = 0;

void setup() {
  SD.begin(chipSelect);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  ina219.begin();
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 1000)
  {
    previousMillis = currentMillis;
    ina219values();
x++;
    TimeFile = SD.open("TIME.txt", FILE_WRITE);
    if (TimeFile) {
      TimeFile.println(currentMillis);
      TimeFile.close();
    }

    cout = SD.open("cout.txt", FILE_WRITE);
    if (cout) {
      cout.println(x);
      cout.close();
    }

   
    displaydata();
  }
}

void displaydata() {
  
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(x);
  display.setCursor(35, 0);
  display.println("V");
  display.setCursor(50, 0);
//  display.println(current_mA);
//  display.setCursor(95, 0);
//  display.println("mA");
//  display.setCursor(0, 10);
//  display.println(loadvoltage * current_mA);
//  display.setCursor(65, 10);
//  display.println("mW");
//  display.setCursor(0, 20);
//  display.println(energy);
//  display.setCursor(65, 20);
//  display.println("mWh");
  display.display();
}

void ina219values() {
//  shuntvoltage = ina219.getShuntVoltage_mV();
//  busvoltage = ina219.getBusVoltage_V();
//  current_mA = ina219.getCurrent_mA();
//  loadvoltage = busvoltage + (shuntvoltage / 1000);
//  energy = energy + loadvoltage * current_mA / 3600;
}



