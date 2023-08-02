# openframeworks

## addons

from https://openframeworks.cc//documentation/ofxOsc/ofxOscReceiver/#!show_hasWaitingMessages

if an addon cannot be included, make sure to add it to addons.make:

`ofxOsc`

### ofxCv

from https://github.com/kylemcdonald/ofxCv seems to be a **better openCV wrapper** than ofxOpenCv

from https://forum.openframeworks.cc/t/ofxcv-ofxopencv-opencv-and-openframeworks/20072/3: 

> ofxOpenCv comes with openFrameworks, and is the addon the examples in openFrameworks/examples will use. It’s the oldest option, and uses the old OpenCv C API.
> ofxCv is newer, and what I’d recommend you use. It’s actively maintained and wraps the modern OpenCv C++ API. If you run into general OpenCv examples online, these will likely also be using the C++ API as well. You’ll need to get ofxCv yourself from https://github.com/kylemcdonald/ofxCv 1.0k and put it in your addons folder. If you’re using the openframeworks version on github (not 0.8.4) you’ll want to use the “develop” branch of ofxCv

### ofxPd

https://github.com/danomatika/ofxPd

...**cannot find ofLogError**...  
--> when adding `#include "ofMain.h":` **undefined reference to 'Poco::Mutex::Mutex()'**  
--> trying to get POCO: https://pocoproject.org/download.html  
--> `vcpkg install POCO` --> **vcpkg: command not found** --> install vcpkg as from https://github.com/microsoft/vcpkg#quick-start-unix ✓  
--> `~/opt/vcpkg/vcpkg install POCO` ✓  
`make` --> **/home/dunland/opt/of_v0.11.2_linux64gcc6_release/addons/obj/linux64/Release/ofxPd/src/ofxPd.o:ofxPd.cpp:function ofxPd::init(int, int, int, int, bool) [clone .cold]: error: undefined reference to 'Poco::SystemException::SystemException(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, int)'**
... of not properly configured?? :(

---

## algorithms

### Edge Detection

from [Finding the Edges (Sobel Operator) - Computerphile)](https://www.youtube.com/watch?v=uihBwtPIBxM)

--> sharp change in intensity


using **Sobel Operator** based on **Kernel Convolution**

---

## bugs

**ofVideoPlayer does not play video when Jack is running.**

Recherche:

- https://forum.openframeworks.cc/t/openframeworks-with-linux-jack/4242
- suche "puredata jack conflict gstreamer": https://www.google.com/search?q=puredata+jack+conflict+gstreamer&source=hp&ei=83FcYZHcIruExc8PmdOtmAo&iflsig=ALs-wAMAAAAAYVyAA0dSSIn4s8lkQh6x-4k_E6kSXAF7&ved=0ahUKEwjRoYvOzbPzAhU7QvEDHZlpC6MQ4dUDCAc&uact=5&oq=puredata+jack+conflict+gstreamer&gs_lcp=Cgdnd3Mtd2l6EAM6CAgAELEDEIMBOhEILhCABBCxAxCDARDHARDRAzoFCAAQsQM6CwgAEIAEELEDEIMBOgQIABADOgsILhCABBDHARDRAzoICC4QgAQQsQM6DgguEIAEEMcBEK8BEJMCOgsILhCABBDHARCvAToFCAAQgAQ6BQguEIAEOhAILhCABBDHARCvARAKEJMCOgcIABCABBAKOgYIABAWEB46CAgAEBYQChAeOgUIIRCgAToHCCEQChCgAVCyAlj0KGCsKmgBcAB4AYABywGIAYAkkgEGMC4zMi4xmAEAoAEB&sclient=gws-wiz
    - → reddit "Problem setting up JACK with Pure Data": https://www.reddit.com/r/puredata/comments/85o55a/problem_setting_up_jack_with_pure_data/