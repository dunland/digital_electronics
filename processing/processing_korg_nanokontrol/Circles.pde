class Circle {

  float size = 100;
  float xpos, ypos;
  float killThresh = -100; // try -100 or 0!

  Circle(float x_pos, float y_pos)
  {
    xpos = x_pos;
    ypos = y_pos;
  }

  void draw()
  {
    fill(xpos/width * 255, ypos/height * 255, random(255), size/100 * 255);
    ellipse(xpos, ypos, size, size);
  }
}

void updateCircles(){
  for (int i = 0; i<circles.size(); i++)
  {
    Circle circle = circles.get(i);
    circle.size--;
    if (circle.size <= circle.killThresh)
    {
     circles.remove(i);
    }
  }
}
