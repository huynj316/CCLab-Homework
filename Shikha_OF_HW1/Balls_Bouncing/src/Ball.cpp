//
//  Ball.cpp
//  inClassSketch
//
//  Created by Shikha Singh on 11/3/15.
//
//

#include "Ball.h"

int xPos;
int yPos;
int yVel;
int xVel;

void Ball::setup(){
    
    ofSetWindowShape(1000, 1000);
    
    xPos = 250;
    
    yPos = 250;
    
    xVel = 5;
    
    yVel = 5;
    

    
   
}

void Ball::update(){
    
    if (xPos >= ofGetWidth()){
        
        xVel = xVel + ofRandom(-5);
        
    }
    
    
    
    if(xPos < -1){
        
        xVel = xVel + ofRandom(5);
        
    }
    
    if (yPos >= ofGetHeight()){
        
        yVel = yVel + ofRandom(-5);
        
    }
    
    
    
    if(yPos < -1){
        
        yVel = yVel + ofRandom(5);
        
    }
        
    
    
}


void Ball::draw(){
    
    
    ofSetColor(255, 0, 127);
    ofFill();
    
//    ofCircle(xPos, ofGetHeight()/2, 20);
    
    ofCircle(xPos, yPos, 70);
    
    
    
    xPos = xPos + xVel;
    
    yPos = yPos + yVel;
    

    
    
    
    
}