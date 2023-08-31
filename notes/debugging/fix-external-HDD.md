# fix external HDD

2022-05-29

Problem: 

> An error occurred while accessing 'DAV 5TB', the system responded: The requested operation has failed: Error mounting /dev/sdc1 at /media/dav/DAV 5TB: can't read superblock on /dev/sdc1

## approach 1

https://www.linuxbabe.com/desktop-linux/fix-cant-read-superblock-error#can-not-read-superblock-linux

- Find out the device name of the damaged partition: `sudo parted -l`
- Determine the location of the backup superblocks: `sudo mke2fs -n /dev/xxx` (For example, the device name of my HDD partition is /dev/sdb1, so I run `sudo mke2fs -n /dev/sdb1`)
- It will tell you that the partition contains an ext4 file system, press y to continue. Don’t worry the -n option tells mke2fs not to create a file system.

> found a gpt partition table in /dev/sdc. Proceed anyway? > y
> Creating filesystem with 1220942646 4k blocks and 152621056 inodes
> Filesystem UUID: 6d93c489-ba02-4063-ba10-9c9b81ee314c
> Superblock backups stored on blocks: 
>	32768, 98304, 163840, 229376, 294912, 819200, 884736, 1605632, 2654208, 
>	4096000, 7962624, 11239424, 20480000, 23887872, 71663616, 78675968, 
>	102400000, 214990848, 512000000, 550731776, 644972544

`sudo e2fsck -b 32768 /dev/sdc`

> e2fsck: Bad magic number in super-block while trying to open /dev/sdc
> The superblock could not be read or does not describe a valid ext2/ext3/ext4
> filesystem.  If the device is valid and it really contains an ext2/ext3/ext4
> filesystem (and not swap or ufs or something else), then the superblock
> is corrupt, and you might try running e2fsck with an alternate superblock:
>     e2fsck -b 8193 <device>
> or
>     e2fsck -b 32768 <device>
> Found a gpt partition table in /dev/sdc
> At the bottom, you can see the location of backup superblocks. Next, restore the superblock from the first backup copy.

## bad magic number in super-block while trying to open

https://www.linode.com/community/questions/20599/how-do-i-fix-a-bad-magic-number-in-super-block-error

```
   73  fsck -b 32768 /dev/sdc
   74  fsck -b 98304 /dev/sdc
   75  e2fsck -b 8193 /dev/sdc
   76  e2fsck -b 163840 /dev/sdc
   77  e2fsck -b 229376 /dev/sdc
   78  e2fsck -b 294912 /dev/sdc
   79  e2fsck -b 819200 /dev/sdc
   80  e2fsck -b 884736 /dev/sdc
   81  e2fsck -b 1605632 /dev/sdc
   82  e2fsck -b 2654208 /dev/sdc
   83  e2fsck -b 4096000 /dev/sdc
   84  e2fsck -b 7962624 /dev/sdc
   85  e2fsck -b 11239424 /dev/sdc
   86  e2fsck -b 20480000 /dev/sdc
   87  e2fsck -b 23887872 /dev/sdc
   88  e2fsck -b 71663616 /dev/sdc
   89  e2fsck -b 78675968 /dev/sdc
   90  e2fsck -b 102400000 /dev/sdc
```
... none working.

`blkid`  
> /dev/sdc1: LABEL="DAV 5TB" UU
> ID="2036-3559" BLOCK_SIZE="512" TYPE="exfat" PTTYPE="dos" PARTUUID="282fc3c5-cf26-4991-9d9c-0ab2e70e25e9"

https://forum.ubuntuusers.de/topic/bad-magic-number-in-super-block-while-trying-t/

`debugfs -w /dev/sdc1`
> debugfs: Bad magic number in super-block while trying to open /dev/sdc1
> /dev/sdc1 contains a exfat file system labelled 'DAV 5TB'


## fix bad superblock on exfat file system

