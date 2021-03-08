#include <Arduino.h>
#include <dht11.h>
 

dht11 DHT11;
//定义传感器连接引脚。此处的PIN2在NodeMcu8266开发板上对应的引脚是D4
#define DHT11PIN 2
 

double Fahrenheit(double celsius)
{
  //摄氏温度度转化为华氏温度
  return 1.8 * celsius + 32; 
}
 
double Kelvin(double celsius)
{
  //摄氏温度转化为开氏温度
  return celsius + 273.15;
}

void setup()
{
  Serial.begin(115200);
  Serial.println("\n");
  Serial.print("DHT11库文件版本: ");
  Serial.println(DHT11LIB_VERSION);
  Serial.println();
}
 

void loop()
{
  Serial.println("\n");

  //读取传感器数据
  DHT11.read(DHT11PIN);
 
  Serial.print("当前湿度( % ): ");
  Serial.println((float)DHT11.humidity, 2);
 
  Serial.print("当前温度( ℃ ): ");
  Serial.println((float)DHT11.temperature, 2);
 
  Serial.print("当前温度( ℉ ): ");
  Serial.println(Fahrenheit(DHT11.temperature), 2);
 
  Serial.print("当前温度( K ): ");
  Serial.println(Kelvin(DHT11.temperature), 2);

  delay(3000);
}
