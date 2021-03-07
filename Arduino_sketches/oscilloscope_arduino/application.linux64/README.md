# Oscilloscope Arduino-Processing

Instructions here: https://www.instructables.com/id/Oscilloscope-Arduino-Processing/

1. Open oscilloscope_arduino.ino
2. Upload to Arduino
3. start program with `bash ./application.linux64`

## Configuration

1. You already have the oscilloscope program running and the Arduino connected to the computer by USB port. Now you have to connect to each other by "serial".
2. In the "Configurar a serial" (Configure the Serial) box, click "select serial" until the COM where the Arduino is connected appears.(if it did not appear, click "refresh" to update)
3. Click "select speed" until the speed 115200 appears.
4. Click "off" to switch to "on"

5. If everything is correct, the oscilloscope will show the 4 channels [A0 (ch-0), A1 (ch-1), A2 (ch-2) and A3 (ch-3)]
    obs: if nothing is connected you will see a noise.

## Tips

1. Click "Trigger" at the Ch-0 (red) to stabilish the signals.
2. To not read the signals of Ch-2 and Ch-3, click on the names "Ch-2" and Ch-3 ".
3. To see the XY (Lissajous figures), click on the name "XYZ"
4. To detect the frequencies, click on "detect freq."
5. To measure voltage and time/frequency, click on "medir" (measure) of the desired channel then click on a point on the graph and drag to the other desired point.
6. To change the dial control value click between vertical lines or drag the edge indicated by the triangles. (see picture)
7. There is so much more! Explore!
