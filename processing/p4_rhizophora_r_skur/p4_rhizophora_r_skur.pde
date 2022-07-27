import netP5.*;
import oscP5.*;

OscP5 oscP5;

// import UDP library
import hypermedia.net.*;
UDP udp;  // define the UDP object
//String local_UDPAddress = "localhost";
String local_UDPAddress = "127.0.0.1";
//int local_UDPin = 6155;
int local_UDPin = 9001;

ArrayList<Circle> circles = new ArrayList<Circle>();
boolean bNewCircle = false;
color bgColor = color(255);

void setup()
{
  size(800, 800);
  // udp = new UDP(this, local_UDPin);
  // udp.log(true);
  // udp.listen(true);
  oscP5 = new OscP5(this, local_UDPin);
}

void draw()
{
  background(bgColor);

  if (bNewCircle)
  {
    bNewCircle = false;
    circles.add(new Circle(random(width), random(height)));
  }
  
  updateCircles();

  for (Circle circle : circles)
  {
    circle.draw();
  }
}

void receive(byte[] data, String ip, int port)
{
  println("[" + hour() + "." + minute() + "." + second() + "] new message incoming: ");
  String message = new String(data);
  println(message);
}

void oscEvent(OscMessage theOscMessage)
{
  /* check if theOscMessage has the address pattern we are looking for. */

  if (theOscMessage.checkAddrPattern("/test")==true) {
    /* check if the typetag is the right one. */
    if (theOscMessage.checkTypetag("ifs")) {
      /* parse theOscMessage and extract the values from the osc message arguments. */
      int firstValue = theOscMessage.get(0).intValue();
      float secondValue = theOscMessage.get(1).floatValue();
      String thirdValue = theOscMessage.get(2).stringValue();
      print("### received an osc message /test with typetag ifs.");
      println(" values: "+firstValue+", "+secondValue+", "+thirdValue);
      return;
    }
  } else if (theOscMessage.checkAddrPattern("/kick")==true) {
    //circles.add(new Circle(random(width), random(height)));
    println("kick!");
    bNewCircle = true;
  } else if (theOscMessage.checkAddrPattern("/snare")==true)
  {
    bgColor = color(random(255), random(255), random(255));
  } else if (theOscMessage.checkAddrPattern("/bp")==true) {
    //circles.add(new Circle(random(width), random(height)));
    println(theOscMessage.get(0).floatValue());
  }

  println("### received an osc message. with address pattern "+theOscMessage.addrPattern());
}
