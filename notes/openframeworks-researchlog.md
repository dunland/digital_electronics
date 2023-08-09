# recherche
## next level openframeworks: addons, shaders etc

- https://ofxaddons.com/categories/8-graphics
- https://github.com/mfargo/ofxFilterLibrary
- https://github.com/armadillu/ofxFboBlur
- https://github.com/TeehanLax/ofxAsciiArt

https://github.com/moostrik/ofxFlowTools/issues/new  
→ create new issue "cannot compile"

with text:

$ `make` returns a **no return statement in function returning non-void [-Werror=return-type]** error. 
I am in Ubuntu 20.04

``` bash

In file included from /home/dunland/opt/of_v0.11.2_linux64gcc6_release/addons/ofxFlowTools/src/ofxFlowTools.h:43,
                 from /home/dunland/opt/of_v0.11.2_linux64gcc6_release/apps/myApps/example-ofxflowtools-1.1.2/src/flowToolsApp.h:5,
                 from /home/dunland/opt/of_v0.11.2_linux64gcc6_release/apps/myApps/example-ofxflowtools-1.1.2/src/flowToolsApp.cpp:1:
/home/dunland/opt/of_v0.11.2_linux64gcc6_release/addons/ofxFlowTools/src/core/fluid/ftFluidFlow.h: In member function ‘float flowTools::ftFluidFlow::setViscosityVel(float)’:
/home/dunland/opt/of_v0.11.2_linux64gcc6_release/addons/ofxFlowTools/src/core/fluid/ftFluidFlow.h:88:66: error: no return statement in function returning non-void [-Werror=return-type]
   88 |   float setViscosityVel(float value)  { viscosityVel.set(value); }
      |                                                                  ^
/home/dunland/opt/of_v0.11.2_linux64gcc6_release/addons/ofxFlowTools/src/core/fluid/ftFluidFlow.h: In member function ‘float flowTools::ftFluidFlow::setViscosityDen(float)’:
/home/dunland/opt/of_v0.11.2_linux64gcc6_release/addons/ofxFlowTools/src/core/fluid/ftFluidFlow.h:89:66: error: no return statement in function returning non-void [-Werror=return-type]
   89 |   float setViscosityDen(float value)  { viscosityDen.set(value); }
      |                                                                  ^
/home/dunland/opt/of_v0.11.2_linux64gcc6_release/addons/ofxFlowTools/src/core/fluid/ftFluidFlow.h: In member function ‘float flowTools::ftFluidFlow::setViscosityTmp(float)’:
/home/dunland/opt/of_v0.11.2_linux64gcc6_release/addons/ofxFlowTools/src/core/fluid/ftFluidFlow.h:90:66: error: no return statement in function returning non-void [-Werror=return-type]
   90 |   float setViscosityTmp(float value)  { viscosityTmp.set(value); }
      |                                                                  ^
In file included from /home/dunland/opt/of_v0.11.2_linux64gcc6_release/apps/myApps/example-ofxflowtools-1.1.2/src/flowToolsApp.cpp:1:
/home/dunland/opt/of_v0.11.2_linux64gcc6_release/apps/myApps/example-ofxflowtools-1.1.2/src/flowToolsApp.h: At global scope:
/home/dunland/opt/of_v0.11.2_linux64gcc6_release/apps/myApps/example-ofxflowtools-1.1.2/src/flowToolsApp.h:39:2: error: ‘ftFbo’ does not name a type
   39 |  ftFbo    cameraFbo;

```



