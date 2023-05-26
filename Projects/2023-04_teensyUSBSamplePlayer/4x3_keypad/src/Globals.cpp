#include <Arduino.h>
#include <vector>

#include "Globals.h"

std::vector<String> Globals::dynamicFileList;

void LED_blink(LED_code code)
{
    static unsigned long last_led_switch = millis();

    switch (code)
    {
    case LED_SDerror: // blink fast:
        if (millis() > last_led_switch + 200)
        {
            int LED_status = !digitalRead(LED_BUILTIN);
            digitalWrite(LED_BUILTIN, LED_status);
            last_led_switch = millis();
        }
        break;

    case LED_playingFile: // permanent on
        if (digitalRead(LED_BUILTIN) == LOW)
            digitalWrite(LED_BUILTIN, HIGH);
        break;

    case LED_running: // blink slowly:
        if (millis() > last_led_switch + 1000)
        {
            int LED_status = !digitalRead(LED_BUILTIN);
            digitalWrite(LED_BUILTIN, LED_status);
            last_led_switch = millis();
        }

        break;

    default:
        break;
    }
}