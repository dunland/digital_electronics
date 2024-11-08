## CSound Cabbage: Building

1. Download Cabbage: https://www.cabbageaudio.com/download/  
2. Download JUCE: https://shop.juce.com/get-juce/download
3. build JUCE:  
``` bash
1133  sudo mv ~/Downloads/JUCE /opt/JUCE
 1134  cd /opt/JUCE/
 1136  cd extras/Projucer/Builds/LinuxMakefile/
 1138  sudo apt-get install libcurl-dev
 1139  sudo apt-get install libcurl4-gnutls-dev
 1141  sudo apt-get install libfreetype6-dev
 1145  pkg-config --cflags --libs freetype2
 1164  sudo mv /usr/include/freetype2/* /usr/include/
 1166  apt-cache search xrandr
 1167  sudo apt-get install libxrandr-dev
 1169  apt-cache search xinerama
 1170  sudo apt-get install libxinerama-dev
 1172  sudo apt-cache search xcursor
 1173  sudo apt-get install libxcursor-dev
 1175  sudo apt-get install webkit2gtk-4.0
 1176  sudo apt-get install gtk+-x11-3.0
 1177  make
```

``` bash
1120  cd ~/SDKs/
 1121  ./copy_vst2_to_vst3_sdk.sh 
 1122  mkdir build
 1123  cmake --version
 1124  sudo apt-get upgrade
 1125  cd VST3_SDK/
 1126  make
 1127  cd ../build/
 1128  make ../VST3_SDK
 1129  cmake ../VST3_SDK
 1130  sudo apt install cmake
 1131  cmake ../VST3_SDK
 1132  sudo apt-cache search xcb-util
 1133  sudo apt-get install libxcb-xrm-dev
 1134  cmake ../VST3_SDK
 1135  sudo apt-cache search xcb-cursor
 1136  sudo apt-get install libxcb-cursor-dev
 1137  cmake ../VST3_SDK
 1138  sudo apt-cache search xcb-keysyms
 1139  sudo apt-get install libxcb-keysyms-dev
 1140  sudo apt-get install libxcb-keysyms1-dev
 1141  cmake ../VST3_SDK
 1142  sudo apt-get install libxcb-xkb-dev
 1143  cmake ../VST3_SDK
 1144  sudo apt-cache search xkbcommon
 1145  sudo apt-get install xcb
 1146  cmake ../VST3_SDK
 1147  sudo apt-cache search xkbcommon-x11
 1148  sudo apt-get install libxkbcommon-x11-dev
 1149  cmake ../VST3_SDK
 1150  sudo apt-cache search gtkmm-3.0
 1151  sudo apt-get install libgtkmm-3.0-dev
 1152  cmake ../VST3_SDK
 1153  sudo apt-get install sqlite3-dev
 1154  sudo apt-cache search sqlite3
 1155  sudo apt-get install sqlite3
 1156  cmake ../VST3_SDK
 1157  whereis sqlite3
 1158  find | grep sqlite3.pc
 1159  locate sqlite3.pc
 1160  sudo updatedb
 1161  locate sqlite3.pc
 1162  find sqlite3.pc
 1163  sudo apt-get install libsqlite3-dev
 1164  cmake ../VST3_SDK

```

** FAILED **

## csound in python
### csound-python

downloaded from https://mageia.pkgs.org/7/mageia-core-release-x86_64/csound-python-6.10.0-1.mga7.x86_64.rpm.html  
`sudo apt-get install alien dpkg-dev debhelper build-essential`  
`sudo alien Downloads/csound-python-6.10.0-1.mga7.x86_64.rpm` --> csound-python_6.10.0-2_amd64.deb generated --> ausführen  

** FAILED **

### ctcsound
documentation: https://csound.com/docs/ctcsound/ctcsound-API.html
installierbar mit `pip install ctcsound` (oder pip3)

## purr-data installation 2024-08-17
Ubuntu 23.04