https://askubuntu.com/questions/837173/how-to-fix-exfat-filesystem

`exfatfsck /dev/sdc1`
> command not found

`apt install exfatprogs`
> dpkg: error processing package openmpi-bin (--configure):
> installed openmpi-bin package post-installation script subprocess returned error exit status 2

`sudo update-alternatives --remove-all mpi`
> update-alternatives: error: /var/lib/dpkg/alternatives/mpi corrupt: slave link same as main link /usr/bin/mpicc

`apt-get install clean && apt-get autoremove`
> E: Unable to locate package clean

### solution (P14s)
2022...

``` bash
blkid
apt install exfat-utils
exfatfsck /dev/sda1
```
> file system checking finished. No errors found.

https://askubuntu.com/questions/837173/how-to-fix-exfat-filesystem

> try running journalctl -f before mounting, and mount exfat afterwards. You should see in the journal the reason exfat was mounted read-only; do you see anything interesting? And while on it, what's your kernel version?

```
journalctl -f
mkdir /media/exfat
mount -t exfat /dev/sda1 /media/exfat
```
... **works!!!**

### P14s: 2022-08-22

https://unix.stackexchange.com/questions/321494/ubuntu-16-04-package-exfat-utils-is-not-available-but-is-referred-to-by-anothe#321589

