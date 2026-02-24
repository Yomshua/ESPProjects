#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT11.h>
#include <iostream>
#include <string>


#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 32 
#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHT11 dht11(4);
using namespace std;
int num = 1;
int humidity = 0;
int temperature = 0;
String temperatura;
String humidade;

void setup() {

  Serial.begin(115200);
  
  pinMode(2, OUTPUT);
  

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); 
  }

  humidity = dht11.readHumidity();
  temperature = dht11.readTemperature();

  temperatura = String(temperature);
  temperatura = temperatura + " C  ";

  humidade = String(humidity);
  humidade = humidade + "%";

  display.display();
  delay(2000); 


  display.clearDisplay();
  display.setCursor(10, 10);
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.print(temperatura);

  display.setCursor(50, 10);
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.print(humidade);

  display.display();

}



void loop() {
 
  
/* 
  num += 1;
   display.clearDisplay();
   display.setCursor(10, 10);
   display.setTextColor(SSD1306_WHITE);
   display.setTextSize(1);
   display.print(num);
   display.display();
  digitalWrite(2,HIGH);
  delay(500);
  digitalWrite(2,LOW);
 */ 

  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2,LOW);

  display.clearDisplay();
  display.setCursor(10, 10);
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.print(temperatura);

  display.setCursor(50, 10);
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.print(humidade);

  display.display();



}
