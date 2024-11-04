- Adapter ist scheinbar `dav-X1 (hci0)` (Hardware Controller Interface)
``` bash
dav@dav-X1:~$ hcitool dev  
Devices:  
       hci0    F4:A4:75:A0:93:B6
```

```
- `aply -l` does not list bluetooth device:
``` bash
**** List of PLAYBACK Hardware Devices ****  
card 0: sofhdadsp [sof-hda-dsp], device 0: HDA Analog (*) []  
 Subdevices: 0/1  
 Subdevice #0: subdevice #0  
card 0: sofhdadsp [sof-hda-dsp], device 3: HDMI1 (*) []  
 Subdevices: 1/1  
 Subdevice #0: subdevice #0  
card 0: sofhdadsp [sof-hda-dsp], device 4: HDMI2 (*) []  
 Subdevices: 1/1  
 Subdevice #0: subdevice #0  
card 0: sofhdadsp [sof-hda-dsp], device 5: HDMI3 (*) []  
 Subdevices: 1/1  
 Subdevice #0: subdevice #0  
card 0: sofhdadsp [sof-hda-dsp], device 31: HDA Analog Deep Buffer (*) []  
 Subdevices: 1/1  
 Subdevice #0: subdevice #0
```

## bluez

https://unix.stackexchange.com/a/632421

> _Aplay_ is ALSA bare-metal recorder/player. It can work with (and aplay -l will actually list) all sound cards driven by whatever ALSA driver installed.
> As far as I know there is no ALSA driver for bluetooth sound devices.
> Therefore, you will need [bluez-alsa](https://github.com/Arkq/bluez-alsa) which enables you to create a virtual device (PCM) to enable alsa compatible players/recorders to directly (with no need for pulseaudio) use your bluetooth sound device.

``` bash
dav@dav-X1:~$ bluetoothctl  
Agent registered  
[Soundcore Note 3i]# show  
Controller F4:A4:75:A0:93:B6 (public)  
       Name: dav-X1  
       Alias: dav-X1  
       Class: 0x007c010c  
       Powered: yes  
       Discoverable: no  
       DiscoverableTimeout: 0x000000b4  
       Pairable: yes  
       UUID: Message Notification Se.. (00001133-0000-1000-8000-00805f9b34fb)  
       UUID: A/V Remote Control        (0000110e-0000-1000-8000-00805f9b34fb)  
       UUID: OBEX Object Push          (00001105-0000-1000-8000-00805f9b34fb)  
       UUID: Message Access Server     (00001132-0000-1000-8000-00805f9b34fb)  
       UUID: PnP Information           (00001200-0000-1000-8000-00805f9b34fb)  
       UUID: IrMC Sync                 (00001104-0000-1000-8000-00805f9b34fb)  
       UUID: Vendor specific           (00005005-0000-1000-8000-0002ee000001)  
       UUID: A/V Remote Control Target (0000110c-0000-1000-8000-00805f9b34fb)  
       UUID: Generic Attribute Profile (00001801-0000-1000-8000-00805f9b34fb)  
       UUID: Phonebook Access Server   (0000112f-0000-1000-8000-00805f9b34fb)  
       UUID: Audio Sink                (0000110b-0000-1000-8000-00805f9b34fb)  
       UUID: Device Information        (0000180a-0000-1000-8000-00805f9b34fb)  
       UUID: Generic Access Profile    (00001800-0000-1000-8000-00805f9b34fb)  
       UUID: Handsfree Audio Gateway   (0000111f-0000-1000-8000-00805f9b34fb)  
       UUID: Audio Source              (0000110a-0000-1000-8000-00805f9b34fb)  
       UUID: OBEX File Transfer        (00001106-0000-1000-8000-00805f9b34fb)  
       UUID: Handsfree                 (0000111e-0000-1000-8000-00805f9b34fb)  
       Modalias: usb:v1D6Bp0246d0542  
       Discovering: no  
       Roles: central  
       Roles: peripheral  
Advertising Features:  
       ActiveInstances: 0x00 (0)  
       SupportedInstances: 0x0c (12)  
       SupportedIncludes: tx-power  
       SupportedIncludes: appearance  
       SupportedIncludes: local-name  
       SupportedSecondaryChannels: 1M  
       SupportedSecondaryChannels: 2M  
       SupportedSecondaryChannels: Coded  
