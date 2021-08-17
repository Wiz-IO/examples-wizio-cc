#include <Arduino.h>
#include <AES_ECB_128.h>

void blink(int led, uint32_t timeout)
{
  static uint32_t start = 0;
  if (millis() - start > timeout)
  {
    start = millis();
    digitalToggle(led);
  }
}

void setup()
{
  Serial.begin(115200, true);
  Serial.printf("\n[APP] AES-ECB-128 TI CC2652 2021 Georgi Angelov\n");
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  //aes_ecb_128_self_test(1);

  uint8_t input[AES_ECB_LENGTH] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', '1', '2', '3', '4', '5', '6', '7', '8'}; // message raw[ 16 ]
  uint8_t output[AES_ECB_LENGTH];

  AesEcb128 aes("1234567890123456"); // init with KEY[ 16 ]

  memset(output, 0, AES_ECB_LENGTH);
  aes.Encrypt(input, output);
  DUMP("", input, AES_ECB_LENGTH);   // print message
  DUMP("", output, AES_ECB_LENGTH);  // print encrypted buffre

  memset(input, 0, AES_ECB_LENGTH);
  aes.Decrypt(output, input);        // output is encrypted message
  DUMP("", input, AES_ECB_LENGTH);   // print decrypted
}

void loop()
{
  blink(LED_GREEN, 100);
  blink(LED_RED, 200);
}
