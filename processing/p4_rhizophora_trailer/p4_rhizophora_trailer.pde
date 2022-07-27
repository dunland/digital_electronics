/**
 * Explode 
 * by Daniel Shiffman. 
 * 
 * Mouse horizontal location controls breaking apart of image and 
 * Maps pixels from a 2D image into 3D space. Pixel brightness controls 
 * translation along z axis. 
 */

PImage img;       // The source image
float imgWidth, imgHeight;
float n = 1;

void setup() {
  frameRate(5);
  size(1920, 1080, P3D); 
  img = loadImage("rhziphora-fontMask-fullHD.gif");  // Load the image
  imgWidth = img.width * 0.1;
  imgHeight = img.height * 0.1;
}

void draw() {
  background(random(255));
  img.resize(int(imgWidth), int(imgHeight));
  imgWidth = imgWidth * (1.01 * n);
  imgHeight = imgHeight * (1.01 * n);
  n = n * 1.005;
  image(img, (width - img.width)/2, (height - img.height) / 2);
}
