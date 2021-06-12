class Dots {

  int density = 10;
  int _width = 20;

  Dots() {}
}

void updateDots()
{
  switch (mode) {
  case 0:
    if (dotsWidth > dotsMinWidth) {
      dotsWidth -= dotsShrinkFactor;
      println("dotsWidth = ", dotsWidth);
    }
    break;

  case 1:
    dotsWidth = abs(sin(frameCount * 0.03) * 20);
    break;

  case 2:
    dotsWidth = (mouseX/width) * 20;
    // dotsDensity = mouseX/width * 20;
    break;
  }
}
