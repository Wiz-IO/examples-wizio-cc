#include <Arduino.h>

void adc_proces(uint32_t timeout)
{
  static uint32_t start = 0;
  if (millis() - start > timeout)
  {
    start = millis();
    digitalToggle(LED_RED);
    Serial.printf("[ADC] value = %d\n", analogRead(ADC_7));
  }
}

void setup()
{
  Serial.begin(115200, true);
  Serial.printf("\n[APP] TI CC2652 2021 Georgi Angelov\n");
  pinMode(LED_GREEN, OUTPUT);
}

void loop()
{
  blink(LED_GREEN, 100);
  adc_proces(5000);
}