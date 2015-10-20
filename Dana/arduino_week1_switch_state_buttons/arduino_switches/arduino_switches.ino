int switchState = 0;


void setup() {
  // put your setup code here, to run once:

//pinModes

pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

//Switch State (check pin 2 to see if button is pressed or not)
switchState = digitalRead(2);


if (switchState == LOW) { //the button is not pressed

//commented out different variations
//  digitalWrite(3, HIGH);
//  delay(250);
//  digitalWrite(3, LOW);
//  delay(250);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

} else {  //the button is pressed
 
  delay(250);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);

  delay(250); //wait 1/4 second
  //toggle the LEDs
  digitalWrite(3,LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(250); //wait 1/4 

  //toggle the LEDs
  digitalWrite(3,LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(250); //wait 1/4 second
   
}

} //got back to the beginning of the loop
