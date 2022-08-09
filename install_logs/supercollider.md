# Supercollider

https://supercollider.github.io/

## Installation

1. `sudo apt-get install supercollider`
2. start Supercollider IDE
3. write `Quarks.install("https://github.com/loopier/ziva");`, Ctrl+Shift-L (Recompile Class)
4. `Ziva.boot`, Ctrl+Enter

... some errors, so:

``` supercollider

Quarks.install("https://github.com/loopier/ziva");
Quarks.install("Bjorklund");
Quarks.install("ddwCommon");
Quarks.install("https://github.com/supercollider/sc3-plugins/");
Ziva.boot

```

Errors treten scheinbar hauptsächlich mit sc3-plugins auf..  
compile from source like [here](https://github.com/supercollider/sc3-plugins#compile-from-source) doesn't work..

> root@P14s:/usr/share/SuperCollider/Extensions/sc3-plugins/build# cmake -DSC_PATH=/path/to/sc/ -DCMAKE_BUILD_TYPE=Release -DSUPERNOVA=OFF ..
> CMake Error at CMakeLists.txt:38 (message):
>  cannot find SuperCollider3 headers.  Set the variable SC_PATH.


> CMake Error at CMakeLists.txt:56 (include):
>  include could not find load file:

>    /path/to/sc/SCVersion.txt


> -- Building plugins for SuperCollider version: .
> -- local_sources: 
> CMake Warning (dev) at source/StkInst/CMakeLists.txt:3 (project):
>   Policy CMP0048 is not set: project() command manages VERSION variables.
>   Run "cmake --help-policy CMP0048" for policy details.  Use the cmake_policy
>   command to set the policy and suppress this warning.

  The following variable(s) would be set to empty:

    PROJECT_VERSION
This warning is for project developers.  Use -Wno-dev to suppress it.

-- Configuring incomplete, errors occurred!
See also "/usr/share/SuperCollider/Extensions/sc3-plugins/build/CMakeFiles/CMakeOutput.log".
root@P14s:/usr/share/SuperCollider/Extensions/sc3-plugins/build# cmake -DSC_PATH=/path/to/sc/ -DCMAKE_BUILD_TYPE=Release -DSUPERNOVA=OFF ..
CMake Error at CMakeLists.txt:38 (message):
  cannot find SuperCollider3 headers.  Set the variable SC_PATH.


CMake Error at CMakeLists.txt:56 (include):
  include could not find load file:

    /path/to/sc/SCVersion.txt


-- Building plugins for SuperCollider version: .
-- local_sources: 
CMake Warning (dev) at source/StkInst/CMakeLists.txt:3 (project):
  Policy CMP0048 is not set: project() command manages VERSION variables.
  Run "cmake --help-policy CMP0048" for policy details.  Use the cmake_policy
  command to set the policy and suppress this warning.

  The following variable(s) would be set to empty:

    PROJECT_VERSION
This warning is for project developers.  Use -Wno-dev to suppress it.

-- Configuring incomplete, errors occurred!
See also "/usr/share/SuperCollider/Extensions/sc3-plugins/build/CMakeFiles/CMakeOutput.log".



## basic commands

- `Ctrl+B` = Boot audio server (white font on black view on bottom of screen will turn green)
- `Ctrl+Enter` = Start audio server
- `Ctrl+.` = STOP
- run multiple lines using `( ... ) `

### server

- `Ctrl+B` boot audio server
- `s.quit` quit localhost
- `s.boot` boot localhost
- `Server.default.boot` boot default server

### [functions](https://doc.sccode.org/Tutorials/Getting-Started/04-Functions-and-Other-Functionality.html)
```
f = {"Function evaluated".postln; } ;
f

f = { arg a, b = 2; a + b; };
f.value(2);             // 2 + 2
```

### audio

```
SinOsc.ar(freq, phase, mul, add) // audiorate. phase is in radians (0 to 2*pi). mul is amplitude multiplicator.
SinOsc.kr( // controlrate; calculating a single value for each block of samples --> this can save a lot of computer power)

## ziva

see instructions and commands here: https://github.com/loopier/ziva

https://github.com/supercollider/sc3-plugins is required for the installation