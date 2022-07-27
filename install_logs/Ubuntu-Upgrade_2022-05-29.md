# Upgrade Ubuntu from 22.04 to 22.04

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

## packages.riot.im/debian not secure

https://forum.ubuntuusers.de/topic/fehler-in-apt-get/

> Zeige mal `apt-key list` Da muss evtl. der alte Schlüssel gelöscht werden und ein neuer angelegt werden. So schlägt das der Entwickler vor.  
`sudo wget -O /usr/share/keyrings/riot-im-archive-keyring.gpg https://packages.riot.im/debian/riot-im-archive-keyring.gpg` ✓

## during installation:

> Could not install 'openmpi-bin'
> The upgrade will continue but the 'openmpi-bin' package may not be in a working state. Please consider submitting a bug report about it.
> installed openmpi-bin package post-installation script subprocess returned error exit status 2

> Could not install the upgrades
> The upgrade has aborted. Your system could be in an unusable state. A recovery will run now (dpkg --configure -a).

## how to remove PPAs


https://askubuntu.com/questions/96/is-there-a-way-to-reset-all-packages-sources-and-start-from-scratch



> You can do an installation of Ubuntu over top of an existing installation. You'll lose all of your (non-local [1]) system files and applications, but it will preserve everything in /home.
> Select the advanced partitioning option from the menu of either the desktop CD installer or the alternate CD installer. Set the mountpoint of your existing root partition to / and make sure the format box is not checked. Repeat these steps for your home partition, if you have one.
> 1: Where local system directories would be /usr/src, /usr/local, and /var/local.
