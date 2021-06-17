class Instrument {
  boolean hit = false;
  char _key;

  Instrument(char key_in)
  {
    _key = key_in;
  }

  void update()
  {
    print(hit);
    hit = false;
  }

}
