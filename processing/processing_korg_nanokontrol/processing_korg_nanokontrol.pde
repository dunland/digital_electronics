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

int midiChannel = 0, midiValue = 0;

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
  background(250);

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
  if (theOscMessage.checkAddrPattern("/midi/channel")==true)
  {
    midiChannel = theOscMessage.get(0).intValue();
    setMidiParams();
    print(midiChannel);
  } else if (theOscMessage.checkAddrPattern("/midi/value")==true)
  {
    midiValue = theOscMessage.get(0).intValue();
    setMidiParams();
    print(midiValue);
  }

  println("### received an osc message. with address pattern "+theOscMessage.addrPattern());
}

void setMidiParams()
{
  if (midiChannel == 41 && midiValue == 127)
  {
    bNewCircle = true;
  }
}
