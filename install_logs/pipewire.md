## pipewire

**HELP:** https://gitlab.freedesktop.org/pipewire/pipewire/-/wikis/Config-PipeWire

- **config** is in /usr/share/pipewire/pipewire.conf

**PipeWire Session Manager: Wireplumber**: download from [here](http://ftp.de.debian.org/debian/pool/main/w/wireplumber/wireplumber_0.4.8-4_amd64.deb) 

.. or maybe from https://github.com/pipewire-debian/pipewire-debian:  

``` bash
sudo add-apt-repository ppa:pipewire-debian/wireplumber-upstream
sudo apt-get update
sudo apt-get intall wireplumber

# Install dependencies

sudo apt install libfdk-aac2 libldacbt-{abr,enc}2 libopenaptx0

# If `libfdk-aac2` is not found install `libfdk-aac1`
# Install pipewire and additional packages

sudo apt install gstreamer1.0-pipewire libpipewire-0.3-{0,dev,modules} libspa-0.2-{bluetooth,dev,jack,modules} pipewire{,-{audio-client-libraries,pulse,bin,locales,tests}}

# Additionally, if you want to install `pipewire-doc`

sudo apt install pipewire-doc

# For WirePlumber (Recommended)

sudo apt-get install wireplumber{,-doc} gir1.2-wp-0.4 libwireplumber-0.4-{0,dev}

# For pipewire-media-session (installing WirePlumber is recommended)

sudo apt-get install pipewire-media-session

```

... throws error:

> Package wireplumber is not available, but is referred to by another package.
> This may mean that the package is missing, has been obsoleted, or
> is only available from another source

> E: Package 'wireplumber' has no installation candidate
> E: Unable to locate package wireplumber-doc
> E: Unable to locate package gir1.2-wp-0.4
> E: Couldn't find any package by glob 'gir1.2-wp-0.4'
> E: Couldn't find any package by regex 'gir1.2-wp-0.4'
> E: Unable to locate package libwireplumber-0.4-0
> E: Couldn't find any package by glob 'libwireplumber-0.4-0'
> E: Couldn't find any package by regex 'libwireplumber-0.4-0'
> E: Unable to locate package libwireplumber-0.4-dev
> E: Couldn't find any package by glob 'libwireplumber-0.4-dev'
> E: Couldn't find any package by regex 'libwireplumber-0.4-dev'


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