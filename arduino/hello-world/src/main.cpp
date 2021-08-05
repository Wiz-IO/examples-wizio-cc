#include <Arduino.h>

void setup()
{
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  Serial.begin(115200, true); // true redirect printf to this Serial
  Serial.printf("\nHello World TI CC2652 2021 Georgi Angelov\n");
}

void loop()
{
  Serial.print("loop ");

  digitalWrite(LED_GREEN, 1);
  delay(500);
  digitalWrite(LED_GREEN, 0);
  delay(500);

  digitalWrite(LED_RED, 1);
  delay(500);
  digitalWrite(LED_RED, 0);
  delay(500);

  // testting printf()
  printf("SECONDS = %d\n", seconds());
  printf("MILLIS = %d\n", millis());
  printf("RANDOM = %ld\n", random(100));
}