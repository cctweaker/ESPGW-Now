
// rename file to private.h before building
// and change the values to your liking

// select the channel that your ESP-Now gateway uses
// from 1 to 14, depending on your region
#define WIFI_CHANNEL 1
//

// hostname / AP name
// ESP-Now makes a new access point with this name
// although there is no use connecting to it
#define HOSTNAME "ESPNowGW"
//

// AP password
// better to have a password so devices don't connect to it
#define PASSWORD "password"
//

// select the MAC address that your ESP-Now gateway uses
// you can pick any address from the following private ranges
// as long as it is not used by any other device
// x2-xx-xx-xx-xx-xx
// x6-xx-xx-xx-xx-xx
// xA-xx-xx-xx-xx-xx
// xE-xx-xx-xx-xx-xx
uint8_t gmac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
// using a custom mac will allow you to change the ESP on the gateway without changing the programming on sensors or buttons
// hardware mac address assigned to the ESP is unchanged, just not used in this case
//
// ESP-Now allows only 6 encrypted peers in slave or combo mode.
// For encryption to work, the gateway (slave) must have all peers already added.
// Since our devices are transmitting sporadically, we can divide those 6 peers per device types:
// light switches, sensors, etc. giving each type a common mac address
// This software adds automatically 6 peers using the following 6 mac addresses (increasing the last byte of gateway mac address with 1 / peer).
//

// pick 16 random numbers to use as key encryption key KOK
uint8_t kok[16] = {0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF};
//

// pick 16 random numbers to use as controller / slave keys
uint8_t key[16] = {0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD, 0xBE, 0xEF, 0xDE, 0xAD};
//
