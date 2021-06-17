import p5
import pathlib

path = pathlib.Path()

image_file = path.joinpath("qgis-export-lang.png")
# image_file = path.joinpath("1x11057.png")

use_panning = True
use_filter = False
image_x_pos = 0
image_y_pos = 0
threshold_val = 0.5
count = 0


def setup():
    global _image
    p5.size(1920, 1080)
    p5.title("satellite_panner")
    _image = p5.load_image(image_file)
    # p5.load_pixels()


def draw():
    global _image, image_x_pos, image_y_pos, threshold_val, count, use_panning, use_filter
    p5.image(_image, image_x_pos, image_y_pos)
    for x in range(0, width):
        for y in range(0, height):
            px_color = _image._get_pixel([x,y])
            p5.fill(px_color)
            p5.ellipse(x, y, 10, 10)

    if use_panning:
        image_y_pos -= 1
    # threshold_val = abs(p5.sin(count))

    print(frame_count)
    if use_filter:
        if frame_count % 50 == 0:
            threshold_val = mouse_x / width
            _image = p5.load_image(image_file)
            _image.filter('threshold', threshold_val)
            print(threshold_val)

    count += 1


if __name__ == '__main__':
    p5.run(frame_rate=60)
    # try:
    #     p5.run(frame_rate=60)
    # except KeyboardInterrupt:
    #     exit()
