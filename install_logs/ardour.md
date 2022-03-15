# Installation

Ubuntu Software Center → Ardour

## Problems

### unknown source id error

```
ERROR: Session: XMLNode describing a AudioRegion references an unknown source id =21646
ERROR: Session: cannot create Region from XML description. Can not load state for region '4CH005I'
ERROR: Session: XMLNode describing a AudioRegion references an unknown source id =21660
ERROR: Session: cannot create Region from XML description. Can not load state for region '4CH005M'
ERROR: Session: XMLNode describing a AudioRegion references an unknown source id =21646
ERROR: Session: cannot create Region from XML description. Can not load state for region '4CH005I.1'
ERROR: Session: XMLNode describing a AudioRegion references an unknown source id =21646
ERROR: Session: cannot create Region from XML description. Can not load state for region '4CH005I.2'
ERROR: Session: XMLNode describing a AudioRegion references an unknown source id =21646
ERROR: Session: cannot create Region from XML description. Can not load state for region '4CH005I.2-L'
ERROR: Session: XMLNode describing a AudioRegion references an unknown source id =21660
ERROR: Session: cannot create Region from XML description. Can not load state for region '4CH005M.1'
ERROR: Session: XMLNode describing a AudioRegion references an unknown source id =21660
ERROR: Session: cannot create Region from XML description. Can not load state for region '4CH005M.1-L'
ERROR: Session: XMLNode describing a AudioRegion references an unknown source id =21646
ERROR: Session: cannot create Region from XML description. Can not load state for region '4CH005I.3-L'
ERROR: Session: XMLNode describing a AudioRegion references an unknown source id =21646
ERROR: Playlist: cannot create region from XML
ERROR: Session: cannot create Playlist from XML description.
ERROR: Could not set session state from XML
```

fixed by editing the `project.ardour` file:
habe die angeblich fehlende Datei in den Ordner `interchange` gelegt und anschließend in der `project.ardour` Datei die Source file eingepflegt:

```
    <Source name="4CH005I.wav" take-id="" type="audio" flags="Broadcast" id="21646" natural-position="2365920900" channel="0" origin="" gain="1"/>

    <Source name="4CH005M.wav" take-id="" type="audio" flags="Broadcast" id="21660" natural-position="2365920900" channel="0" origin="" gain="1"/>
```

danach konnten die Quelldateien wieder gefunden werden. Allerdings musste ich diese auch via `sox input.wav -i 48000 output.wav` manuell zu 48kHz ändern, damit alles wieder klappte.


### memlock error 
> WARNING: Your system has a limit for maximum amount of locked memory. This might cause Ardour to run out of memory before your system runs out of memory. 

> You can view the memory limit with 'ulimit -l', and it is normally controlled by  /etc/security/limits.conf

[Solution](https://discourse.ardour.org/t/your-system-has-a-limit-to-locked-memory-solution/86813/18):

> The example assumes that you want Ardour to be able to use max 10 GB of memory (memlock). The username in the example is: mika

> Nano is a text editor and you save text in it by pressing ctrl + o and enter.
You exit from nano by pressing: ctrl + x

> First open a terminal window and then you open config files in the nano editor and edit them.

- Add the following lines to limits.conf: `sudo nano /etc/security/limits.conf`
	`@audio - rtprio 99`
	`@audio - memlock 10000000`
- Add the user that is going to be running Ardour to the group: audio
	`sudo usermod -a -G audio mika`
- Add the following lines to 99-sysctl.conf: sudo nano /etc/sysctl.d/99-sysctl.conf
	`vm.swappiness = 10`
	`fs.inotify.max_user_watches = 524288`
- Reboot

## Plugins

### Install x42 package:
nice visual EQ etc

`sudo apt install x42-plugins`
