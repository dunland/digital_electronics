#pragma once

#include <Arduino.h>
#include <vector>

class Globals
{
    public:
    static std::vector<String> dynamicFileList;
};

enum LED_code
{
    LED_SDerror,
    LED_playingFile,
    LED_running
};

void LED_blink(LED_code code);