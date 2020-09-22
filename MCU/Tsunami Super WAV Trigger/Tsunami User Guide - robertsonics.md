[Tsunami User Guide – robertsonics](http://robertsonics.com/tsunami-user-guide/)

> ### .Introduction
> 
> Tsunami is an advanced polyphonic embedded audio player, capable of playing 44.1kHz, 16-bit mono or stereo .wav files (tracks) from an on-board microSD card. Depending on whether it is running in mono or stereo mode, it can play up 18 stereo or 32 mono tracks independently and simultaneously, mixing them to any of either 4 stereo or 8 mono line-level audio outputs. Up to 4096 tracks can be indexed and started with low latency (typically 8ms) using either 16 programmable trigger inputs, a serial control port or a dedicated MIDI port.
> 
> There are many ways to use Tsunami:
> 
> **Standalone:** Using the programmable trigger inputs it’s possible to create a complete multi-channel audio delivery system with nothing more than Tsunami and some buttons. Triggers can be programmed to start, pause, resume, stop or loop individual tracks, sequential or random ranges of tracks, even control volume. You can even play 5.1 or 7.1 surround content with a single trigger input.
> 
> **With another microcontroller such as an Arduino:** A serial control port along with a rich serial control protocol, provides a way to access all 4096 tracks and take advantage of Tsunami’s internal faders to do real-time mixing, crossfading and pitch bending. An Arduino Serial Control Library makes it easy to access all of Tsunami’s features from within your Arduino Sketch.
> 
> **MIDI:** Tsunami’s dedicated MIDI port makes it easy to connect your MIDI keyboard or controller. Tsunami supports MIDI Note-On, Note-Off, Pitch Bend and Program Changes messages, as well as Controller messages for real-time control of sustain, attack and release times and volume. A voice-stealing algorithm means that new notes always play even if you run out of voices.
> 
> Tsunami’s programmable features are controlled by an optional “.ini” file stored on the microSD card and read during a reset. While this file is human-readable text, a Tsunami Configurator utility (Windows, Mac and Linux versions available), makes it easy to set options and generate this file. See sections below on how to use the Configurator.
> 
> ### 2.Electrical
> 
> Tsunami can be powered either with 5 – 15VDC applied to the VIN/GND header or through the onboard USB Micro-B connector.
> 
> IMPORTANT: Tsunami is 3.3V device and the Atmel SAM S70 processor’s inputs are not 5V tolerant! Please keep this in mind when you connect signals from other powered devices, such as Arduinos and gate signals from modular synths.
> 
> ### 3.Wav Files and Tracks
> 
> Tsunami plays “.wav” files stored on a FAT16 or FAT32 formatted microSD card. (Most microSD cards are already formatted so reformatting is typically not necessary.) You might think that the latest, fastest SD cards would be best, but that’s not always the case. Please review [this page](https://robertsonics.com/microsd-cards-for-audio/) to fully understand the issues, but as a general rule, speed class 4 or 10, non-UHS cards work best.
> 
> Tsunami firmware currently comes in 2 versions: Mono and Stereo. The mono version _requires_ 16-bit, 44.1kHz mono .wav files, while the stereo version _requires_ 16-bit, 44.1kHz stereo .wav files. Both versions also _require_ that there be no meta-data (tags) prior to the start of the audio in the file. If these rules are not met, the file will simply not be played.
> 
> The easiest way to ensure proper formatting is by using the free audio editor Audacity to save your Tsunami .wav files.
> 
>   
>  
> 
> Tsunami indexes the .wav files into track numbers based on the filename. In order to be recognized by Tsunami, .wav file names must begin with a number between 1 and 4096. This number can be from 1 to 4 digits and leading 0’s are not required. Additionally, and only for use with MIDI, if the track number is immediately followed with “\_FN”, where F = “L” or “S” and N = 1 – 8, this will specify whether the track is to be looped and what output it should be routed to. If the “\_FN” is omitted, then the track will not loop (single-shot) and will be routed to output 1. Again, this “\_FN” field is only used when the track is started with a MIDI Note-On command.
> 
> The remainder of the filename does not matter and long filenames are allowed.
> 
> The following are examples of valid filenames and their meaning:
> 
> _1-Music Loop 21.wav_:  Track 1
> 
> _438\_Barking Dog.wav_:  Track 438
> 
> _0101\_L3 Violin A3.wav_:  Track 101, when triggered by MIDI will loop and appear on output 3
> 
> _4096\_S4 Flute B3.wav_:  Track 4096, when trigger by MIDI will not loop and appear on output 4
> 
> All .wav files must be located in the root directory of the microSD card.
> 
> Anytime the microSD card is removed and re-inserted, Tsunami must be either reset or power-cycled. This is because it reads the init file (see below) and indexes all the tracks only when reset.
> 
> Some things to keep in mind when planning your track numbering: The default behavior of the trigger inputs is to start the corresponding track, e.g. Trigger 1 plays Track 1, Trigger 2 plays Track 2 and so on. A Trigger Bank feature allows you to shift the trigger tracks up by increments of 16, so while the default trigger tracks are 1 – 16, Trigger Bank 1 maps them to Tracks 17 – 32, Trigger Bank 2 maps them to Tracks 33 – 48, and so on.
> 
> When using MIDI, Tsunami maps MIDI Note number to track number, so MIDI Notes 1 – 128 map to Tracks 1 – 128. Similarly, a MIDI Bank feature shifts offsets the track number by 128, so MIDI Bank 1 maps MIDI Notes 1 – 128 to Tracks 129 – 256, and so on up to MIDI Bank 32. The MIDI Bank can be incremented and decremented either with trigger inputs or the MIDI Program Change message.
> 
> When using serial control, it’s easy to control any track directly by it’s track number so the numbering scheme is more just a matter of personal preference.
> 
> ### 4.Polyphony
> 
> Unlike most other embedded audio players, Tsunami is “polyphonic”. This means that it can play more than one track at a time. It does this by maintaining multiple file pointers and digitally mixing the tracks to Tsunami outputs. When operating in polyphonic mode, tracks can be started at any time, regardless of whatever tracks may be playing, including other copies of the same track (depending on the settings). The only limit is the number of “voices” – the number of separate tracks that can be played at any given moment. Currently, Tsunami provides 18 low-latency stereo voices or 32 low-latency mono voices.
> 
> Polyphony can make things quite complex, and it’s important to understand the various options so that you can achieve the results you want.
> 
> Polyphony also affects how you handle volume. If you mix 4 tracks together that are all full-scale volume, the result will be clipped and distorted. In this case, it won’t help to lower the output gain setting since this only affects the final output stage – you’ll just lower the volume of an already clipped mix. You must reduce the volume of the .wav files themselves so that the resulting addition of the tracks does not clip
> 
> ### 5.Configurator
> 
> Tsunami has a number of options that can be set through the use of an Init file – a text file placed on the microSD card along with the .wav files. Tsunami Configurator is an application that allows you to set these options using a graphical user interface, and will then create the Init file for you. The Init file is still a text file and can be created and/or edited by hand, but Configurator makes this process much easier and less prone to error.
> 
> To be recognized by Tsunami, the Init file must be named “tsunami.ini” and be placed in the root directory of the microSD card.
> 
> An Init file is only required if you want to change a default behavior, and the only entries that are required are for options that are not default.
> 
> [![](https://robertsonics.com/wp-content/uploads/2017/01/Configurator.jpg)](https://robertsonics.com/wp-content/uploads/2017/01/Configurator.jpg)
> 
> The following discussion of Tsunami’s options assumes that you’ll be using the Configurator app to create an Init file.
> 
> ### 5.1.Global Options
> 
> **Serial Baudrate:** This sets the baudrate for the async serial port. This baudrate will remain in effect until the next power cycle. The default is 57.6kbps.
> 
> **Mode:** This selects either mono or stereo mode and should be set to match the version of firmware you are using in Tsunami. It simply adjusts the number of outputs available, which are arranged as either 8 mono or 4 stereo. The mono version also includes a trigger function to start a pair of tracks in adjacent outputs as a way of playing stereo content.
> 
> **Output N Volume:** These sliders set the initial volume applied to the final mix of tracks mixed to the corresponding output. These values can be overridden by a volume command. The range is -70dB to +10dB, and the default value is 0dB (unity gain). This gain affects the final output mix for that output, not the individual tracks that make up the mix.
> 
> ### 5.2.Trigger Options
> 
> Trigger options are set by first selecting the trigger number in the Trigger combo box. If there’s already an entry for that trigger in the Init file, the options will indicate the current values for that entry. If there is no entry for that trigger, the options will reset to default. Using the “Save” or “Update” buttons will create or update an entry in the Init file for that trigger. Once saved, trigger settings may be transferred to Tsunami over the serial port (if it is connected) using the “Test” button. This allows you to easily test the effect of changing options without having to deal with writing the init file, transferring the microSD card and resetting Tsunami.
> 
> Not all trigger functions support all options. For example, the Next, Previous and Random functions are inherently edge triggered type functions, so the “Type” field defaults to “Edge” and is disabled for these functions.
> 
> **Hardware Interface:** The “Contact Closure” option enables an internal pull-up for the trigger input so that with nothing connected, the trigger input is “high”. When combined with the non-inverted (default) option, a contact closure (button or switch) to ground will pull the trigger input low and activate the trigger. The “Active – 3.3V” options disables the internal pull-up for the trigger, requiring either an external 3.3V signal to bring the input “high”. This allows the trigger to be driven with the digital output of another micro controller. The invert option will control whether the trigger will be activated on a low or high signal level.
> 
> Please note that you should never select “Active – 3.3V” option without having an active signal connected to the trigger. With nothing connected, the trigger input is floating and will produce false and random triggers. Similarly, you should never apply 3.3V to a trigger without first setting it to “Active – 3.3V”.
> 
> **Type:** This option affects only certain trigger functions. For the “Normal” trigger function, “Edge Triggered” starts the track when the trigger first goes active, and the track continues to play until stopped by some other event. “Level Triggered” starts the track when the trigger goes active, but the track plays only as long as the trigger remains active. When combined with the “Stop” function, “Level Triggered” will prevent one or more tracks from starting as long as it remains active, creating an “inhibit” function. “Latched” will activate on a transition but remain active as if it was level type. Another trigger is required to stop any action that is started by a “Latched” type trigger.
> 
> **Function:** This option selects the function that the trigger will perform. Some of the functions require that a range of tracks be specified, and the values in the range can be from 1 to 999. The high value must be equal to or greater than the low value.
> 
> “Normal”, the default function, directs Tsunami to play the corresponding track number. The track range is not used. Combining with the “Level Triggered” type option will make the trigger act like a MIDI Note On, causing the track to play only as long as the trigger remains active.
> 
> “Next” plays the next track in the specified range, starting with the low track and wrapping back to that track after playing the high track in the range.
> 
> “Previous” plays the previous track in the specified range, starting with the highest track and wrapping back to that track after playing the lowest track in the range.
> 
> “Random” plays a random track from the specified range. The only rule imposed is that it will not play the same track twice in a row.
> 
> “Pause” will pause all the tracks in the specified range. These tracks will remain paused until they are resumed or restarted. Combining with the “Level Triggered” type option creates a momentary Pause feature; the specified tracks will resume when the trigger is released.
> 
> “Resume” will resume all the tracks in the specified range, provided that they are still “paused”.
> 
> “Stop” will stop all the tracks in the specified range. Combining with the “Level Triggered” type option will create a “Stop and Inhibit” function, preventing all the tracks in the range from restarting as long as the trigger remains active. (Triggers that would have otherwise started an “inhibited” track are ignored, not queued.)
> 
> “Volume Up” or Volume Dn” will re-purpose the trigger to be a volume control. Each activation of the trigger will increase or decrease the output stage volume of Tsunami by 1dB.
> 
> “MIDI Bank Up” or MIDI Bank Dn” will re-purpose the trigger to increment or decrement the MIDI Bank number. Each MIDI Bank maps MIDI note numbers 1 through 128 to the next bank of 128 track numbers.
> 
> “Trigger Bank Up” or Trigger Bank Dn” will re-purpose the trigger to increment or decrement the Trigger Bank number. Each Trigger Bank maps the normal function triggers to the next bank of 16 track numbers.
> 
> “Synced Set” is available only when running Tsunami’s mono firmware version, and will start up to 8 tracks, specified in the track range fields, routing the “Low” track to the specified output and subsequent tracks to the next sequential outputs; The tracks will start and stay sample-locked, enabling you to use one trigger to play stereo or even 5.1 or 7.1 surround content.
> 
> **Invert:** This check box will invert the logic of the trigger. The default is active low. Checking this option makes the trigger active high.
> 
> **Re-Triggers:** This option enables certain trigger functions to work again immediately while the track(s) that they may have previously started is (are) still playing. For example, with the “Normal” trigger function, enabling this option allows the trigger restart the corresponding track even if it has not finished playing, while disabling this option prevents the trigger from working until the track has finished playing (or is stopped by some other event.) Similarly, for the “Next”, “Previous” and “Random” functions, disabling this option prevents the trigger from working until whatever track was previously started from this trigger is finished.
> 
> Re-Triggers is enabled by default.
> 
> **Polyphonic:** This option specifies that the track played by the trigger function (for those functions that play tracks) should be mixed with any track(s) currently playing. When this option is disabled, activating the trigger will stop any and all tracks that are currently playing before the new track is started.
> 
> **Loop:** This option, when enabled, will cause the track to loop continuously regardless of the state of any trigger which may have started it. Tsunami loops tracks seamlessly over the length of the loop. The sample frame immediately following the last sample in the file will be the first sample frame in the file.
> 
> **Lock Voice:** This option allows you to specify that the track will not be subject to Tsunami’s voice stealing algorithm. This allows you, for example, to use a trigger to start a backing track, and play MIDI notes on top of it without risk of the backing track being stopped because you played too many notes for the available number of voices.
> 
> **Output:** Any and all tracks started by this trigger will be routed to this output. In mono mode you can select outputs 1 – 8, while in stereo mode you can select stereo pairs 1 – 4.
> 
> ### 5.3.MIDI Options
> 
> **Channel:** This sets the MIDI Channel number that Tsunami responds to. Omni, the default, means that Tsunami will ignore the MIDI Channel number and respond to all MIDI messages.
> 
> **Pitch Bend Semitones:** This sets the number of semi-tones up, and down, corresponding to full scale Pitch Bend messages.
> 
> **Default Release:** This slider sets the default release time for sounds which are stopped with a MIDI Note-Off command. It can be overridden using MIDI Controller messages as described in the MIDI implementation below.
> 
> **Ignore Velocity:** When checked, this tells Tsunami to ignore the MIDI Note-On velocity value and play all tracks started with MIDI at full volume.
> 
> **Ignore Note-Offs:** When check, this tells Tsunami to ignore all MIDI Note-Off commands. Useful if you simply want to use a MIDI Controller to start tracks but not stop them.
> 
> ### 6.Serial Control
> 
> The bidirectional asynchronous serial port can be used to control and monitor Tsunami’s operation. The default baudrate is 57.6kbps, but this can be changed by placing the appropriate entry in the init file using the Configurator.
> 
> If you’re going to be using Tsunami with an Arduino, there’s an easy to use [Tsunami Serial Control Library](https://github.com/robertsonics/Tsunami-Arduino-Serial-Library) that will handle all of the serial protocol for you. If you’re going to be writing your own serial control code, you still may want to review the library since the source is available and it’s written in C.
> 
> All messages **to** Tsunami start with the same 2-byte Start-of-Message (SOM) header, followed by a byte indicating the total number of bytes in the message. Next is a 1-byte message code in the range of 0x00 to 0x7f, followed by a number of bytes of data specific to the message. Immediately following the last data byte is an End-of-Message (EOM) byte.
> 
> All message **from** Tsunami are formatted the same way. The only difference is that the message codes are in the range of 0x80 to 0xff.
> 
> 16-bit data values such as track number and volume are sent “little-endian”, that is with the LSB first and the MSB second.
> 
> Message format: ( SOM1, SOM2, length, message code, data \* n , EOM ),  where SOM1=0xf0,  SOM2=0xaa,  EOM=0x55
> 
> ### 6.1.Commands TO Tsunami
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (0)
> 
> Response
> 
> CommandGET\_VERSION
> 
> Code0x01
> 
> Length5
> 
> Data Bytes (0)none
> 
> ResponseVERSION\_STRING
> 
> Requests Tsunami to transmit the VERSION\_STRING message
> 
> Example: 0xf0, 0xaa, 0x05, 0x01, 0x55
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (0)
> 
> Response
> 
> CommandGET\_SYS\_INFO
> 
> Code0x02
> 
> Length5
> 
> Data Bytes (0)none
> 
> ResponseSYSINFO
> 
> Request Tsunami to transmit the SYS\_INFO message
> 
> Example: 0xf0, 0xaa, 0x05, 0x02, 0x55
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (1)
> 
> Response
> 
> CommandSET\_REPORTING
> 
> Code0x0d
> 
> Length6
> 
> Data Bytes (1)Reporting state = 0/1
> 
> Responsenone
> 
> Enable/disable asynchronous serial reporting of track status. See TRACK\_REPORT in the next section.
> 
> Example: 0xf0, 0xaa, 0x06, 0x0d, 0x01, 0x55  Enables reporting
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (5)
> 
> Response
> 
> CommandCONTROL\_TRACK
> 
> Code0x03
> 
> Length10
> 
> Data Bytes (5)Control Code (see below)
> 
> Responsenone
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (5)Track Number LSB
> 
> Response
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (5)Track Number MSB
> 
> Response
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (5)Output (0 - 7)
> 
> Response
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (5)Flags (see below)
> 
> Response
> 
> Send one of the following Track Control Code to a specific track number.
> 
> Track Control Codes:
> 
> TRK\_PLAY\_SOLO = 0x00:
> 
> TRK\_PLAY\_POLY = 0x01;
> 
> TRK\_PAUSE = 0x02;
> 
> TRK\_RESUME = 0x03
> 
> TRK\_STOP = 0x04
> 
> TRK\_LOOP\_ON = 0x05
> 
> TRK\_LOOP\_OFF = 0x06
> 
> TRK\_LOAD = 0x07
> 
> Output: Specifies either stereo (0 – 3) or mono output (0 – 7) for this track.
> 
> Flags: Bit 0: Voice Lock flag. If 1, prevents voice from being stolen for MIDI notes.
> 
> Example: 0xf0, 0xaa, 0x0a, 0x03, 0x01, 0x07, 0x00, 0x03, 0x01, 0x55  Plays track 7 polyphonically to output 4, voice locked.
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (0)
> 
> Response
> 
> CommandSTOP\_ALL
> 
> Code0x04
> 
> Length5
> 
> Data Bytes (0)none
> 
> Responsenone
> 
> Stop all tracks.
> 
> Example: 0xf0, 0xaa, 0x05, 0x04, 0x55
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (3)
> 
> Response
> 
> CommandOUTPUT\_VOLUME
> 
> Code0x05
> 
> Length8
> 
> Data Bytes (3)Output (0 - 7)
> 
> Responsenone
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (3)Gain LSB
> 
> Response
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (3)Gain MSB
> 
> Response
> 
> Set the gain of one of the audio output. Gain values are in dB and range from -70 to +10.
> 
> This adjust the gain of the post mix of all the tracks playing to this output. It does not reduce the pre-mix volume of the individual tracks. If the result of mixing the tracks causes clipping, then reducing the output volume will not fix the clipping. You would need to use the Track Volume command to reduce the gain of the tracks prior to mixing. Think of the output gain as an output buss level.
> 
> Example: 0xf0, 0xaa, 0x08, 0x05, 0x01, 0xf6, 0xff, 0x55  Sets the gain of output 2 to -10dB
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (4)
> 
> Response
> 
> CommandTRACK\_VOLUME
> 
> Code0x08
> 
> Length9
> 
> Data Bytes (4)Track LSB
> 
> Responsenone
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (4)Track MSB
> 
> Response
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (4)Gain LSB
> 
> Response
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (4)Gain MSB
> 
> Response
> 
> Set the gain of the specified track. Gain values are in dB and range from -70 to +10.
> 
> This adjusts the gain of an individual track prior to mixing to the output. If you are playing many tracks to one output, you may need to reduce the gain of each track to avoid clipping in the output mix buffer.
> 
> The change in gain is applied smoothly over one audio buffer (about 3ms) to avoid distortion, but is otherwise immediate. If you want to smoothly ramp the volume up or down over time, use the TRACK\_FADE command instead.
> 
> Example: 0xf0, 0xaa, 0x09, 0x08, 0x01, 0x00, 0xf6, 0xff, 0x55  Sets the gain of track 1 to -10dB
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (7)
> 
> Response
> 
> CommandTRACK\_FADE
> 
> Code0x0a
> 
> Length12
> 
> Data Bytes (7)Track LSB
> 
> Responsenone
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (7)Track MSB
> 
> Response
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (7)Gain LSB
> 
> Response
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (7)Gain MSB
> 
> Response
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (7)Milliseconds LSB
> 
> Response
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (7)Milliseconds MSB
> 
> Response
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (7)Stop Flag = 0/1
> 
> Response
> 
> Fade (up or down) a track to a target gain from the current level in the specified number of milliseconds, with an option to stop the track at the end of the fade.
> 
> Target gain is specified in dB and range is from -70 to +10. If Stop Flag = 1, the track will stop at the end of the fade. This is most useful for implementing a fade out, since Tsunami will automatically stop the track and release the voice at the end of the fade out.
> 
> Example: 0xf0, 0xaa, 0x0c, 0x0a, 0x02, 0x00, 0xc8, 0xff, 0xe8, 0x03, 0x01, 0x55  Fade track 2 to -50dB in 1000ms and stop.
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (0)
> 
> Response
> 
> CommandRESUME\_ALL\_SYNC
> 
> Code0x0b
> 
> Length5
> 
> Data Bytes (0)none
> 
> Responsenone
> 
> Resume all paused tracks
> 
> Example: 0xf0, 0xaa, 0x05, 0x0b, 0x55
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (3)
> 
> Response
> 
> CommandOUTPUT\_SAMPLERATE\_OFFSET
> 
> Code0x0c
> 
> Length8
> 
> Data Bytes (3)Output (0 - 7)
> 
> Responsenone
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (3)Offset LSB
> 
> Response
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (3)Offset MSB
> 
> Response
> 
> Set the sample rate offset for the specified output.
> 
> Each of Tsunami’s outputs can support it’s own vari-speed control. The offset value ranges from -32768, corresponding to 1/2X speed (one octave pitch shift down), to +32767, corresponding to 2X speed (one octave pitch shift up.)
> 
> Example: 0xf0, 0xaa, 0x08, 0x0c, 0x00, 0x5a, 0x1f, 0x55  Set output 1 to pitch up 2 semitones.
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (1)
> 
> Response
> 
> CommandSET\_TRIGGER\_BANK
> 
> Code0x0e
> 
> Length6
> 
> Data Bytes (1)Bank number (1 - 32)
> 
> Responsenone
> 
> Set the trigger bank.
> 
> Example: 0xf0, 0xaa, 0x06, 0x0e, 0x04, 0x55 Sets the trigger bank to 4
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (1)
> 
> Response
> 
> CommandSET\_INPUT\_MIX
> 
> Code0x0f
> 
> Length6
> 
> Data Bytes (1)Output mask (0x0m)
> 
> Responsenone
> 
> Set the input routing mix.
> 
> The lowest 4 bits of the mask correspond to the 4 output pairs. A “1” in the position will enable the audio input to be mixed to the corresponding output pair.
> 
> Example: 0xf0, 0xaa, 0x06, 0x0f, 0x05, 0x55 Audio input pair is mixed to output pairs 1 and 3
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (1)
> 
> Response
> 
> CommandSET\_MIDI\_BANK
> 
> Code0x10
> 
> Length6
> 
> Data Bytes (1)Bank number (1 - 32)
> 
> Responsenone
> 
> Set the MIDI bank.
> 
> Example: 0xf0, 0xaa, 0x06, 0x10, 0x0a, 0x55 Sets the MIDI bank to 10
> 
> ### 6.2.Command FROM Tsunami
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (22)
> 
> CommandVERSION\_STRING
> 
> Code0x81
> 
> Length27
> 
> Data Bytes (22)ASCII Version String
> 
> Sent in response to a GET\_VERSION command. Contains the current Tsunami firmware version string.
> 
> Example: 0xf0, 0xaa, 0x1b, 0x81, “Tsunami v0.44m (c)2016”, 0x55
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (3)
> 
> CommandSYSINFO
> 
> Code0x82
> 
> Length8
> 
> Data Bytes (3)Number of Voices
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (3)Number of Tracks LSB
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (3)Number of Tracks MSB
> 
> Sent in response to a GET\_SYSINFO command. Contains the maximum number of voices in the current firmware and the total number of tracks found on the installed SD card.
> 
> Example: 0xf0, 0xaa, 0x08, 0x82, 0x20, 0xc4, 0x09, 0x55  Tsunami reports 32 Voices and 2500 Tracks found on SD card
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (4)
> 
> CommandTRACK\_REPORT
> 
> Code0x83
> 
> Length9
> 
> Data Bytes (4)Track Number LSB
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (4)Track Number MSB
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (4)Voice
> 
> Command
> 
> Code
> 
> Length
> 
> Data Bytes (4)State = 0/1
> 
> When Track Reporting is enabled using the SET\_REPORTING command, Tsunami sends this message every time a track starts or stops.
> 
> Example: 0xf0, 0xaa, 0x09, 0x84, 0x10, 0x00, 0x07, 0x01, 0x55  Tsunami reports Track 16 started using Voice 7
> 
> ### 7.MIDI Implementation
> 
> Tsunami has a dedicated MIDI port and can act as a low-latency, velocity-sensitive, polyphonic sample player when used with a MIDI controller. It supports both channel assigned and Omni modes of operation, and implements an internal MIDI Bank Number that allows for mapping MIDI’s 128 note numbers to alternate groups of track numbers – see below. Also, a filename option routes individual MIDI Notes to any one of the Tsunami’s outputs, making it possible to split your keyboard across multiple outputs. See the “Wave Files and Tracks” section above.
> 
> Tsunami responds to MIDI Pitch Bend with an adjustable pitch range (in semitones), and provides MIDI Control Change support for adjustable attack and release times, as well as sustain.
> 
> MIDI Implementation:
> 
> **Note-On**
> 
> Starts track number T, where T = (MIDI Bank Number \* 128) + MIDI Note Number.
> 
> The final volume is scaled by the MIDI Velocity, where a velocity value of 127 = 0dB (full volume). If the MIDI Attack time is great than 0, the volume will ramp up to the target value over the specified attack time.
> 
> The MIDI Bank Number can be changed by using the MIDI Program Change message (see below) or by using the increment/decrement MIDI Bank trigger functions.
> 
> The attack time can be set either with the ini file or changed dynamically using a MIDI Control Change message (see below)
> 
> **Note-Off**
> 
> If the “Ignore MIDI Note Off” option is not set, then track T (as calculated above) will be stopped. If the MIDI Release Time is greater than 0, then the volume will ramp down over the specified release time.
> 
> The release time can be set either with the ini file or changed dynamically using a MIDI Control Change message (see below)
> 
> **Pitch Bend**
> 
> All of the tracks playing to output N will be pitched up or down by an amount determined by the Pitch Bend Semitones set in the ini file (default is 2 semitones), where N = MIDI Channel Number. In other words, Pitch Bend on MIDI Channel 1 will control the pitch of output 1, Pitch Bend on MIDI Channel 2 will control the pitch of output 2, and so on.
> 
> **Program Change**
> 
> Program change will set the current MIDI Bank Number to the new program value.
> 
> **Control Change**
> 
> CC#1: Release time (0 – 2000ms)
> 
> CC#7: Volume Output 1
> 
> CC#20: Volume Output 1  
> CC#21: Volume Output 2  
> CC#22: Volume Output 3  
> CC#23: Volume Output 4  
> CC#24: Volume Output 5  
> CC#25: Volume Output 6  
> CC#26: Volume Output 7  
> CC#27: Volume Output 8
> 
> CC#73: Attack Time (0 – 2000ms)
> 
> CC#72: Release Time (0 – 2000ms)
> 
> CC#64: Sustain
> 
> CC#123: All-Notes-Off, reset pitch
> 
> **Real Time**
> 
> Stop (0xfc): All-Notes-Off, reset pitch
> 
> ### 8.Updating the Firmware
> 
> Tsunami has a resident boot loader that can update the firmware directly from the microSD card. Use the following procedure to update the firmware in your Tsunami:
> 
> 1.  [Download the desired](https://robertsonics.com/tsunami-downloads/) version and unzip to a .hex file.
> 2.  Copy the hex file to a microSD card and then rename the copy on the card to: “tsunamix.hex”
> 3.  Put the card into Tsunami and make sure Tsunami is powered.
> 4.  Press and hold the user button and then tap the reset button. Wait for Tsunami’s LED to go on solid.
> 5.  Release the user button and tap the reset button, or power-cycle the Tsunami.
> 6.  You should now be running the new firmware.
> 
> If Tsunami’s LED does anything other than go solid, here are the error codes:
> 
> -   1 long blink every 2 secs: No SD card found
> -   1 long blink, followed by 1 short blink: SD format error
> -   1 long blink, followed by 2 short blinks: Hex file error
> -   Continuous short blinks: Flash write error
