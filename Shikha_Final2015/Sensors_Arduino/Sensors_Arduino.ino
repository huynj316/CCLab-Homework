#include <Servo.h>

Servo servoLeft;
Servo servoRight;

//touch sensor

int fsrAnalogPin = 1;
int fsrReading; 

//Dust Sensor
int dustPin = 0;
int dustVal = 0;

int ledPower = 2;
int delayTime = 280;
int delayTime2 = 40;

float offTime = 9680;


// Temperature & Humidity
//int DHpin = 4;
//byte dat [5];
//byte read_data () {
//  byte data;
//  for (int i = 0; i < 8; i ++) {
//    if (digitalRead (DHpin) == LOW) {
//      while (digitalRead (DHpin) == LOW); // wait for 50us
//      delayMicroseconds (30); // determine the duration of the high level to determine the data is '0 'or '1'
//      if (digitalRead (DHpin) == HIGH)
//        data |= (1 << (7 - i)); // high front and low in the post
//      while (digitalRead (DHpin) == HIGH); // data '1 ', wait for the next one receiver
//    }
//  }
//  return data;
//}



void setup() {

  Serial.begin(9600);
  pinMode(ledPower, OUTPUT);
  pinMode(12, OUTPUT);
//  pinMode (DHpin, OUTPUT);

  servoLeft.attach(9);
  servoRight.attach(10);
  


}


void loop() {


  // Reading particulate matter

  digitalWrite(ledPower, LOW);
  delayMicroseconds(delayTime);
  dustVal = analogRead(dustPin);
  delayMicroseconds(delayTime2);
  digitalWrite(ledPower, HIGH);
  delayMicroseconds(offTime);

  Serial.print("D");
  Serial.print(",");  
  Serial.println(dustVal);

  



  if (dustVal >= 0 && dustVal < 600) {
    servoLeft.write(80);
    servoRight.write(100);
 
  } else {
    servoLeft.write(45);
    servoRight.write(135);
  }
  


  //Reading temperature

//  temp ();

  //      Serial.print ("Humdity =");
  //      Serial.print (dat [0], DEC); // display the humidity-bit integer;
  //      Serial.print ('.');
  //      Serial.print (dat [1], DEC); // display the humidity decimal places;
  //      Serial.println ('%');
//  Serial.print ("T");
//  Serial.print (",");
//  Serial.print (dat [2], DEC); // display the temperature of integer bits;
//  Serial.print ('.');
//  Serial.println (dat [3], DEC); // display the temperature of decimal places;

  touch();
  delay (2000);




}



//void temp () {
//  digitalWrite (DHpin, LOW); // bus down, send start signal
//  delay (30); // delay greater than 18ms, so DHT11 start signal can be detected
//
//  digitalWrite (DHpin, HIGH);
//  delayMicroseconds (40); // Wait for DHT11 response
//
//  pinMode (DHpin, INPUT);
//  while (digitalRead (DHpin) == HIGH);
//  delayMicroseconds (80); // DHT11 response, pulled the bus 80us
//  if (digitalRead (DHpin) == LOW);
//  delayMicroseconds (80); // DHT11 80us after the bus pulled to start sending data
//
//  for (int i = 0; i < 4; i ++) // receive temperature and humidity data, the parity bit is not considered
//    dat[i] = read_data ();
//
//  pinMode (DHpin, OUTPUT);
//  digitalWrite (DHpin, HIGH); // send data once after releasing the bus, wait for the host to open the next Start signal
//}

void touch(){
  fsrReading = analogRead(fsrAnalogPin);
  Serial.print ("C");
  Serial.print (",");
  Serial.println(fsrReading); 
  }



