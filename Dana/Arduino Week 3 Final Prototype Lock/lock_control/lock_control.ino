const int switchPin = 13;
int setByte;

void setup() {
  // put your setup code here, to run once:
//initialize serial communication
Serial.begin(9600);
//initialize switch pin as output
pinMode(switchPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //check for connection
  if(Serial.available() > 0) {
    //save situation in setByte
    setByte = Serial.read();
    //if o open
    if (setByte == 'o') {
    digitalWrite(switchPin, LOW);
  }
  //if c close
  if (setByte == 'c') {
    digitalWrite(switchPin, HIGH);
  }
  //if d open 5 seconds then close
  if (setByte == 'd') {
    digitalWrite(switchPin, LOW);
    delay(5000);
    digitalWrite(switchPin, HIGH);
  }
} 
}
