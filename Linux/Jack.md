
**SYNOPSIS**
```
jackd [options] -d backend [backend-parameters]
jackd --help
```

**start server:**
- `/usr/bin/jackd -r -dalsa -dhw:sofhdadsp -r44100 -p512 -D -Phw:sofhdadsp`

## samplerate
- set **samplerate** like described in >> [[pipewire]] !
## using realtime scheduling:
https://jackaudio.org/faq/linux_rt_config.html

>Distributions that are known to get this completely right include:
>- AVLinux
>- 64Studio These distributions have JACK packages that will create and configure a group with the required priviledges for RT scheduling, but will not add you to that group.
>- Debian Squeeze
>- Fedora 13 and later
>- Ubuntu Studio
>- Ubuntu - However, the user needs to be added to “audio” group.

1. `sudo usermod -a -G audio $USER` adds current user to `audio` group
2. create `/etc/security/limits.d/audio.conf`:

```
@audio   -  rtprio     95
@audio   -  memlock    unlimited
```

3. reboot ✓