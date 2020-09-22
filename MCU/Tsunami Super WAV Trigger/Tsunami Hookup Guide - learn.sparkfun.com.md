> # Tsunami Hookup Guide
> 
> [≡ Pages](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all#)
> 
> Contributors: [![](https://static.sparkfun.com/avatar/d069e186dea25a3b82d74ef824716693?d=retro&s=20&r=pg) Byron J.](https://www.sparkfun.com/users/468760)
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 2
> 
> [Share](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all#)
> 
> Use this URL to share:  
> 
> [Share on Google+](https://plus.google.com/share?url=http%3A%2F%2Fsfe.io%2Ft622 "Share on Google+") [Share on Tumblr](https://www.tumblr.com/share/link?url=http%3A%2F%2Fsfe.io%2Ft622&name=Tsunami+Hookup+Guide "Share on Tumblr") [Submit to reddi](https://www.reddit.com/submit?url=http%3A%2F%2Fsfe.io%2Ft622 "Submit to reddit")
> 
> [Share on Twitter](https://twitter.com/intent/tweet?text=Tsunami+Hookup+Guide&url=http%3A%2F%2Fsfe.io%2Ft622&via=sparkfun "Share on Twitter") [Share on Facebook](http://www.facebook.com/sharer.php?u=http%3A%2F%2Fsfe.io%2Ft622&t=Tsunami+Hookup+Guide "Share on Facebook") [Pin It](https://www.pinterest.com/pin/create/button/?url=http%3A%2F%2Fsfe.io%2Ft622&media=https%3A%2F%2Fcdn.sparkfun.com%2F%2Fr%2F500-1000%2Fassets%2Flearn_tutorials%2F6%2F2%2F2%2F13810-01.jpg&description=Tsunami+Hookup+Guide "Pin It")
> 
> ## Introduction
> 
> Tsunami is the next-generation SparkFun polyphonic WAV file player.
> 
>  [![Tsunami Super WAV Trigger](https://cdn.sparkfun.com/r/500-500/assets/parts/1/1/3/9/6/13810-01.jpg)](https://www.sparkfun.com/products/13810) 
> 
>    
> 
> added to your [cart](https://www.sparkfun.com/cart)!
> 
> ### [Tsunami Super WAV Trigger](https://www.sparkfun.com/products/13810)
> 
> [23 available](https://learn.sparkfun.com/static/bubbles/ "23 available") WIG-13810
> 
> Based on a new generation ARM Cortex M7, the Tsunami extends polyphony to 32 mono or 18 stereo simultaneous uncompressed 44.1…
> 
> $79.95
> 
> 13
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 22
> 
> [Wish List](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to wish list")
> 
> Tsunami is a bigger, better brother to the [WAV Trigger](https://www.sparkfun.com/products/13660). It starts with the same polyphonic WAV file playback engine, then adds a bunch of new features.
> 
> -   First, Tsunami features eight analog outputs, which can be configured as either eight mono outputs or four stereo outputs.
>     -   In stereo mode, it can simultaneously play 18 stereo WAV files.
>     -   In mono mode, it can play back 32 mono WAV files.
>     -   Mono mode also offers a track synchronization option, which allows for playback of multichannel content, including quadrophonic, 5.1 and 7.1 surround formats.
> -   Tsunami also features a stereo audio input that can be mixed into any combination of the outputs.
> -   Each output provides independent, real-time volume control and pitch bend.
> -   WAV files can be independently mapped to outputs.
> -   Up to 4,096 WAV files can be indexed and played off a microSD card.
> -   Tracks can be triggered via three different interfaces.
>     -   There are 16 onboard inputs that can be tied to switches or logic-level devices.
>     -   The FTDI-compatible footprint allows serial control from a computer or microcontroller.
>     -   There are onboard MIDI input and output circuits --- just add DIN-5 sockets.
> -   Tsunami offers low latency. Tracks typically start within 8 mSec of a trigger event.
> -   Detailed track control --- tracks can start, pause, resume and stop, and loop seamlessly.
> -   Firmware can be easily loaded from the SD card, which facilitates switching between stereo and mono playback modes, as well as upgrading as new features are released.
> 
> Tsunami was developed in collaboration with [Robertsonics](http://robertsonics.com/). A portion of each sale goes back to them for product support and continued development.
> 
> This guide will show you how to start using Tsunami. We'll start by putting .WAV and configuration files on a microSD card, then pop it in Tsunami, then trigger sounds across multiple outputs.
> 
> ### Required Materials
> 
> To follow along with this project tutorial, you will need the following materials:
> 
> [**Tsunami Hookup Guide** SparkFun Wish List](https://www.sparkfun.com/wish_lists/135908)
> 
> [![](https://cdn.sparkfun.com/r/58-58/assets/parts/1/1/4/3/0/13833-02.jpg)microSD Card with Adapter - 16GB (Class 10)  COM-13833This is a class 10 16GB microSD memory card, perfect for housing operating systems for single board computers and a multitude of other information. Si…](https://www.sparkfun.com/products/13833)
> 
> [![](https://cdn.sparkfun.com/r/58-58/assets/parts/9/7/8/2/12890-01.jpg)Wall Adapter Power Supply - 5V DC 2A (USB Micro-B)  TOL-12890This is a high quality switching 'wall wart' AC to DC 5V 2000mA USB Micro-B wall power supply manufactured specifically for SparkFun Electronics. Thes…](https://www.sparkfun.com/products/12890)
> 
> [![](https://cdn.sparkfun.com/r/58-58/assets/parts/4/5/5/8/10215-01.jpg)USB micro-B Cable - 6 Foot  CAB-10215USB 2.0 type A to micro USB 5-pin. This is a new, smaller connector for USB devices. Micro USB connectors are about half the height of mini USB. Micro…](https://www.sparkfun.com/products/10215)
> 
> [![](https://cdn.sparkfun.com/r/58-58/assets/parts/7/1/0/8/11367-Hook-Up_Wire_-_Assortment__Solid_Core__22_AWG_-01.jpg)Hook-Up Wire - Assortment (Solid Core, 22 AWG)  PRT-11367An assortment of colored wires: you know it's a beautiful thing. Six different colors of solid core wire in a cardboard dispenser box. Sit this on you…](https://www.sparkfun.com/products/11367)
> 
> [![](https://cdn.sparkfun.com/r/58-58/assets/parts/7/5/4/6/11570-01.jpg)SparkFun TRRS 3.5mm Jack Breakout  BOB-11570TRRS connectors are the audio-style connectors that you see on some phones, MP3 players and development boards. TRRS stands for "Tip, Ring, Ring, Slee…](https://www.sparkfun.com/products/11570)
> 
> [![](https://cdn.sparkfun.com/r/58-58/assets/parts/3/4/1/00501-1.jpg)IC Hook Test Leads  CAB-00501These are various leaded cables for attaching to multimeters, power supplies, oscilloscopes, function generators, etc. 5 pairs of IC Hook to IC Hook t…](https://www.sparkfun.com/products/501)
> 
> [![](https://cdn.sparkfun.com/r/58-58/assets/parts/1/1/3/9/6/13810-01.jpg)Tsunami Super WAV Trigger  WIG-13810The Tsunami Super WAV Trigger is the next evolutionary step beyond the original \[WAV Trigger\](https://www.sparkfun.com/products/13660).Based on a new …](https://www.sparkfun.com/products/13810)
> 
> #### Tools
> 
> You will also need a microSD card reader and a set of headphones or multimedia speakers.
> 
> ### Suggested Reading
> 
> If you aren't familiar with the following concepts, we recommend checking out these tutorials before continuing.
> 
> -   Robertsonics has a more detailed [Tsunami page](http://robertsonics.com/tsunami/). If this SparkFun guide doesn't have the information you're looking for, check there.
> -   Robertsonics also releases a cross-platform utility for generating Tsunami configuration files and new firmware files. All of these can be downloaded from Robertsonics' [Tsunami downloads](http://robertsonics.com/tsunami-downloads/) page.
> 
> [
> 
> ### Analog to Digital Conversion
> 
> ](https://learn.sparkfun.com/tutorials/analog-to-digital-conversion)
> 
> The world is analog. Use analog to digital conversion to help digital devices interpret the world.
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 45
> 
> [
> 
> ### Switch Basics
> 
> ](https://learn.sparkfun.com/tutorials/switch-basics)
> 
> A tutorial on electronics' most overlooked and underappreciated component: the switch! Here we explain the difference between momentary and maintained switches and what all those acronyms (NO, NC, SPDT, SPST, ...) stand for.
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 42
> 
> [
> 
> ### Analog vs. Digital
> 
> ](https://learn.sparkfun.com/tutorials/analog-vs-digital)
> 
> This tutorial covers the concept of analog and digital signals, as they relate to electronics.
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 50
> 
> [
> 
> ### MIDI Tutorial
> 
> ](https://learn.sparkfun.com/tutorials/midi-tutorial)
> 
> Understanding the Musical Instrument Digital Interface.
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 19
> 
> ## Hardware Overview
> 
> The Tsunami board has the following features and interfaces.
> 
> [![alt text](https://cdn.sparkfun.com/r/600-600/assets/learn_tutorials/6/2/2/callouts.png)](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/callouts.png)
> 
> _Major Tsunami Subsystems._
> 
> -   **MicroSD card slot.** We've had the [best results](http://robertsonics.com/microsd-cards-for-audio/) with Class 4 and Class 10 cards.
> -   **Micro-B USB port** for power input.
> -   **Reset switch.** Used to reinitialize Tsunami, particularly after swapping the SD card.
> -   **3.3V FTDI-style serial interface**. Tsunami can be controlled using a PC, or an external microcontroller.
> -   **Atmel ATSAMS70N20 Cortex M7 microcontroller**. The brains of the whole operation!
> -   **0.1 inch header power input**. Connect an external supply of 5--15 VDC here.
> -   **16 trigger inputs**. Used to control WAV file playback. Each has an adjacent ground pad to make connecting switches easier.
> -   **Stereo audio input**. Can be mixed to any combination of outputs.
> -   **Audio outputs**, configurable as four stereo outputs or eight mono outputs. Again, each output has an adjacent ground pad to facilitate wiring.
> -   **MIDI input and output ports**. Just add 5-pin DIN connectors for MIDI.
> 
> Each of these is described in more detail in the [Tsunami Online User Guide](http://robertsonics.com/tsunami-user-guide/).
> 
> ### Tsunami Power Notes
> 
> #### Power Supply Requirements
> 
> Tsunami should be powered with between **5 and 12 VDC**. Tsunami is also rather power hungry: While playing WAV files, it draws about 200 mA.
> 
> Power can be applied two ways. For convenience, Tsunami can be powered by the USB micro-B connector, from a USB port, or a [micro-B terminated wall adapter](https://www.sparkfun.com/products/12890). Alternatively, Tsunami can be powered more directly using the 0.1 inch header power input.
> 
> [![alt text](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/powering.png)](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/powering.png)
> 
> _Powering Tsunami._
> 
> #### Logic Levels
> 
> On Tsunami, the incoming voltage is regulated down to 3.3V for all of the onboard circuitry. The processor, codec and other circuitry are all powered from 3.3V.
> 
> Tsunami's digital interfaces operate at 3.3V and are not compatible with 5V logic. If you are connecting other devices to the FTDI header or trigger inputs, you need to be sure to use 3.3V devices, or a [voltage translator](https://www.sparkfun.com/products/11771) to bridge the gap.
> 
> The one exception to this is the opto-isolated MIDI input. Being opto-isolated, it is fully compatible with regular 5V MIDI circuitry.
> 
> ## Tsunami Demonstration
> 
> To show how easy it is to use Tsunami, let's hook it up and play some sounds.
> 
> For this demo, we'll be using the firmware that comes preloaded when you purchase the board. This is the stereo version, which plays stereo WAV files and treats the adjacent outputs as pairs, numbered 1 through 4. Mono file playback is supported by a different firmware image.
> 
> ## Prepare the SD Card
> 
> The contents of the microSD card are the key to Tsunami. To start this demonstration, we'll prepare a card with some prerecorded files.
> 
> First, a quick warning about formatting your uSD card. If you need to format your card, it is _very important_ that you use the correct settings:
> 
> -   File system must be FAT16 or FAT32
> -   File Allocation Size must be 32 kilobytes
> -   "Quick format" is usually okay
> -   Note, if you are using a "brand new card", then formatting may not be necessary. If you notice that your Tsunami is missing commands, making occasional strange buzzing sounds, and sometimes crashing, then your file allocation size may be incorrect.
> 
> [![alt text](https://cdn.sparkfun.com/r/500-500/assets/home_page_posts/2/6/9/6/format32.jpg)](https://cdn.sparkfun.com/assets/home_page_posts/2/6/9/6/format32.jpg)
> 
> _Formatting settings for Tsunami uSD card_
> 
> Next, download the demo files. Unzip the folder and put the files on the root directory of the card.
> 
> Before we put the card in Tsunami, let's quickly examine the files.
> 
> [![Files on the card](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/card-dir.png)](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/card-dir.png)
> 
> _Files on the card_
> 
> Notice that there are two types of file: 16 WAV files, and one INI file.
> 
> ### WAV Files
> 
> The WAV files are the audio content Tsunami will be playing back. These are 16 stereo WAV files, configured to play from the 16 trigger inputs.
> 
> #### Naming
> 
> The file names contain the trigger input mapping for the files. Each one starts with a three-digit number, which assigns it to the corresponding trigger input.
> 
> [![alt text](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/trigger-to-file.png)](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/trigger-to-file.png)
> 
> _File number to trigger mapping_
> 
> With 16 files, numbered 001 to 016, we'll be assigning a file to each of the trigger inputs.
> 
> #### WAV File Format
> 
> We should also take a moment to examine the file format. Tsunami plays WAV files recorded at 16-bit resolution, with a 44.1kHz sampling rate. Different firmware images allow for the playback of stereo or mono files.
> 
> Tsunami also requires that the file not contain any additional header information. Some audio recording programs, such as Pro Tools, write additional information at the start of the file. One easy way to remove unnecessary header information is by opening the file in [Audacity](http://www.audacityteam.org/) and exporting it as "WAV (Microsoft) signed 16-bit PCM." As part of the export process, be sure to clear out any entries in the metadata dialog (title, artist, genre, etc.). The following video gives a brief demonstration of the Audacity export process.
> 
> _Exporting from Audacity to Tsunami._
> 
> If you're curious about the header contents, Rail John Rogut has written the [Header Investigator](http://www.railjonrogut.com/HeaderInvestigator.htm) application, which can display Pro Tools region information and BWF time stamps. This extra data might be meaningful to DAW applications, but Tsunami doesn't use the information.
> 
> ### .INI File
> 
> There is also an initialization file, `tsunami.ini`. Tsunami reads this file when it starts, to gather more details about how it should handle the trigger inputs. In this case, the triggers are constrained so that a file plays completely and can't be retriggered until it is done playing. This prevents stuttering when the trigger inputs aren't clean.
> 
> INI files are generated and edited using the [Tsunami Configurator](http://robertsonics.com/tsunami-downloads/) application. They are human readable ASCII text files. If you're curious about what's inside, you can open them in a text editor.
> 
> [![alt text](https://cdn.sparkfun.com/r/600-600/assets/learn_tutorials/6/2/2/config-util.png)](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/config-util.png)
> 
> _Tsunami configurator_
> 
> If you want to map the triggered sounds to other outputs, you can select the output number in the "Trigger Settings" portion of the app.
> 
> You can find more information about the configurator utility in the [Tsunami user guide](http://robertsonics.com/tsunami-user-guide/#configurator).
> 
> ## Install the Card
> 
> Now that we've looked at the contents of the card, eject the card from your computer and put it in the slot on Tsunami.
> 
> ## Connect Outputs
> 
> For this demo, we'll only be using the first stereo output, Output 1L and 1R.
> 
> To listen to that output, we'll make a temporary adapter using a [3.5mm TRRS breakout board](https://www.sparkfun.com/products/11570) and some [IC Hook test leads](https://www.sparkfun.com/products/501). We're using the IC Hooks so we don't have to solder them to the board, making a temporary connection for the sake of the example.
> 
> We cut three of the leads in half and soldered them to the `TIP`, `RING1` and `SLEEVE` pads of the breakout, using the following connection scheme. We didn't make any connection to the `RING2` pad.
> 
> Jumper Color
> 
> Breakout Connection
> 
> Tsunami Connection
> 
> Blue
> 
> TIP
> 
> Output 1L
> 
> Red
> 
> RING1
> 
> Output 1R
> 
> Green
> 
> SLEEVE
> 
> GND
> 
> The adapter cable looks like this.
> 
> [![alt text](https://cdn.sparkfun.com/r/600-600/assets/learn_tutorials/6/2/2/Tsunami_Super_Wav_Trigger_Hookup_Guide-02.jpg)](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/Tsunami_Super_Wav_Trigger_Hookup_Guide-02.jpg)
> 
> _Adapter cable_
> 
> With care, you can put the ends of the IC hooks through the 0.1" pads on the PCB, connected as described in the table above.
> 
> [![alt text](https://cdn.sparkfun.com/r/600-600/assets/learn_tutorials/6/2/2/Tsunami_Super_Wav_Trigger_Hookup_Guide-03.jpg)](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/Tsunami_Super_Wav_Trigger_Hookup_Guide-03.jpg)
> 
> _Adapter cable in place_
> 
> Finally, connect your headphones, multimedia speakers, or other output device.
> 
> * * *
> 
> ## Connect Power
> 
> For this demo, we're simply powering Tsunami from the USB port on our computer.
> 
> [![alt text](https://cdn.sparkfun.com/r/600-600/assets/learn_tutorials/6/2/2/Tsunami_Super_Wav_Trigger_Hookup_Guide-04.jpg)](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/Tsunami_Super_Wav_Trigger_Hookup_Guide-04.jpg)
> 
> _Test setup_
> 
> When you apply power, the board will initialize, and indicate readiness by blinking the status LED three times. From then on, the LED pulse every few seconds, indicating that the board is alive, and waiting to be triggered.
> 
> ## Trigger Sounds
> 
> The simplest way to drive Tsunami is by shorting the trigger inputs to ground. By default, the trigger inputs use an internal pullup resistor, and recognize when they are grounded.
> 
> For this demo, we're going to use a short piece of wire to bridge trigger inputs to their corresponding ground pads. A more permanent application might use momentary switches, such as [cherry switches](https://www.sparkfun.com/products/13834), [tactile switches](https://www.sparkfun.com/products/97) or [microswitches](https://www.sparkfun.com/products/9414).
> 
> [![alt text](https://cdn.sparkfun.com/r/600-600/assets/learn_tutorials/6/2/2/Tsunami_Super_Wav_Trigger_Hookup_Guide-05.jpg)](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/Tsunami_Super_Wav_Trigger_Hookup_Guide-05.jpg)
> 
> _Triggering a WAV file_
> 
> We've bent the wire into a 0.1" wide U-shape. We insert one end into a ground pad, and use the other to tap the trigger inputs.
> 
> ## Eureka!
> 
> When the wire makes contact, you should hear a sound on the output. The files on the card simply recite the number of the trigger input.
> 
> The status LED also illuminates while files are playing.
> 
> ## Further Experiments
> 
> Now that you've got sound, there are a few other things you can try out.
> 
> ### Other Trigger Modes
> 
> If your application doesn't have switches that can easily short the trigger inputs to ground, there are three methods to trigger sounds.
> 
> 1.  Using an `*.INI` file, you can convert to trigger inputs to respond to 3.3V active-high logic pulses, which could be sent by a microcontroller or discrete logic.
> 2.  You can send MIDI note on and off commands to the MIDI port to trigger sounds.
> 3.  You can use the [Tsunami Serial Protocol](http://robertsonics.com/tsunami-user-guide/#serial-control) to trigger sounds on the FTDI-compatible serial port. You can connect to a computer using an FTDI [USB-to-serial converter](https://www.sparkfun.com/products/9873), or use the [Tsunami Arduino Library](https://github.com/robertsonics/Tsunami-Arduino-Serial-Library) on a microcontroller.
> 
> Tsunami responds on all of these interfaces simultaneously.
> 
> #### Connecting MIDI Input
> 
> For Tsunami to receive MIDI, all you need to do is add a [5-pin DIN](https://www.sparkfun.com/products/9536) socket. Simply connect pins 4 and 5 to the pads with corresponding labels.
> 
> [![alt text](https://cdn.sparkfun.com/r/600-600/assets/learn_tutorials/6/2/2/Tsunami_Super_Wav_Trigger_Hookup_Guide-06.jpg)](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/Tsunami_Super_Wav_Trigger_Hookup_Guide-06.jpg)
> 
> _MIDI input connection._
> 
> Keep in mind that the pins on a 5-pin DIN are out of order, but as a reminder, the numbers are usually embossed in the plastic of the connector.
> 
> Tsunami responds to MIDI note on and off, pitch bend, program change, and a number of continuous controller messages. By default it is in Omni-on mode, responding to messages on any channel, though the channel can be specifically assigned using the configuration file. More details about the MIDI implementation can be found in the [Tsunami user guide](http://robertsonics.com/tsunami-user-guide/#midi-implementation).
> 
> ### More Outputs
> 
> To streamline this example, we've limited it to the first stereo output -- but of course, one of the best features of Tsunami is the multiple outputs. So let's take a look at a couple of ways to reassign WAV files to those outputs.
> 
> #### Trigger Output Mapping
> 
> The first method of assigning files to outputs is by editing the INI file. Using the Tsunami Configurator, you can assign files to outputs in the **"Trigger Settings"** section. Each trigger can be assigned to a different output.
> 
> [![alt text](https://cdn.sparkfun.com/r/600-600/assets/learn_tutorials/6/2/2/config-util-output-assig.png)](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/config-util-output-assig.png)
> 
> _Tsunami output parameter._
> 
> Of course, the INI file only covers the 16 trigger inputs.
> 
> #### MIDI Output Mapping
> 
> If you're using MIDI to trigger Tsunami, you can assign tracks to outputs using filenames. A fully specified file name begins with a number, followed by an underscore, a letter, and another number.
> 
> [![alt text](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/filename.png)](https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/filename.png)
> 
> _Example Tsunami filename._
> 
> -   The `first number` (before the underscore) assign the file to one of the trigger inputs.
> -   The `underscore (_)` keeps the track number from running into the output field.
> -   The `letter` after the underscore, S or L, specifies **S**ingle-shot or **L** ooping playback.
> -   The `second number` (after the underscore) assigns the file to one of the four stereo outputs.
> -   The `filename` (remainder of the name) is not required, but might be useful to remind you what the contents of the file are.
> 
> For instance, file `001_S1beep.wav` will sound when trigger 1 is activated, and play on output 1. The trigger inputs are numbered `001` through `016`, and the stereo outputs are `1` through `4`. If you want to alter the mapping between files, trigger inputs, and audio outputs, you can simply change the numbers in the file names.
> 
> #### Serial Protocol Output Mapping
> 
> Finally, when you trigger sounds using the [serial control protocol](http://robertsonics.com/tsunami-user-guide/#serial-control), the output is specified as part of the trigger message.
> 
> Unlike the trigger input and MIDI track assignments, the mapping can be assigned on-the-fly as sounds are triggered.
> 
> ### Mono Playback Firmware
> 
> In these examples, we've been using the [stereo (dual-channel)](https://en.wikipedia.org/wiki/Stereophonic_sound) version of the Tsunami firmware. There is an alternate version of the firmware that plays [monophonic (single-channel)](https://en.wikipedia.org/wiki/Monaural) files. It nearly doubles the maximum polyphony, from 18 to 32 simultaneous files, and the outputs become 8 individually-assignable outputs. The mono version also has an option for starting a group of tracks at the same time, mapped to sequential outputs. This allows mono mode to play stereo, quadrophonic, and surround material.
> 
> You can get the mono mode firmware from Robertsonics [download page](http://robertsonics.com/tsunami-downloads/). It's easy to load from the micro SD card if you follow [these instructions](http://robertsonics.com/tsunami-user-guide/#updating-the-firmware).
> 
> If Tsunami gets a mapping number it doesn't understand (a mapping to output #9, for instance), it usually ignores it, and uses the default setting for that parameter (9 would become 1).
> 
> ## Resources and Going Further
> 
> Now that you've successfully got your Tsunami up and running, it's time to incorporate it into your own project!
> 
> For more information, check out the resources below:
> 
> Robertsonics support pages:
> 
> -   [Information Page](http://robertsonics.com/tsunami/)
> -   [User Guide](http://robertsonics.com/tsunami-user-guide/)
> -   [Downloads Page](http://robertsonics.com/tsunami-downloads/) for formware updates and helper applications
> -   [GitHub Arduino Library Repo](https://github.com/robertsonics/Tsunami-Arduino-Serial-Library) Arduino serial-control library.
> -   [GitHub Hardware Repository](https://github.com/sparkfun/tsunami)
> -   [TsunamiSnake](https://github.com/nickhayeck/TsunamiSnake) (Control your Tsunami from Python) by Nick Hayeck\]
> 
> Some useful parts for building a more complete Tsunami system:
> 
>  [![SparkFun Logic Level Converter - Bi-Directional](https://cdn.sparkfun.com/r/140-140/assets/parts/8/5/2/2/12009-06.jpg)](https://www.sparkfun.com/products/12009) 
> 
>    
> 
> added to your [cart](https://www.sparkfun.com/cart)!
> 
> ### [SparkFun Logic Level Converter - Bi-Directional](https://www.sparkfun.com/products/12009)
> 
> [In stock](https://learn.sparkfun.com/static/bubbles/ "in stock") BOB-12009
> 
> The SparkFun bi-directional logic level converter is a small device that safely steps down 5V signals to 3.3V AND steps up 3.…
> 
> $2.95
> 
> 104
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 126
> 
> [Wish List](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to wish list")
> 
>  [![SparkFun FTDI Basic Breakout - 3.3V](https://cdn.sparkfun.com/r/140-140/assets/parts/3/9/5/8/09873-01a.jpg)](https://www.sparkfun.com/products/9873) 
> 
>    
> 
> added to your [cart](https://www.sparkfun.com/cart)!
> 
> ### [SparkFun FTDI Basic Breakout - 3.3V](https://www.sparkfun.com/products/9873)
> 
> [In stock](https://learn.sparkfun.com/static/bubbles/ "in stock") DEV-09873
> 
> This is the newest revision of our \[FTDI Basic\](https://www.sparkfun.com/products/retired/8772). We now use a SMD 6-pin heade…
> 
> $15.50
> 
> 64
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 48
> 
> [Wish List](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to wish list")
> 
>  [![FTDI Cable 5V VCC-3.3V I/O](https://cdn.sparkfun.com/r/140-140/assets/parts/3/6/3/0/09717-01.jpg)](https://www.sparkfun.com/products/9717) 
> 
>    
> 
> added to your [cart](https://www.sparkfun.com/cart)!
> 
> ### [FTDI Cable 5V VCC-3.3V I/O](https://www.sparkfun.com/products/9717)
> 
> [In stock](https://learn.sparkfun.com/static/bubbles/ "in stock") DEV-09717
> 
> The FTDI cable is a USB to Serial (TTL level) converter which allows for a simple way to connect TTL interface devices to USB…
> 
> $17.95
> 
> 11
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 17
> 
> [Wish List](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to wish list")
> 
>  [![USB Wall Charger - 5V, 1A (Black)](https://cdn.sparkfun.com/r/140-140/assets/parts/7/3/1/0/11456-02a.jpg)](https://www.sparkfun.com/products/11456) 
> 
>    
> 
> added to your [cart](https://www.sparkfun.com/cart)!
> 
> ### [USB Wall Charger - 5V, 1A (Black)](https://www.sparkfun.com/products/11456)
> 
> [In stock](https://learn.sparkfun.com/static/bubbles/ "in stock") TOL-11456
> 
> USB is being implemented as a power connection standard more and more these days, but you don't always have a computer on han…
> 
> $3.95
> 
> 2
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 10
> 
> [Wish List](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to wish list")
> 
>  [![MIDI Connector - Female Right Angle](https://cdn.sparkfun.com/r/140-140/assets/parts/3/1/8/7/09536-MIDI_Connector_-_Female_Right_Angle-01.jpg)](https://www.sparkfun.com/products/9536) 
> 
>    
> 
> added to your [cart](https://www.sparkfun.com/cart)!
> 
> ### [MIDI Connector - Female Right Angle](https://www.sparkfun.com/products/9536)
> 
> [In stock](https://learn.sparkfun.com/static/bubbles/ "in stock") PRT-09536
> 
> Looking to add MIDI to your project? This is a female, 5-pin, right-angle DIN 5/180? connector which will interface with most…
> 
> $1.95
> 
> 1
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 10
> 
> [Wish List](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to wish list")
> 
>  [![Right Angle Tactile Button](https://cdn.sparkfun.com/r/140-140/assets/parts/5/7/7/6/10791-01.jpg)](https://www.sparkfun.com/products/10791) 
> 
>    
> 
> added to your [cart](https://www.sparkfun.com/cart)!
> 
> ### [Right Angle Tactile Button](https://www.sparkfun.com/products/10791)
> 
> [28 available](https://learn.sparkfun.com/static/bubbles/ "28 available") COM-10791
> 
> This right-angle tactile switch has a great 'click' to it. Also, because it's a through-hole design it's very sturdy. Mount i…
> 
> $0.50
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 4
> 
> [Wish List](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to wish list")
> 
>  [![microSD Card with Adapter - 16GB (Class 10)](https://cdn.sparkfun.com/r/140-140/assets/parts/1/1/4/3/0/13833-02.jpg)](https://www.sparkfun.com/products/retired/13833) 
> 
> ### [microSD Card with Adapter - 16GB (Class 10)](https://www.sparkfun.com/products/retired/13833)
> 
> [Retired](https://learn.sparkfun.com/static/bubbles/ "Retired") COM-13833
> 
> This is a class 10 16GB microSD memory card, perfect for housing operating systems for single board computers and a multitude…
> 
> 6 **Retired**
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 8
> 
> [Wish List](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to wish list")
> 
> If you need additional inspiration for your Tsunami project, please check out our related tutorials below.
> 
> [
> 
> ### WAV Trigger Hookup Guide V11
> 
> ](https://learn.sparkfun.com/tutorials/wav-trigger-hookup-guide-v11)
> 
> An introduction to being able to trigger music and sound effects based on buttons, sensors, or switches using the WAV Trigger board.
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 0
> 
> [
> 
> ### Wireless Audio Bluetooth Adapter w/ BC127
> 
> ](https://learn.sparkfun.com/tutorials/wireless-audio-bluetooth-adapter-w-bc127)
> 
> Build a custom wireless audio Bluetooth adapter using BlueCreation's BC127 and add it to your old speaker system!
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 11
> 
> [
> 
> ### Vox Imperium: Stormtrooper Voice Changer
> 
> ](https://learn.sparkfun.com/tutorials/vox-imperium-stormtrooper-voice-changer)
> 
> Add some flair to your Imperial uniform by changing your voice using a Teensy 3.2 and Prop Shield.
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 7
> 
> [
> 
> ### MIDI BLE Tutorial
> 
> ](https://learn.sparkfun.com/tutorials/midi-ble-tutorial)
> 
> Developing a bidirectional MIDI-BLE link with the nRF52832 Breakout.
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 6
> 
> Or maybe add BLE to the Tsunami:
> 
> [
> 
> ### Enginursday: BLE MIDI for the Tsunami!
> 
> February 22, 2018
> 
> ](https://www.sparkfun.com/news/2615 "February 22, 2018: Tsunami looping firmware is released, and connectable by MIDI. And why not MIDI BLE? It's done with the nRF52832 this week.")
> 
> [Favorited Favorite](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all# "Add to favorites") 1
> 
> [Share](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all#)
> 
> Use this URL to share:  
> 
> [Share on Google+](https://plus.google.com/share?url=http%3A%2F%2Fsfe.io%2Ft622 "Share on Google+") [Share on Tumblr](https://www.tumblr.com/share/link?url=http%3A%2F%2Fsfe.io%2Ft622&name=Tsunami+Hookup+Guide "Share on Tumblr") [Submit to reddi](https://www.reddit.com/submit?url=http%3A%2F%2Fsfe.io%2Ft622 "Submit to reddit")
> 
> [Share on Twitter](https://twitter.com/intent/tweet?text=Tsunami+Hookup+Guide&url=http%3A%2F%2Fsfe.io%2Ft622&via=sparkfun "Share on Twitter") [Share on Facebook](http://www.facebook.com/sharer.php?u=http%3A%2F%2Fsfe.io%2Ft622&t=Tsunami+Hookup+Guide "Share on Facebook") [Pin It](https://www.pinterest.com/pin/create/button/?url=http%3A%2F%2Fsfe.io%2Ft622&media=https%3A%2F%2Fcdn.sparkfun.com%2F%2Fr%2F500-1000%2Fassets%2Flearn_tutorials%2F6%2F2%2F2%2F13810-01.jpg&description=Tsunami+Hookup+Guide "Pin It")
> 
> ×
> 
> **Sections** [Introduction](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all#introduction) [Hardware Overview](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all#hardware-overview) [Tsunami Demonstration](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all#tsunami-demonstration) [Further Experiments](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all#further-experiments) [Resources and Going Further](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all#resources--going-further)
> 
> [Comments 0](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/discuss) [View Paginated](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/introduction) [Print](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all#)
> 
> -   **Tags**
> -   -   [Audio](https://learn.sparkfun.com/tutorials/tags/audio)
>     -   [Hookup](https://learn.sparkfun.com/tutorials/tags/hookup)
> 
> -   **License**
> -   Creative Commons tutorials are [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/)
> 
> hbspt.forms.create({ portalId: "2224003", formId: "1f5a7872-dd7a-4e36-99fe-cafe431ba0b2" });
> 
> ![](https://cdn2.hubspot.net/hubfs/2224003/Hosted%20Images/flame-32.png)
> 
> stay in touch with us
> 
> Weekly product releases, special offers, and more.
> 
> -   [YouTube](https://www.youtube.com/sparkfun)
> -   [Instagram](https://www.instagram.com/sparkfun/)
> -   [GitHub](https://www.github.com/sparkfun)
> -   [Facebook](https://www.facebook.com/SparkFun)
> -   [Twitter](https://twitter.com/sparkfun)
> -   [RSS](https://www.sparkfun.com/feeds)
> 
> ### ABOUT SPARKFUN
> 
> -   [Read Our Story](https://www.sparkfun.com/about_sparkfun)
> -   [Press & Media](https://www.sparkfun.com/coverage)
> -   [Success with SparkFun](https://www.sparkfun.com/success)
> -   [SparkFun Education](http://www.sparkfuneducation.com)
> -   [Job Openings](https://www.sparkfun.com/jobs)
> 
> ### PARTNER WITH US
> 
> -   [See Our Partners](https://www.sparkfun.com/partner_with_us)
> -   [Become a Distributor/Reseller](https://www.sparkfun.com/become_a_distributor)
> -   [Receive Volume Discounts](https://www.sparkfun.com/volume_sales)
> -   [Explore Services](https://www.sparkfun.com/services)
> -   [Apply for a Hardware Donation](https://www.sparkfun.com/community_outreach)
> 
> ### SUPPORT
> 
> -   [Customer Support](https://www.sparkfun.com/support)
> -   [Purchase Orders & Payment Terms](https://www.sparkfun.com/support#PurchaseOrders)
> -   [Technical Assistance](https://www.sparkfun.com/technical_assistance)
> -   [FAQs](https://www.sparkfun.com/faq)
> -   [Contact Us](https://www.sparkfun.com/static/contact)
> 
> ### SITE INFORMATION
> 
> -   [Terms of Service](https://www.sparkfun.com/terms)
> -   [Privacy Policy](https://www.sparkfun.com/privacy)
> -   [Compliance](https://www.sparkfun.com/compliance)
> -   [Site Map](https://www.sparkfun.com/sitemap)
> 
> -   SparkFun Electronics [®](https://www.sparkfun.com/news/300)
> -   [**6333 Dry Creek Parkway, Niwot, Colorado 80503**](http://maps.google.com/maps?f=q&source=s_q&hl=en&geocode=&q=6333+Dry+Creek+Parkway,+Niwot,+CO+80503)
> -   [Desktop Site](https://www.sparkfun.com/account/mobile_toggle?redirect=%2Flearn%2Ftutorials%2Ftsunami-hookup-guide%2Fall)
> 
> -   [Your Account](https://learn.sparkfun.com/tutorials/tsunami-hookup-guide/all#)
> -   [Log In](https://www.sparkfun.com/account/login?redirect=%2Flearn%2Ftutorials%2Ftsunami-hookup-guide%2Fall)
> -   [Register](https://www.sparkfun.com/account/make)
> 
> ×Close
> 
> #### Log In
> 
> var SFECONFIG = { dnt: true, http\_server: 'http://learn.sparkfun.com', https\_server: 'https://learn.sparkfun.com', http\_static: 'https://cdn.sparkfun.com', learn\_server: 'https://learn.sparkfun.com', commerce\_server: 'https://www.sparkfun.com', base\_url: '/', url: '/', controller: 'tutorials', action: 'view', entity\_id: '', auth: false, sparkrev: '1600190210', search\_key: 'xY6qr5Ui3V2UMA762D9Z' }; $('#learn').learn(); $('#learn').sfeutil(); $.shared('domready');
> 
> If you click this button, Facebook will be able to track your visit to this site.
> 
> If you click this button, Facebook will be able to track your visit to this site.
