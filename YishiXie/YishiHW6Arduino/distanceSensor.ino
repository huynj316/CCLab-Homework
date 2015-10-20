int trigPin = 3;
int echoPin = 2;
 int ledPin = 9;
 int brightness = 0;
 int sensorLow = 3;
 int sensorHigh = 200;

 
void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
//sensor
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
//led
pinMode(ledPin, OUTPUT);
}

void loop() {
  
  int duration, distance;
    digitalWrite(trigPin, HIGH); 
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  // print out the value of distance:
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
  //make the value of brightness between 0 and 255
  brightness = map(distance, sensorLow, sensorHigh, 0, 255);
  analogWrite(ledPin, brightness); 
  
}
