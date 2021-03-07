/*
    recording_player.ino - Object I/F based recording and play example application
    Copyright 2018 Sony Semiconductor Solutions Corporation

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,  MA 02110-1301  USA
*/

#include <MediaRecorder.h>
#include <MediaPlayer.h>
#include <OutputMixer.h>
#include <MemoryUtil.h>

MediaRecorder *theRecorder;
MediaPlayer *thePlayer;
OutputMixer *theMixer;

const int32_t sc_buffer_size = 6144;
// const int32_t sc_buffer_size = 12288; //24576;
uint8_t s_buffer[sc_buffer_size];

const int16_t delay_time = 96000; // 2 s * sampleRate
int16_t delayBuffer[delay_time];
int16_t writePos = 48000;
int16_t readPos = 0;

// int16_t *writePos = (int16_t*)delayBuffer + 48000; // start writing at half of delay buffer
// int16_t *readPos = (int16_t*)delayBuffer; // start reading from beginning

bool ErrEnd = false;

/**
   @brief Audio attention callback

   When audio internal error occurc, this function will be called back.
*/

static void attention_cb(const ErrorAttentionParam *atprm)
{
  puts("Attention!");

  if (atprm->error_code > AS_ATTENTION_CODE_WARNING)
  {
    ErrEnd = true;
  }
}

/**
   @brief Recorder done callback procedure

   @param [in] event        AsRecorderEvent type indicator
   @param [in] result       Result
   @param [in] sub_result   Sub result

   @return true on success, false otherwise
*/

static bool mediarecorder_done_callback(AsRecorderEvent event, uint32_t result, uint32_t sub_result)
{
  return true;
}

/**
   @brief Mixer done callback procedure

   @param [in] requester_dtq    MsgQueId type
   @param [in] reply_of         MsgType type
   @param [in,out] done_param   AsOutputMixDoneParam type pointer
*/
static void outputmixer_done_callback(MsgQueId requester_dtq,
                                      MsgType reply_of,
                                      AsOutputMixDoneParam *done_param)
{
  return;
}

/**
   @brief Mixer data send callback procedure

   @param [in] identifier   Device identifier
   @param [in] is_end       For normal request give false, for stop request give true
*/
static void outmixer_send_callback(int32_t identifier, bool is_end)
{
  AsRequestNextParam next;

  next.type = (!is_end) ? AsNextNormalRequest : AsNextStopResRequest;

  AS_RequestNextPlayerProcess(AS_PLAYER_ID_0, &next);

  return;
}

/**
   @brief Player done callback procedure

   @param [in] event        AsPlayerEvent type indicator
   @param [in] result       Result
   @param [in] sub_result   Sub result

   @return true on success, false otherwise
*/
static bool mediaplayer_done_callback(AsPlayerEvent event, uint32_t result, uint32_t sub_result)
{
  /* If result of "Play", Start recording to supply captured data to player */

  if (event == AsPlayerEventPlay)
  {
    theRecorder->start();
  }

  return true;
}

/**
   @brief Player decode callback procedure

   @param [in] pcm_param    AsPcmDataParam type
*/
void mediaplayer_decode_callback(AsPcmDataParam pcm_param)
{
  /* You can imprement any audio signal process */
  {
    delayEffect(pcm_param);
    // revertSample(pcm_param);
    // static uint32_t s_frame_cnt = 0;

    // uint8_t sel = (s_frame_cnt++ / 1000) % 3;
    /*
        if (sel == 1)
          {
            rc_filter(pcm_param);
            puts("mode = 1, rcfilter active");
          }
        else if (sel == 2)
          {
            //distortion_filter(pcm_param);
            puts("mode = 2, distortion_filter active");
          }
        else
          {
            puts("no filter active");
            // No filter
  }
  */
}

/* Output and sound audio data */

theMixer->sendData(OutputMixer0,
                   outmixer_send_callback,
                   pcm_param);
}

