//
//  Ball.cpp
//  mySketch
//
//  Created by Audrey on 11/9/15.
//
//

#include "Ball.hpp"
#include "ofApp.h"

void Ball::setup() {
    xPos = ofRandom(0,90);
    yPos = ofRandom(0,90);
    
    xSpeed = 2.8;
    ySpeed = 2.2;
    

    
}
void Ball::update() {
    
    xPos = xPos + xSpeed;
    yPos = yPos + ySpeed;
    
    
    if (xPos <0 || xPos >=ofGetWidth()) {
        xSpeed *=(-1);
    }
    if  (yPos <0 || yPos >= ofGetHeight()){
        ySpeed *=(-1);
    }
    
}
void Ball::draw() {
    
    ofCircle(xPos, yPos, ofRandom(5,50));
    
    
}