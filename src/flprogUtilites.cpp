
#include "flprogUtilites.h"

/*
---------------------------------------
            namespace flprog
---------------------------------------
*/
//-------------Тестирование--------------------
bool flprog::isNumberChar(char value)
{
    return ((value == '0') || (value == '1') || (value == '2') || (value == '3') || (value == '4') || (value == '5') || (value == '6') || (value == '7') || (value == '8') || (value == '9'));
}
bool flprog::isHexNumberChar(char value)
{
    return ((value == 'A') || (value == 'a') || (value == 'B') || (value == 'b') || (value == 'C') || (value == 'c') || (value == 'D') || (value == 'd') || (value == 'E') || (value == 'e') || (value == 'F') || (value == 'f'));
}

//-------------Конвертация------------------------
bool flprog::stringToBool(String value)
{
    if (value.length() == 0)
    {
        return false;
    }
    value.toLowerCase();
    if (value.equals("true"))
    {
        return true;
    }
    if (value.equals("да"))
    {
        return true;
    }
    if (value.toInt() > 0)
    {
        return true;
    }
    return false;
}

char flprog::stringToChar(String value)
{
    if (value.length() == 0)
    {
        return (char)0;
    }
    return value.charAt(0);
}

int32_t flprog::hexStringToLong(String value)
{
    if (value.length() == 0)
    {
        return 0;
    }
    bool isNegaded = false;
    String temp;
    if (value.charAt(0) == '-')
    {
        temp = value.substring(1);
        isNegaded = true;
    }
    else
    {
        temp = value;
    }
    int32_t decValue = flprog::hexStringToUnsignedLong(temp);
    if (isNegaded)
    {
        decValue = 0 - decValue;
    }
    return decValue;
}

uint32_t flprog::hexStringToUnsignedLong(String value)
{
    if (value.length() == 0)
    {
        return 0;
    }
    uint32_t decValue = 0;
    int16_t nextInt;
    for (uint16_t i = 0; i < value.length(); i++)
    {
        nextInt = int(value.charAt(i));
        if (nextInt >= 48 && nextInt <= 57)
        {
            nextInt = map(nextInt, 48, 57, 0, 9);
        }
        if (nextInt >= 65 && nextInt <= 70)
        {
            nextInt = map(nextInt, 65, 70, 10, 15);
        }
        if (nextInt >= 97 && nextInt <= 102)
        {
            nextInt = map(nextInt, 97, 102, 10, 15);
        }
        nextInt = constrain(nextInt, 0, 15);
        decValue = (decValue * 16) + nextInt;
    }
    return decValue;
}

int32_t flprog::binStringToLong(String value)
{
    if (value.length() == 0)
    {
        return 0;
    }
    bool isNegaded = false;
    String temp;
    if (value.charAt(0) == '-')
    {
        temp = value.substring(1);
        isNegaded = true;
    }
    else
    {
        temp = value;
    }
    int32_t result = flprog::binStringToUnsignedLong(temp);
    if (isNegaded)
    {
        result = 0 - result;
    }
    return result;
}

uint32_t flprog::binStringToUnsignedLong(String value)
{
    uint32_t result = 0;
    uint8_t powNumber = 0;
    for (int16_t i = (value.length() - 1); i >= 0; i--)
    {
        if ((value.charAt(i)) == '1')
        {
            result = result + (pow(2, powNumber));
        }
        powNumber++;
    }
    return result;
}

// ----------------Управление Uart---------

#ifdef FLPROG_COMPACT_LIBRARY_MODE
static FLProgCompactUartStruct flprogCompactUart;
#endif

void flprog::beginUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    Serial.begin(flprogCompactUart.speed);
    flprogCompactUart.status = 1;
#else
    RT_HW_Base.uartBegin(number);
#endif
}

void flprog::endUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    Serial.end();
    flprogCompactUart.status = 0;
#else
    RT_HW_Base.uartEnd(number);

#endif
}

