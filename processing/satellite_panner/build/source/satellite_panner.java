import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class satellite_panner extends PApplet {

String image_file = "qgis-export-lang.png";
PImage _image;
// image_file = path.joinpath("1x11057.png")

boolean use_panning = true, use_filter = false;
int image_x_pos = 0, image_y_pos = 0;
float threshold_val = 0.5f;
int count = 0;

Instrument kick, snare;
ArrayList<Instrument> instruments;

float image_panning_factor = 1; // must be positive

int dotsDensity = 10;
float dotsWidth = 20;
float dotsMinWidth = 0;
float dotsMaxWidth = 40;
float dotsShrinkFactor = 0.3f;
int[] selected_pixels;

int mode = 0; // 0 = 'a' trigger; 1 = sin(frameCount); 2 = mouseX


/////////////////////////////////// SETUP //////////////////////////////////////
public void setup() {

  
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
public void draw() {

  background(255);
  // image(_image, image_x_pos, image_y_pos);


  for (int x = 0; x < width; x += 10) {
    for (int y = 0; y < height; y += 10) {
      int px_color = _image.get(x, y +  count);
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
class Instrument {
  boolean hit = false;
  char _key;

  Instrument(char key_in)
  {
    _key = key_in;
  }

  public void update()
  {
    print(hit);
    hit = false;
  }

}
public void keyPressed() {
  for (Instrument instrument : instruments) {
    if (instrument._key == key) {
      instrument.hit = true;
      println(key, "=", instrument.hit);
      for (int i = 0; i < 200; i++)
      {
        selected_pixels[i] = PApplet.parseInt(random(image_y_pos, image_y_pos + width * height));
      }
    }
  }
}

public void keyReleased() {
  for (Instrument instrument : instruments) {
    if (instrument._key == key) {
      instrument.hit = false;
      println(key, "=", instrument.hit);
    }
  }
}
class Dots {

  int density = 10;
  int _width = 20;

  Dots() {}
}

public void updateDots()
{
  switch (mode) {
  case 0:
    if (dotsWidth > dotsMinWidth) {
      dotsWidth -= dotsShrinkFactor;
      println("dotsWidth = ", dotsWidth);
    }
    break;

  case 1:
    dotsWidth = abs(sin(frameCount * 0.03f) * 20);
    break;

  case 2:
    dotsWidth = (mouseX/width) * 20;
    // dotsDensity = mouseX/width * 20;
    break;
  }
}
  public void settings() {  size(1920, 1080, P3D); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "satellite_panner" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
