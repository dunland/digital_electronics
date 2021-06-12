void keyPressed() {
  for (Instrument instrument : instruments) {
    if (instrument._key == key) {
      instrument.hit = true;
      println(key, "=", instrument.hit);
      for (int i = 0; i < 200; i++)
      {
        selected_pixels[i] = int(random(image_y_pos, image_y_pos + width * height));
      }
    }
  }
}

void keyReleased() {
  for (Instrument instrument : instruments) {
    if (instrument._key == key) {
      instrument.hit = false;
      println(key, "=", instrument.hit);
    }
  }
}
