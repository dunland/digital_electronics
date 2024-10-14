## hibernate to partition

1. find UUID for swap device: 
``` bash
sudo blkid

/dev/sda1: UUID="65f47e96-a58e-4367-8ec8-248c60f21a64" TYPE="ext4" PARTUUID="6b04b0ed-01"
/dev/sda2: UUID="a269984f-1894-41b9-9933-aa65712f4bad" TYPE="swap" PARTUUID="6b04b0ed-02"
/dev/sda3: UUID="CA1880AF18809C57" TYPE="ntfs" PARTUUID="6b04b0ed-03"

```

2. copy UUID and insert in grub file:

``` bash
sudo gedit /etc/default/grub

GRUB_CMDLINE_LINUX_DEFAULT="initcall_debug no_console_suspend resume=UUID=a269984f-1894-41b9-9933-aa65712f4bad"
```

3. insert UUID to system file:
``` bash
sudo nano /etc/fstab

# /etc/fstab: static file system information.
#
# Use 'blkid' to print the universally unique identifier for a
# device; this may be used with UUID= as a more robust way to name devices
# that works even if disks are added and removed. See fstab(5).
#
# <file system> <mount point>   <type>  <options>       <dump>  <pass>
# / was on /dev/sda1 during installation
UUID=65f47e96-a58e-4367-8ec8-248c60f21a64 /               ext4    errors=remoun$
# swap was on /dev/sda5 during installation
#UUID=e2174c15-f626-4c5e-bdd7-79dc0ec5555e none            swap    sw          $
UUID=84a7ee07-9324-4388-8344-ffadb5e67817 none          swap    sw      0      $

```


4. `sudo update-grub`

## hibernate to swapfile
https://ubuntuhandbook.org/index.php/2021/08/enable-hibernate-ubuntu-21-10/

## create start menu entry
in KDE: https://www.reddit.com/r/Kubuntu/comments/1c2frkd/enabling_hibernation_on_2404/