void delayEffect(AsPcmDataParam pcm_param)
{
  // int temp = ls[0]
  // ls[0] = 0;

  /*for 16bit PCM */

  // static const int PeakLevel = 32700;
  static const int LevelGain = 1;

  // get physical address of sample
  // interleaved frame samples: LRLRLRLRLR...
  int16_t *ls = (int16_t*)pcm_param.mh.getPa(); // left
  int16_t *rs = ls + 1; // right

  static int16_t ls_l = 0;
  static int16_t rs_l = 0;

  // if (!ls_l && !rs_l)
  // {
  //   ls_l = *ls * LevelGain;
  //   rs_l = *rs * LevelGain;
  // }

  for (uint32_t cnt = 0; cnt<pcm_param.size; cnt += 4)
  {
    // set gain
    *ls = *ls * LevelGain;
    *rs = *rs * LevelGain;

    // write to buffer
    delayBuffer[writePos] = *ls;
    delayBuffer[writePos + 1] = *rs;

    // signal processing
    *ls += delayBuffer[readPos] * 1/2;
    *rs += delayBuffer[readPos + 1] * 1/2;

    // ls_l = *ls;
    // rs_l = *rs;

    ls += 2;
    rs += 2;
    // writePos += 2;
    // readPos += 2;
    readPos = (readPos >= (96000 - 4)) ? 0 : readPos + 2;
    writePos = (writePos >= (96000 - 4)) ? 0 : writePos + 2;
  }


  // iterate through entire Sample
  // for (uint32_t i = 0; i<pcm_param.size; i+=4)
  // {
  //
  //   *writePos = *ls;
  //
  //   // *ls += 0.5 * readPos; // adds delay to sample
  //   // *rs += 0.5 * readPos + 1;
  //   *ls = *ls + 0.5 * *readPos; // add delay at amp=1 to sample
  //   // *rs += readPos + 1;
  //
  //   // ls++;
  //   ls += 2;
  //   // rs += 2;
  //   readPos = (readPos >= (96000 - 1)) ? &delayBuffer : readPos + 1;
  //   // readPos = (readPos >= (pcm_param.size - 2)) ? 0 : readPos + 2;
  //   writePos = (writePos >= (96000 - 1)) ? &delayBuffer : writePos + 1;
  //   // writePos = (writePos >= (pcm_param.size - 2)) ? 0 : writePos + 2;
  // }

}

void revertSample(AsPcmDataParam pcm_param)
{
  /*for 16bit PCM */

  // static const int PeakLevel = 32700;
  static const int LevelGain = 1;

  // get physical address of sample
  // interleaved frame samples: LRLRLRLRLR...
  int16_t *ls = (int16_t*)pcm_param.mh.getPa(); // left
  int16_t *rs = ls + 1; // right

  int16_t *start = ls;
  int16_t *end = ls + pcm_param.size - 2; // 2 for interleaved samples

  static int16_t ls_l = 0;
  static int16_t rs_l = 0;

  if (!ls_l && !rs_l)
  {
    ls_l = *ls * LevelGain;
    rs_l = *rs * LevelGain;
  }

  for (uint32_t cnt = 0; cnt < pcm_param.size; cnt += 4) // iterate through entire Sample
  {
    int temp = *end;
    if (start < end)
    {
      *end = *start;
      *start = temp;
    }
    start += 2;
    end += 2;
  }
}

/**
   @brief RC-Filter function

   @param [in] pcm_param    AsPcmDataParam type
*/
void rc_filter(AsPcmDataParam pcm_param)
{
  /* Example : RC filter for 16bit PCM */

  static const int PeakLevel = 32700;
  static const int LevelGain = 2;

  int16_t *ls = (int16_t*)pcm_param.mh.getPa();
  int16_t *rs = ls + 1;

  static int16_t ls_l = 0;
  static int16_t rs_l = 0;

  if (!ls_l && !rs_l)
  {
    ls_l = *ls * LevelGain;
    rs_l = *rs * LevelGain;
  }

  for (uint32_t cnt = 0; cnt < pcm_param.size; cnt += 4)
  {
    int32_t tmp;

    *ls = *ls * LevelGain;
    *rs = *rs * LevelGain;

    tmp = (ls_l * 98 / 100) + (*ls * 2 / 100);
    *ls = clip(tmp, PeakLevel);
    tmp = (rs_l * 98 / 100) + (*rs * 2 / 100);
    *rs = clip(tmp, PeakLevel);

    ls_l = *ls;
    rs_l = *rs;

    ls += 2;
    rs += 2;
  }
}

/**
   @brief Distortion(Peak-cut)-Filter function

   @param [in] pcm_param    AsPcmDataParam type
*/
void distortion_filter(AsPcmDataParam pcm_param)
{
  /* Example : Distortion filter for 16bit PCM */

  static const int PeakLevel = 170;

  int16_t *ls = (int16_t*)pcm_param.mh.getPa();
  int16_t *rs = ls + 1;

  for (uint32_t cnt = 0; cnt < pcm_param.size; cnt += 4)
  {
    int32_t tmp;

    tmp = *ls * 4 / 3;
    *ls = clip(tmp, PeakLevel);
    tmp = *rs * 4 / 3;
    *rs = clip(tmp, PeakLevel);

    ls += 2;
    rs += 2;
  }
}

