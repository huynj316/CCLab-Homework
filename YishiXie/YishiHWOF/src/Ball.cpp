//
//  Ball.cpp
//  InClassSketch
//
//  Created by Yishi Xie on 11/3/15.
//
//

#include "Ball.h"



void Ball::setup(){
    xPos = 0;
    xVel = 5;
    ofSetWindowShape(500,500);
    
    counter = 0;
}

void Ball::update(){
    if (xPos>=0 && xPos<=500) {
        xVel = xVel;
    }
    else{
        xVel = -xVel;
    }
    xPos += xVel;
    
    counter = counter + 0.033f;
}

void Ball::draw(){
    float radius = 50 + 10 * sin(counter);
    ofFill();		// draw "filled shapes"
    
    //
    ofSetColor(180,220,180,(int)(counter * 20.0f) % 255);
    ofFill();		// draw "filled shapes"
    ofCircle(xPos, ofGetHeight()/2, 200);
    
    //
    ofSetColor(200,220,240,(int)(counter * 30.0f) % 255);
    ofFill();		// draw "filled shapes"
    ofCircle(xPos, ofGetHeight()/2, 80+radius);
    
    //    ofNoFill();
    //    ofSetHexColor(0xCCCCCC);
    ofSetColor(255,200,200,(int)(counter * 40.0f) % 255);
    ofCircle(xPos, ofGetHeight()/2,80);
    
    
    //ball moving horizontally L - R
    ofSetColor(150,200,(int)(counter * 40.0f) % 255);
    ofCircle(xPos, ofGetHeight()/2, radius);
    
    
    
    
    
}