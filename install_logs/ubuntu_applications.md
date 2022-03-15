# Ubuntu Applications

## baobab

folders+files allocation GUI

## compiz

corrupt compiz results in glitchy display. Restart compiz is enough:
``` bash
killall compiz
compiz
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

## pipewire

**HELP:** https://gitlab.freedesktop.org/pipewire/pipewire/-/wikis/Config-PipeWire

- **config** is in /usr/share/pipewire/pipewire.conf

### enable pipewire:
from https://ubuntuhandbook.org/index.php/2021/05/enable-pipewire-audio-service-ubuntu-21-04/:

**You don’t have to remove the PulseAudio, just disable it and enable Pipewire:**

    Run command to reload the new service files:

    `systemctl --user daemon-reload`

    Disable PulseAudio service via command:

    `systemctl --user --now disable pulseaudio.service pulseaudio.socket`

    And finally enable the Pipewire services:

    `systemctl --user --now enable pipewire pipewire-pulse`



### disable pipewire:

`sudo systemctl disable --global pipewire`

> Removed /etc/systemd/user/default.target.wants/pipewire.service.
> Removed /etc/systemd/user/sockets.target.wants/pipewire.socket.

**ACHTUNG:** was passiert hier überhaupt?

### pw-jack

starts programs using pipewire and jack! e.g. `pw-jack ardour5`

from https://discourse.ardour.org/t/fedora-34-and-sample-rate/105875/5:
> If you want to change sample rate and/or buffer period you can start ardour using: `pw-jack -p 256 -s 44100 ardour6, for example.`
> Do you wanna know which sample rate Ardour started? Try `PIPEWIRE_DEBUG=3 pw-jack -p 256 -s 44100 ardour6`

**set global samplerate**: 

[[1]](https://gitlab.freedesktop.org/pipewire/pipewire/-/wikis/Configuration?version_id=25749f548c1e2fddd9e1678d9b7e57ebfcae3cf2#set-
global-sample-rate) [[2]](https://gitlab.freedesktop.org/pipewire/pipewire/-/wikis/Config-PipeWire)

what I did:  
1. `sudo nano /usr/share/pipewire/pipewire.conf`
2. set default-samplerate to 44100 and add that to allowed samplerates
3. temporarily force/use samplerate via `pw-metadata -n settings 0 clock.force-rate 44100` → **jack now @ 44100Hz ✓**
4. `PIPEWIRE_LATENCY=1024/44100 ardour5` to start ardour5 with that samplerate
5. **ardour5 still crashing**
6. re-enabling pipewire:

```
dunland@P14s:/$ sudo systemctl --global enable pipewire
[sudo] password for dunland: 
Created symlink /etc/systemd/user/default.target.wants/pipewire.service → /usr/lib/systemd/user/pipewire.service.
Created symlink /etc/systemd/user/sockets.target.wants/pipewire.socket → /usr/lib/systemd/user/pipewire.socket.
```

## pulseaudio

stopping pulseaudio:

```
dunland@P14s:~$ systemctl --user stop pulseaudio.service 
Warning: Stopping pulseaudio.service, but it can still be activated by:
  pulseaudio.socket
dunland@P14s:~$ systemctl --user stop pulseaudio.socket 
```

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

## xmonad

Lightweight X11 minimalist tiling window manager written in Haskell
