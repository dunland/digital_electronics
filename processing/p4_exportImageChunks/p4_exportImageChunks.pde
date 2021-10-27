PImage img;

/* Pd arrays are 200px x 70px
 with 5 px boundary on each side they are 210x80
 */
int array_width = 210;
int array_height = 80;

// ------------------------- setup -----------------------------------
void setup()
{
  size(1888, 958); // dimension of image

  img = loadImage("mountainScanner_2021-10-26 23-55-58_arrays.png");
  img.loadPixels(); // now .pixels is available
}

// ------------------------- draw ------------------------------------
void draw()
{
  background(img);
}

// ------------------- chunk & export --------------------------------
void export_image_chunks()
{
  int chunk_count = 0;
  for (int y = 0; y < 12; y++) // source image has 12 rows
    for (int x = 0; x < 9; x++) // source image has 9 columns
    {
      PImage croppedImg = get(x*array_width, y*array_height, array_width, array_height); // x, y, w, h
      String filename = "export/" + str(chunk_count) + ".png";
      croppedImg.save(filename);
      println("exporting file " + filename);
      println("done exporting");

      chunk_count++;
    }
}

// ----------------- start chunk & export by hitting space: -----------
void keyReleased()
{
  if (key == ' ')
    export_image_chunks();
}