int flprog::availableUart(uint8_t number)
{
    if (getStatusUart(number) == 0)
    {
        beginUart(number);
        return 0;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    return Serial.available();
#else
    return RT_HW_Base.uartAvailable(number);
#endif
}

uint8_t flprog::readUart(uint8_t number)
{
    if (getStatusUart(number) == 0)
    {
        beginUart(number);
        return 0;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    return Serial.read();
#else
    return RT_HW_Base.uartRead(number);
#endif
}

void flprog::writeUart(uint8_t val, uint8_t number)
{
    if (getStatusUart(number) == 0)
    {
        beginUart(number);
        return;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    Serial.write(val);
#else
    RT_HW_Base.uartWrite(val, number);
#endif
}

void flprog::writeUart(uint8_t *buffer, uint16_t size, uint8_t number)
{
    if (getStatusUart(number) == 0)
    {
        beginUart(number);
        return;
    }
    for (uint16_t i = 0; i < size; i++)
    {
        writeUart(buffer[i], number);
    }
}

void flprog::setSpeedUart(uint32_t speed, uint8_t number)
{
    uint32_t newSpeed;
    if (speed < 50)
    {
        newSpeed = speedFromCode(speed);
    }
    else
    {
        newSpeed = speed;
    }

    if (getSpeedUart(number) == newSpeed)
    {
        return;
    }

#ifdef FLPROG_COMPACT_LIBRARY_MODE
    flprogCompactUart.speed = speed;
#else
    RT_HW_Base.uartSetSpeed(newSpeed, number);
#endif
    endUart(number);
}

void flprog::setDataBitUart(uint8_t value, uint8_t number)
{
    if (getDataBitUart(number) == value)
    {
        return;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    flprogCompactUart.dataBit = value;
#else
    RT_HW_Base.uartSetDataBit(value, number);
#endif
    endUart(number);
}

void flprog::setStopBitUart(uint8_t value, uint8_t number)
{
    if (getStopBitUart(number) == value)
    {
        return;
    }

#ifdef FLPROG_COMPACT_LIBRARY_MODE
    flprogCompactUart.stopBit = value;
#else
    RT_HW_Base.uartSetStopBit(value, number);
#endif
    endUart(number);
}

void flprog::setParityUart(uint8_t value, uint8_t number)
{
    if (getParityUart(number) == value)
    {
        return;
    }
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    flprogCompactUart.parity = value;
#else
    RT_HW_Base.uartSetParity(value, number);
#endif
    endUart(number);
}

void flprog::setPinRxUart(uint8_t pin, uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)pin;
    (void)number;
#else
    if (getPinRxUart(number) == pin)
    {
        return;
    }
    RT_HW_Base.uartSetPinRX(pin, number);
    endUart(number);
#endif
}

void flprog::setPinTxUart(uint8_t pin, uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)pin;
    (void)number;
#else
    if (getPinTxUart(number) == pin)
    {
        return;
    }
    RT_HW_Base.uartSetPinTX(pin, number);
    endUart(number);
#endif
}

void flprog::setPinsUart(uint8_t pinRx, uint8_t pinTx, uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)pinRx;
    (void)pinTx;
    (void)number;
#else
    if (getPinRxUart(number) == pinRx)
    {
        if (getPinTxUart(number) == pinTx)
        {
            return;
        }
    }
    RT_HW_Base.uartSetPins(pinRx, pinTx, number);
    endUart(number);
#endif
}

uint32_t flprog::getSpeedUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.speed;
#else
    return RT_HW_Base.uartGetSpeed(number);
#endif
}

uint8_t flprog::getDataBitUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.dataBit;
#else
    return RT_HW_Base.uartGetDataBit(number);
#endif
}

uint8_t flprog::getStopBitUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.stopBit;

#else
    return RT_HW_Base.uartGetStopBit(number);
#endif
}

uint8_t flprog::getParityUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.parity;
#else
    return RT_HW_Base.uartGetParity(number);
#endif
}

uint8_t flprog::getPinRxUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return 0;
#else
    return RT_HW_Base.uartGetPinRX(number);
#endif
}

uint8_t flprog::getPinTxUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return 1;
#else
    return RT_HW_Base.uartGetPinTX(number);
#endif
}

uint8_t flprog::getStatusUart(uint8_t number)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)number;
    return flprogCompactUart.status;
#else
    return RT_HW_Base.uartGetStatus(number);
#endif
}

//-----------------------------Работа с таймерами---------------------------------------------

uint32_t flprog::difference32(uint32_t start, uint32_t end)
{
    if (end >= start)
    {
        return end - start;
    }
    return (0xfFFFFFFF - start) + end;
}

bool flprog::isTimer(uint32_t startTime, uint32_t period)
{
    return (difference32(startTime, (millis()))) >= period;
}

