# Upgrade Ubuntu from 22.04 to 22.04

## hints & infos

2022-12-06: ubuntu 22.04 is using wayland as default window manager. Because of that, there might be errors with screen sharing!

https://askubuntu.com/questions/1407494/screen-share-not-working-in-ubuntu-22-04-in-all-platforms-zoom-teams-google-m

**chaning the display manager**:

``` bash
echo $XDG_SESSION_TYPE  # wayland
sudo nano /etc/gdm3/custom.conf
```
→ uncomment this line: `WaylandEnable=false`

## W530

`sudo apt-get update` throws _403 Errors_.

https://askubuntu.com/questions/711794/apt-get-update-always-failed-to-fetch

https://askubuntu.com/questions/41605/trouble-downloading-packages-list-due-to-a-hash-sum-mismatch-error

`sudo rm -fr /var/lib/apt/lists/*` ✓

```
sudo apt-get upgrade
sudo update-manager -d
```

Error: 
> W:Updating from such a repository can't be done securely, and is therefore disabled by default., W:See apt-secure(8) manpage for repository creation and user configuration details., W:GPG error: https://packages.riot.im/debian default InRelease: The following signatures were invalid: EXPKEYSIG C2850B265AC085BD riot.im packages <packages@riot.im>, E:The repository 'https://packages.riot.im/debian default InRelease' is not signed.

Source: https://ubuntuforums.org/showthread.php?t=2462126
>  It is usually important to disable, or better remove all PPAs before attempting an upgrade from version to version, and then add the PPA repos you need again after the upgrade.

### packages.riot.im/debian not secure

https://forum.ubuntuusers.de/topic/fehler-in-apt-get/

> Zeige mal `apt-key list` Da muss evtl. der alte Schlüssel gelöscht werden und ein neuer angelegt werden. So schlägt das der Entwickler vor.  
`sudo wget -O /usr/share/keyrings/riot-im-archive-keyring.gpg https://packages.riot.im/debian/riot-im-archive-keyring.gpg` ✓

### during installation:

> Could not install 'openmpi-bin'
> The upgrade will continue but the 'openmpi-bin' package may not be in a working state. Please consider submitting a bug report about it.
> installed openmpi-bin package post-installation script subprocess returned error exit status 2

> Could not install the upgrades
> The upgrade has aborted. Your system could be in an unusable state. A recovery will run now (dpkg --configure -a).

### how to remove PPAs

https://askubuntu.com/questions/96/is-there-a-way-to-reset-all-packages-sources-and-start-from-scratch

> You can do an installation of Ubuntu over top of an existing installation. You'll lose all of your (non-local [1]) system files and applications, but it will preserve everything in /home.
> Select the advanced partitioning option from the menu of either the desktop CD installer or the alternate CD installer. Set the mountpoint of your existing root partition to / and make sure the format box is not checked. Repeat these steps for your home partition, if you have one.
> 1: Where local system directories would be /usr/src, /usr/local, and /var/local.

## on P14s:

again, `sudo apt-get update` fails..

`sudo rm -fr /var/lib/apt/lists/*` still throws errors:

> Err:131 http://deb.seadrive.org jessie InRelease  
>  522   [IP: 2606:4700:3037::6815:2ff9 80]  
> Reading package lists... Done                                                     
> W: GPG error: http://download.opensuse.org/repositories/home:/aggraef/xUbuntu_20.04  InRelease: The following signatures were invalid: EXPKEYSIG 9F4C646D4A7F7998 home:aggraef OBS Project <home:aggraef@build.opensuse.org>  
> E: The repository 'http://download.opensuse.org/repositories/home:/aggraef/xUbuntu_20.04  InRelease' is not signed.  
> N: Updating from such a repository can't be done securely, and is therefore disabled by default.  
> N: See apt-secure(8) manpage for repository creation and user configuration details.  
> W: GPG error: https://packages.riot.im/debian default InRelease: The following signatures were invalid: EXPKEYSIG C2850B265AC085BD riot.im packages <packages@riot.im>  
> E: The repository 'https://packages.riot.im/debian default InRelease' is not signed.  
> N: Updating from such a repository can't be done securely, and is therefore disabled by default.  
> N: See apt-secure(8) manpage for repository creation and user configuration details.  
> E: Failed to fetch http://deb.seadrive.org/dists/jessie/InRelease  522   [IP: 2606:4700:3037::6815:2ff9 80]  
> E: The repository 'http://deb.seadrive.org jessie InRelease' is not signed.  
> N: Updating from such a repository can't be done securely, and is therefore disabled by default.  
> N: See apt-secure(8) manpage for repository creation and user configuration details.

