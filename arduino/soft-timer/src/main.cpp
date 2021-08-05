#include <Arduino.h>
#include <SoftTimer.h>

SoftTimer red, green;

void green_callback()
{
  digitalToggle(LED_GREEN);
}

void red_callback()
{
  digitalToggle(LED_RED);
}

void setup()
{
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  Serial.begin(115200, true);
  Serial.printf("\nHello World TI CC2652 2021 Georgi Angelov\n");

  green.begin(green_callback, 1000);
  red.begin(red_callback, 500);
}

void loop()
{
  SoftTimer::loop();
}