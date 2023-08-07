# ffmpeg

## video creation

### screencast using ffmpeg:
`ffmpeg -f x11grab -video_size 1920x1080 -framerate 30 -i :0.0 -vcodec libx264 -preset ultrafast -qp 0 -pix_fmt yuv444p video.mkv`

### create video from image files:

`ffmpeg -i ./img%d.jpg output.mp4` for files named "img1.jpg, img2.jpg" etc  
`ffmpeg -i ./img%03d.jpg output.mp4` for files named "img001.jpg, img002.jpg" etc  

## video tweaking

### cut

`ffmpeg -ss 00:08 -i input_file.mp4 -t 00:06:00 -t

### extract audio from video:
```
sudo apt install ffmpeg
ffmpeg -i VIDEOFILE -acodec libmp3lame -metadata TITLE="Name of Song" OUTPUTFILE.mp3
```
or `ffmpeg -i sample.avi -q:a 0 -map a sample.mp3`

### convert mp4 to gif:

`ffmpeg -ss 30 -t 3 -i input.mp4 -vf "fps=10,scale=320:-1:flags=lanczos,split[s0][s1];[s0]palettegen[p];[s1][p]paletteuse" -loop 0 output.gif`
> This example will skip the first 30 seconds (-ss 30) of the input and create a 3 second output (-t 3).
> fps filter sets the frame rate. A rate of 10 frames per second is used in the example.
> scale filter will resize the output to 320 pixels wide and automatically determine the height while preserving the aspect ratio. The lanczos scaling algorithm is used in this example.
> palettegen and paletteuse filters will generate and use a custom palette generated from your input. These filters have many options, so refer to the links for a list of all available options and values. Also see the Advanced options section below.
> split filter will allow everything to be done in one command and avoids having to create a temporary PNG file of the palette.
> Control looping with -loop output option but the values are confusing. A value of 0 is infinite looping, -1 is no looping, and 1 will loop once meaning it will play twice. So a value of 10 will cause the GIF to play 11 times.

### change video speed:

> If you change each timestamp (Presentation Timestamp, PTS) to be half of its original value, your video will be half as long.
> So, if the PTS is x * PTS, then your final duration will be x * duration.

```
$ ffprobe -loglevel error input.mp4 -show_format -show_entries format=duration -of compact=p=0:nk=1
60.000000
$ ffmpeg -i input.mp4 -filter:v 'setpts=0.5*PTS' -filter:a 'atempo=2' output.mp4
...
$ ffprobe -loglevel error output.mp4 -show_format -show_entries format=duration -of compact=p=0:nk=1
30.050000
```