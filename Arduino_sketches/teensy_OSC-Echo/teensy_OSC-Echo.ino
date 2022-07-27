#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCMatch.h>
#include <OSCTiming.h>
#include <OSCBoards.h>
#include <OSCData.h>
#include <SLIPEncodedUSBSerial.h>
#include <SLIPEncodedSerial.h>


#ifdef BOARD_HAS_USB_SERIAL
#include <SLIPEncodedUSBSerial.h>
SLIPEncodedUSBSerial SLIPSerial( thisBoardsSerialUSB );
#else
#include <SLIPEncodedSerial.h>
SLIPEncodedSerial SLIPSerial(Serial1);
#endif


void setup() {
  Serial.begin(9600);
  SLIPSerial.begin(9600);   // set this as high as you can reliably run on your platform
#if ARDUINO >= 100
  while (!Serial)
    ;   // Leonardo bug
#endif
}

void loop() {
  //make an empty message to fill with the incoming data
  OSCMessage msg;
  //wait for the end of the packet to be received
  while (!SLIPSerial.endofPacket()) {
    int size = SLIPSerial.available();
    if (size > 0) {
      //fill the msg with all of the available bytes
      while (size--) {
        msg.fill(SLIPSerial.read());
      }
    }
  }

  //returns true if the data in the first position is an integer
  if (msg.isInt(0)) {
    //get that integer
    int data = msg.getInt(0);
    Serial.println(data);
  }

  static int i = 0;
  Serial.println(i++);

}
