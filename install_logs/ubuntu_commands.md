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



## Hardware
`lsusb` shows list of connected USB devices
`cat /proc/asound/cards` displays active sound cards

list disk/partitions:

``` bash
sudo blkid

/dev/loop0: TYPE="squashfs"
/dev/loop1: TYPE="squashfs"
/dev/loop2: TYPE="squashfs"
/dev/loop3: TYPE="squashfs"
/dev/loop4: TYPE="squashfs"
/dev/loop5: TYPE="squashfs"
/dev/loop6: TYPE="squashfs"
/dev/loop7: TYPE="squashfs"
/dev/sda1: UUID="65f47e96-a58e-4367-8ec8-248c60f21a64" TYPE="ext4" PARTUUID="58a27272-01"
/dev/sda3: LABEL="System-reserviert" UUID="7CB07DB7B07D790A" TYPE="ntfs" PARTUUID="58a27272-03"
/dev/sda4: UUID="CA1880AF18809C57" TYPE="ntfs" PARTUUID="58a27272-04"
/dev/sda5: UUID="e2174c15-f626-4c5e-bdd7-79dc0ec5555e" TYPE="swap" PARTUUID="58a27272-05"
/dev/loop8: TYPE="squashfs"
/dev/loop9: TYPE="squashfs"
/dev/loop10: TYPE="squashfs"
/dev/loop11: TYPE="squashfs"
/dev/loop12: TYPE="squashfs"
/dev/loop13: TYPE="squashfs"
/dev/loop14: TYPE="squashfs"
/dev/loop15: TYPE="squashfs"
/dev/loop16: TYPE="squashfs"
/dev/loop17: TYPE="squashfs"
/dev/loop18: TYPE="squashfs"
/dev/loop19: TYPE="squashfs"
/dev/loop20: TYPE="squashfs"
/dev/loop21: TYPE="squashfs"
/dev/loop22: TYPE="squashfs"
/dev/loop23: TYPE="squashfs"
/dev/loop24: TYPE="squashfs"
/dev/loop25: TYPE="squashfs"
/dev/loop26: TYPE="squashfs"
/dev/loop27: TYPE="squashfs"
/dev/loop28: TYPE="squashfs"
/dev/sdb1: LABEL="INTENSO" UUID="A068-D57E" TYPE="vfat" PARTUUID="c3072e18-01"
```



## files and folders

### move, rename, copy, delete
moving folders: `mv from/path to/path`  
rename a folder: `mv /home/user/oldname /home/user/newname`  

### symlinks
create symlink: `sudo ln -s /path/to/file/file-to-link /destination/folder/`  
show symlink origin: `readlink -f symlinkname`

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

### unpack/extract tar files
`tar -xvzf archive.tar.gz -C output_folder`

x - extract  
v - verbose  
z - filter the archive through gzip(1)  
f - file selection  
C - change to directory before performing any operations.

### Text File Handling

`touch ubuntu_commands.md` creates text file
`gedit ubuntu_commands.md` opens text file for changes

#### pdf
merge pdfs: `pdftk input1.pdf input2.pdf input3.pdf cat output out.pdf`



## processes
`ps aux | grep XXXX` shows active processes containing string XXXX in their title


## terminal

`history` shows terminal command history


## audio
extract audio from video using ffmpeg:
```
sudo apt install ffmpeg
ffmpeg -i VIDEOFILE -acodec libmp3lame -metadata TITLE="Name of Song" OUTPUTFILE.mp3
```

