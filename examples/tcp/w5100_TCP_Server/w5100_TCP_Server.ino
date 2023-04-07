#include "flprogUtilites.h"
byte ethernet_mac[] = {0x78, 0xAC, 0xC0, 0x77, 0xE3, 0x05};
IPAddress ethernet_ip(192, 168, 1, 95);
byte ethernet_dns[] = {192, 168, 1, 1};
byte ethernet_gateway[] = {192, 168, 1, 1};
byte ethernet_subnet[] = {255, 255, 255, 0};
int counter = 0;
FLProgW5100TcpDevice tcpDevice;


void setup() {
  Ethernet.begin(ethernet_mac, ethernet_ip, ethernet_dns, ethernet_gateway, ethernet_subnet);
  tcpDevice.setPort(80);
  tcpDevice.beServer();
  tcpDevice.begin();
}

void loop() {
  tcpDevice.connect();
  if (tcpDevice.connected()) {
    tcpDevice.println("HTTP/1.1 200 OK");
    tcpDevice.println("Content-Type: text/html");
    tcpDevice.println("Connection: close");  // the connection will be closed after completion of the response
    tcpDevice.println("Refresh: 5");  // refresh the page automatically every 5 sec
    tcpDevice.println();
    tcpDevice.println("<!DOCTYPE HTML>");
    tcpDevice.println("<html>");
    tcpDevice.print("<br>ArduinoFlprog<br>");
    tcpDevice.print("<br>");
    tcpDevice.print(String(counter));
    tcpDevice.print("<br>");
    tcpDevice.println("</html>");
    counter++;
  }

  delay(1);
  tcpDevice.stop();
}