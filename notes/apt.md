# apt

source list is in `/etc/apt/sources.list.d`

## apt-get update

only fetches packages upgrades

**Problem:**
> http://security.ubuntu.com/ubuntu xenial-security InRelease
>  The following signatures couldn't be verified because the public key is not available: NO_PUBKEY 40976EAF437D05B5 NO_PUBKEY 3B4FE6ACC0B21F32

https://askubuntu.com/a/15272

```
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 3B4FE6ACC0B21F32
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 40976EAF437D05B5
```
✓

## apt-get upgrade

upgrades all upgradable packages

## update core system:

```
sudo apt-get dist-upgrade
sudo apt dist-upgrade
```