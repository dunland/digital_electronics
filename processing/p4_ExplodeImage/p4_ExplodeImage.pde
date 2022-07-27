import peasy.*;

/**
 * Explode 
 * by Daniel Shiffman. 
 * 
 * Mouse horizontal location controls breaking apart of image and 
 * Maps pixels from a 2D image into 3D space. Pixel brightness controls 
 * translation along z axis. 
 */

PImage img;       // The source image
int cellsize = 4; // Dimensions of each cell in the grid
int columns, rows;   // Number of columns and rows in our system

PeasyCam cam;

void setup() {
  size(1920, 1080, P3D);
  fullScreen();
  img = loadImage("rhizo.png");  // Load the image
  columns = img.width / cellsize;  // Calculate # of columns
  rows = img.height / cellsize;  // Calculate # of rows
  cam = new PeasyCam(this,400);
}

void draw() {
  background(0);
  // Begin loop for columns
  for ( int i = 0; i < columns; i++) {
    // Begin loop for rows
    for ( int j = 0; j < rows; j++) {
      int x = i*cellsize + cellsize/2;  // x position
      int y = j*cellsize + cellsize/2;  // y position
      int loc = x + y*img.width;  // Pixel array location
      color c = img.pixels[loc];  // Grab the color
      // Calculate a z position as a function of mouseX and pixel brightness
      float z = (mouseX / float(width)) * 2 * brightness(img.pixels[loc]) - 20.0;
      // Translate to the location, set fill and stroke, and draw the rect
      pushMatrix();
      translate(x + 200, y + 100, z);
      fill(c, 204);
      noStroke();
      rectMode(CENTER);
      rect(0, 0, cellsize, cellsize);
      popMatrix();
    }
  }
}

void keyPressed()
{
   if (key == 's')
   saveFrame();
}
