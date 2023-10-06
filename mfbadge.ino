// ei mf badge

#include "FastLED.h"
#define NUM_LEDS 10
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

const int NEO   = 8;
const int button    = 5;
const int buzz  = A0;
const int red   = 13;

void setup() {
  FastLED.addLeds<LED_TYPE, NEO, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  pinMode(button, INPUT_PULLDOWN);
  pinMode(buzz, OUTPUT);
  pinMode(red, OUTPUT);
  digitalWrite(red, LOW);
  ran();
}

void loop() {
  sunrise();
  day();
  for (int x = 0; x < 5000; x++) {
    if (digitalRead(button) == HIGH) {
      beeper();
    }
    delay(1);
  }
  sunset();
  moonrise();
  night();
  for (int x = 0; x < 5000; x++) {
    if (digitalRead(button) == HIGH) {
      beeper();
    }
    delay(1);
  }
  moonset();
  ran();
}

void ran() {
  int a = random(255);
  int b = random(255);
  int c = random(255);
  for (int x = 0; x < 10; x++) {
    pixel(a, b, c, x);
    delay(20);
  }
  for (int x = 0; x < 10; x++) {
    pixel(0, 0, 0, x);
    delay(20);
  }
}

void sunrise() {
  pixel(255, 128, 0, 9);
  delay(200);
  pixel(255, 128, 0, 8);
  pixel(120, 60, 0, 9);
  delay(200);
  pixel(255, 128, 0, 7);
  pixel(120, 60, 0, 8);
  pixel(0, 0, 0, 9);
  delay(200);
  pixel(255, 128, 0, 6);
  pixel(120, 60, 0, 7);
  pixel(0, 0, 0, 8);
  delay(200);
  pixel(255, 128, 0, 5);
  pixel(120, 60, 0, 6);
  pixel(0, 0, 0, 7);
  delay(200);
  pixel(120, 60, 0, 5);
  pixel(0, 0, 0, 6);
  delay(200);
  pixel(0, 0, 0, 5);
}

void day() {
  for (int x = 0; x < 250; x++) {
    if (digitalRead(button) == HIGH) {
      beeper();
    }
    int y = x / 2;
    pixel(x, y, 0, 5);
    pixel(x, y, 0, 6);
    pixel(x, y, 0, 7);
    pixel(x, y, 0, 8);
    pixel(x, y, 0, 9);
    delay(50);
  }
}

void sunset() {
  pixel(255, 128, 0, 9);
  delay(200);
  pixel(255, 128, 0, 8);
  pixel(120, 60, 0, 9);
  delay(200);
  pixel(255, 128, 0, 7);
  pixel(120, 60, 0, 8);
  pixel(0, 0, 0, 9);
  delay(200);
  pixel(255, 128, 0, 6);
  pixel(120, 60, 0, 7);
  pixel(0, 0, 0, 8);
  delay(200);
  pixel(255, 128, 0, 5);
  pixel(120, 60, 0, 6);
  pixel(0, 0, 0, 7);
  delay(200);
  pixel(120, 60, 0, 5);
  pixel(0, 0, 0, 6);
  delay(200);
  pixel(0, 0, 0, 5);
}

void moonrise() {
  pixel(0, 0, 255, 9);
  delay(200);
  pixel(0, 0, 255, 8);
  pixel(0, 0, 120, 9);
  delay(200);
  pixel(0, 0, 255, 7);
  pixel(0, 0, 120, 8);
  pixel(0, 0, 0, 9);
  delay(200);
  pixel(0, 0, 255, 6);
  pixel(0, 0, 120, 7);
  pixel(0, 0, 0, 8);
  delay(200);
  pixel(0, 0, 255, 5);
  pixel(0, 0, 120, 6);
  pixel(0, 0, 0, 7);
  delay(200);
  pixel(0, 0, 120, 5);
  pixel(0, 0, 0, 6);
  delay(200);
  pixel(0, 0, 0, 5);
}

void night() {
  for (int x = 0; x < 250; x++) {
    if (digitalRead(button) == HIGH) {
      beeper();
    }
    pixel(0, 0, x, 5);
    pixel(0, 0, x, 6);
    pixel(0, 0, x, 7);
    pixel(0, 0, x, 8);
    pixel(0, 0, x, 9);
    delay(50);
  }
}

void moonset() {
  pixel(0, 0, 255, 9);
  delay(200);
  pixel(0, 0, 255, 8);
  pixel(0, 0, 120, 9);
  delay(200);
  pixel(0, 0, 255, 7);
  pixel(0, 0, 120, 8);
  pixel(0, 0, 0, 9);
  delay(200);
  pixel(0, 0, 255, 6);
  pixel(0, 0, 120, 7);
  pixel(0, 0, 0, 8);
  delay(200);
  pixel(0, 0, 255, 5);
  pixel(0, 0, 120, 6);
  pixel(0, 0, 0, 7);
  delay(200);
  pixel(0, 0, 120, 5);
  pixel(0, 0, 0, 6);
  delay(200);
  pixel(0, 0, 0, 5);
}

void beeper() {
  for (int w = 0; w < 3; w++) {
    noise(buzz, 1100, 100);
    delay(random(500));
    noise(buzz, 500, 100);
    delay(random(400));
  }
  noise(buzz, 300, 1200);
}

void pixel(int r, int g, int b, int p) {
  leds[p] = CRGB (r, g, b);
  FastLED.show();
}

void noise (unsigned char buzzpin, int htz, long tim) {
  int p;
  long da = (long)(1000000 / htz);
  long lt = (long)((tim * 1000) / (da * 2));
  for (p = 0; p < lt; p++) {
    digitalWrite(buzzpin, HIGH);
    delayMicroseconds(da);
    digitalWrite(buzzpin, LOW);
    delayMicroseconds(da);
  }
}
