//
//  Ball.cpp
//  mySketch
//
//  Created by Raha Ghassemi on 11/3/15.
//
//

#include "Ball.h"
#include "ofApp.h"


void Ball::setup(){
    
    ofSetWindowShape(500, 500);
    
    xPos = 150;
    yPos = 150;
    xVel = 10;
    yVel = 10;
    
    
}

//--------------------------------------------------------------
void Ball::update(){
    
    if(xPos >= ofGetWidth()){
        xVel = xVel + ofRandom(-7);
    }
    
    if (xPos < -1) {
        xVel = xVel + ofRandom(7);
    }
    
    if (yPos >= ofGetHeight()) {
        yVel = yVel + ofRandom(-7);
    }
    
    if (yPos < -1) {
        yVel = yVel + ofRandom(7);
    }
    
}

//--------------------------------------------------------------
void Ball::draw(){
    
    
    
    ofCircle(xPos, yPos, 30);
    
    xPos = xPos + xVel;
    yPos = yPos + yVel;
    
    
    
}

//--------------------------------------------------------------
void Ball::keyPressed(int key){
    
}

//--------------------------------------------------------------
void Ball::keyReleased(int key){
    
}

//--------------------------------------------------------------
void Ball::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void Ball::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Ball::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Ball::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Ball::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void Ball::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void Ball::dragEvent(ofDragInfo dragInfo){
    
}


