/*
 *!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * This example uses Smooth's fork of the artNet library.
 * https://github.com/SmoothTechnology/Artnet
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * Simply prints incomming data and responds to artPoll with name an IP info.


*/

#include <Artnet.h>

// #include <Ethernet.h>
// #include <EthernetUdp.h>

#include <SPI.h>

Artnet artnet;

// Change ip and mac address for your setup

void setup()
{
  Serial.begin(115200);
  Serial.println("ArtnetReceive Sketch");

  byte mac[6];

  artnet.teensyMAC(mac); // if using teensy get real mac//
  //  byte mac[] = {0x04, 0xE9, 0xE5, 0x00, 0x69, 0xEC};   // else create fake mac

  artnet.begin(mac); // for DHCP

  // byte ip[] = {192, 168, 0, 198};  // for static ip
  // artnet.begin(mac, ip);

  artnet.setName("Teensy Artnet Boy"); // set name for artPoll reply (how it shows up in resolume etc.)
}

void loop()
{
  if (artnet.read() == ART_DMX)
  {
    // print out our data
    Serial.print("universe number = ");
    Serial.print(artnet.getUniverse());
    Serial.print("\tdata length = ");
    Serial.print(artnet.getLength());
    Serial.print("\tsequence n0. = ");
    Serial.println(artnet.getSequence());
    // Serial.print("DMX data: ");
    // for (int i = 0 ; i < artnet.getLength() ; i++)
    // {
    //   Serial.print(artnet.getDmxFrame()[i]);
    //   Serial.print("  ");
    // }
    // Serial.println();
    Serial.println();
  }
}
