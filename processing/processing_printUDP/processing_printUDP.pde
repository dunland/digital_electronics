// import UDP library
import hypermedia.net.*;
UDP udp;  // define the UDP object
//String local_UDPAddress = "localhost";
String local_UDPAddress = "127.0.0.1";
//int local_UDPin = 6155;
int local_UDPin = 9001;

void setup()
{
        udp = new UDP(this, local_UDPin);
        // udp.log(true);
        udp.listen(true);
}

void draw()
{

}

void receive(byte[] data, String ip, int port)
{
  println("[" + hour() + "." + minute() + "." + second() + "] new message incoming: ");
  String message = new String(data);
  println(message);
}