Installiere wie [hier](https://git.purrdata.net/jwilkes/purr-data#linux) beschrieben:

``` bash
 sudo apt-get install bison flex automake libasound2-dev \
      libjack-jackd2-dev libtool libbluetooth-dev libgl1-mesa-dev \
      libglu1-mesa-dev libglew-dev libmagick++-dev libftgl-dev \
      libgmerlin-dev libgmerlin-avdec-dev libavifile-0.7-dev \
      libmpeg3-dev libquicktime-dev libv4l-dev libraw1394-dev \
      libdc1394-22-dev libfftw3-dev libvorbis-dev ladspa-sdk \
      dssi-dev tap-plugins invada-studio-plugins-ladspa blepvco \
      swh-plugins mcp-plugins cmt blop slv2-jack omins rev-plugins \
      libslv2-dev dssi-utils vco-plugins wah-plugins fil-plugins \
      mda-lv2 libmp3lame-dev libspeex-dev libgsl0-dev \
      portaudio19-dev liblua5.3-dev python-dev libsmpeg0 libjpeg62-turbo \
      flite1-dev libgsm1-dev libgtk2.0-dev git libstk0-dev \
      libfluidsynth-dev fluid-soundfont-gm byacc \
      python3-markdown
```
... dabei alle Pakete, die Fehler aufwerfen, durch aktualisierte Pakete ersetzen. Mittels `apt-cache search [paket]` können richtige Namen gefunden werden

`make all`

**Error: lua.h not found** obwohl lua5.3 installiert ist. `lua.pc` muss zu `PKG_CONFIG_PATH` hinzugefügt werden. Dazu muss lua.pc lokalisiert werden. Ich habe es gefunden in `/lib/x86_64-linux-gnu/pkgconfig/` als `lua5.3.pc`. Dann symlink erstellt zu `/lib/x86_64-linux-gnu/pkgconfig/lua.h`

`make clean && make all`
`cd packages/linux_make && make install`
`purr-data` ✓

## purr-data (2019-11-11)

nach vielen Installationsversuchen (von git und anderen Quellen), hat diese Variante funktioniert:

from https://github.com/agraef/purr-data/wiki/Installation#linux

insert your Ubutntu Version for "xUbuntu_18.04".
``` bash
sudo su

wget -nv https://download.opensuse.org/repositories/home:aggraef/xUbuntu_18.04/Release.key
apt-key add Release.key

echo 'deb http://download.opensuse.org/repositories/home:/aggraef/xUbuntu_18.04/ /' > /etc/apt/sources.list.d/home:aggraef.list
apt update

apt install purr-data
```

### pd-aubio

``` bash
sudo apt-get install aubio-tools libaubio-dev libaubio-doc -y
sudo apt-get install pd-aubio
cd /~Downloads/
tar xf pd-aubio-0.4.tar.bz2
cd pd-aubio-0.4
./waf configure build
sudo ./waf install
sudo cp /usr/lib/pd/extra/aubio /opt/purr-data/lib/pd-l2ork/extra/aubio
purr-data -lib aubio
```

### gem for pd
2021-03-27

```
whereis pd
cd /usr/local/lib/pd
sudo mv Gem-v0.94 /usr/local/lib/pd/extra/
./autogen.sh 
./configure 
make
make install
```
**Fehlermeldung: `TextBase.h:39:12: fatal error: FTFont.h: No such file or directory`**

## processing

### gstreamer-based video library
Version 1.0 of the video library uses gstreamer 0.10.x, which is deprecated an may be missing in the Linux distribution. There will be a v2.0 of the library, which has been updated to use gstreamer 1.x.  

**Error:** `UnsatisfiedLinkError: Error looking up function 'gst_date_get_type': /usr/lib/x86_64-linux-gnu/libgstreamer-1.0.so: undefined symbol: gst_date_get_type`  
[fix](https://github.com/processing/processing-video/releases/tag/r6-v2.0-beta4):  
1. Download Video Library 2.0 (beta)  
2. copy to home/dav/sketchbook/libraries/  
3. also install gstreamer correctly:  
 `apt-get install libgstreamer1.0-0 gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-doc gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio`
done! **Achtung:** Videos müssen in Ordner sketch/data/ liegen!


## Ardour5
2020-06-29  
konnte im Ubuntu Software-Center heruntergeladen werden.  
hängt jedoch beim Start mit Hinweis `ardour: [INFO]: Loading color file /usr/share/ardour5/themes/dark-ardour.colors`  
Umbenennung der Datei (in dark-ardour.colors.backup) lässt das Programm zwar starten, jedoch mit sehr unübersichtlichem UI

## openFrameworks

### openFrameworks & VSCode:
2021-06-12

``` bash
cd [OF]/apps
git clone git@github.com:hiroMTB/vscode_oF
```
→ **use the example folder in vscode_oF/exampleEmpty as a template for new projects to be developed in VSCode**

## pipewire

### 1. Versuch: apt
`sudo apt install meson`

`git clone https://gitlab.freedesktop.org/pipewire/pipewire.git`  
`./autogen.sh --prefix=$PREFIX`
    > meson.build:1:0: ERROR: Meson version is 0.53.2 but project requires >= 0.54.0  
    --> get newest version here: https://github.com/mesonbuild/meson/releases
..**meson 54+ gibt es nur für ubuntu 21.04+...**

### 2. Versuch: installation von ppa:

from https://ubuntuhandbook.org/index.php/2021/05/install-latest-pipewire-ppa-ubuntu-20-04/

```
sudo add-apt-repository ppa:pipewire-debian/pipewire-upstream
sudo apt install pipewire
```

[How to Enable PipeWire Audio Service to Replace PulseAudio in Ubuntu 21.04](https://ubuntuhandbook.org/index.php/2021/05/enable-pipewire-audio-service-ubuntu-21-04/):

`sudo apt install pipewire-audio-client-libraries`

disable pulseaudio and enable pipewire:

```
systemctl --user daemon-reload
systemctl --user --now disable pulseaudio.service pulseaudio.socket
systemctl --user --now enable pipewire pipewire-pulse
```

> And check if Pipewire is working, run pactl info command. And it’s working if you see “PulseAudio (on PipeWire 0.3.24)” in output.

... works!

`sudo apt install pipewire gstreamer1.0-pipewire libpipewire-0.2-1 libpipewire-0.2-dev libpipewire-0.2-doc`