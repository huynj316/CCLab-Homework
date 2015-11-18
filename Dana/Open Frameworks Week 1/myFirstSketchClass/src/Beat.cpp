//
//  BeatSquare.cpp
//  myFirstSketchClass
//
//  Created by Dana Martens on 11/5/15.
//
//

#include "Beat.h"

int xPos;
int xVel;
int height;
int width;
int yPos;
int yVel;
float volume;
int angle1;
float tempo;


void Beat::setup() {
    //--------------------set up ball motion
    ofSetWindowShape(600, 600);
    height = 50;
    width = 50;
    xPos = ofRandom(400);
    xVel = 10;
    yPos = ofRandom(200);
    angle1 = ofRandom(3);
    yVel = 7;
    volume = 0.6f;
    tempo = 1.0f;
    
    //-----------------load synth sounds
    beat.loadSound("sounds/beat.wav");
    beat.setVolume(volume);
    beat.setSpeed(tempo);
    beat.setMultiPlay(true);
    beat.play();
    beat.getIsPlaying();
    hit.loadSound("sounds/blurp_x.wav");
    hit.setVolume(volume +0.2f);
    
    cam3.setDistance(300);
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    
}

void Beat::draw(){

    if (beat.getIsPlaying() == false) {
        beat.play();
    }
    
    
    cam3.begin();
    ofPushMatrix(); //of pushmatrix, popmatrix and translate center in cameras view...
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    ofSetColor(140, 220, 10);
    ofFill();
    ofRect(xPos, yPos, width, height);
    ofSetColor(260, 50, 255);
    ofFill();
    ofRect(yPos, xPos, width, height);
    ofPopMatrix();
    cam3.end();
}

void Beat::update(){
    
    
    xPos = xPos + xVel;
    yPos = yPos + yVel;
    if (xPos < 0 || xPos > ofGetWidth()) {
        xVel = -xVel;
        tempo + 0.2f;
        volume = volume +0.1f;
        hit.play();
    }
    
    if (yPos < 0 || yPos > ofGetHeight()) {
        yVel = -yVel;
        tempo = tempo + 0.2f;
        volume = volume - 0.1f;
        hit.play();
    }
    
    if (xPos == yPos || yPos == xPos) {
        xVel = -xVel;
        yVel = -yVel;
        tempo = tempo - 0.2f;
        volume = volume + 0.1f;
        hit.play();
    }
    
}
