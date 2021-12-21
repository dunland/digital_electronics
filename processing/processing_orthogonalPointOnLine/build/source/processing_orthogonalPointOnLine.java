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

public class processing_orthogonalPointOnLine extends PApplet {

// here is it - https://www.openprocessing.org/sketch/413945
// the original code at https://forum.processing.org/two/discussion/15700/orthogonal-projection-of-a-point-onto-a-line by cameyo
//
// presented on openprocessing by Yuri Konoplev
// let us play together on github.com/j0k , fb.com/yuri.konoplev

float x1,y1,x2,y2;
PVector p1,p2;
PVector point, target, previous, proj;
int n = 1;
int t = 0;
float increment = 0;


float cx = width/2;
float cy = height/2;

public void setup()
{
   size(600,600);
   randomVals();





}

public void randomVals()
{
   x1 = (int)random(100,500);
   y1 = (int)random(100,500);
   x2 = (int)random(100,500);
   y2 = (int)random(100,500);
   cx = (int)random(100,500);
   cy = (int)random(100,500);
	 cx = mouseX;
	 cy = mouseY;

   p1 = new PVector(x1,y1);
   p2 = new PVector(x2,y2);

   proj = projection(p1, p2, new PVector(cx,cy));
   previous = new PVector(cx, cy);
   target = proj;

   point = PVector.sub(target,previous);
   point.mult(increment);
   point.add(previous);

   increment = 0;
   t = 0;
}

public PVector projection(PVector line_p1, PVector line_p2, PVector p){
  float y1 = line_p1.y;
  float y2 = line_p2.y;
  float x1 = line_p1.x;
  float x2 = line_p2.x;

  if ((x1 == x2) && (y1 == y2))
    return line_p1;

  float k = ((y2-y1) * (cx-x1) - (x2-x1) * (cy-y1)) / (sq(y2-y1) + sq(x2-x1));
  float x4 = p.x - k * (y2-y1);
  float y4 = p.y + k * (x2-x1);

  return new PVector(x4,y4);
}

// does projection inside line?
public boolean inside(PVector line_p1, PVector line_p2, PVector proj, float near){
  boolean x_res = false;
  boolean y_res = false;
  if ((near + line_p1.x >= proj.x) && (proj.x >= line_p2.x - near)){
    x_res = true;
  }

  if ((line_p1.x - near <= proj.x) && (proj.x <= line_p2.x + near)){
    x_res = true;
  }

  if ((line_p1.y + near >= proj.y) && (proj.y >= line_p2.y - near)){
    y_res = true;
  }

  if ((line_p1.y - near <= proj.y) && (proj.y <= line_p2.y + near)){
    y_res = true;
  }

  return (x_res && y_res);
}


public void draw()
{
  background(60);
  // randomVals();

  noFill();
  ellipse(cx,cy,50,50);
  noStroke();
  fill(220,20,20);
  ellipse(cx,cy,8,8);
  // calculate the point



  if (inside(p1,p2,proj,0))
  {
  	stroke(220);
    move(previous, target);
  }
  else
  {
    stroke(color(220,0,220));
    text("line out of toleranted reach", 50, 100);
  }

  line(x1,y1,x2,y2);

  float x4 = proj.x;
  float y4 = proj.y;
  fill(20,20,220);
  ellipse(x4,y4, 8,8);
  stroke(0);
  line(cx,cy,x4,y4);
  // noLoop();
  // move(previous, target);
}

public void move(PVector from, PVector to)
{
  if(point.dist(to) > 1)
  {
          point = PVector.sub(to,from);
          point.mult(increment);
          point.add(from);
  }
  else if (point.dist(to) < 1)
  {
          increment = 0;
          t = 0;
          fill(255);
          text("press any key to continue", 50, 100);
          // randomVals();
          // from.set(targetsList.get(n));
          // n = (n + 1) % (targetsList.size());
          // to.set(targetsList.get(n));
  }

  fill(255);
  ellipse(point.x, point.y, 20, 20);

  // linear movement normalized to vector length
  PVector v = PVector.sub(to, from);
  t ++;
  increment = t / v.mag();

  println(t, increment, point.x, point.y);
}

public void keyPressed() { randomVals(); }
public void mousePressed() { randomVals(); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "processing_orthogonalPointOnLine" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
