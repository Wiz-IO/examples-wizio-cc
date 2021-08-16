#include <Arduino.h>
#include <LRADIO.h>

LRadio radio(0x249D /* PAN_ID */, 0x8888 /* MY_ADDRESS */ /*, channel 11-26 def=11, power in dbm def=0 */);

void blink(int led, uint32_t timeout)
{
  static uint32_t start = 0;
  if (millis() - start > timeout)
  {
    start = millis();
    digitalToggle(led);
  }
}

void send_raw(uint32_t timeout)
{
  static uint32_t start = 0;
  uint8_t data[5] = {1, 2, 3, 4, 5}; // TODO
  if (millis() - start > timeout)
  {
    start = millis();
    Serial.printf("[APP] SEND: %d\n", radio.write(data, sizeof(data)));
  }
}

void txDone(RadioFrame *aFrame, RadioFrame *aAckFrame, RadioError aError)
{
  Serial.printf("[APP] %s( %d )\n", __func__, (int)aError);
}

void rxDone(RadioFrame *aFrame)
{
  static uint32_t cnt = 0; // count receive buffers
  Serial.printf("[APP] %s( %lu )\n", __func__, ++cnt);
}

void setup()
{
  Serial.begin(115200, true);
  Serial.printf("\n[APP] IEEE RADIO TI CC2652 2021 Georgi Angelov\n");
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  uint64_t A = radio.getEUI64();
  Serial.printf("[APP] EUI64: %08X%08X\n", (int)(A >> 32), (int)A);
  radio.setup(rxDone, txDone);
  while (false == radio.begin())
  {
    digitalWrite(LED_RED, 1);
    delay(500);
    digitalWrite(LED_RED, 0);
    delay(500);
  }
}

void loop()
{
  radio.process();
  blink(LED_GREEN, 100);
}