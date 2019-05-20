/*
   Tasks:
   1.Interface 16 pt100 sensors
   2.Switch relay based on set point temperature
   3.Interface RTC
   4.Interface Bluetooth
   5.Interface ESP8266
   6.Send notifications using Bluetooth and ESP8266
   7.Interface RS485
   8.Interface TCP/IP
   
   Progress:
   1.Completed relay test @ 8/3/19
   2.Completed sensor declations
*/

#include <Adafruit_MAX31865.h>
// The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RREF      430.0
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL  100.0
// Use software SPI: CS, DI, DO, CLK

//Sensor declarations
Adafruit_MAX31865 ch1 = Adafruit_MAX31865(2, 24, 25, 23);
Adafruit_MAX31865 ch2 = Adafruit_MAX31865(3, 24, 25, 23);
Adafruit_MAX31865 ch3 = Adafruit_MAX31865(4, 24, 25, 23);
Adafruit_MAX31865 ch4 = Adafruit_MAX31865(5, 24, 25, 23);

Adafruit_MAX31865 ch5 = Adafruit_MAX31865(6, 24, 25, 23);
Adafruit_MAX31865 ch6 = Adafruit_MAX31865(7, 24, 25, 23);
Adafruit_MAX31865 ch7 = Adafruit_MAX31865(8, 24, 25, 23);
Adafruit_MAX31865 ch8 = Adafruit_MAX31865(9, 24, 25, 23);

Adafruit_MAX31865 ch9 = Adafruit_MAX31865(10, 24, 25, 23);
Adafruit_MAX31865 ch10 = Adafruit_MAX31865(11, 24, 25, 23);
Adafruit_MAX31865 ch11 = Adafruit_MAX31865(12, 24, 25, 23);
Adafruit_MAX31865 ch12 = Adafruit_MAX31865(13, 24, 25, 23);

Adafruit_MAX31865 ch13 = Adafruit_MAX31865(42, 24, 25, 23);
Adafruit_MAX31865 ch14 = Adafruit_MAX31865(43, 24, 25, 23);
Adafruit_MAX31865 ch15 = Adafruit_MAX31865(44, 24, 25, 23);
Adafruit_MAX31865 ch16 = Adafruit_MAX31865(45, 24, 25, 23);
/*
  float ch1temp = ch1.temperature(RNOMINAL, RREF);
  uint16_t rtd1 = ch1.readRTD();
  float ratio1 = rtd1;
  float ch1sptemp = 35.0;
*/

//Relays

const int relay1 = 26;
const int relay2 = 27;
const int relay3 = 28;
const int relay4 = 29;

const int relay5 = 30;
const int relay6 = 31;
const int relay7 = 32;
const int relay8 = 33;

const int relay9 = 34;
const int relay10 = 35;
const int relay11 = 36;
const int relay12 = 37;

const int relay13 = 38;
const int relay14 = 39;
const int relay15 = 40;
const int relay16 = 41;

const int buzzer = 42;

//Sensor Temperatures

float ch1Temp;
float ch2Temp;
float ch3Temp;
float ch4Temp;

float ch5Temp;
float ch6Temp;
float ch7Temp;
float ch8Temp;

float ch9Temp;
float ch10Temp;
float ch11Temp;
float ch12Temp;

float ch13Temp;
float ch14Temp;
float ch15Temp;
float ch16Temp;

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit MAX31865 PT100 Sensor Test!");

  ch1.begin(MAX31865_2WIRE);  // set to 2WIRE or 4WIRE as necessary
  ch2.begin(MAX31865_2WIRE);
  ch3.begin(MAX31865_2WIRE);
  ch4.begin(MAX31865_2WIRE);
  
  ch5.begin(MAX31865_2WIRE);
  ch6.begin(MAX31865_2WIRE);
  ch7.begin(MAX31865_2WIRE);
  ch8.begin(MAX31865_2WIRE);
  
  ch9.begin(MAX31865_2WIRE);
  ch10.begin(MAX31865_2WIRE);
  ch11.begin(MAX31865_2WIRE);
  ch12.begin(MAX31865_2WIRE);
  
  ch13.begin(MAX31865_2WIRE);
  ch14.begin(MAX31865_2WIRE);
  ch15.begin(MAX31865_2WIRE);
  ch16.begin(MAX31865_2WIRE);
  
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);
  
  pinMode(relay9, OUTPUT);
  pinMode(relay10, OUTPUT);
  pinMode(relay11, OUTPUT);
  pinMode(relay12, OUTPUT);
  
  pinMode(relay13, OUTPUT);
  pinMode(relay14, OUTPUT);
  pinMode(relay15, OUTPUT);
  pinMode(relay16, OUTPUT);

  pinMode(buzzer, OUTPUT);

  //initial state
  digitalWrite(relay1, HIGH); // Turn the relay ON
  digitalWrite(relay2, HIGH); // Turn the relay ON
  digitalWrite(relay3, HIGH); // Turn the relay ON  
  digitalWrite(relay4, HIGH); // Turn the relay ON  
  digitalWrite(relay5, HIGH); // Turn the relay ON  
  digitalWrite(relay6, HIGH); // Turn the relay ON  
  digitalWrite(relay7, HIGH); // Turn the relay ON  
  digitalWrite(relay8, HIGH); // Turn the relay ON  
  digitalWrite(relay9, HIGH); // Turn the relay ON  
  digitalWrite(relay10, HIGH); // Turn the relay ON  
  digitalWrite(relay11, HIGH); // Turn the relay ON  
  digitalWrite(relay12, HIGH); // Turn the relay ON  
  digitalWrite(relay13, HIGH); // Turn the relay ON  
  digitalWrite(relay14, HIGH); // Turn the relay ON  
  digitalWrite(relay15, HIGH); // Turn the relay ON  
  digitalWrite(relay16, HIGH); // Turn the relay ON 

}

