
#include "flprogUtilites.h"

void AbstractFLProgClass::setFlags()
{
  if (_oldStatus != _status)
  {
    _isChangeStatus = true;
    _oldStatus = _status;
  }
  if (_oldError != _errorCode)
  {
    _isChangeError = true;
    _oldError = _errorCode;
  }
}

void AbstractTaskDevice::pool()
{
  // Режим может меняться после первого вызова pool(); старую задачу удаляет setType().
  if (!_task.isInit() || _activeTaskMode != _taskMode)
  {
    _task.setType(_taskMode);
    if (_task.isInit())
    {
      _activeTaskMode = _taskMode;
      _task.setQntPass(_taskQntPass);
      _task.setPeriod(_taskPeriod);
    }
  }
  _task.direct(_taskEn);
  if (_status != FLPROG_READY_STATUS)
  {
    init();
    return;
  }
  workPool();
}

bool AbstractFLProgClass::getIsChangeStatusWithReset()
{
  bool temp = _isChangeStatus;
  _isChangeStatus = false;
  return temp;
}

bool AbstractFLProgClass::getIsChangeErrorWithReset()
{
  bool temp = _isChangeError;
  _isChangeError = false;
  return temp;
}

bool AbstractFLProgClass::statusForExtGetBitWithReset(uint8_t bit)
{
  bool temp = bitRead(_statusForExt, bit);
  bitWrite(_statusForExt, bit, 0);
  return temp;
}

uint8_t AbstractFLProgI2CDevice::readRegister(uint8_t reg)
{
  RT_HW_Base.i2cWrite(_device, reg);
  RT_HW_Base.i2cRead(_device);
  return _device.bf8;
}

void AbstractFLProgI2CDevice::writeRegister(uint8_t reg, uint8_t value)
{
  uint8_t data[2];
  data[0] = reg;
  data[1] = value;
  RT_HW_Base.i2cWriteArr(_device, data, 2);
}

void AbstractFLProgI2CDevice::devicePool()
{
  if (_status == FLPROG_NOT_REDY_STATUS)
  {
    RT_HW_Base.i2cInitDevice(_device);
    if (!_device.link)
    {
      return;
    }
    if (_device.status == 1)
    {
      _status = FLPROG_WAIT_I2C_FIND_ADDRESS;
      return;
    }
    else
    {
      return;
    }
  }
  if (_status == FLPROG_WAIT_I2C_FIND_ADDRESS)
  {
    RT_HW_Base.i2cFindAdr(_device);
    if (!_device.link)
    {
      return;
    }
    if (_device.codeErr)
    {
      _status = FLPROG_WAIT_I2C_REFIND_ADDRES_PAUSE;
      _pauseStartTime = millis();
      return;
    }
    else
    {
      _status = FLPROG_WAIT_I2C_DEVICE_INIT;
      return;
    }
  }
  if (_status == FLPROG_WAIT_I2C_REFIND_ADDRES_PAUSE)
  {
    if (flprog::isTimer(_pauseStartTime, 1000))
    {
      _status = FLPROG_WAIT_I2C_FIND_ADDRESS;
    }
    else
    {
      return;
    }
  }
  if (_status == FLPROG_WAIT_I2C_DEVICE_INIT)
  {
    init();
    return;
  }
  if (_task.canWork())
  {
    workPool();
  }
  if (_device.codeErr)
  {
    _status = FLPROG_NOT_REDY_STATUS;
    return;
  }
}
/*
---------------------------------------
            namespace flprog
---------------------------------------
*/

//-------------Базовое--------------------
void flprog::specialSetup()
{
#ifdef RT_HW_SPECIAL_SETUP
  RT_HW_SPECIAL_SETUP
#endif
}
void flprog::specialPool()
{
#ifdef RT_HW_SPECIAL_POOL
  RT_HW_SPECIAL_POOL
#endif
}

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
// Считаем истиной "true", "да" и положительные числа, остальные строки — false.
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

// Разбор двоичной строки за O(n) без pow()/float; старшие разряды обрезаются,
// как и при обычной 32-битной беззнаковой арифметике.
uint32_t flprog::binStringToUnsignedLong(String value)
{
  uint32_t result = 0;
  for (uint16_t i = 0; i < value.length(); ++i)
  {
    result <<= 1;
    if (value.charAt(i) == '1')
    {
      result |= 1;
    }
  }
  return result;
}

//-----------------------------Работа с таймерами---------------------------------------------

// Беззнаковое вычитание корректно учитывает переполнение счётчика millis()/micros().
// В старой реализации на границе переполнения терялась одна единица времени.
uint32_t flprog::difference32(uint32_t start, uint32_t end)
{
  return end - start;
}

bool flprog::isTimer(uint32_t startTime, uint32_t period)
{
  return (difference32(startTime, (millis()))) >= period;
}

