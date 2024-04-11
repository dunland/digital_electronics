# Ubuntu Commands

## Core / Architecture Info

### Print certain system information.

``` bash 
dav@dav-lx:~$ uname -a
Linux dav-lx 4.15.0-55-lowlatency #60-Ubuntu SMP PREEMPT Tue Jul 2 19:11:22 UTC 2019 x86_64 x86_64 x86_64 GNU/Linux
dav@dav-lx:~$ uname -m
x86_64
```

`lshw` - list hardware

`top` -- task manager

`dmesg`	-- print system messages history 

`fdisk -l` -- List  the  partition  tables  for the specified devices and then
              exit.  If no devices are given, those mentioned in  /proc/parti‐
              tions (if that file exists) are used.

-------------------------------------------------------------------------------

## Hardware

`lspci` - list all PCI devices
`lsusb` shows list of connected USB devices
`cat /proc/asound/cards` displays active sound cards

list disk/partitions:

``` bash
sudo blkid

/dev/loop0: TYPE="squashfs"
...
/dev/loop7: TYPE="squashfs"
/dev/sda1: UUID="65f47e96-a58e-4367-8ec8-248c60f21a64" TYPE="ext4" PARTUUID="58a27272-01"
/dev/sda3: LABEL="System-reserviert" UUID="7CB07DB7B07D790A" TYPE="ntfs" PARTUUID="58a27272-03"
/dev/sda4: UUID="CA1880AF18809C57" TYPE="ntfs" PARTUUID="58a27272-04"
/dev/sda5: UUID="e2174c15-f626-4c5e-bdd7-79dc0ec5555e" TYPE="swap" PARTUUID="58a27272-05"
/dev/loop8: TYPE="squashfs"
...
/dev/sdb1: LABEL="INTENSO" UUID="A068-D57E" TYPE="vfat" PARTUUID="c3072e18-01"
```

### webcam

**find out which program is using my webcam:**  

```
$ fuser /dev/video0
/dev/video0:         13004m
/dev/video0: 1871m

$ ps ax1 | grep 13004
  13004 ?        Sl    90:33 python3 -m scanner.scanner
  16689 pts/0    S+     0:00 grep --color=auto 13004

$ killall python3
```

**reload webcam:**  

``` bash
sudo rmmod uvcvideo
sudo modprobe uvcvideo
```

-------------------------------------------------------------------------------

## files and folders
see [[linux-filesystem-hierarchy-standard-2.3.pdf]] for an overview on the linux system

### move, rename, copy, delete

moving folders: `mv from/path to/path`  
rename a folder: `mv /home/user/oldname /home/user/newname`  

### copy using rsync

`rsync -vrpXtUN /from/path /to/path` copy using

- increased verbosity (-v)
- recursing into directories (-r)
- preserving permissions (-p)
- preserving extended attributes (-X)
- preserving modification times (-t)
- preserving acces (use) times (-U)
- preserving create times (-N)

### splitting and concatenating files

split: `split --bytes=1M /path/to/image/image.jpg /path/to/image/prefixForNewImagePieces`  
merge: `cat prefixFiles* > newimage.jpg`

### search and find files

`find /path/to/search/in -name file_nam*`

### symlinks

- create symlink: `sudo ln -s /path/to/file/file-to-link /destination/folder/`  
- show symlink target: `readlink path/to/symlink/location`
change/overwrite symlink: `sudo ln -s -f /path/to/file-to-link /destination/folder`

### permissions

changing folder ownership: `sudo chown -R $USER ~/.blabla` (Make the current user own everything inside the folder (and the folder itself))  

list permission of folder: `ls -l`

