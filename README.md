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

- You must to boot up the Raspberry Pi3 and set up the USB sound card.
- Raspberry Pi3 mainboard is able to connet with USB sound card by USB gates. USB sound card has 2 interface for micro and headphone,
so that tou allowed to working with audio from your computer or the sound from real time.
- In order to use USB sound card you should:
.Checking the USB sound card is connected or not by using "lsusb" command.
.Run the command "sudo nano /etc/asound.conf" and put the following content to the file:
        pcm.!default {
          type plug
          slave {
            pcm "hw:1,0"
          }
        }
        ctl.!default {
            type hw
            card 1
        }
.Back to home, then run the command "nano .asoundrc" and put the same content to the file.
.Run the command "alsamixer" to see and make sure that the USB sound card is the default audio device.

For the newest version of Raspbian (a.k.a. Jessie) come with new version of alsa-utils (1.0.28), which has a bug while recoding.
We can fix that problem by downgrading the ealier version of alsa-utils (1.0.25). Following below step:
- Run the command "sudo nano /etc/apt/sources.list" and add the line "deb http://mirrordirector.raspbian.org/raspbian/ wheezy main contrib non-free rpi" in the end.
- Run "sudo apt-get update" to update the version.
- Run "sudo aptitude versions alsa-utils" to check the version 1.0.25 is available or not.
- Run "sudo apt-get install alsa-utils=1.0.25-4" to downgrade it.
- If it not work, you should reboot the RPi or try again the above steps.
- Run "arecord -r44100 -c1 -f S16_LE -d5 test.wav" to test your microphone. Run "ls" and you should see a "test.wav" file in the folder.
- Connect your headphone and run "aplay test.wav" to check the recording process is okay.

2.Installation instructions:

My project is able to use without installing to the computer. (If you downloaded all file of my project on my GitHub)

3.Operating instructions:

3.1.Install libcurl:

In order to run some file attached curl. You should install libcurl:
- Run the command "ls /usr/include/curl" to identify that /usr/include/curl/ folder exists or not.
- If the folder doesn’t exist. Run “sudo apt-get update” to update the application list.
- Run “sudo apt-get install libcurl3” to install the libcurl3.
- Run “sudo apt-get install libcurl4-openssl-dev” to install the development API of libcurl4.

3.2.Program operation:

Before "make" file. You should determine the way that program work.
There are 2 way for working: nomal and DEBUG.

3.2.a.DEBUG working:

Run "nano wave.h" and enable DEBUD mode by delete the "//" sign before DEBUG.
The DEBUG mode is able to show the WAVEFORM of the sound that you put into microphone.

3.2.b.Nomal working:

Run "nano wave.h" and disable DEBUG mode by let the "//" sign before DEBUG.
The nomal mode is able to show the DATA and INFOMATION of the sound that you put into the microphone.

After choose the way of program work. Run the command "make" to create the application file. It's name should be "sound.a".
Run the command "./sound.a" and start ro record your sound.
Press "CTRL + C" when you want to stop the program.
You also see your sound's data in "http://www.cc.puv.fi/~e1601105/sound_log.txt".

4.List of files include:

4.1.Necessary for program running:

main.c
wave.c
screen.c
comm.c
testlib.c
wave.h
screen.h
comm.h
makefile

4.2.For reference and test:

README.md
test.c
curl.php
sound.php

5.Troubleshooting:

5.1.The data is negative or incorrect:

Checking and make sure that you microphone is connected and work clearly.

5.2.Program run incorrect:

If you try to edit something on one or more file. You should run the program again.
Run the command "make clean" to clean all file ".o" and file "sound.a".
Then, "make" file again and run nomally.

6.Contact information:

Developer: Do Thuan
Email: dov.thuan96@gmail.com
Git: https://github.com/dothuan96/

5.Credits and acknowledgments:

This project is developed in Raspberry Pi 3 by Do Thuan.
It's free for use and edit for learning and reference.
