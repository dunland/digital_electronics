# Ubuntu Applications

## baobab

folders+files allocation GUI

------------------------------------
## Print & Scan

### CUPS

`localhost:631`
#### change Port

If CUPS (Common Unix Printing System) is using port 8000 on your localhost in Ubuntu and you want to change this port, you can follow these steps:

1. **Stop CUPS Service**: Before making any changes, stop the CUPS service to ensure that there are no active connections to the current port. Open a terminal and use the following command: 
- `sudo systemctl stop cups`

- **Edit Configuration File**: The CUPS configuration file can be found at `/etc/cups/cupsd.conf`. You will need administrative privileges to edit this file. Open the configuration file using a text editor like `nano` or `vim`:
- `sudo nano /etc/cups/cupsd.conf` 

- **Find and Update Port**: In the configuration file, search for the line that specifies the port CUPS is using. This line typically looks like:

`Listen localhost:8000`

Change the port number to the desired port, for example, let's say you want to change it to port 9000:

- `Listen localhost:9000`
   
- **Save and Close**: After making the changes, save the file and close the text editor.
   
- **Restart CUPS Service**: Restart the CUPS service to apply the changes:

- `sudo systemctl restart cups`
   
- **Check Status**: Verify that the CUPS service has started without any errors:

- `sudo systemctl status cups`   

Keep in mind that changing the port might require updating other configurations or services that interact with CUPS. For instance, if you have a firewall enabled, you might need to adjust its rules to allow traffic on the new port.

Additionally, if you're using CUPS for printer sharing across a network, clients will need to be updated with the new port information as well.

Remember to test the printing functionality after making these changes to ensure that everything is working as expected on the new port.

### Skanlite
KDE-Programm zum Scannen

---------------------------------------------------
## compiz

corrupt compiz results in glitchy display. Restart compiz is enough:
``` bash
killall compiz
compiz
``` 

## gnome

restart gnome:

1. `Alt+F2`
2. `r`

## inxi

*Command line system information script for console and IRC*

```bash
dav@dav-ThinkPad-W530:~$ inxi -GSayz  
System:  
 Kernel: 6.2.0-39-generic arch: x86_64 bits: 64 compiler: N/A  
   parameters: BOOT_IMAGE=/boot/vmlinuz-6.2.0-39-generic  
   root=/dev/mapper/vgkubuntu-root ro quiet splash  
   resume=/dev/mapper/vgkubuntu-swap_1 vt.handoff=7  
 Desktop: KDE Plasma v: 5.27.4 tk: Qt v: 5.15.8 wm: kwin_x11 vt: 1 dm: SDDM  
   Distro: Ubuntu 23.04 (Lunar Lobster)  
Graphics:  
 Device-1: Intel 3rd Gen Core processor Graphics vendor: Lenovo driver: i915  
   v: kernel arch: Gen-7 process: Intel 22nm built: 2012-13 ports:  
   active: LVDS-2 empty: VGA-2 bus-ID: 00:02.0 chip-ID: 8086:0166  
   class-ID: 0300  
 Device-2: NVIDIA GK107GLM [Quadro K1000M] vendor: Lenovo driver: nouveau  
   v: kernel alternate: nvidiafb non-free: series: 470.xx+  
   status: legacy-active (EOL~2023/24) arch: Kepler code: GKxxx  
   process: TSMC 28nm built: 2012-18 pcie: gen: 1 speed: 2.5 GT/s lanes: 16  
   link-max: gen: 3 speed: 8 GT/s ports: active: VGA-1 empty: DP-1, DP-2,  
   DP-3, LVDS-1 bus-ID: 01:00.0 chip-ID: 10de:0ffc class-ID: 0300 temp: 44.0 C  
 Device-3: Acer ThinkPad Integrated Camera type: USB driver: uvcvideo  
   bus-ID: 1-1.6:6 chip-ID: 5986:02d2 class-ID: 0e02  
 Display: x11 server: X.Org v: 1.21.1.7 with: Xwayland v: 22.1.8  
   compositor: kwin_x11 driver: X: loaded: modesetting unloaded: fbdev,vesa  
   dri: crocus gpu: i915,nouveau display-ID: :0 screens: 1  
 Screen-1: 0 s-res: 1920x2130 s-dpi: 96 s-size: 506x562mm (19.92x22.13")  
   s-diag: 756mm (29.77")  
 Monitor-1: LVDS-2 pos: primary,bottom-l model: AU Optronics 0x11ed  
   built: 2012 res: 1920x1080 hz: 60 dpi: 142 gamma: 1.2  
   size: 344x193mm (13.54x7.6") diag: 394mm (15.5") ratio: 16:9  
   modes: 1920x1080  
 Monitor-2: VGA-1 mapped: VGA-1-1 pos: top-right model: Dell 2209WA  
   serial: <filter> built: 2009 res: 1680x1050 hz: 60 dpi: 90 gamma: 1.2  
   size: 474x296mm (18.66x11.65") diag: 559mm (22") ratio: 16:10 modes:  
   max: 1680x1050 min: 720x400  
 API: OpenGL v: 4.2 Mesa 23.0.4-0ubuntu1~23.04.1 renderer: Mesa Intel HD  
   Graphics 4000 (IVB GT2) direct-render: Yes
```
   