example for weird, password-protected folder "zoom":  
``` bash
dav@dav-ubu:~/2019/zoom$ ls -l
total 20
drwx------ 12 root root 4096 Okt 22 00:41  4CH
-rw-------  1 dav  dav     0 Okt 21 23:33  4CH000I.wav
drwxrwxr-x  2 dav  dav  4096 Okt 21 23:34  FOLDER06
drwx------  6 root root 4096 Okt 22 00:41  MTR
drwxr-xr-x 12 root root 4096 Okt 22 00:42  STEREO
drwxr-xr-x  2 root root 4096 Okt 22 00:42 'System Volume Information'
```

### make bash file executable

`chmod u+x script`

### unpack/extract tar files
`tar -xvzf archive.tar.gz -C output_folder`

x - extract  
v - verbose  
z - filter the archive through gzip(1)  
f - file selection  
C - change to directory before performing any operations.

### date and time headers

overwrite Modify Date by EXIF data:

`for i in ./**/*.JPG ; do exiftool "-DateTimeOriginal>FileModifyDate" "$i"; done`

### Text File Handling

`touch ubuntu_commands.md` creates text file
`gedit ubuntu_commands.md` opens text file for changes

#### pdf

merge pdfs: `pdftk input1.pdf input2.pdf input3.pdf cat output out.pdf`

compress pdfs:
`gs -sDEVICE=pdfwrite -dCompatibilityLevel=1.4 -dPDFSETTINGS=/ebook -dNOPAUSE -dQUIET -dBATCH -sOutputFile=David_out.pdf DavidUnland_Urkunde-Abiturzeugnis.pdf `
mit 
``` 
–dPDFSETTINGS=/screen (screen-view-only quality, 72 dpi images)
–dPDFSETTINGS=/ebook (low quality, 150 dpi images)
–dPDFSETTINGS=/printer (high quality, 300 dpi images)
–dPDFSETTINGS=/prepress (high quality, color preserving, 300 dpi imgs)
–dPDFSETTINGS=/default (almost identical to /screen)  
```

## network

### show listening ports

- `sudo lsof -nP -iTCP -sTCP:LISTEN` mit PID

```
COMMAND   PID     USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
sshd      445     root    3u  IPv4  16434      0t0  TCP *:22 (LISTEN)
sshd      445     root    4u  IPv6  16445      0t0  TCP *:22 (LISTEN)
apache2   515     root    4u  IPv6  16590      0t0  TCP *:80 (LISTEN)
mysqld    534    mysql   30u  IPv6  17636      0t0  TCP *:3306 (LISTEN)
mysqld    534    mysql   33u  IPv6  19973      0t0  TCP *:33060 (LISTEN)
apache2   764 www-data    4u  IPv6  16590      0t0  TCP *:80 (LISTEN)
apache2   765 www-data    4u  IPv6  16590      0t0  TCP *:80 (LISTEN)
master    929     root   13u  IPv4  19637      0t0  TCP *:25 (LISTEN)
master    929     root   14u  IPv6  19638      0t0  TCP *:25 (LISTEN)
```

- `ss -natu` where The n option means don't translate addresses to names. The a options means show all (listening and non-listening) connections. The t option means TCP connections. The 'u' option means show UDP connections.
- `sudo ss -tunlp` 
- `netstat -apv`

    ```
        l – show only listening sockets
        t – show TCP connections
        n – show addresses in a numerical form
        u – show UDP connections
        p – show process id/program name
    ```

- `nmcli` (-c) shows network connections

#### ip sharing does not work

`iptables -S` hat gezeigt: `FORWARD DROP`.. nach **Deinstallation von Docker** hat alles wieder funktioniert!

## processes

`ps aux | grep XXXX` shows active processes containing string XXXX in their title

`Ctrl+Z` stops a process → `bg` will continue running it (i.e. first from `jobs` list) in background

## sources

> add apt repo ist nur Schnickschnack was die /etc/apt/sources bearbeitet und die Schlüssel runterlädt wenn noch fehlen
> gabs früher nicht
> einfach die config zeile (siehe internet) in die sources eintragen

## terminal

`history` shows terminal command history
