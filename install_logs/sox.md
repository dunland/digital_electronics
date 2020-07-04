# sox

## trim

`sox in.mp3 out.mp3 trim [begin] [end after]`
--> z.B. `sox in.mp3 out.mp3 trim 0:20 3:30` erstellt Soundfile das bei 20s beginnt und 3:30 min lang ist, (also cut von 0:20 bis 3:50)

## stereo to mono

`sox input.wav output.wav channels 1`
