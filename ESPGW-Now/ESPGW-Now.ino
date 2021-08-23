ADC_MODE(ADC_VCC);
#include <ESP8266WiFi.h>
extern "C"
{
#include <espnow.h>
#include <user_interface.h>
}

// remember to edit example_private.h before building project!
#include "example_private.h"

void initVariant()
{
  WiFi.mode(WIFI_AP);
  wifi_set_macaddr(SOFTAP_IF, gmac);

  char HOSTNAME[32];
  sprintf(HOSTNAME, "%s_%06x", FWN, ESP.getChipId());

  WiFi.softAP(HOSTNAME, PASSWORD, WIFI_CHANNEL, HIDE_AP);
}

void setup()
{
  Serial.begin(115200);
  Serial.println();

  if (esp_now_init())
    ESP.restart();

  esp_now_register_recv_cb(rxcb);
  esp_now_register_send_cb(txcb);

  esp_now_set_kok(kok, 16);

  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);

  // add 6 more peers after gmac by increasing last byte in the gateway mac
  for (uint8_t i = 0; i < 6; i++)
  {
    gmac[5]++;
    esp_now_add_peer(gmac, ESP_NOW_ROLE_COMBO, WIFI_CHANNEL, key, 16);
    esp_now_set_peer_key(gmac, key, 16);
  }
}

void loop()
{
  if (millis() - last_hb >= heartbeat)
  {
    last_hb = millis();

    char tx[256];

    sprintf(tx, "{\"t\":\"%s\",\"v\":%.2f,\"ID\":\"%06x\",\"vcc\":%d}", FWN, VERSION, ESP.getChipId(), ESP.getVcc());

    Serial.print(&tx[0]);
  }
}

void rxcb(uint8_t *senderMac, uint8_t *incomingData, uint8_t len)
{
  Serial.println((char *)incomingData);
}

void txcb(uint8_t *mac, uint8_t sendStatus) {}