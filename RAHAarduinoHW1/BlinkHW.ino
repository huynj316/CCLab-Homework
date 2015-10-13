/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
int led = 13;
int buttonPin = 2;
int buttonState;
int stateLED = LOW;
int previous = LOW;
long times = 0;
long debounce = 200;


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin 13 as an output.
  pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH && previous == LOW && millis() - times > debounce){
    if(stateLED == HIGH) {
      stateLED = LOW;
    } else {
      stateLED = HIGH;
    }
    times = millis();
  }
  digitalWrite(led, stateLED);   
  previous == buttonState;

}
