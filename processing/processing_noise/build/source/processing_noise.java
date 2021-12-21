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

public class processing_noise extends PApplet {

float xoff = 0.0f;

public void draw() {
  background(204);
  xoff = xoff + .01f;
  float n = noise(xoff) * width;
  line(n, 0, n, height);
}
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "processing_noise" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
