PImage img;

/* Pd arrays are 200px x 70px
 with 5 px boundary on each side they are 210x80
 */
int array_width = 210;
int array_height = 80;
String input_image = "crni_vrh_arrays_2022-08-13.png";
int num_of_rows = 3; // source image rows
int num_of_columns = 4;// source image columns

// ------------------------- setup -----------------------------------
void setup()
{
  size(841, 241); // dimension of image

  img = loadImage(input_image);
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
  for (int y = 0; y < num_of_rows; y++) 
    for (int x = 0; x < num_of_columns; x++) 
    {
      PImage croppedImg = get(x*array_width, y*array_height, array_width, array_height); // x, y, w, h
      String filename = "export/" + input_image.split(".png")[0] + "_" + str(chunk_count) + ".png";
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
