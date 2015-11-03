

int DO = 2; //Pin for Digital Output - DO
int DA = A0; // Pin for Analog Output - AO
int threshold = 46; //Set minimum threshold for LED lit
int volume;
 
void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}
 
void loop() {
  volume = analogRead(DA);  //Read the analog value
  Serial.print("Analog: ");
  Serial.print(volume);  //Print the analog value
  Serial.print("  ");
  Serial.print("Digital: ");
  Serial.println(digitalRead(DO));  //Print the digital value
 
  if (volume >= threshold) { //Compare analog value with threshold
    digitalWrite(4, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(12, LOW); 
    digitalWrite(13, HIGH); 
  }
  else {
    digitalWrite(4, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
}
