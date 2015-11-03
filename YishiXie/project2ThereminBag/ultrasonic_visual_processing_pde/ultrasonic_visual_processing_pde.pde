/*
Yishi Xie
Theremin Bag
Arduino final
 */

import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import ddf.minim.signals.*;
import ddf.minim.spi.*;
import ddf.minim.ugens.*;

import processing.serial.*;

PImage theremin, note;

int numOfNotes = 7; // Number of notes to display on screen 
int shapeSpeed = 5; // Speed at which the shapes move to new position


Note[] myNotes = new Note[numOfNotes];
int noteSize;
int distanceX, distanceY;
String comPortString;
Serial myPort;

Minim minim;
AudioPlayer song;

String[] notes= new String[20];

int value;
int noteValue;


void setup() {
  size(1300,963);
  //size(displayWidth, displayHeight);  //full screen
  smooth(); 
  
  theremin=loadImage("theremin.jpg");
  note=loadImage("note.png");
  
  /* Calculate the size of the Notes*/
  noteSize = (width/numOfNotes); 
  for (int i = 0; i<numOfNotes; i++) {
    myNotes[i]=new Note(int(noteSize*i), height-40);
  }

  /*Open the serial port for communication with the Arduino*/
  myPort = new Serial(this, "/dev/cu.usbmodem1421", 9600);
  myPort.bufferUntil('\n'); // Trigger a SerialEvent on new line

  minim=new Minim(this);
  notes[0]="A3-220.0.mp3";
  notes[1]="A4-440.0.mp3";
  notes[2]="Asharp3-233.08.mp3";
  notes[3]="Asharp4-466.16.mp3";
  notes[4]="B3-246.94.mp3";
  notes[5]="B4-493.88.mp3";
  notes[6]="C4-261.63.mp3";
  notes[7]="C5-523.25.mp3";
  notes[8]="Csharp4-277.18.mp3";
  notes[9]="Csharp5-554.37.mp3";
  notes[10]="D4-293.66.mp3";
  notes[11]="D5-587.33.mp3";
  notes[12]="Dsharp4-311.13.mp3";
  notes[13]="Dsharp5-622.25.mp3";
  notes[14]="E4-329.63.mp3";
  notes[15]="E5-659.26.mp3";
  notes[16]="F4-349.23.mp3";
  notes[17]="Fsharp4-369.99.mp3";
  notes[18]="G4-392.0.mp3";
  notes[19]="Gsharp4-415.3.mp3";
  frameRate(20);
}


void draw() {
  image(theremin, 0, 0);
  delay(10); 

  drawNotes(); 
  playNotes();
}


void playNotes(){
  noteValue=int(map(value, 0, height-80, 0, 9));
  if (noteValue<0 || noteValue>9) {
   noteValue=1;
  }
  println(noteValue);
   song=minim.loadFile(notes[noteValue]);
   song.play();
}


void serialEvent(Serial cPort) {
  comPortString = cPort.readStringUntil('\n');
  
  if (comPortString != null) {
    comPortString=trim(comPortString);
    println(comPortString);
    /* Use the distanceY received by the Arduino to modify the position of the Note. */
    distanceY = int(map(Integer.parseInt(comPortString), 1, 25, 1, height)); 
    distanceX = int(map(Integer.parseInt(comPortString), 1, 25, 1, width)); 
    
    
    value=distanceY;
    
    if (distanceY<0) {
      distanceY = 0;
    }
  }
}



void drawNotes() {
  int oldY, newY, targetY;
  int oldX, newX, targetX;

  /* Set the position of the Note based on sensor value received */
  myNotes[0].setY((height - note.height)-distanceY-20);
  myNotes[0].setX((width - note.width)-distanceX-120);
  

  /* Update the position each of the Notes */
  for (int i = numOfNotes-1; i>0; i--) {
    targetY=myNotes[i-1].getY();
    oldY=myNotes[i].getY();
    targetX=myNotes[i-1].getX();
    oldX=myNotes[i].getX();
    
      newY=oldY-((oldY-targetY)/shapeSpeed)-int(random(20));
      
      newX=oldX-((oldX-targetX)/shapeSpeed)-int(random(20));

    //Set the new position of the Note
    myNotes[i].setY(newY);
    myNotes[i].setX(newX);

    /* Draw the Note on the screen */
    image(note, myNotes[i].getX()-100, myNotes[i].getY()-200);
  }
}


class Note {
  int xPosition, yPosition;

  Note(int xPos, int yPos) {
    xPosition = xPos;
    yPosition = yPos;
  }

  int getX() {
    return xPosition;
  }

  int getY() {
    return yPosition;
  }

  void setY(int yPos) {
    yPosition = yPos;
  }
  
  void setX(int xPos) {
    xPosition = xPos;
  }
}

void stop() {
  super.stop();
}