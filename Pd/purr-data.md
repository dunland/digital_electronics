## Installation

from https://github.com/agraef/purr-data/wiki/Installation#linux

### binary:

#### via software center:

> Failed to install file: not supportedy

#### using console:

``` bash
dav@dav-ubu:/tmp/mozilla_dav0$ sudo apt install ./purr-data_2.17.0+git4829+ca592f6f-1_amd64.deb 
[sudo] password for dav: 
Reading package lists... Done
Building dependency tree       
Reading state information... Done
Note, selecting 'purr-data' instead of './purr-data_2.17.0+git4829+ca592f6f-1_amd64.deb'
The following packages were automatically installed and are no longer required:
  libmagick++-6.q16-7 libmagickcore-6.q16-3 libmagickwand-6.q16-3
Use 'sudo apt autoremove' to remove them.
Suggested packages:
  fluid-soundfont-gm
The following NEW packages will be installed:
  purr-data
0 upgraded, 1 newly installed, 0 to remove and 18 not upgraded.
Need to get 0 B/90,6 MB of archives.
After this operation, 344 MB of additional disk space will be used.
Get:1 /tmp/mozilla_dav0/purr-data_2.17.0+git4829+ca592f6f-1_amd64.deb purr-data amd64 2.17.0+git4829+ca592f6f-1 [90,6 MB]
debconf: unable to initialize frontend: Dialog
debconf: (Dialog frontend requires a screen at least 13 lines tall and 31 columns wide.)
debconf: falling back to frontend: Readline
Selecting previously unselected package purr-data.
(Reading database ... 445508 files and directories currently installed.)
Preparing to unpack .../purr-data_2.17.0+git4829+ca592f6f-1_amd64.deb ...
Unpacking purr-data (2.17.0+git4829+ca592f6f-1) ...
Setting up purr-data (2.17.0+git4829+ca592f6f-1) ...
Processing triggers for shared-mime-info (1.15-1) ...
Processing triggers for bamfdaemon (0.5.3+18.04.20180207.2-0ubuntu2) ...
Rebuilding /usr/share/applications/bamf-2.index...
Processing triggers for desktop-file-utils (0.24-1ubuntu3) ...
Processing triggers for mime-support (3.64ubuntu1) ...
Processing triggers for hicolor-icon-theme (0.17-2) ...
Processing triggers for gnome-menus (3.36.0-1ubuntu1) ...
N: Download is performed unsandboxed as root as file '/tmp/mozilla_dav0/purr-data_2.17.0+git4829+ca592f6f-1_amd64.deb' couldn't be accessed by user '_apt'. - pkgAcquire::Run (13: Permission denied)
```

... purr-data lässt sich trotzdem asführen. → **SUCCESS**??

### via console:

``` bash

sudo apt remove purr-data
echo 'deb http://download.opensuse.org/repositories/home:/aggraef/xUbuntu_20.04/ /' | sudo tee /etc/apt/sources.list.d/home:aggraef.list
curl -fsSL https://download.opensuse.org/repositories/home:aggraef/xUbuntu_20.04/Release.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/home_aggraef.gpg > /dev/null
sudo apt update
sudo apt install purr-data
```

**Error:**

> Reading package lists... Done  
> Building dependency tree  
> Reading state information... Done  
> Package purr-data is not available, but is referred to by another package.  
> This may mean that the package is missing, has been obsoleted, or  
> is only available from another source  
> E: Package 'purr-data' has no installation candidate  

----------------------------------
## Externals

https://puredata.info/docs/faq/how-do-i-install-externals-and-help-files/

`[declare -lib mrpeach]` --> *libdir_loader: added 'mrpeach' to the canvas-local objectclass path*

### Location of Externals:

GNU/Linux

Many externals can be installed through the package manager in Debian/Ubuntu/Mint. The Packages have a pd-... prefix.

Application-specific
    typically /usr/lib/pd/extra if you installed Pd via a package manager (such as apt) or /usr/local/lib/pd/extra if you compiled Pd yourself.
User-specific
    ~/.local/lib/pd/extra (since Pd-0.47-1, preferred) or ~/pd-externals (deprecated/older Pd-versions; still usable)
Global
    /usr/local/lib/pd-externals 

**LIBRARIES KÖNNEN NUR MIT SUPERUSER-RECHTEN GELADEN WERDEN, WENN SIE IN /opt/purr-data/lib/pd-l2ork/extra/ LIEGEN!!**