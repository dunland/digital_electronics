String image_file = "qgis-export-lang.png";
PImage _image;
// image_file = path.joinpath("1x11057.png")

boolean use_panning = true, use_filter = false;
int image_x_pos = 0, image_y_pos = 0;
float threshold_val = 0.5;
int count = 0;

Instrument kick, snare;
ArrayList<Instrument> instruments;

float image_panning_factor = 1; // must be positive

int dotsDensity = 10;
float dotsWidth = 20;
float dotsMinWidth = 0;
float dotsMaxWidth = 40;
float dotsShrinkFactor = 0.3;
int[] selected_pixels;

int mode = 0; // 0 = 'a' trigger; 1 = sin(frameCount); 2 = mouseX


/////////////////////////////////// SETUP //////////////////////////////////////
void setup() {

  size(1920, 1080, P3D);
  _image = loadImage(image_file);
  _image.loadPixels();

  kick = new Instrument('a');
  snare = new Instrument('s');
  instruments = new ArrayList<Instrument>();
  instruments.add(kick);
  instruments.add(snare);
  selected_pixels = new int[200];
}

/////////////////////////////////// DRAW  //////////////////////////////////////
void draw() {

  background(255);
  // image(_image, image_x_pos, image_y_pos);


  for (int x = 0; x < width; x += 10) {
    for (int y = 0; y < height; y += 10) {
      color px_color = _image.get(x, y +  count);
      px_color = color(red(px_color), green(px_color), blue(px_color), 50);
      fill(px_color);
      noStroke();
      ellipse(x, y, dotsWidth, dotsWidth);
    }
  }

  if (use_panning)
    image_y_pos -= image_panning_factor;

  if (use_filter) {

    if (frameCount % 50 == 0) {

      threshold_val = mouseX / width;
      _image = loadImage(image_file);
      _image.filter(THRESHOLD, threshold_val);
      println(threshold_val);
    }
  }

  if (kick.hit) {
    if (dotsWidth <= dotsMaxWidth) {
      dotsWidth += 5;
    }
    println("kick was hit, dotsWidth = ", dotsWidth);
  }

  // update stuff:
  count += image_panning_factor;
  updateDots(); // shrink dots to 0
  for (Instrument instrument : instruments) {
    // instrument.update();
  }
}
