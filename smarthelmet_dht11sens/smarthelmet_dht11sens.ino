#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
  
const int pResistor = A0;  
const int buzzer= 7;        
const int gasSensor= A1;    
const int hLight= 8;        
const int redLed=9;         

int dTemp = 35; 
int dGas = 400;    
int bValue= 10;  

int gasValue;
int lightValue;
float tempValue;

void setup()
{
  Serial.begin(9600);
  pinMode(hLight,OUTPUT);
  pinMode(redLed, OUTPUT);
  delay(10000);
  dht.begin();
}

void loop()
{ 
  Serial.println();

  //float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  //Serial.print('Humidity %');
  //Serial.println(h);
  if(!isnan(t)){
    tempValue = t;
    Serial.println(t);
  }
  else{
    Serial.println(tempValue);
  }

  //Serial.println('Temperatuture C');
  //Serial.print(t);
  
  gasValue   = analogRead(gasSensor);
  delay(100);
  lightValue = analogRead(pResistor);
  delay(100);

   
    if (gasValue >= dGas+100 && gasValue < dGas+200)
    {
    //tone(buzzer, 1000);
    digitalWrite(redLed,HIGH);
    delay(150);
    noTone(buzzer);
    digitalWrite(redLed,LOW);
    delay(150);
  }
    else if (gasValue >= dGas+200 && gasValue < dGas+300){
    //tone(buzzer, 1000);
    digitalWrite(redLed,HIGH);
    delay(100);
    noTone(buzzer);
    digitalWrite(redLed,LOW);
    delay(100);
  }
    else if (gasValue >= dGas+300 && gasValue < dGas+400){
    tone(buzzer, 1000);
    digitalWrite(redLed,HIGH);
    delay(75);
    noTone(buzzer);
    digitalWrite(redLed,LOW);
    delay(75);
  }
    else if (gasValue >= dGas+400 && gasValue < dGas+500){
    tone(buzzer, 1000);
    digitalWrite(redLed,HIGH);
    delay(50);
    noTone(buzzer);
    digitalWrite(redLed,LOW);
    delay(50);
  }
    else if (gasValue >= dGas+500 && gasValue < dGas+600){
    tone(buzzer, 1000);
    digitalWrite(redLed,HIGH);
    delay(25);
    noTone(buzzer);
    digitalWrite(redLed,LOW);
    delay(25);
  }
    else if (gasValue >= dGas+600){
    tone(buzzer, 1000);
    digitalWrite(redLed,HIGH);
  }
    else if (t < dTemp+15 ){
    noTone(buzzer);
    digitalWrite(redLed,LOW);
  }
    else{}
    
  if (t >= dTemp+15 && t<16 ){
    //tone(buzzer, 600);
    digitalWrite(redLed, HIGH);
    delay(150);
    noTone(buzzer);
    digitalWrite(redLed, LOW);
    delay(150);
  }
    else if (t >= dTemp+16 && t<17){
   // tone(buzzer, 600);
    digitalWrite(redLed, HIGH);
    delay(125);
    noTone(buzzer);
    digitalWrite(redLed, LOW);
    delay(125);
  }
    else if (t >= dTemp+17 && t<18){
    //tone(buzzer, 600);
    digitalWrite(redLed, HIGH);
    delay(100);
    noTone(buzzer);
    digitalWrite(redLed, LOW);
    delay(100);
  }
    else if (t >= dTemp+18 && t<19){
    digitalWrite(redLed, HIGH);
    delay(75);
    noTone(buzzer);
    digitalWrite(redLed, LOW);
    delay(75);
  }
      else if (t >= dTemp+19){
    tone(buzzer, 600);
    digitalWrite(redLed, HIGH);
  }
  else if(gasValue <= 700){
    noTone(buzzer);
    digitalWrite(redLed, LOW);
  }
  else {}
  if (lightValue > bValue){
    digitalWrite(hLight, LOW);
  }
  else{
    digitalWrite(hLight, HIGH);
  }
}
