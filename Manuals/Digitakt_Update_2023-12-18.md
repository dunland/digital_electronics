## 1. elektroid installation

1. `sudo apt-get install automake libtool build-essential libasound2-dev libgtk-3-dev libpulse-dev libsndfile1-dev libsamplerate0-dev autopoint gettext zlib1g-dev libjson-glib-dev libzip-dev `
2. ```autoreconf --install
   ./configure
   make
   sudo make install```
→ trotz Fehlermeldungen `elektroid` ausführbar aus Konsole!

## 2. elektroid commands

https://github.com/dagargo/elektroid#device-commands

1. downloade Firmware von https://www.elektron.se/en/download-support-digitakt#resources
2. `cd path/to/Downloads`
3. schließe Digitakt via USB an PC an
4. `elektroid-cli ld`:
>	 0: id: SYSTEM_ID; name: dav-ThinkPad-W530  
		1: id: hw:1,0,0; name: hw:1,0,0: Elektron Digitakt, Elektron Digitakt MIDI 1
4. `elektroid-cli upgrade Digitakt_OS1.50.syx 1`
