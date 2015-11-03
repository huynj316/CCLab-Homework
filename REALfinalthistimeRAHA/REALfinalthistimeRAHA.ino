int REDPIN = 11;
int GREENPIN = 10;
int BLUEPIN = 9;
int REDPIN2 = 3;
int GREENPIN2 = 6;
int BLUEPIN2 = 5;
int LEDPin = 13;
int brightness = 0;
int FADESPEED = 5;
long duration, distance;

#define trigPin 8
#define echoPin 7
int minimumRange = 0;
int maximumRange = 50;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);

  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(REDPIN2, OUTPUT);
  pinMode(GREENPIN2, OUTPUT);
  pinMode(BLUEPIN2, OUTPUT);
  pinMode(LEDPin, OUTPUT);


  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //Calculate the distance (in cm) based on the speed of sound.
  distance = duration / 58.2;
  if (distance >= maximumRange || distance <= minimumRange) {
    /* Send a negative number to computer and Turn LED ON
    to indicate "out of range" */
    Serial.println("-1");
    digitalWrite(LEDPin, HIGH);
  }
  else {
    /* Send the distance to the computer using Serial protocol, and
    turn LED OFF to indicate successful reading. */
    Serial.println(distance);
    digitalWrite(LEDPin, LOW);
  }
  //Delay 50ms before next reading.
  delay(50);

  if (distance > 10){

 brightness = map(distance, minimumRange, maximumRange, 255, 0);

 brightness = constrain (brightness, 0, 255);

 analogWrite(BLUEPIN, brightness);
 analogWrite(BLUEPIN2, brightness);
 
  }

 if (distance <= 10 && distance > 0){
  analogWrite(REDPIN, 255);
  analogWrite(REDPIN2, 255);
  analogWrite(BLUEPIN, 0);
  analogWrite(BLUEPIN2, 0);
  tone(4, 400);
  delay(1000);
  noTone(4);
  

 } else if (distance > 10){
  analogWrite(REDPIN, 0);
  analogWrite(REDPIN2, 0);
 }


  
}
