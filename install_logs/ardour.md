# Installation

Ubuntu Software Center → Ardour

## Problems

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
