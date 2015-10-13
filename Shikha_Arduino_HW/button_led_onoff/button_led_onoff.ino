int buttonPin = 2;         
int ledPin = 13;       

int state = LOW;      // the current state of the ledPin
int reading;           // the current reading from the button pin
int previous = LOW;    // the previous reading from the button pin

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the led pin was toggled
long debounce = 50;   // the debounce time, increase if the output flickers

void setup()
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  reading = digitalRead(buttonPin);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == LOW){
      state = HIGH;
      Serial.println("on");
      
    }else{
      state = LOW;
      Serial.println("off");
      

    time = millis();    
  }
 }

  digitalWrite(ledPin, state);

  previous = reading;
}