/**
   @brief clip function

   @param [in] val   source value
   @param [in] peak  clip point value
*/
inline int16_t clip(int32_t val, int32_t peak)
{
  return (val > 0) ? ((val < peak) ? val : peak) : ((val > (-1 * peak)) ? val : (-1 * peak));
}

/**
   @brief Setup Recorder

   Set input device to Mic <br>
   Initialize recorder to encode stereo wav stream with 48kHz sample rate <br>
   System directory "/mnt/sd0/BIN" will be searched for SRC filter (SRC file)
   Open "Sound.wav" file <br>
*/

void setup()
{
  // init delay buffer
  memset(delayBuffer, 0, delay_time);

  /* Initialize memory pools and message libs */

  initMemoryPools();
  createStaticPools(MEM_LAYOUT_RECORDINGPLAYER);

  /* start audio system */

  theRecorder = MediaRecorder::getInstance();
  thePlayer = MediaPlayer::getInstance();
  theMixer  = OutputMixer::getInstance();

  theRecorder->begin();
  thePlayer->begin();

  puts("initialization MediaRecorder, MediaPlayer and OutputMixer");

  theMixer->activateBaseband(); // activates audio HW ?? must be called to sound

  /* Create Objects */

  thePlayer->create(MediaPlayer::Player0, attention_cb);
  theMixer->create(attention_cb);

  /* Activate Objects. Set output device to Speakers/Headphones */

  theRecorder->activate(AS_SETRECDR_STS_INPUTDEVICE_MIC, mediarecorder_done_callback);
  thePlayer->activate(MediaPlayer::Player0, AS_SETPLAYER_OUTPUTDEVICE_SPHP, mediaplayer_done_callback);
  theMixer->activate(OutputMixer0, outputmixer_done_callback);

  usleep(100 * 1000);

  /*
     Initialize recorder to decode stereo wav stream with 48kHz sample rate
     Search for SRC filter in "/mnt/sd0/BIN" directory
  */

  theRecorder->init(AS_CODECTYPE_LPCM, AS_CHANNEL_STEREO, AS_SAMPLINGRATE_16000, AS_BITLENGTH_16, AS_BITRATE_8000);
  // theRecorder->init(AS_CODECTYPE_LPCM, AS_CHANNEL_MONO, AS_SAMPLINGRATE_48000, AS_BITLENGTH_16, AS_BITRATE_8000); // working
  // theRecorder->init(AS_CODECTYPE_LPCM, AS_CHANNEL_MONO, AS_SAMPLINGRATE_96000, AS_BITLENGTH_16, AS_BITRATE_192000); // working
   // theRecorder->init(AS_CODECTYPE_WAV, AS_CHANNEL_MONO, AS_SAMPLINGRATE_192000, AS_BITLENGTH_16, AS_BITRATE_384000);
  puts("recorder init");
  thePlayer->init(MediaPlayer::Player0, AS_CODECTYPE_WAV, AS_SAMPLINGRATE_16000, AS_CHANNEL_STEREO);
  // thePlayer->init(MediaPlayer::Player0, AS_CODECTYPE_WAV, AS_SAMPLINGRATE_48000, AS_CHANNEL_MONO);
  puts("player init");

  theMixer->setVolume(0, 0, 0);
}

/**
   @brief Record audio frames
*/

typedef enum
{
  StateReady = 0,
  StateRun,
} State;

void loop()
{
  static State s_state = StateReady;

  if (s_state == StateReady)
  {
    /* Prestore audio dummy data to start player */

    memset(s_buffer, 0, sizeof(s_buffer));
    thePlayer->writeFrames(MediaPlayer::Player0, s_buffer, sizeof(s_buffer));

    /* Start play */

    thePlayer->start(MediaPlayer::Player0, mediaplayer_decode_callback);
    puts("player start");

    s_state = StateRun;
  }
  else if (s_state == StateRun)
  {
    /* Get recorded data and play */

    uint32_t read_size = 0;

    do
    {
      theRecorder->readFrames(s_buffer, sc_buffer_size, &read_size);

      if (read_size > 0)
      {
        thePlayer->writeFrames(MediaPlayer::Player0, s_buffer, read_size);
      }
    }
    while (read_size != 0);
  }
  else
  {
  }

  if (ErrEnd)
  {
    printf("Error End\n");
    goto exitRecording;
  }

  usleep(1);

  return;

exitRecording:

  thePlayer->stop(MediaPlayer::Player0);
  theRecorder->stop();

  puts("Exit.");

  exit(1);
}
