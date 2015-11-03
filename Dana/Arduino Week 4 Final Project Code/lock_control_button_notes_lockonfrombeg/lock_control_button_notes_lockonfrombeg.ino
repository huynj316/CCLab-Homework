/* This tone code is was made by ianklatzco - https://gist.github.com/ianklatzco/9127560
 * He derived it from the http://www.arduino.cc/en/Tutorial/Melody
 * This plays the chest noise from the Legend of Zelda on a piezo buzzer connected to pin 8 
 * and ground when a button is pushed. 
 * Pushing the button also unlocks the electromagnetic lock for the chest for 2 seconds.
 */
  

const int switchPin = 13;
int setByte;
const int button = 2;
int buttonState = 0;
int speakerPin = 8;
char notes[] = "gabygabyxzCDxzCDabywabywzCDEzCDEbywFCDEqywFGDEqi        azbC"; // a space represents a rest
int length = sizeof(notes); // the number of notes
int beats[] = { 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 2,3,3,16,};
int tempo = 75;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'x', 'a', 'z', 'b', 'C', 'y', 'D', 'w', 'E', 'F', 'q', 'G', 'i' };
  // c=C4, C = C5. These values have been tuned.
  int tones[] = { 1898, 1690, 1500, 1420, 1265, 1194, 1126, 1063, 1001, 947, 893, 843, 795, 749, 710, 668, 630, 594 };
   
  // play the tone corresponding to the note name
  for (int i = 0; i < 18; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
//initialize serial communication
Serial.begin(9600);
//initialize switch pin as output
pinMode(switchPin, OUTPUT);
pinMode(button, INPUT);
digitalWrite(switchPin, HIGH);
digitalWrite(speakerPin, LOW);

}

void loop() {
pinMode(speakerPin, OUTPUT);
buttonState = digitalRead(button);
if (buttonState == HIGH) {
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    // pause between notes
    delay(tempo / 2); 
  } 
  }
  digitalWrite(switchPin, LOW;
  delay(2000);
} else if (buttonState == LOW) {
  digitalWrite(switchPin, HIGH);
}

//pinMode(speakerPin, OUTPUT);
//  if (buttonState == HIGH) {
//    for (int i = 0; i < length; i++) {
//    if (notes[i] == ' ') {
//      delay(beats[i] * tempo); // rest
//    } else {
//      playNote(notes[i], beats[i] * tempo);
//    }
//    
//    // pause between notes
//    delay(tempo / 2); 
//  }
//  }
//  delay(100);
  // put your main code here, to run repeatedly:
  //check for connection

//  if(Serial.available() > 0) {
//    //save situation in setByte
//    setByte = Serial.read();
//    //if o open
//    if (setByte == 'o') {
//    digitalWrite(switchPin, LOW);
//  }
//  //if c close
//  if (setByte == 'c') {
//    digitalWrite(switchPin, HIGH);
//  }
//  //if d open 5 seconds then close
//  if (setByte == 'd') {
//    digitalWrite(switchPin, LOW);
//    delay(5000);
//    digitalWrite(switchPin, HIGH);
//  }
//} 
 
}