bool flprog::isTimerMicros(uint32_t startTime, uint32_t period)
{
    return (difference32(startTime, (micros()))) >= period;
}

uint32_t flprog::timeBack(uint32_t value)
{
    uint32_t current = millis();
    if (value < current)
    {
        return current - value;
    }
    return (0xfFFFFFFF - value) + current;
}

//------------------- Режимы уарт--------------------------------------
uint32_t flprog::speedFromCode(uint8_t code)
{
    switch (code)
    {
    case FLPROG_SPEED_300:
        return 300;
        break;
    case FLPROG_SPEED_600:
        return 600;
        break;
    case FLPROG_SPEED_1200:
        return 1200;
        break;
    case FLPROG_SPEED_2400:
        return 2400;
        break;
    case FLPROG_SPEED_4800:
        return 4800;
        break;
    case FLPROG_SPEED_9600:
        return 9600;
        break;
    case FLPROG_SPEED_14400:
        return 14400;
        break;
    case FLPROG_SPEED_19200:
        return 19200;
        break;
    case FLPROG_SPEED_28800:
        return 28800;
        break;
    case FLPROG_SPEED_38400:
        return 38400;
        break;
    case FLPROG_SPEED_57600:
        return 57600;
        break;
    case FLPROG_SPEED_115200:
        return 115200;
        break;
    default:
        return 9600;
        break;
    }
}

uint8_t flprog::codeFromSpeed(int32_t speed)
{
    switch (speed)
    {
    case 300:
        return FLPROG_SPEED_300;
        break;
    case 600:
        return FLPROG_SPEED_600;
        break;
    case 1200:
        return FLPROG_SPEED_1200;
        break;
    case 2400:
        return FLPROG_SPEED_2400;
        break;
    case 4800:
        return FLPROG_SPEED_4800;
        break;
    case 9600:
        return FLPROG_SPEED_9600;
        break;
    case 14400:
        return FLPROG_SPEED_14400;
        break;
    case 19200:
        return FLPROG_SPEED_19200;
        break;
    case 28800:
        return FLPROG_SPEED_28800;
        break;
    case 38400:
        return FLPROG_SPEED_38400;
        break;
    case 57600:
        return FLPROG_SPEED_57600;
        break;
    case 115200:
        return FLPROG_SPEED_115200;
        break;
    }
    return FLPROG_SPEED_9600;
}

int flprog::serialCodeForParametrs(byte portDataBits, byte portStopBits, byte portParity)
{
    int code = 0;
    if (portStopBits == 2)
    {
        code = code + 8;
    }
    if (portDataBits == 6)
    {
        code = code + 2;
    }
    if (portDataBits == 7)
    {
        code = code + 4;
    }
    if (portDataBits == 8)
    {
        code = code + 6;
    }
    if (portParity == 1)
    {
        code = code + 32;
    }
    if (portParity == 2)
    {
        code = code + 48;
    }
    return code;
}

//--------------------------------------Сетевые утилиты------------------------------------------------------
bool flprog::applyMac(uint8_t m0, uint8_t m1, uint8_t m2, uint8_t m3, uint8_t m4, uint8_t m5, uint8_t *target)
{
    bool result = false;

    if (m0 != target[0])
    {
        target[0] = m0;
        result = true;
    }
    if (m1 != target[1])
    {
        target[1] = m1;
        result = true;
    }
    if (m2 != target[2])
    {
        target[2] = m2;
        result = true;
    }
    if (m3 != target[3])
    {
        target[3] = m3;
        result = true;
    }
    if (m4 != target[4])
    {
        target[4] = m4;
        result = true;
    }
    if (m5 != target[5])
    {
        target[5] = m5;
        result = true;
    }
    return result;
}

bool flprog::checkMacAddres(uint8_t *target)
{
    bool result = 0;
    for (uint8_t i = 0; i < 6; i++)
    {
        if (target[i] == 255)
        {
            return false;
        }
        if (target[i] > 0)
        {
            result = true;
        }
    }
    return result;
}

void flprog::parseMacAddressString(String value, uint8_t *array)
{
    int index;
    uint8_t buffer[6] = {255, 255, 255, 255, 255, 255};
    uint8_t raz = 0;
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
        buffer[raz] = byte(flprog::hexStrToInt(tempString));
        raz++;
    }
    if (flprog::checkMacAddres(buffer))
    {
        for (uint8_t i = 0; i < 6; i++)
        {
            array[i] = buffer[i];
        }
    }
}

