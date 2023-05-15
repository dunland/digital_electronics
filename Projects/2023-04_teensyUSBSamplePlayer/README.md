# teensy USB Sample Player

## 2023-05-15 TODO:

- [ ] optional: mehrere Dateien simultan abspielen können? (--> Bsp. "SamplePlayer.ino")
- [ ] optional: erste 12 Dateien von SD Karte auslesen und automatisch den Knöpfen zuweisen

## 2023-05-15 Audioshield

**Ich habe Audio Shield Rev B --> für Teensy 3! Der hat ganz anderes Pinout als die Revisions für Teensy 4 (Rev D).**

[Audio Adaptor Boards for Teensy 3.x and Teensy 4.x](https://www.pjrc.com/store/teensy3_audio.html)

Lösung: [Getting started Teensy 4.1 and audio shield rev B](https://forum.pjrc.com/threads/64315-Getting-started-Teensy-4-1-and-audio-shield-rev-B)

[pjrc forum: audio shield <--> teensy 4 wiring](https://forum.pjrc.com/threads/57341-Bad-wiring-posted-somewhere-for-Teesny-4-0-to-Audio-Shield?p=214981&viewfull=1#post214981)

```

On the Audio Shield it expects:

    Ground pin on left side
    Pin 6 on the audio shield (SPI Flash memory chip select), Pin 6 on the Teensy 4.0
    Pin 7 on the audio shield (SPI MOSI), Pin 11 on the Teensy 4.0 (SPI MOSI)
    Pin 9 on the audio shield (I2S BCLK), Pin 21 on the Teensy 4.0 (I2S BCLK)
    Pin 10 on the audio shield (SPI SD card chip select), Pin 10 on the Teensy 4.0
    Pin 11 on the audio shield (I2S MCLK), Pin 23 on the Teensy 4.0 (I2S MCLK)
    Pin 12 on the audio shield (SPI MISO), Pin 12 on the Teensy 4.0 (SPI MISO)
    Pin 13 on the audio shield (I2S RX), Pin 8 on the Teensy 4.0 (I2S IN1)
    Pin 14 on the audio shield (SPI SCLK), Pin 13 on the Teensy 4.0 (SPI SCLK)
    Pin 15 on the audio shield (on board pins for attaching trimpot), Pin 15 on the Teensy 4.0
    Pin 18 on the audio shield (I2C SDA), Pin 18 on the Teensy 4.0 (I2C SDA)
    Pin 19 on the audio shield (I2C SCL), Pin 19 on the Teensy 4.0 (I2C SCL)
    Pin 22 on the audio shield (I2S TX), Pin 7 on the Teensy 4.0 (I2S OUT1A)
    Pin 23 on the audio shield (LRCLK), Pin 20 on the Teensy 4.0 (I2S LRCLK)
    3.3v, ground pins on the right side (maybe VIN as well)
```
