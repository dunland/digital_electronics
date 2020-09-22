# Tsunami Super Wav Trigger
## sources

[Tsunami Hookup Guide](Tsunami Hookup Guide - learn.sparkfun.com.md)

[Tsunami Intro](Tsunami Intro - robertsonics.md)

[Tsunami User Guide](Tsunami User Guide - robertsonics.md)

---

## formatting SD Card

> -   File system must be FAT16 or FAT32
> -   File Allocation Size must be 32 kilobytes
> -   "Quick format" is usually okay
> -   Note, if you are using a "brand new card", then formatting may not be necessary. If you notice that your Tsunami is missing commands, making occasional strange buzzing sounds, and sometimes crashing, then your file allocation size may be incorrect.

## teensy example

do not use an Arduino, since its IO ports are 5V! 3.3V max required!!

`Examples>TsunamiDemo` contains all you have to know.

``` C++
//    teensy        Tsunami
//    =======       =======
//    GND  <------> GND
//    TXn  <------> RX
//    RXn  <------> TX
```

In **SPRESENSE** the RX and TX pins on the extension board can be adressed with **Serial2**.  
To change the standard Serial port, go to Tsunami.h and change:

``` C++
// ==================================================================
// The following defines are used to control which serial class is
//  used. Uncomment only the one you wish to use. If all of them are
//  commented out, the library will use Hardware Serial
//#define __TSUNAMI_USE_SERIAL1__
#define __TSUNAMI_USE_SERIAL2__
//#define __TSUNAMI_USE_SERIAL3__
//#define __TSUNAMI_USE_ALTSOFTSERIAL__
// ==================================================================
```