String flprog::macAddresToString(uint8_t *array)
{
    String result = "";
    String temp = "";
    for (uint8_t i = 0; i < 6; i++)
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

bool flprog::checkMacAddresString(String value)
{
    uint8_t buffer[6] = {255, 255, 255, 255, 255, 255};
    parseMacAddressString(value, buffer);
    return checkMacAddres(buffer);
}

bool flprog::compareMacAddresWithString(uint8_t *array, String value)
{
    return value.equals(macAddresToString(array));
}

bool flprog::compareMacAddreses(uint8_t *array1, uint8_t *array2)
{
    for (uint8_t i = 0; i < 6; i++)
    {
        if (array1[i] != array2[i])
        {
            return 0;
        }
    }
    return 1;
}

int flprog::hexStrToInt(String str)
{
    uint8_t len = str.length();
    if (len == 0)
        return 0;
    int result = 0;
    for (uint8_t i = 0; i < 8; i++) // только первые 8 цыфар влезуть в uint32
    {
        char ch = str[i];
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

bool flprog::inet_aton(const char *address, IPAddress &result)
{
    uint16_t acc = 0;
    uint8_t dots = 0;
    while (*address)
    {
        char c = *address++;
        if (c >= '0' && c <= '9')
        {
            acc = acc * 10 + (c - '0');
            if (acc > 255)
            {
                return false;
            }
        }
        else if (c == '.')
        {
            if (dots == 3)
            {
                return false;
            }
            result[dots++] = acc;
            acc = 0;
        }
        else
        {
            return false;
        }
    }
    if (dots != 3)
    {
        return false;
    }
    result[3] = acc;
    return true;
}

void flprog::ipToArray(IPAddress ip, uint8_t *array)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        array[i] = ip[i];
    }
}

uint32_t flprog::ipToNumber(IPAddress value)
{
    uint8_t bufer[4] = {0, 0, 0, 0};
    for (uint8_t i = 0; i < 4; i++)
    {
        bufer[i] = value[i];
    }
    unsigned long *y = (unsigned long *)&bufer;
    return y[0];
}

String flprog::ipToString(const IPAddress &ipAddress)
{
    return String(ipAddress[0]) + String(".") + String(ipAddress[1]) + String(".") + String(ipAddress[2]) + String(".") + String(ipAddress[3]);
}

IPAddress flprog::numberToIp(uint32_t value)
{
    IPAddress result;
    uint8_t *x = (uint8_t *)&value;
    for (uint8_t i = 0; i < 4; i++)
    {
        result[i] = x[i];
    }
    return result;
}

bool flprog::checkIPAdressString(String value)
{
    IPAddress temp;
    return temp.fromString(value);
}

IPAddress flprog::stringToIp(String value)
{
    IPAddress temp;
    temp.fromString(value);
    return temp;
}

String flprog::flprogErrorCodeName(uint8_t code)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    return String(code);
#else
    if (code == FLPROG_NOT_ERROR)
    {
        return "FLPROG_NOT_ERROR";
    }
    if (code == FLPROG_ETHERNET_HARDWARE_INIT_ERROR)
    {
        return "ETH_HW_INIT_ERR";
    }
    if (code == FLPROG_ETHERNET_INTERFACE_NOT_READY_ERROR)
    {
        return "FLPROG_ETHERNET_INTERFACE_NOT_READY_ERROR";
    }
    if (code == FLPROG_ETHERNET_SOKET_INDEX_ERROR)
    {
        return "FLPROG_ETHERNET_SOKET_INDEX_ERROR";
    }
    if (code == FLPROG_ETHERNET_DHCP_NOT_CORRECT_RESULT_ERROR)
    {
        return "FLPROG_ETHERNET_DHCP_NOT_CORRECT_RESULT_ERROR";
    }
    if (code == FLPROG_ETHERNET_DHCP_TIMEOUT_ERROR)
    {
        return "FLPROG_ETHERNET_DHCP_TIMEOUT_ERROR";
    }
    if (code == FLPROG_ETHERNET_DHCP_DISCOVERY_ERROR_ID_ERROR)
    {
        return "FLPROG_ETHERNET_DHCP_DISCOVERY_ERROR_ID_ERROR";
    }

    if (code == FLPROG_ETHERNET_DHCP_REREQUEST_ERROR_ID_ERROR)
    {
        return "FLPROG_ETHERNET_DHCP_REREQUEST_ERROR_ID_ERROR";
    }
    if (code == FLPROG_ETHERNET_DHCP_REREQUEST_NAK_ERROR)
    {
        return "FLPROG_ETHERNET_DHCP_REREQUEST_NAK_ERROR";
    }
    if (code == FLPROG_ETHERNET_DHCP_NOT_DEFINED_ERROR)
    {
        return "FLPROG_ETHERNET_DHCP_NOT_DEFINED_ERROR";
    }
    if (code == FLPROG_ETHERNET_DNS_NOT_READY_ERROR)
    {
        return "FLPROG_ETHERNET_DNS_NOT_READY_ERROR";
    }
    if (code == FLPROG_ETHERNET_DNS_INVALID_SERVER)
    {
        return "FLPROG_ETHERNET_DNS_INVALID_SERVER";
    }
    if (code == FLPROG_ETHERNET_DNS_TRUNCATED)
    {
        return "FLPROG_ETHERNET_DNS_TRUNCATED";
    }
    if (code == FLPROG_ETHERNET_DNS_INVALID_RESPONSE)
    {
        return "FLPROG_ETHERNET_DNS_INVALID_RESPONSE";
    }
    if (code == FLPROG_ETHERNET_UDP_SOKET_START_ERROR)
    {
        return "FLPROG_ETHERNET_UDP_SOKET_START_ERROR";
    }
    if (code == FLPROG_ETHERNET_UDP_TIMEOUT_ERROR)
    {
        return "FLPROG_ETHERNET_UDP_TIMEOUT_ERROR";
    }
    if (code == FLPROG_ETHERNET_SOKET_NOT_INIT_ERROR)
    {
        return "FLPROG_ETHERNET_SOKET_NOT_INIT_ERROR";
    }
    if (code == FLPROG_ETHERNET_SOKET_UDP_NOT_CORRECT_DATA_ERROR)
    {
        return "FLPROG_ETHERNET_SOKET_UDP_NOT_CORRECT_DATA_ERROR";
    }
    if (code == FLPROG_ETHERNET_SOKET_SEND_TIMEOUT_ERROR)
    {
        return "FLPROG_ETHERNET_SOKET_SEND_TIMEOUT_ERROR";
    }
    if (code == FLPROG_ETHERNET_LINK_OFF_ERROR)
    {
        return "FLPROG_ETHERNET_LINK_OFF_ERROR";
    }
    if (code == FLPROG_ETHERNET_CLIENT_SOKET_START_ERROR)
    {
        return "FLPROG_ETHERNET_CLIENT_SOKET_START_ERROR";
    }
    if (code == FLPROG_ETHERNET_CLIENT_CONNECT_TIMEOUT_ERROR)
    {
        return "FLPROG_ETHERNET_CLIENT_CONNECT_TIMEOUT_ERROR";
    }
    if (code == FLPROG_ETHERNET_CLIENT_SOKET_CLOSED_ERROR)
    {
        return "FLPROG_ETHERNET_CLIENT_SOKET_CLOSED_ERROR";
    }
    if (code == FLPROG_ETHERNET_SERVER_NOT_CALLBACK_ERROR)
    {
        return "FLPROG_ETHERNET_SERVER_NOT_CALLBACK_ERROR";
    }
    if (code == FLPROG_ETHERNET_SERVER_SOKET_ERROR)
    {
        return "FLPROG_ETHERNET_SERVER_SOKET_ERROR";
    }
    if (code == FLPROG_ETHERNET_DHCP_NOT_READY_ERROR)
    {
        return "FLPROG_ETHERNET_DHCP_NOT_READY_ERROR";
    }
    return "Unknown error code: " + String(code);
#endif
}

