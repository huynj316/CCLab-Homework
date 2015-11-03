//RGB LEDs
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
int brightness = 0

//Proximity Sensor
 int sensorLow = 0;
 int sensorHigh = 20;
 int trigPin = 3;
 int echoPin = 2;

//PIR Motion Sensor
int inputPin = 4;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;  


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //RGB LEDs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  //Proximity Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //PIR Motion Sensor
  pinMode(inputPin);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Proximity Sensor
  long distance;
  
  for (distance = 0; distance < 20; distance++) {
    int sensorValue = analogRead(A0);
    brightness--;
    setColor(255, 255, 255);
  }

  for (distance = 20; distance > 0; distance--) {
    brightness++;
    setColor(255,255,255);
  }

  //PIR Motion Sensor
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(redPin, LOW); // turn LED OFF
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    if (pirState == HIGH){
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  

}

void setColor (int r, int g, int b) {
  r = 255 - r;
  g = 255 - g;
  b = 255 - b;

  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}