void relayTest()
{

  //Serial.print("Relay "); Serial.print(i+1);Serial.println(" ON");
  digitalWrite(relay1, LOW); // Turn the relay ON
  delay(500);
  digitalWrite(relay2, LOW); // Turn the relay ON
  delay(500);
  digitalWrite(relay3, LOW); // Turn the relay ON
  delay(500);
  digitalWrite(relay4, LOW); // Turn the relay ON
  delay(500);
  digitalWrite(relay5, LOW); // Turn the relay ON
  delay(500);
  digitalWrite(relay6, LOW); // Turn the relay ON
  delay(500);
  digitalWrite(relay7, LOW); // Turn the relay ON
  delay(500);
  digitalWrite(relay8, LOW); // Turn the relay ON
  delay(500);
  digitalWrite(relay9, LOW); // Turn the relay ON
  delay(500);
  digitalWrite(relay10, LOW); // Turn the relay ON
  delay(500);
  digitalWrite(relay11, LOW); // Turn the relay ON
  delay(500);
  digitalWrite(relay12, LOW); // Turn the relay ON
  delay(500);
  digitalWrite(relay13, LOW); // Turn the relay ON
  delay(500);
  digitalWrite(relay14, LOW); // Turn the relay ON
  delay(500);
  digitalWrite(relay15, LOW); // Turn the relay ON
  delay(500);
  digitalWrite(relay16, LOW); // Turn the relay ON
  delay(500);

  digitalWrite(relay1, HIGH); // Turn the relay ON
  delay(200);
  digitalWrite(relay2, HIGH); // Turn the relay ON
  delay(200);
  digitalWrite(relay3, HIGH); // Turn the relay ON
  delay(200);
  digitalWrite(relay4, HIGH); // Turn the relay ON
  delay(200);
  digitalWrite(relay5, HIGH); // Turn the relay ON
  delay(200);
  digitalWrite(relay6, HIGH); // Turn the relay ON
  delay(200);
  digitalWrite(relay7, HIGH); // Turn the relay ON
  delay(200);
  digitalWrite(relay8, HIGH); // Turn the relay ON
  delay(200);
  digitalWrite(relay9, HIGH); // Turn the relay ON
  delay(200);
  digitalWrite(relay10, HIGH); // Turn the relay ON
  delay(200);
  digitalWrite(relay11, HIGH); // Turn the relay ON
  delay(200);
  digitalWrite(relay12, HIGH); // Turn the relay ON
  delay(200);
  digitalWrite(relay13, HIGH); // Turn the relay ON
  delay(200);
  digitalWrite(relay14, HIGH); // Turn the relay ON
  delay(200);
  digitalWrite(relay15, HIGH); // Turn the relay ON
  delay(200);
  digitalWrite(relay16, HIGH); // Turn the relay ON
  delay(200);

}


void channel1() {
  uint16_t rtd = ch1.readRTD();
  ch1Temp = (ch1.temperature(RNOMINAL, RREF));
  Serial.print("RTD value: "); Serial.println(rtd);
  float ratio = rtd;
  ratio /= 32768;
  //Serial.print("Ratio = "); Serial.println(ratio,8);
  //Serial.print("Resistance = "); Serial.println(RREF*ratio,8);
  Serial.print("Channel 1 Temperature = "); Serial.println(ch1Temp);

  
  if((ch1.temperature(RNOMINAL, RREF))>40){
    digitalWrite(relay1,LOW);    
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
  }
  else{
  digitalWrite(relay1,HIGH);
  }
  // Check and print any faults
  uint8_t fault = ch1.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (fault & MAX31865_FAULT_HIGHTHRESH) {
      Serial.println("RTD High Threshold"); 
    }
    if (fault & MAX31865_FAULT_LOWTHRESH) {
      Serial.println("RTD Low Threshold"); 
    }
    if (fault & MAX31865_FAULT_REFINLOW) {
      Serial.println("REFIN- > 0.85 x Bias"); 
    }
    if (fault & MAX31865_FAULT_REFINHIGH) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_RTDINLOW) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_OVUV) {
      Serial.println("Under/Over voltage"); 
    }
    ch1.clearFault();
  }
