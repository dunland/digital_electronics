#include <Audio.h>

AudioClass *theAudio;

void setup() {
  theAudio = AudioClass::getInstance();
  theAudio->begin();
  /* Setup a baseband audio path from mic input to line out */
  theAudio->setThroughMode(AudioClass::MicIn, AudioClass::None,
                           true, 160, AS_SP_DRV_MODE_LINEOUT);
  theAudio->setVolume(-10);
}

void loop() {
  /* Do nothing */
}
