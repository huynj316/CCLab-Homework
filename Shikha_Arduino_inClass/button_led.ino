int led = 13;
int buttonPin = 2;
int buttonState = 0;


void setup() {
  
  Serial.begin(9600);
  
  pinMode(led, OUTPUT);
  
  pinMode(buttonPin, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  
  buttonState = digitalRead(buttonPin);
  
  if(buttonState == HIGH){
    digitalWrite(led, HIGH);
    Serial.println("on");

    
  } else {
    digitalWrite(led, LOW);
    Serial.println("off");

    
  }
}