//  Serial.println();
//  delay(5000);
}

void channel2() {
  uint16_t rtd = ch2.readRTD();
  ch2Temp = (ch2.temperature(RNOMINAL, RREF));
  Serial.print("RTD value: "); Serial.println(rtd);
  float ratio = rtd;
  ratio /= 32768;
  //Serial.print("Ratio = "); Serial.println(ratio,8);
  //Serial.print("Resistance = "); Serial.println(RREF*ratio,8);
  Serial.print("Channel 2 Temperature = "); Serial.println(ch2Temp);

  
  if((ch2.temperature(RNOMINAL, RREF))>40){
    digitalWrite(relay2,LOW);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
  }
  else{
  digitalWrite(relay2,HIGH);
  }
  // Check and print any faults
  uint8_t fault = ch2.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (fault & MAX31865_FAULT_HIGHTHRESH) {
      Serial.println("RTD High Threshold"); 
    }
    if (fault & MAX31865_FAULT_LOWTHRESH) {
      Serial.println("RTD Low Threshold"); 
    }
    if (fault & MAX31865_FAULT_REFINLOW) {
      Serial.println("REFIN- > 0.85 x Bias"); 
    }
    if (fault & MAX31865_FAULT_REFINHIGH) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_RTDINLOW) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_OVUV) {
      Serial.println("Under/Over voltage"); 
    }
    ch2.clearFault();
  }
//  Serial.println();
//  delay(5000);
}

void channel3() {
  uint16_t rtd = ch3.readRTD();
  ch3Temp = (ch3.temperature(RNOMINAL, RREF));
  Serial.print("RTD value: "); Serial.println(rtd);
  float ratio = rtd;
  ratio /= 32768;
  //Serial.print("Ratio = "); Serial.println(ratio,8);
  //Serial.print("Resistance = "); Serial.println(RREF*ratio,8);
  Serial.print("Channel 3 Temperature = "); Serial.println(ch3Temp);

  
  if((ch3.temperature(RNOMINAL, RREF))>40){
    digitalWrite(relay3,LOW);    
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
  }
  else{
  digitalWrite(relay3,HIGH);
  }
  // Check and print any faults
  uint8_t fault = ch3.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (fault & MAX31865_FAULT_HIGHTHRESH) {
      Serial.println("RTD High Threshold"); 
    }
    if (fault & MAX31865_FAULT_LOWTHRESH) {
      Serial.println("RTD Low Threshold"); 
    }
    if (fault & MAX31865_FAULT_REFINLOW) {
      Serial.println("REFIN- > 0.85 x Bias"); 
    }
    if (fault & MAX31865_FAULT_REFINHIGH) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_RTDINLOW) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_OVUV) {
      Serial.println("Under/Over voltage"); 
    }
    ch3.clearFault();
  }
//  Serial.println();
//  delay(5000);
}

void channel4() {
  uint16_t rtd = ch4.readRTD();
  ch4Temp = (ch4.temperature(RNOMINAL, RREF));
  Serial.print("RTD value: "); Serial.println(rtd);
  float ratio = rtd;
  ratio /= 32768;
  //Serial.print("Ratio = "); Serial.println(ratio,8);
  //Serial.print("Resistance = "); Serial.println(RREF*ratio,8);
  Serial.print("Channel 4 Temperature = "); Serial.println(ch4Temp);

  
  if((ch4.temperature(RNOMINAL, RREF))>40){
    digitalWrite(relay4,LOW);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
  }
  else{
  digitalWrite(relay4,HIGH);
  }
  // Check and print any faults
  uint8_t fault = ch4.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (fault & MAX31865_FAULT_HIGHTHRESH) {
      Serial.println("RTD High Threshold"); 
    }
    if (fault & MAX31865_FAULT_LOWTHRESH) {
      Serial.println("RTD Low Threshold"); 
    }
    if (fault & MAX31865_FAULT_REFINLOW) {
      Serial.println("REFIN- > 0.85 x Bias"); 
    }
    if (fault & MAX31865_FAULT_REFINHIGH) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_RTDINLOW) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_OVUV) {
      Serial.println("Under/Over voltage"); 
    }
    ch4.clearFault();
  }
  //Serial.println();
  //delay(5000);
}
void loop() {
  // put your main code here, to run repeatedly:
  //relayTest();
  channel1();
  channel2();
  channel3();
  channel4();
  Serial.println();
  delay(5000);
}