```
sudo su
apt-get clean
rm -rf /var/lib/apt/lists/*
apt-get clean
apt-get update 
apt-get upgrade
```

> E: Failed to fetch http://deb.seadrive.org/dists/jessie/InRelease  521   [IP: 172.67.174.216 80]
E: The repository 'http://deb.seadrive.org jessie InRelease' is not signed.
N: Updating from such a repository can't be done securely, and is therefore disabled by default.
N: See apt-secure(8) manpage for repository creation and user configuration details.
W: GPG error: https://packages.riot.im/debian default InRelease: The following signatures were invalid: EXPKEYSIG C2850B265AC085BD riot.im packages <packages@riot.im>
E: The repository 'https://packages.riot.im/debian default InRelease' is not signed.
N: Updating from such a repository can't be done securely, and is therefore disabled by default.
N: See apt-secure(8) manpage for repository creation and user configuration details.
W: GPG error: http://download.opensuse.org/repositories/home:/aggraef/xUbuntu_20.04  InRelease: The following signatures were invalid: EXPKEYSIG 9F4C646D4A7F7998 home:aggraef OBS Project <home:aggraef@build.opensuse.org>
E: The repository 'http://download.opensuse.org/repositories/home:/aggraef/xUbuntu_20.04  InRelease' is not signed.
N: Updating from such a repository can't be done securely, and is therefore disabled by default.
N: See apt-secure(8) manpage for repository creation and user configuration details.

disabling the corrupt packages in _Software & Updates_...

>  The following signatures were invalid: EXPKEYSIG C2850B265AC085BD riot.im packages <packages@riot.im>  
> Reading package lists... Done  
> W: GPG error: https://packages.riot.im/debian default InRelease: The following signatures were invalid: EXPKEYSIG C2850B265AC085BD riot.im packages <packages@riot.im>  
> E: The repository 'https://packages.riot.im/debian default InRelease' is not signed.  
> N: Updating from such a repository can't be done securely, and is therefore disabled by default.  
>N: See apt-secure(8) manpage for repository creation and user configuration details.

[How to handle "invalid signature" in apt-get](https://askubuntu.com/questions/1240263/how-to-handle-invalid-signature-in-apt-get)

apt lists are in '/etc/apt/sources.list`  
[Update repository GPG key by using command below](https://askubuntu.com/questions/1344835/errors-when-trying-to-upgrade-to-ubuntu-21-04-from-20-10)
``` bash
sudo apt-key adv --recv-keys --keyserver keyserver.ubuntu.com C2850B265AC085BD

wget -q -O - https://packages.riot.im/element-release-key.gpg | sudo apt-key add -
wget -q -O - https://packages.riot.im/element-release-key-2020.gpg | sudo apt-key add -
wget -q -O - https://packages.riot.im/riot-release-key.gpg | sudo apt-key add -
```

``` bash
$ sudo ls -la /usr/share/keyrings/  | grep riot
-rw-r--r--   1 root root  2887 Apr 16  2019 riot-im-archive-keyring.gpg

$ sudo rm /usr/share/keyrings/riot-im-archive-keyring.gpg

$ sudo wget -O /usr/share/keyrings/riot-im-archive-keyring.gpg https://packages.riot.im/debian/riot-im-archive-keyring.gpg

$ echo "deb [signed-by=/usr/share/keyrings/riot-im-archive-keyring.gpg] https://packages.riot.im/debian/ default main" | sudo tee /etc/apt/sources.list.d/riot-im.list
```

``` bash
apt-get update
apt-get dist-upgrade
```

> Reading package lists... Done  
> Building dependency tree       
> Reading state information... Done  
> Calculating upgrade... Done  
> 0 upgraded, 0 newly installed, 0 to remove and 0 not upgraded.  

`update-manager -d` → Authentication failed!

`sudoedit /etc/update-manager/release-upgrades` → set `Prompt=normal`
`sudo do-release-upgrade`