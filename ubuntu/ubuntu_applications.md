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
