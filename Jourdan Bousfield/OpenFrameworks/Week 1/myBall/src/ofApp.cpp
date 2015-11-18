#include "ofApp.h"

int xPos;

int yPos;

int xVel;

int yVel;



//--------------------------------------------------------------

void ofApp::setup(){
    
    
    
    ofSetWindowShape(500,500);
    
    
    
    
    
    
    
    xPos = 250;
    
    yPos = 250;
    
    xVel = 5;
    
    yVel = 5;
    
    
    
}



//--------------------------------------------------------------

void ofApp::update(){
    
    
    
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



//--------------------------------------------------------------

void ofApp::draw(){
    
    
    
    ofCircle(xPos, yPos, 10);
    
    
    
    xPos = xPos + xVel;
    
    yPos = yPos + yVel;
    
    
    
}