bool flprog::isTimerMicros(uint32_t startTime, uint32_t period)
{
  return (difference32(startTime, (micros()))) >= period;
}

// Момент времени на value миллисекунд раньше текущего (по модулю 2^32).
uint32_t flprog::timeBack(uint32_t value)
{
  return uint32_t(millis()) - value;
}

//------------------- Режимы уарт--------------------------------------

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

// Историческое правило FLProg: запрещены компоненты FF и адрес из одних нулей.
// Это строже общего формата IEEE 802 MAC-48; сохранено для совместимости.
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

// При некорректной строке исходный массив НЕ изменяем.
// Допускаются группы из одной или двух шестнадцатеричных цифр; групп ровно шесть.
void flprog::parseMacAddressString(String value, uint8_t *array)
{
  if (array == nullptr)
  {
    return;
  }

  uint8_t buffer[6];
  for (uint8_t i = 0; i < 6; ++i)
  {
    const int separator = value.indexOf(':');
    const String part = (separator < 0) ? value : value.substring(0, separator);
    if (part.length() < 1 || part.length() > 2)
    {
      return;
    }
    for (uint8_t j = 0; j < part.length(); ++j)
    {
      const char symbol = part.charAt(j);
      if (!flprog::isNumberChar(symbol) && !flprog::isHexNumberChar(symbol))
      {
        return;
      }
    }
    buffer[i] = uint8_t(flprog::hexStrToInt(part));
    if (i < 5)
    {
      if (separator < 0)
      {
        return;
      }
      value = value.substring(separator + 1);
    }
    else if (separator >= 0)
    {
      return; // Седьмой компонент недопустим.
    }
  }

  // Сохраняем прежнее правило допустимости MAC (проверка выполняется отдельно).
  if (flprog::checkMacAddres(buffer))
  {
    for (uint8_t i = 0; i < 6; ++i)
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

// Перевод до восьми HEX-цифр в число; поддерживаются оба регистра букв.
// Для использования здесь (один или два разряда MAC) переполнения int не происходит.
int flprog::hexStrToInt(String str)
{
  uint32_t result = 0;
  const uint16_t count = (str.length() > 8) ? 8 : str.length();
  for (uint16_t i = 0; i < count; ++i)
  {
    const char ch = str.charAt(i);
    uint8_t digit;
    if (ch >= '0' && ch <= '9') digit = ch - '0';
    else if (ch >= 'a' && ch <= 'f') digit = ch - 'a' + 10;
    else if (ch >= 'A' && ch <= 'F') digit = ch - 'A' + 10;
    else return 0;
    result = (result << 4) | digit;
  }
  return static_cast<int>(result);
}

// Старый парсер IPv4 (не используется stringToIp): заполняет IPAddress по октетам.
// Для строгой проверки произвольной строки рекомендуется checkIPAdressString().
bool flprog::inet_aton_1(const char *address, IPAddress &result)
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

// Порядок байтов: первый октет IPv4 — младший байт uint32_t.
// Так же работал исходный код на AVR/ESP, но без небезопасного приведения указателя.
uint32_t flprog::ipToNumber(IPAddress value)
{
  return uint32_t(value[0]) |
         (uint32_t(value[1]) << 8) |
         (uint32_t(value[2]) << 16) |
         (uint32_t(value[3]) << 24);
}

String flprog::ipToString(const IPAddress &ipAddress)
{
  return String(ipAddress[0]) + String(".") + String(ipAddress[1]) + String(".") + String(ipAddress[2]) + String(".") + String(ipAddress[3]);
}

// Обратная операция к ipToNumber, независимо от порядка байтов процессора.
IPAddress flprog::numberToIp(uint32_t value)
{
  IPAddress result;
  for (uint8_t i = 0; i < 4; ++i)
  {
    result[i] = uint8_t(value >> (8 * i));
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
  if (code == FLPROG_ETHERNET_NTP_NOT_SERVER_ERROR)
  {
    return "FLPROG_ETHERNET_NTP_NOT_SERVER_ERROR";
  }
  if (code == FLPROG_ETHERNET_CLIENT_ANSWER_TIMEOUT_ERROR)
  {
    return "FLPROG_ETHERNET_CLIENT_ANSWER_TIMEOUT_ERROR";
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
  if (code == FLPROG_WAIT_UDP_PACAGE_ANSVER)
  {
    return "FLPROG_WAIT_UDP_PACAGE_ANSVER";
  }
  if (code == FLPROG_WAIT_ETHERNET_CLIENT_CONNECT_STATUS)
  {
    return "FLPROG_WAIT_ETHERNET_CLIENT_CONNECT_STATUS";
  }
  if (code == FLPROG_WAIT_ETHERNET_CLIENT_ANSWER_STATUS)
  {
    return "FLPROG_WAIT_ETHERNET_CLIENT_ANSWER_STATUS";
  }
  return "Unknown status code: " + String(code);
#endif
}
