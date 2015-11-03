int REDPIN = 3;
int BLUEPIN = 5;
int GREENPIN = 6;
#define FADESPEED 40

int thresholdONE = 100; //Change This
int thresholdTWO = 200;
int thresholdTHREE = 300;

int volume;
 

void setup() {                
  Serial.begin(9600); // For debugging
 
  pinMode(REDPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
       
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);

  volume = analogRead(A0); // Reads the value from the Analog PIN A0

  int r, g, b;
  
  if(volume>=thresholdONE){
    digitalWrite (REDPIN, 0); //Turn ON Led
    delay(FADESPEED);  
  }  
  else{
    digitalWrite(REDPIN, LOW);// Turn OFF Led
    digitalWrite(GREENPIN, LOW);
    digitalWrite(BLUEPIN, LOW);
  }


if(volume>=thresholdTWO){
    digitalWrite (GREENPIN, HIGH); //Turn ON Led
    delay(FADESPEED);  
  }  
  else{
    digitalWrite(REDPIN, LOW);// Turn OFF Led
    digitalWrite(GREENPIN, LOW);
    digitalWrite(BLUEPIN, LOW);
  }

if(volume>=thresholdTHREE){
    digitalWrite (BLUEPIN, HIGH); //Turn ON Led
    delay(FADESPEED);  
  }  
  else{
    digitalWrite(REDPIN, LOW);// Turn OFF Led
    digitalWrite(GREENPIN, LOW);
    digitalWrite(BLUEPIN, LOW);
  }

}