String flprog::flprogStatusCodeName(uint8_t code)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    return String(code);
#else
    if (code == FLPROG_NOT_REDY_STATUS)
    {
        return "FLPROG_NOT_REDY_STATUS";
    }
    if (code == FLPROG_READY_STATUS)
    {
        return "FLPROG_READY_STATUS";
    }
    if (code == FLPROG_WAIT_ETHERNET_HARDWARE_INIT_STATUS)
    {
        return "FLPROG_WAIT_ETHERNET_HARDWARE_INIT_STATUS";
    }
    if (code == FLPROG_WAIT_ETHERNET_DHCP_STATUS)
    {
        return "FLPROG_WAIT_ETHERNET_DHCP_STATUS";
    }
    if (code == FLPROG_WAIT_ETHERNET_DNS_STATUS)
    {
        return "FLPROG_WAIT_ETHERNET_DNS_STATUS";
    }
    if (code == FLPROG_WAIT_ETHERNET_UDP_STATUS)
    {
        return "FLPROG_WAIT_ETHERNET_UDP_STATUS";
    }
    if (code == FLPROG_WAIT_ETHERNET_CLIENT_CONNECT_STATUS)
    {
        return "FLPROG_WAIT_ETHERNET_CLIENT_CONNECT_STATUS";
    }
    if (code == FLPROG_WAIT_ETHERNET_LINK_ON_STATUS)
    {
        return "FLPROG_WAIT_ETHERNET_LINK_ON_STATUS";
    }
    if (code == FLPROG_ETHERNET_HARDWARE_INIT_STATUS)
    {
        return "FLPROG_ETHERNET_HARDWARE_INIT_STATUS";
    }
    if (code == FLPROG_WAIT_ETHERNET_CONNECT_STATUS)
    {
        return "FLPROG_WAIT_ETHERNET_CONNECT_STATUS";
    }
    if (code == FLPROG_WAIT_WIFI_CLIENT_CONNECT_STATUS)
    {
        return "FLPROG_WAIT_WIFI_CLIENT_CONNECT_STATUS";
    }
    if (code == FLPROG_WAIT_ETHERNET_START_CLIENT_CONNECT_STATUS)
    {
        return "FLPROG_WAIT_ETHERNET_START_CLIENT_CONNECT_STATUS";
    }
    if (code == FLPROG_WAIT_WEB_SERVER_READ_REQEST)
    {
        return "FLPROG_WAIT_WEB_SERVER_READ_REQEST";
    }
    if (code == FLPROG_WAIT_WEB_SERVER_SEND_ANSVER)
    {
        return "FLPROG_WAIT_WEB_SERVER_SEND_ANSVER";
    }
    if (code == FLPROG_WAIT_SEND_UDP_PACAGE)
    {
        return "FLPROG_WAIT_SEND_UDP_PACAGE";
    }
    return "Unknown status code: " + String(code);
