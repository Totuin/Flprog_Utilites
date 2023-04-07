#include "flprogUtilites.h"
byte ethernet_mac[] = {0x78, 0xAC, 0xC0, 0x77, 0xE3, 0x05};
IPAddress ethernet_ip(192, 168, 1, 95);
byte ethernet_dns[] = {192, 168, 1, 1};
byte ethernet_gateway[] = {192, 168, 1, 1};
byte ethernet_subnet[] = {255, 255, 255, 0};

char server[] = "www.flprog.ru";

FLProgW5100TcpDevice tcpDevice;
FLProgUart uart1(&Serial);

void setup()
{
    Ethernet.begin(ethernet_mac, ethernet_ip, ethernet_dns, ethernet_gateway, ethernet_subnet);
    tcpDevice.setPort(80);
    tcpDevice.beClient();
    tcpDevice.begin();
    uart1.begin();
    delay(1000);
    uart1.print("connecting to ");
    uart1.print(server);
    uart1.println("...");
    tcpDevice.connect(server, 80);
    if (tcpDevice.connected())
    {
        uart1.print("connected to ");
        uart1.println(server);
        // Make a HTTP request:
        tcpDevice.println("GET /HTTP/1.1");
        tcpDevice.println("Host: www.flprog.ru");
        tcpDevice.println("Connection: close");
        tcpDevice.println();
    }
    else
    {
        // if you didn't get a connection to the server:
        uart1.println("connection failed");
    }
}

void loop()
{
    while (tcpDevice.available())
    {
        uart1.write(tcpDevice.read());
    }
}