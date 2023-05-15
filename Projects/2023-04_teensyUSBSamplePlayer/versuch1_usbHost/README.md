# teensyUSBSamplePlayer

ein Abspielgerät für Sounds, die via Ziffernblock angesteuert werden können.

## teensy 4.1 doc

https://www.pjrc.com/store/teensy41.html

> USB Host
>    A second USB port operates in host mode, which allows you to connect USB devices to Teensy 4.1. It is fully independent of the main USB device port, so USB devices you connect on the host port can simultaeously communicate with Teensy while Teensy communicates with your computer via the USB device port. This USB host port runs at 480, 12 or 1.5 Mbit/sec, depending on the speed if the device you connect. USB hubs may be used to connect many USB devices. The USBHost_t36 library is used for the USB host port. This USB host cable is normally used to connect a USB device or hub.

https://github.com/PaulStoffregen/USBHost_t36

## USB: Raw HID (Human Interface Device)

https://www.pjrc.com/teensy/rawhid.html

> If you want to create a custom application, Raw HID is simple way to send 64 byte packets between your code on the Teensy and your application on the PC or Mac.

> HID works automatically with built-in drivers in Linux, Mac OS X and Windows, so users will not need to load any drivers. Your application can detect your Teensy running your customized Raw HID, so to the user everything "just works" automatically.

> You can send up to 1000 packets per second in each direction. The USB host controller will reserve USB bandwidth. You are not required send all packets, but if you do, you are guaranteed to be able to transmit the number of packets per second your code specifies, even when other USB devices are active. 

### example: /home/dav/Arduino/libraries/USBHost_t41/examples/KeyboardForward

spezifische header-lokation gesetzt: `#include "/home/dav/Arduino/libraries/USBHost_t41/USBHost_t36.h"`

> In file included from /home/dav/github/digital_electronics/Projects/2023-04_teensyUSBSamplePlayer/teensyUSBSamplePlayer/lib/USBHost_t41/examples/KeyboardForeward/KeyboardForeward.ino:5:0:
> /home/dav/Arduino/libraries/USBHost_t41/USBHost_t36.h:2052:19: fatal error: SdFat.h: No such file or directory
> compilation terminated.
> Fehler beim Kompilieren für das Board Teensy 4.1.


## suche: [teensy get keyboard input from usbhost](https://www.google.com/search?channel=fs&client=ubuntu-sn&q=teensy+get+keyboard+input+from+usbhost)

result 1: https://forum.pjrc.com/threads/52828-USB-keyboard-input-in-Teensy

> You can with the Teensy 3.6 which has USB input support for some devices including many/most keyboards. Look under examples for the library USBHost_t36 and look at the example: Mouse. Which includes drivers for several devices including keyboards 

installed https://reference.arduino.cc/reference/en/libraries/sdfat/ via LibraryManager

