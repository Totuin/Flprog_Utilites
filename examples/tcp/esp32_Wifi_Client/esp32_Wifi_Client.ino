#include "flprogUtilites.h"

bool ESPControllerWifiClient_HRD = 0;
bool ESPControllerWifiClient_status = 1;
bool isWifiClientReconectWite = 0;
unsigned long startWifiClientReconectWite;
bool ESPControllerWifiClient_isDHCP = 0;
bool ESPControllerWifiClient_IsNeedReconect = 0;
bool ESPControllerWifiClient_workStatus = 1;
char ESPControllerWifiClient_SSID[40] = "yana";
char ESPControllerWifiClient_password[40] = "12345678";
IPAddress ESPControllerWifiClient_ip(192, 168, 1, 125);
IPAddress ESPControllerWifiClient_dns(192, 168, 1, 1);
IPAddress ESPControllerWifiClient_gateway(192, 168, 1, 1);
IPAddress ESPControllerWifiClient_subnet(255, 255, 255, 0);
uint8_t ESPControllerWifiClient_mac[6] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

char server[] = "www.flprog.ru";

FLProgWiFiTcpDevice tcpDevice;
FLProgUart uart1(&Serial);

void setup()
{
    WiFi.mode(WIFI_STA);
    if (WiFi.getAutoConnect() != true)
        WiFi.setAutoConnect(true);
    WiFi.setAutoReconnect(true);
    _esp32WifiModuleClientReconnect();
    _parseMacAddressString(WiFi.macAddress(), ESPControllerWifiClient_mac);

    tcpDevice.setPort(80);
    tcpDevice.beClient();
    tcpDevice.begin();
    uart1.begin();
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
    // Код для работы с WiFi модулем
    if (ESPControllerWifiClient_IsNeedReconect)
    {
        _esp32WifiModuleClientReconnect();
        ESPControllerWifiClient_IsNeedReconect = 0;
    }
    ESPControllerWifiClient_status = WiFi.status() == WL_CONNECTED;
    if (ESPControllerWifiClient_status)
    {
        if (!ESPControllerWifiClient_HRD)
        {
            ESPControllerWifiClient_ip = WiFi.localIP();
            ESPControllerWifiClient_subnet = WiFi.subnetMask();
            ESPControllerWifiClient_gateway = WiFi.gatewayIP();
            ESPControllerWifiClient_dns = WiFi.dnsIP();
            ESPControllerWifiClient_HRD = 1;
        }
    }
    else
    {
        ESPControllerWifiClient_HRD = 0;
    }
    if (ESPControllerWifiClient_workStatus && (!ESPControllerWifiClient_status))
    {
        if (!isWifiClientReconectWite)
        {
            isWifiClientReconectWite = 1;
            startWifiClientReconectWite = millis();
        }
        else
        {
            if (_isTimer(startWifiClientReconectWite, 5000))
            {
                WiFi.disconnect();
                _esp32WifiModuleClientReconnect();
                isWifiClientReconectWite = 0;
            }
        }
    }

    while (tcpDevice.available())
    {
        uart1.write(tcpDevice.read());
    }
}

// Функции необходимые для работы с модулем WiFi не имеющие отношения к Modbus
bool _isTimer(unsigned long startTime, unsigned long period)
{
    unsigned long currentTime;
    currentTime = millis();
    if (currentTime >= startTime)
    {
        return (currentTime >= (startTime + period));
    }
    else
    {
        return (currentTime >= (4294967295 - startTime + period));
    }
}

int hexStrToInt(String instring)
{
    byte len = instring.length();
    if (len == 0)
        return 0;
    int result = 0;
    for (byte i = 0; i < 8; i++)
    {
        char ch = instring[i];
        if (ch == 0)
            break;
        result <<= 4;
        if (isdigit(ch))
            result = result | (ch - '0');
        else
            result = result | (ch - 'A' + 10);
    }
    return result;
}
void _esp32WifiModuleClientReconnect()
{
    if (ESPControllerWifiClient_isDHCP)
    {
        WiFi.config(0U, 0U, 0U, 0U, 0U);
    }
    else
    {
        WiFi.config(ESPControllerWifiClient_ip, ESPControllerWifiClient_gateway, ESPControllerWifiClient_subnet, ESPControllerWifiClient_dns, ESPControllerWifiClient_dns);
    }
    WiFi.begin(ESPControllerWifiClient_SSID, ESPControllerWifiClient_password);
}
bool _checkMacAddres(byte array[])
{
    bool result = 0;
    for (byte i = 0; i < 6; i++)
    {
        if (array[i] == 255)
        {
            return 0;
        }
        if (array[i] > 0)
        {
            result = 1;
        }
    }
    return result;
}
void _parseMacAddressString(String value, byte array[])
{
    int index;
    byte buffer[6] = {255, 255, 255, 255, 255, 255};
    byte raz = 0;
    String tempString;
    while ((value.length() > 0) && (raz <= 6))
    {
        index = value.indexOf(":");
        if (index == -1)
        {
            tempString = value;
            value = "";
        }
        else
        {
            tempString = value.substring(0, index);
            value = value.substring(index + 1);
        }
        buffer[raz] = byte(hexStrToInt(tempString));
        raz++;
    }
    if (_checkMacAddres(buffer))
    {
        for (byte i = 0; i < 6; i++)
        {
            array[i] = buffer[i];
        }
    }
}
bool _compareMacAddreses(byte array1[], byte array2[])
{
    for (byte i = 0; i < 6; i++)
    {
        if (array1[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}
bool _compareMacAddresWithString(byte array[], String value)
{
    byte buffer[6] = {255, 255, 255, 255, 255, 255};
    _parseMacAddressString(value, buffer);
    return _compareMacAddreses(array, buffer);
}
bool _checkMacAddresString(String value)
{
    byte buffer[6] = {255, 255, 255, 255, 255, 255};
    _parseMacAddressString(value, buffer);
    return _checkMacAddres(buffer);
}
String _macAddresToString(byte array[])
{
    String result = "";
    String temp = "";
    for (byte i = 0; i < 6; i++)
    {
        temp = String(array[i], HEX);
        if (temp.length() < 2)
        {
            temp = String("0") + temp;
        }
        result = result + temp;
        if (i < 5)
        {
            result = result + String(":");
        }
    }
    result.toUpperCase();
    return result;
}
