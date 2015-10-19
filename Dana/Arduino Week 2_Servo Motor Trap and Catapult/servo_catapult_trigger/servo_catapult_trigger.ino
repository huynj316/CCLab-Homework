
#include <Servo.h>

Servo trigger;

int const potPin = A0;
int potVal;
int angle;

void setup() {
  trigger.attach(9);
  Serial.begin(9600); //read value from pin 9 to computer
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("pot Val: ");
  Serial.println(potVal);

  angle = map(potVal, 0, 1023, 0, 179); //map potentiometer value to angles in 180(range of motor)
  Serial.print(", angle: ");
  Serial.println(angle);

  //write angle to the servo that was mapped above by Pot
  trigger.write(angle);
  delay(15);
}
