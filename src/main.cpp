#include <Arduino.h>
#include <GyverOLED.h>
#include "VoltageDivider.hpp"

GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;

namespace Display {
  void init() {
    oled.init();
    oled.clear();
    oled.home();
    oled.setScale(2);
    oled.println("by clumsy");
    oled.print("Baboon");
    delay(800);
    oled.clear();
  }
};

VoltageDivider AAABattery(47.0, 10.0);

void setup() {
  Display::init();
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  analogReference(INTERNAL);
  VoltageDivider::vRef = 1.06;
}

void loop() {
  // digitalWrite(2, HIGH);
  // delay(700);
  // digitalWrite(2, LOW);
  // delay(700);
  Serial.print("Value: ");
  Serial.println(AAABattery.getV(analogRead(A3)));
  delay(100);
}
