//
//  Ball.cpp
//  myFirstSketchClass
//
//  Created by Dana Martens on 11/3/15.
//
//

#include "Ball.h"

int xPos1;
int xVel1;
int radius;
int yPos1;
int yVel1;
int angle;
bool ballPressed;

void Ball::setup() {
    //--------------------set up ball motion
    ofSetWindowShape(600, 600);
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    cam2.setDistance(200);
    
    radius = 25;
    xPos1 = 10;
    xVel1 = 4;
    yPos1 = 10;
    angle = ofRandom(-1.0, 1.0);
    yVel1 = 5;
    bool ballPressed = false;
    
    
    //-----------------load synth sounds
    synth.loadSound("sounds/bloop_x.wav");
    boing.loadSound("sounds/spring.wav");
    boing.setVolume(0.8f);
    synth.setVolume(0.8f);
    
}

void Ball::draw(){
    cam2.begin();
    ofPushMatrix(); //of pushmatrix, popmatrix and translate center in cameras view...
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    ofSetColor(255, 0, 124);
    ofFill();
    ofCircle(xPos1, yPos1, radius);
    ofSetColor(220, 100, 124);
    ofFill();
    ofCircle(yPos1, xPos1, radius);
    ofSetColor(200, 120, 214);
    ofFill();
    ofCircle(yPos1*ofRandom(2), xPos1*ofRandom(2), radius+10);
    ofPopMatrix();
    cam2.end();
}

void Ball::update(){
    xPos1 = xPos1 + xVel1;
    yPos1 = yPos1 + yVel1;
    if (xPos1 < 0 || xPos1 > ofGetWidth()) {
        xVel1 = -xVel1+angle;
        radius = radius + 2;
        synth.play();
    }
    
    if (yPos1 < 0 || yPos1 > ofGetHeight()) {
        yVel1 = -yVel1-angle;
         radius = radius - 2;
        synth.play();
    }
    
    if (xPos1 == yPos1 || yPos1 == xPos1) {
        xVel1 = -xVel1;
        yVel1 = -yVel1;
        boing.play();
    
    }
    
  
    
}

//--------------------------------------------------------------
void Ball::mouseDragged(int mouseX, int mouseY, int button){

}

void Ball::mouseMoved(int x, int y ){

}


//--------------------------------------------------------------
void Ball::mousePressed(int x, int y, int button){
    float distance = ofDist(xPos1, yPos1, x, y);
    if(distance < radius)
    {
        radius = radius + 2;
        boing.play();
        ballPressed = true;
}
    
    if (ballPressed == true) {
        xVel1 = xVel1 + .05;
        yVel1 = yVel1 + .05;
    }
    
    ballPressed = false;
}

//--------------------------------------------------------------
void Ball::mouseReleased(int x, int y, int button){
    ballPressed = false;
}


