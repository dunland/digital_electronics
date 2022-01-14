import processing.video.*;
import processing.sound.*;

SoundFile soundfile;

// Step 1. Declare a Movie object.
Movie movie;

void setup() {
  size(320, 240);

  // Step 2. Initialize Movie object. The file "testmovie.mov" should live in the data folder.
  movie = new Movie(this, "/home/dunland/OF/apps/of_projects/of_satellitePanner/bin/data/satellite_panner.mp4");
  soundfile = new SoundFile(this, "/home/dunland/Desktop/dateien/ÍS-2021/ZOOMH4N/210930-000_Flaggenwind.wav");

  // Step 3. Start playing movie and audio. To play just once play() can be used instead.
  soundfile.play();  
  movie.loop();
}

// Step 4. Read new frames from the movie.
void movieEvent(Movie movie) {
  movie.read();
}

// Step 5. Display movie.
void draw() {
  image(movie, 0, 0);
}
