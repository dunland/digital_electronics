void setup()
{
  size(800, 600);
  textAlign(LEFT,BOTTOM);
}

void draw()
{
  int x_old = mouseX, y_old = mouseY;

  background(255);

  fill(128);
  ellipse(x_old, y_old, 20, 20);

  stroke(128);
  line(x_old, y_old, x_old, 0);
  line(x_old, y_old, 0, y_old);

  fill(0);
  text("alt", x_old, y_old+20);
  text(mouseX, mouseX+10, 10);
  text(mouseY, 10, mouseY+10);

  float y_new = (x_old/float(width) * height);
  float x_new = width - (y_old/float(height) * width);

  fill(165, 215, 78);
  ellipse(x_new, y_new, 20, 20);
  text("neu", x_new, y_new+20);
}
