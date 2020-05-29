#include <DHT.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>   
float str1,str2; 
int start;
#define OLED_D0  7
#define OLED_D1   6
#define OLED_RES 5
#define OLED_DC    4
#define OLED_CS    3


#define PIN_DHT11 12

DHT dht(PIN_DHT11, DHT11);
//Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);  
Adafruit_SSD1306 display(OLED_D1, OLED_D0, OLED_DC, OLED_RES, OLED_CS);  
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2  

void setup()  
{  
  Serial.begin(9600);  
  Wire.begin();
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC);//初始化
  display.display();
  display.clearDisplay();
  delay(500); 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
   display.print("person_1:");
  display.println("chenhaoming"); 
  display.print("person_2:");
  display.println("jiangwentian "); 
  display.display();//显示出来
  delay(3000); 
  display.clearDisplay();
}    
void loop()  
{ 
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  delay(2000);  
  float h = dht.readHumidity();//读湿度
  float t = dht.readTemperature();//读温度，默认为摄氏度
  Serial.print("Humidity: ");  
  Serial.println(h);
  Serial.print("Temperature: ");  
  Serial.println(t);

  display.println("Temperature:");
  String  temperature=" ";
  temperature+=t;
  temperature+=" Celsius";
  display.println(temperature);
  display.println("Humidity: ");
  String humidity=" ";
  humidity+=h;
  humidity+=" RH";
  display.println(humidity);
 
//  display.println(temperature); 
//  display.println(humidity); 
//  display.println(); 
  display.display();//显示出来
  display.clearDisplay();
} 
