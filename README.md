# This is my README
Raspberry PI acoustic sensor project

This project will turn a raspberry Pi3 into an acoustic sensor.

1. Configuration

1.1 Hardware configuration

A raspberry Pi3 is recommended. If a older version of Pi is used, corresponding configuration might be changed.
The Pi is mounted with a USB sound card, and plugged in microphone.
It is recommended to have Ethernet connection for your Pi.

1.2 Software configuration

The USB sound card has to be set as default audio device. To do so, you need to modify two files with following content.
......

If you are using Raspbian Jessie, you have to roll back