[Soundcore Note 3i]#
```

### Create a jack sink using bluealsa:

[Using BlueALSA with the JACK Audio Connection Kit](https://github.com/arkq/bluez-alsa/wiki/Using-BlueALSA-with-the-JACK-Audio-Connection-Kit)

Possibly the [simplest example](https://github.com/arkq/bluez-alsa/wiki/Using-BlueALSA-with-the-JACK-Audio-Connection-Kit#zita-j2a) is to create a jack sink using the `bluealsa` default PCM:

`zita-j2a -j bluealsa -d bluealsa -p 1024 -n 3 -c 2 -L`
### Problem: Couldn't get BlueALSA PCM: Rejected

> D: bluealsa-pcm.c:1309: Getting BlueALSA PCM: PLAYBACK 00:00:00:00:00:00 a2dp 
> ALSA lib bluealsa-pcm.c:1313:(_snd_pcm_bluealsa_open) Couldn't get BlueALSA PCM: Rejected send message, 1 matched rules; type="method_call", sender=":1.132" (uid=1000 pid=6338 comm="zita-j2a -j bluealsa -d bluealsa -p 1024 -n 3 -c 2" label="unconfined") interface="org.freedesktop.DBus.ObjectManager" member="GetManagedObjects" error name="(unset)" requested_reply="0" destination="org.bluealsa" (uid=0 pid=4905 comm="/usr/bin/bluealsa -p a2dp-source -p a2dp-sink" label="unconfined")
> Can't open ALSA playback device 'bluealsa'.

**ChatGPT:**

> It seems like your `zita-j2a` command is unable to open the ALSA playback device 'bluealsa'. The error message indicates that the D-Bus communication between `zita-j2a` and BlueALSA (which manages Bluetooth audio) failed.
> Here are a few steps you can take to troubleshoot and potentially resolve the issue:
>1. **Check Bluetooth Connection**: Make sure your Bluetooth device is properly connected and paired with your computer.
>2. **Verify BlueALSA Service**: Ensure that the BlueALSA service is running. You can check its status by running:

`sudo systemctl status bluealsa` ✓

> If the issue persists, you may need to dig deeper into the logs to understand what's going wrong. Check system logs (`/var/log/syslog` or `/var/log/messages`) for any relevant error messages that could provide additional insight into the problem.

### Soundcore_Note_i3 specific:
`dav@dav-X1:~$ zita-a2j -j Soundcore_Note_i3 -d bluealsa:F4:A4:75:A0:93:B6 -p 4096 -n 3 -c 2 -L`
> D: bluealsa-pcm.c:1309: Getting BlueALSA PCM: CAPTURE F4:A4:75:A0:93:B6 a2dp ALSA lib bluealsa-pcm.c:1313:(_snd_pcm_bluealsa_open) Couldn't get BlueALSA PCM: Rejected send message, 1 matched rules; type="method_call", sender=":1.147" (uid=1000 pid=6910 comm="zita-a2j -j Soundcore_Note_i3 -d bluealsa:F4:A4:75" label="unconfined") interface="org.freedesktop.DBus.ObjectManager" member="GetManagedObjects" error name="(unset)"requested_reply="0" destination="org.bluealsa" (uid=0 pid=4905 comm="/usr/bin/bluealsa -p a2dp-source -p a2dp-sink" label="unconfined") 
> Can't open ALSA capture device 'bluealsa:F4:A4:75:A0:93:B6'.


`dav@dav-X1:~$ bluealsa-aplay -l`
> bluealsa-aplay: W: aplay.c:945: Couldn't get BlueALSA PCM list: Rejected send message,  1 matched rules; type="method_call", sender=":1.148" (uid=1000 pid=7003 comm="bluealsa-aplay -l" label="unconfined") interface="org.freedesktop.DBus.ObjectManager" member="GetManagedObjects" error name="(unset)" requested_reply="0" destination="org.bluealsa" (uid=0 pid=4905 comm="/usr/bin/bluealsa -p a2dp-source -p a2dp-sink" label="unconfined")

### add user to group 'audio':

``` bash
dav@dav-X1:~$ groups dav  
dav : dav adm cdrom sudo dip plugdev users lpadmin sambashare  
dav@dav-X1:~$ sudo usermod -aG audio dav  
[sudo] password for dav:    
dav@dav-X1:~$ sudo systemctl restart alsa-utils  
Failed to restart alsa-utils.service: Unit alsa-utils.service is masked.  
dav@dav-X1:~$ sudo systemctl restart alsa-utils  
Failed to restart alsa-utils.service: Unit alsa-utils.service is masked.  
dav@dav-X1:~$ groups dav  
dav : dav adm cdrom sudo audio dip plugdev users lpadmin sambashare
```

### Using PulseAudio Wrapper for Application?

**ChatGPT:**

>If an application is communicating directly with ALSA (Advanced Linux Sound Architecture) rather than going through the PulseAudio sound server, it won't appear in KDE's application output list because PulseAudio manages the audio streams for KDE.

>Here are a few potential approaches to address this:

1. [ ] **PulseAudio Wrapper**: You can use a tool like `padsp` (PulseAudio OSS Wrapper) to wrap the application's ALSA output with PulseAudio. This essentially intercepts the ALSA calls and redirects them through PulseAudio. To use `padsp`, you would typically launch your application with it. For example:
    
    `padsp /opt/alfaview/alfaview`
    
2. [ ] **PulseAudio Module**: You can use PulseAudio's module-alsa-sink to create a virtual ALSA sink that forwards audio to PulseAudio. This allows ALSA applications to output their audio through PulseAudio. You can load the module by running:
       
    `pactl load-module module-alsa-sink device=hw:0`
    
    Replace `hw:0` with the appropriate ALSA device identifier. You can find the ALSA device identifier using `aplay -l`.
    
3. **ALSA Configuration**: If the application has configuration options for audio output, check if there's an option to route the audio through PulseAudio instead of ALSA. Sometimes applications have settings to select the audio backend or output device.
    
4. **PulseAudio Configuration**: Ensure that PulseAudio is running and configured correctly. If PulseAudio is not running, or if there are configuration issues, applications may resort to using ALSA directly.
    
5. **Check Application Documentation**: Review the documentation or settings of the application you're using to see if there are any options related to audio output or audio backend selection. Some applications provide configuration options to choose the audio backend or output device.
    

>By using one of these methods, you should be able to route the application's audio output through PulseAudio, making it visible in KDE's application output list and allowing for more flexible audio management within the KDE environment.

## fix missing A2DP Profile

**restarting blueman** and pipewire/pulseaudio helps:
``` bash
sudo pkill pipewire-pulse
sudo pkill blueman-*
sudo pkill bluetoothd
```

Codec for music: A2DP

- `pactl list sinks`
- `sudo systemctl status bluetooth.service`

`pactl set-card-profile bluez_card.9C_0C_35_D5_6B_5E a2dp_sink`
>No such entity

`pactl list cards short`
>184     bluez_card.9C_0C_35_D5_6B_5E    module-bluez5-device.c

[stackexchange:](https://unix.stackexchange.com/questions/677348/cannot-load-pulseaudio-modules-via-pactl-failure-no-such-entity)
> You are missing the package `pipewire-audio-client-libraries` which will add `module-tunnel-sink` `module-zeroconf-discover` and `bluetooth`. Those are now handled by `pipewire` since 0.3.28. `apt install` that and it will work like before.

`sudo apt install pipewire-audio-client-libraries && reboot`

...

Verify Bluetooth Device in PipeWire: `pw-cli ls Node | grep Soundcore -C 10`
>
       id 81, type PipeWire:Interface:Node/3  
               object.serial = "208"  
               factory.id = "8"  
               client.id = "34"  
               device.id = "123"  
               priority.session = "2010"  
               priority.driver = "2010"  
               node.description = "**Soundcore** Note 3i"  
               node.name = "bluez_input.9C_0C_35_D5_6B_5E.0"  
               media.class = "Audio/Source"  
       id 82, type PipeWire:Interface:Node/3  
               object.serial = "209"  
               factory.id = "8"  
               client.id = "34"  
               device.id = "123"  
               priority.session = "1010"  
               priority.driver = "1010"  
               node.description = "**Soundcore** Note 3i"  
               node.name = "bluez_output.9C_0C_35_D5_6B_5E.1"  
               media.class = "Audio/Sink"

``` bash
dav@dav-X1:/usr/share/pipewire$ pw-cli set-param Node 81 Props {audio.profile A2DP}  
Error: "set-param: unknown param type: 81"  
dav@dav-X1:/usr/share/pipewire$ pw-cli set-param Node 82 Props {audio.profile A2DP}  
Error: "set-param: unknown param type: 82"
```

Laut [PulseAudio Documentation](https://www.freedesktop.org/wiki/Software/PulseAudio/Documentation/User/Modules/#module-bluetooth-discover) ist a2dp nur in bluez4 enthalten.
### weitere Quellen

- `/etc/bluetooth/main.conf`
- `/usr/share/pipewire/pipewire.conf` Bluetooth enabled?
- [BluetoothUser a2dp](https://wiki.debian.org/BluetoothUser/a2dp)
- "install pavucontrol and go to configuration tab to set the codec"