#endif
}

void flprog::printConsole(String title)
{
#ifdef FLPROG_COMPACT_LIBRARY_MODE
    (void)title;
#else
    RT_HW_Base.consoleBegin();
    if (!RT_HW_Base.console.head)
    {
        return;
    }

    RT_HW_Base.consoleCR(3);
    if (title.length() > 0)
    {
        RT_HW_Base.consoleHead(title, '=');
    }
    RT_HW_Base.consoleHead(String(F("Main parameters")), '-');
    RT_HW_Base.mess.modePin = 'T';
    RT_HW_Base.consoleBoardGeneral();
    // RT_HW_Base.consoleTest(String(F("FLPROG->Code CORE")),(uint8_t)FLPROG_CORE_CODE,';');
    // RT_HW_Base.consoleTest(String(F(" Name CORE")),(String)FLPROG_CORE_NAME);
    RT_HW_Base.consoleHead(String(F("Add parameters")));
    RT_HW_Base.mess.modePin = 'T';
    RT_HW_Base.consoleBoardAdd();
    RT_HW_Base.consoleHead(String(F("Task parameters")));
    RT_HW_Base.consoleShedulerParameters();
    // RT_HW_Base.consoleHead(String(F("PGM array")));
    // RT_HW_Base.mess.modePin='T'; RT_HW_Base.consoleFromPGM();
    RT_HW_Base.consoleHead(String(F("Available pins")));
    RT_HW_Base.mess.modePin = 'A';
    RT_HW_Base.consolePinsAll();
    RT_HW_Base.consoleHead(String(F("Interface")));
    RT_HW_Base.mess.modePin = 'T';
    RT_HW_Base.consoleInterface();
    RT_HW_Base.consoleHead(String(F("System & test pins")));
    RT_HW_Base.mess.modePin = 'T';
    RT_HW_Base.consolePinsSystem();
    RT_HW_Base.consolePinsTest();
    // RT_HW_Base.consoleHead(String(F("Scan i2c")));
    // RT_HW_Base.mess.modePin='T'; RT_HW_Base.i2cScanBus(0);
    RT_HW_Base.consoleLine('+');

#endif
}