```
In file included from /home/dav/github/digital_electronics/Projects/2023-04_teensyUSBSamplePlayer/teensyUSBSamplePlayer/lib/USBHost_t41/examples/KeyboardForeward/KeyboardForeward.ino:5:0:
/opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h:2257:1: error: expected class-name before '{' token
 {
 ^
/opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h:2295:45: error: 'SeekSet' was not declared in this scope
  virtual bool seek(uint64_t pos, int mode = SeekSet) {
                                             ^
/opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h: In member function 'virtual bool MSCFile::seek(uint64_t, int)':
/opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h:2296:15: error: 'SeekSet' was not declared in this scope
   if (mode == SeekSet) return mscfatfile.seekSet(pos);
               ^
/opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h:2297:15: error: 'SeekCur' was not declared in this scope
   if (mode == SeekCur) return mscfatfile.seekCur(pos);
               ^
/opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h:2298:15: error: 'SeekEnd' was not declared in this scope
   if (mode == SeekEnd) return mscfatfile.seekEnd(pos);
               ^
/opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h: In member function 'virtual File MSCFile::openNextFile(uint8_t)':
/opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h:2334:42: error: no matching function for call to 'FsFile::FsFile(MSCFile*)'
   if (file) return File(new MSCFile(file));
                                          ^
In file included from /home/dav/Arduino/libraries/SdFat/src/FsLib/FsLib.h:31:0,
                 from /home/dav/Arduino/libraries/SdFat/src/SdFat.h:33,
                 from /opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h:2052,
                 from /home/dav/github/digital_electronics/Projects/2023-04_teensyUSBSamplePlayer/teensyUSBSamplePlayer/lib/USBHost_t41/examples/KeyboardForeward/KeyboardForeward.ino:5:
/home/dav/Arduino/libraries/SdFat/src/FsLib/FsFile.h:869:7: note: candidate: FsFile::FsFile()
 class FsFile : public StreamFile<FsBaseFile, uint64_t> {
       ^
/home/dav/Arduino/libraries/SdFat/src/FsLib/FsFile.h:869:7: note:   candidate expects 0 arguments, 1 provided
/home/dav/Arduino/libraries/SdFat/src/FsLib/FsFile.h:869:7: note: candidate: FsFile::FsFile(const FsFile&)
/home/dav/Arduino/libraries/SdFat/src/FsLib/FsFile.h:869:7: note:   no known conversion for argument 1 from 'MSCFile*' to 'const FsFile&'
/home/dav/Arduino/libraries/SdFat/src/FsLib/FsFile.h:869:7: note: candidate: FsFile::FsFile(FsFile&&)
/home/dav/Arduino/libraries/SdFat/src/FsLib/FsFile.h:869:7: note:   no known conversion for argument 1 from 'MSCFile*' to 'FsFile&&'
In file included from /home/dav/github/digital_electronics/Projects/2023-04_teensyUSBSamplePlayer/teensyUSBSamplePlayer/lib/USBHost_t41/examples/KeyboardForeward/KeyboardForeward.ino:5:0:
/opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h: At global scope:
/opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h:2363:32: error: expected class-name before ',' token
 class USBFilesystem : public FS, public USBFSBase
                                ^
/opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h:2381:49: error: 'FILE_READ' was not declared in this scope
  File open(const char *filepath, uint8_t mode = FILE_READ) {
                                                 ^
/opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h: In member function 'File USBFilesystem::open(const char*, uint8_t)':
/opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h:2383:15: error: 'FILE_WRITE' was not declared in this scope
   if (mode == FILE_WRITE) { flags = O_RDWR | O_CREAT | O_AT_END; }
               ^
/opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h:2384:20: error: 'FILE_WRITE_BEGIN' was not declared in this scope
   else if (mode == FILE_WRITE_BEGIN) { flags = O_RDWR | O_CREAT; }
                    ^
/opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h:2386:42: error: no matching function for call to 'FsFile::FsFile(MSCFile*)'
   if (file) return File(new MSCFile(file));
                                          ^
In file included from /home/dav/Arduino/libraries/SdFat/src/FsLib/FsLib.h:31:0,
                 from /home/dav/Arduino/libraries/SdFat/src/SdFat.h:33,
                 from /opt/arduino-1.8.9/hardware/teensy/avr/libraries/USBHost_t41/USBHost_t36.h:2052,
                 from /home/dav/github/digital_electronics/Projects/2023-04_teensyUSBSamplePlayer/teensyUSBSamplePlayer/lib/USBHost_t41/examples/KeyboardForeward/KeyboardForeward.ino:5:
/home/dav/Arduino/libraries/SdFat/src/FsLib/FsFile.h:869:7: note: candidate: FsFile::FsFile()
 class FsFile : public StreamFile<FsBaseFile, uint64_t> {
       ^
/home/dav/Arduino/libraries/SdFat/src/FsLib/FsFile.h:869:7: note:   candidate expects 0 arguments, 1 provided
/home/dav/Arduino/libraries/SdFat/src/FsLib/FsFile.h:869:7: note: candidate: FsFile::FsFile(const FsFile&)
/home/dav/Arduino/libraries/SdFat/src/FsLib/FsFile.h:869:7: note:   no known conversion for argument 1 from 'MSCFile*' to 'const FsFile&'
/home/dav/Arduino/libraries/SdFat/src/FsLib/FsFile.h:869:7: note: candidate: FsFile::FsFile(FsFile&&)
/home/dav/Arduino/libraries/SdFat/src/FsLib/FsFile.h:869:7: note:   no known conversion for argument 1 from 'MSCFile*' to 'FsFile&&'
Bibliothek SdFat in Version 2.2.2 im Ordner: /home/dav/Arduino/libraries/SdFat  wird verwendet
Bibliothek SPI in Version 1.0 im Ordner: /opt/arduino-1.8.9/hardware/teensy/avr/libraries/SPI  wird verwendet
Fehler beim Kompilieren für das Board Teensy 4.1.

```

## example: Beispiele>Teensy4.1>KeyPad>HelloKeypad

... passiert quasi nichts.

## example: Teensy4.1>USBHost_t36>Serial>Mouse

... passiert quasi nichts.

## example: Teensy4.1>USBHost_t36>Test>test

... ist ein midi-tester??

## example: Teensy4.1>USBHost_t36>Test>SerialTest