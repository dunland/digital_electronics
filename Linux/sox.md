# sox

## trim

`sox in.mp3 out.mp3 trim [begin] [end after]`
--> z.B. `sox in.mp3 out.mp3 trim 0:20 3:30` erstellt Soundfile das bei 20s beginnt und 3:30 min lang ist, (also cut von 0:20 bis 3:50)

## stereo to mono

`sox input.wav output.wav channels 1`

## split stereo to mono files

```
sox input.wav -c 1 output_left.wav remix 1
sox input.wav -c 1 output_right.wav remix 2
```

## convert flac to mp3 using sox (batch command)

`for i in *.flac ; do sox "$i" -C 320 $(echo $i.mp3) ; done`

## change samplerate

`sox input.wav -r SAMPLERATE output.wav`