# Limited-Hand-Motion-Keyboard
Keyboard designed using the arduino pro micro and a Digital Light Intensity Sensor Module for people with limited hand motion.

## Usage
To use the Keyboard you simply place your finger over the light sensor.
A light will flash three times.
Now on each following flash you will cover the light sensor or leave it.
There is a list of patterns for each character.
Depending on the firware wether your using the 5_bit or 8_bit the device will flash 5 times or 8 times.
The 5_bit version and 8_bit version have a seperate mapping document.

## How it works
This device is very simple and it works by waiting until the user covers the light sensor. This triggers the device to take a reading and flash around every second. When you cover the sensor the reading is "1". When you leave it the reading is "0". Then after either 8 readings or 5 readings depending on the firmware the device will ocnvert the readings into a binary number and then into an integer. This will then either map the number with an array of characters and type the correct charcter. Or treat it as an ascii code and convert it into a character and type i$

### 5_bit
This takes an array of the alphabet and some commonly used symbols and maps the number that the user creates to this array. Therefore by typing ```1 (00001)``` the device will map this too ```a```. This has a seperate character mapping document to follow if you want to use this firmware.

### 8_bit
This takes the number that the user entered and treats it as an ascii charcter code therefore allowing every possible symbol and charcter combination to be typed using this keyboard. In order to do this the legnth of the binary number needs to be longer and therefore is an 8_bit number hence the different firmware. This also has a charcter mapping document.

## What you will need
- [Arduino Pro Micro](https://www.amazon.co.uk/KOOKYE-ATmega32U4-arduino-Leonardo-ATmega328/dp/B019SXN84E/ref=sr_1_1?ie=UTF8&qid=1509474050&sr=8-1&keywords=arduino+pro+micro)
- [Digital Light Intensity Sensor Module](https://www.amazon.co.uk/gp/product/B01BTGV566/ref=oh_aui_detailpage_o05_s00?ie=UTF8&psc=1)
- [Female to Female Umper cables](https://www.amazon.co.uk/Aukru-20cm-Female-Female-Jumpers-Raspberry/dp/B00OL6JZ3C/ref=sr_1_3?s=electronics&ie=UTF8&qid=1509474247&sr=1-3&keywords=female+to+female+jumper+cables)
- [Micro USB to USB Cable](https://www.amazon.co.uk/Xillie-Short-USB-2-0-High-Speed/dp/B013G4EGOW/ref=sr_1_1_sspa?s=electronics&ie=UTF8&qid=1509474475&sr=1-1-spons&keywords=micro+usb+to+usb&psc=1)

## Initial Setup
Firstly you will want to connect the following pins together.
```
Arduino   Light Sensor     Colour
---------------------------------
VCC           VCC          Red
GND           GND          Black
GPIO/3        D0           Green
```
```The colour scheme does not have to be the same```

## Setup
Now you will want to setup your arduino so you can write the firmware to it. To do this follow [this](https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide) link and there are tutorials showing you how to do it for each OS.

Once you have your arduino and set up and plugged in you will want to select whether to use the 5_bit version or the 8_bit version. once you have selected you will want to copy the code into your arduino IDE select the correct board, port and settings and write the image to the board.

Now when your arduino is plugged into any computer and you should be able to type charcaters using the character mapping documents in this rep.

### Things to be aware of
- The first charcter you type may be dodgy but after the first charcter it will work fine
- If the sensor is not responding when you place your finger over it it may be because the resistance is too high, you will want to adjust the resistence by moving the blue wheel clockwise and anti clockwise.

### Author
CuPcakeN1njA
