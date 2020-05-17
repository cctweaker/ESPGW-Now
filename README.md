# ESPGW-Now
is half of a gateway to receive packets using the ESP-Now fast communication solution.
It runs on any ESP8266 device and is designed to receive json packets from battery powered sensors, switches, buttons and so on and send them out through serial to be picked up by a second device.

The other half of the software is <a href="https://github.com/cctweaker/ESPGW-WiFi">ESPGW-WiFi</a>, it will pick up the json string and send it through SSL to a MQTT server.

As far as I know, at least at the moment, this is the only ESP-Now solution published that allows to change the ESP-Now default encryption keys.

# Features
- perfect for infrequent small data transmissions
- no need for full blown WiFi, connects and transmits data instantly
- much faster than other solutions that rely on Wifi
- lower total power consumption, great for battery operated sensors/buttons
- creates a parallel network for IoT without hoarding your DHCP leases or WiFi (just the gateway is connected)


# Build
Clone in PlatformIO or download archive and extract main source folder to your Arduino projects folder.
Does not depend on any libraries.

# Setup
Rename example_private.h to private.h and edit to you liking.

# Hardware
Roll your own by cross-connecting RX and TX from two ESP8266 devices. GND pin must be common if not powered from the same source.
See the hardware folder for the current version.