```
sudo add-apt-repository "deb http://archive.ubuntu.com/ubuntu $(lsb_release -sc) universe"
sudo add-apt-repository universe
```
> Adding component(s) 'universe' to all repositories.
> Press [ENTER] to continue or Ctrl-c to cancel.
> Hit:1 https://updates.signal.org/desktop/apt xenial InRelease
> Hit:2 https://librealsense.intel.com/Debian/apt-repo focal InRelease
> 0% [Connecting to de.archive.ubuntu.com] [Connecting to security.ubuntu.com] [CoHit:3 http://security.ubuntu.com/ubuntu jammy-security InRelease               
> Hit:4 http://de.archive.ubuntu.com/ubuntu jammy InRelease                      
> Hit:5 http://lenovo.archive.canonical.com jammy InRelease                      
> Hit:6 http://de.archive.ubuntu.com/ubuntu jammy-updates InRelease              
> Hit:7 https://packages.riot.im/debian default InRelease                        
> Hit:8 http://de.archive.ubuntu.com/ubuntu jammy-backports InRelease            
> Ign:9 https://ppa.launchpadcontent.net/jconti/recent-notifications/ubuntu jammy InRelease
> Hit:10 http://archive.ubuntu.com/ubuntu jammy InRelease
> Err:11 https://ppa.launchpadcontent.net/jconti/recent-notifications/ubuntu jammy Release
>   404  Not Found [IP: 2620:2d:4000:1::3e 443]
> Reading package lists... Done                                  
> W: https://librealsense.intel.com/Debian/apt-repo/dists/focal/InRelease: Key is stored in legacy trusted.gpg keyring (/etc/apt/trusted.gpg), see the DEPRECATION section in apt-key(8) for details.
> E: The repository 'https://ppa.launchpadcontent.net/jconti/recent-notifications/ubuntu jammy Release' does not have a Release file.
> N: Updating from such a repository can't be done securely, and is therefore disabled by default.
> N: See apt-secure(8) manpage for repository creation and user configuration details.
> W: Skipping acquire of configured file 'sutton.newell/binary-i386/Packages' as repository 'http://lenovo.archive.canonical.com jammy InRelease' doesn't have the component 'sutton.newell' (component misspelt in sources.list?)
> W: Skipping acquire of configured file 'sutton.newell/binary-amd64/Packages' as repository 'http://lenovo.archive.canonical.com jammy InRelease' doesn't have the component 'sutton.newell' (component misspelt in sources.list?)
> W: Skipping acquire of configured file 'sutton.newell/i18n/Translation-en_US' as repository 'http://lenovo.archive.canonical.com jammy InRelease' doesn't have the component 'sutton.newell' (component misspelt in sources.list?)
> W: Skipping acquire of configured file 'sutton.newell/i18n/Translation-en' as repository 'http://lenovo.archive.canonical.com jammy InRelease' doesn't have the component 'sutton.newell' (component misspelt in sources.list?)
> W: Skipping acquire of configured file 'sutton.newell/dep11/Components-amd64.yml' as repository 'http://lenovo.archive.canonical.com jammy InRelease' doesn't have the component 'sutton.newell' (component misspelt in sources.list?)
> W: Skipping acquire of configured file 'sutton.newell/dep11/icons-48x48.tar' as repository 'http://lenovo.archive.canonical.com jammy InRelease' doesn't have the component 'sutton.newell' (component misspelt in sources.list?)
> W: Skipping acquire of configured file 'sutton.newell/dep11/icons-64x64.tar' as repository 'http://lenovo.archive.canonical.com jammy InRelease' doesn't have the component 'sutton.newell' (component misspelt in sources.list?)
> W: Skipping acquire of configured file 'sutton.newell/dep11/icons-64x64@2.tar' as repository 'http://lenovo.archive.canonical.com jammy InRelease' doesn't have the component 'sutton.newell' (component misspelt in sources.list?)
> W: Skipping acquire of configured file 'sutton.newell/cnf/Commands-amd64' as repository 'http://lenovo.archive.canonical.com jammy InRelease' doesn't have the component 'sutton.newell' (component misspelt in sources.list?)


```
sudo apt-get update
sudo apt-get install exfat-fuse exfat-utils 
```

still not successful...

``` bash
apt install exfatprogs
sudo apt autoremove
```

https://github.com/exfatprogs/exfatprogs

``` bash
fsck.exfat /dev/sda1
```

2022-09-06:  
`fsck.exfat /dev/sda1 --verbose`

from sudo dd if=/dev/mmcblk0 of=/var/tmp/safeplace bs=1024k :

> Before you try anything else, copy the entire device to a safe place:
`sudo dd if=/dev/sda1 of=/var/tmp/safeplace bs=1024k`

> Next, use try reading the partition table:

`sudo parted -l /dev/mmcblk0`

> What is the partition type?
> If it's vfat, maybe the superblock is corrupted; try sudo fsck.vfat /dev/mmcblk0p1 (check the man page for options).
> Did you actually create it on a linux machine? If not, maybe it's an exFAT filesystem. Try:

`sudo dd if=/dev/mmcblk0p1 bs=16 count=1 | hd`

> and see if the first few bytes are 'EXFAT'. If so, install the fuse-based exfat:

`sudo apt-get install exfat-fuse`

> and try mounting manually if the GUI won't automatically recognize it.
> If this still doesn't work, well, we'll have to dig deeper :)

`mount.exfat-fuse /dev/sda1 /media/exfat` ... **works**!!

### W530

https://askubuntu.com/questions/1403900/how-to-install-exfat-utils-and-hddtemp-on-ubuntu-22-04

> exfat-utils has been replaced by exfatprogs (tools to create, check and label exFAT filesystems) in Ubuntu 22.04 and later. To install exfatprogs in Ubuntu 22.04 run the following command.

```
sudo su
apt install exfatprogs
apt update
# add-apt-repository "deb http://archive.ubuntu.com/ubuntu $(lsb_release -sc) universe"
apt-get update
add-apt-repository universe
```
**... cannot install exfat-utils!!**


## using windows
`chkdsk D: /f`
> Der Typ des Dateisystems ist RAW. CHKDSK ist für RAW-Laufwerke nicht verfügbar.


## Problem (HDD 3TB):
> Error mounting /dev/sdc1 at /media/dav/DAV3TB: mount(2) system call failed: Structure needs cleaning

```
blkid  # gives information on disks
e2fsck /dev/sdc1
```
... doesn't work.
formatting.. worked.

