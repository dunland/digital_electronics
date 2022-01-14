import gifAnimation.*;
GifMaker gifExport;
boolean exportGif = false; // activate if you want to export a gif

PVector dot;
PVector goal;
PVector previous;
int n = 1;
int t = 0;
float increment = 0;

ArrayList<PVector> goalsList = new ArrayList();

void setup()
{
        size(500, 500);

        if (exportGif)
        {
        gifExport = new GifMaker(this, "export.gif");
        gifExport.setRepeat(0);
        }

        goalsList.add(new PVector(random(1*width/4), random(1*height/4)));
        goalsList.add(new PVector(random(2*width/4), random(2*height/4)));
        goalsList.add(new PVector(random(3*width/4), random(3*height/4)));
        goalsList.add(new PVector(random(width), random(height)));

        previous = new PVector(goalsList.get(0).x, goalsList.get(0).y);
        goal = new PVector(goalsList.get(1).x, goalsList.get(1).y);

        dot = PVector.sub(goal,previous);
        dot.mult(increment);
        dot.add(previous);
}

void draw()
{
        if ((frameCount % 5) == 0 && exportGif)
        {
                gifExport.setDelay(1);
                gifExport.addFrame();
        }

        background(255);
        stroke(0);
        noFill();
        beginShape();
        vertex(goalsList.get(0).x, goalsList.get(0).y);
        vertex(goalsList.get(1).x, goalsList.get(1).y);
        vertex(goalsList.get(2).x, goalsList.get(2).y);
        vertex(goalsList.get(3).x, goalsList.get(3).y);
        vertex(goalsList.get(0).x, goalsList.get(0).y);
        endShape();

        if(dot.dist(goal) > 1)
        {
                dot = PVector.sub(goal,previous);
                dot.mult(increment);
                dot.add(previous);
        }
        else if (dot.dist(goal) < 1)
        {
                increment = 0;
                t = 0;
                previous.set(goalsList.get(n));
                n = (n + 1) % (goalsList.size());
                goal.set(goalsList.get(n));
                if (exportGif && n == 1)
                {
                        gifExport.finish();
                }
        }

        fill(255);
        ellipse(dot.x, dot.y, 20, 20);

        // linear movement normalized to vector length
        PVector v = PVector.sub(goal, previous);
        t ++;
        increment = t / v.mag();
}
