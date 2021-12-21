import processing.dxf.*;

boolean record;

void setup() {
  size(500, 500, P3D);
}

void draw() {
  if (record) {
    beginRaw(DXF, "output.dxf");
  }

  // Do all your drawing here
  if (record) {
    endRaw();
    record = false;
  }
}

void keyPressed() {
  // Use a key press so that it doesn't make a million files
  if (key == 'r') {
    record = true;
  }
}