## jhead

Rename files matched by *.jpg in the format YYYYMMDD-HHMMSS:
`jhead -n%Y%m%d-%H%M%S *.jpg `

## neofetch

``` bash
dunland@P14s:~$ neofetch
            .-/+oossssoo+/-.               dunland@P14s 
        `:+ssssssssssssssssss+:`           ------------ 
      -+ssssssssssssssssssyyssss+-         OS: Ubuntu 20.04.2 LTS x86_64 
    .ossssssssssssssssssdMMMNysssso.       Host: 20Y10002GE ThinkPad P14s Gen 1 
   /ssssssssssshdmmNNmmyNMMMMhssssss/      Kernel: 5.11.0-34-generic 
  +ssssssssshmydMMMMMMMNddddyssssssss+     Uptime: 6 days, 15 hours, 50 mins 
 /sssssssshNMMMyhhyyyyhmNMMMNhssssssss/    Packages: 3179 (dpkg), 21 (snap) 
.ssssssssdMMMNhsssssssssshNMMMdssssssss.   Shell: bash 5.0.17 
+sssshhhyNMMNyssssssssssssyNMMMysssssss+   Resolution: 1920x1080 
ossyNMMMNyMMhsssssssssssssshmmmhssssssso   DE: GNOME 
ossyNMMMNyMMhsssssssssssssshmmmhssssssso   WM: Mutter 
+sssshhhyNMMNyssssssssssssyNMMMysssssss+   WM Theme: Adwaita 
.ssssssssdMMMNhsssssssssshNMMMdssssssss.   Theme: Yaru [GTK2/3] 
 /sssssssshNMMMyhhyyyyhdNMMMNhssssssss/    Icons: Yaru [GTK2/3] 
  +sssssssssdmydMMMMMMMMddddyssssssss+     Terminal: gnome-terminal 
   /ssssssssssshdmNNNNmyNMMMMhssssss/      CPU: AMD Ryzen 7 PRO 4750U with Rade 
    .ossssssssssssssssssdMMMNysssso.       GPU: AMD ATI 07:00.0 Renoir 
      -+sssssssssssssssssyyyssss+-         Memory: 7965MiB / 31394MiB 
        `:+ssssssssssssssssss+:`
            .-/+oossssoo+/-.                                       
                                                                   
```

## okular

render markdown files correctly

## peek

screen to gif or mp4 recorder

## [[pipewire]]

## pulseaudio

**stopping pulseaudio:**

```
dunland@P14s:~$ systemctl --user stop pulseaudio.service 
Warning: Stopping pulseaudio.service, but it can still be activated by:
  pulseaudio.socket
dunland@P14s:~$ systemctl --user stop pulseaudio.socket 
```

**pulseaudio crashes with firefox** ("digital distortion")

> I think i fixed the issue by disable the following in about:config:

> `reader.parse-on-load.enabled false`
> `media.webspeech.synth.enabled false`

## qrencode

qrencode - Encode input data in a QR Code and save as a PNG or EPS image.

`qrencode -o "howCreepQR.png" -d 300 https://open.spotify.com/playlist/1tjdPAIZMlcyaZ7hzN5vYy?si=d342dba580f04726"`
## speedtest

```
dunland@P14s:~$ speedtest
Retrieving speedtest.net configuration...
Testing from Vodafone Germany Cable (95.90.202.43)...
Retrieving speedtest.net server list...
Selecting best server based on ping...
Hosted by Deutsche Telekom (Berlin) [258.36 km]: 43.383 ms
Testing download speed................................................................................
Download: 50.67 Mbit/s
Testing upload speed......................................................................................................
Upload: 5.65 Mbit/s
```

## video

- kdenlive
- losslesscut (snap)

## xmonad

Lightweight X11 minimalist tiling window manager written in Haskell
