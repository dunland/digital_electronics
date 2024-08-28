source list is in `/etc/apt/sources.list.d`
## Error: signature couldn't be verified

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

## Error: package no longer has a Release file

- update release link for the current ubuntu version in `/etc/apt/sources.list.d/package-name`
- if version for current system not supported anymore:
	- `sudo apt-mark hold package` will prevent package from being updated
	- oder: comment out the link in `/etc/apt/sources.list.d/package-name`
- 
## apt-get upgrade

upgrades all upgradable packages

## searching for header files:
from https://askubuntu.com/a/706520:

`apt-file search` gives the information

```c
$ apt-file search --regex  /cairo.h$
libcairo2-dev: /usr/include/cairo/cairo.h
```

Because of that execute

```c
sudo apt install libcairo2-dev
```

and compile with

```c
g++ screenshot.cpp $(pkg-config --libs --cflags cairo)
```


## update core system:

```
sudo apt-get dist-upgrade
sudo apt dist-upgrade
```

