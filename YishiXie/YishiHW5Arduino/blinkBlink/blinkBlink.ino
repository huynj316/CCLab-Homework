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
//pin 13 has an LED connected on arduino board
int led1 = 13;
int led2 = 12;
int buttonPin = 2;
int buttonState = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  //start the serial connetion from 9600 bits/second
  Serial.begin(9600);
  // initialize digital pin 13 as an output.
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buttonPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  //read the button
  buttonState = digitalRead(buttonPin);
  //diff perform depending on the state of button
  if(buttonState == HIGH){
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(300);              // wait for a second
  digitalWrite(led1, LOW);
  delay(300);
  digitalWrite(led2, HIGH);
  delay(300);
  digitalWrite(led2, LOW);
  delay(300);
  Serial.println("LED1 and LED2 are blinking");

  } else {
    digitalWrite(led2, HIGH);    // turn the LED off by making the voltage LOW
  delay(600);
  digitalWrite(led2, LOW); 
  delay(600);  
  digitalWrite(led1, LOW);
  Serial.println("LED2 is blinking");
  }
}
