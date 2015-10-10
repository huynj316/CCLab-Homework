int state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(3, INPUT);
}

void loop() {
  state = digitalRead(3);
  Serial.println(state);
  if(state == HIGH){
      digitalWrite(9, HIGH);
      delay(200);
  }else{
    digitalWrite(9, LOW);
  }
  delay(50);
   
}

