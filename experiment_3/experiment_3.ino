#include <DHT.h>

//定义针脚
#define PIN_DHT11 7
//定义类型，DHT11或者其它
#define DHTTYPE DHT11
//进行初始设置 
DHT dht(PIN_DHT11, DHTTYPE);

//int Relay_pin = 8;

void setup() {
//  pinMode(Relay_pin, OUTPUT);
  Serial.begin(9600);
  dht.begin(); //DHT开始工作
}

void loop() {
  // 两次检测之间，要等几秒钟，这个传感器有点慢。
  delay(2000);
  // 读温度或湿度要用250毫秒
  float h = dht.readHumidity();//读湿度
  float t = dht.readTemperature();//读温度，默认为摄氏度
  Serial.print("Humidity: ");//湿度
  Serial.println(h);
  Serial.print("Temperature: ");//温度
  Serial.print(t);
  Serial.println(" ℃ ");
  //digitalWrite(Relay_pin, HIGH);
  //t=20;
//  if (t >= 10){
//    digitalWrite(Relay_pin, LOW);
//    }
//  else{
//    digitalWrite(Relay_pin, HIGH);
//    }
}
