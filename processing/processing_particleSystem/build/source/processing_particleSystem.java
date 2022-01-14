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

public class processing_particleSystem extends PApplet {

ParticleSystem ps;

public void setup() {
  size(640,360);
  ps = new ParticleSystem();
}

public void draw() {
  background(255);
  ps.run();
}
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "processing_particleSystem" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
