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
