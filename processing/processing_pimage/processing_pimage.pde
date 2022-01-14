PImage despacito;
int i = 1;

void setup()
{
  despacito = loadImage("despacito.png");
  size(despacito.width, despacito.height);

  loadPixels();
  despacito.loadPixels();
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int loc = x + y*width;

      // The functions red(), green(), and blue() pull out the 3 color components from a pixel.
      // float r = red(despacito.pixels[loc]);
      // float g = green(despacito.pixels[loc]);
      // float b = blue(despacito.pixels[loc]);
      //
      // // Image Processing would go here
      // // If we were to change the RGB values, we would do it here,
      // // before setting the pixel in the display window.
      //
      // // Set the display pixel to the image pixel
      // pixels[loc] =  color(r,g,b);
    }
  }
  updatePixels();
}

void draw()
{
  loadPixels();
  despacito.loadPixels();
  // image(despacito,0,0);
  // for (int i = 0; i<despacito.pixels.length; i++)
  // {
  // }
  // despacito.pixels[i] = color(0);
   //despacito.pixels[i] = despacito.pixels[i-1];
  // updatePixels();

  float r = red(despacito.pixels[i-1]);
  float g = green(despacito.pixels[i-1]);
  float b = blue(despacito.pixels[i-1]);

  // Image Processing would go here
  // If we were to change the RGB values, we would do it here,
  // before setting the pixel in the display window.

  // Set the display pixel to the image pixel
  pixels[i] = color(r,g,b);
  i+=26;
  // pixels[i] = pixels[i-1];
  updatePixels();
  println(i);
}
