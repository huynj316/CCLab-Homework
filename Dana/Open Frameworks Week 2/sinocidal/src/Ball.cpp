//
//  Ball.cpp
//  sinocidal
//
//  Created by Dana Martens on 11/16/15.
//
//

#include <stdio.h>
#include "Ball.h"

int radius1;
int radius2;



//--------------------------------------------------------------
void Ball::setup() {
    ofBackground(0);
    
    //Music Control --------
    beat.load("beat2.mp3");
    
    fftSmooth = new float [8192];
    for (int i = 0; i<8192; i++) {
        fftSmooth[i] = 0;
    }
    
    bands = 64;
    beat.setLoop(true);
    beat.setVolume(0.2);
   
    //GUI SETUP FOR BALL CONTROL-----------
    gui.setup();
    gui.add(sinPar.set("BALL 1 SINE", 0.0, 0.0, 400.0));
    gui.add(cosPar.set("BALL 1 COSINE", 0.0, 0.0, 400.0));
    gui.add(sinPar2.set("BALL 2 SINE", 0.0, 0.0, 500.0));
    gui.add(cosPar2.set("Ball 2 COSINE", 0.0, 0.0, 300.0));
    gui.add(speed.set("Speed is", 1.0, 0.0, 10.0));
    
}

//--------------------------------------------------------------

void Ball::update(){
    //Sound -------
    ofSoundUpdate();
    
    float * value = ofSoundGetSpectrum(bands);
    for (int i = 0; i < bands; i++){
        fftSmooth[i] *= 0.9f; //controls how fast dies down
        if (fftSmooth[i] < value[i]) {
            fftSmooth[i] = value[i];
        }
    }
    
    //Movement------
    
    sine = sin(ofGetElapsedTimef() * speed+5) * sinPar;
    cosine = cos(ofGetElapsedTimef() * speed+5) * cosPar;
    sine2 = sin(ofGetElapsedTimef() * speed) * sinPar2;
    cosine2 = cos(ofGetElapsedTimef() * speed) * cosPar2;
    
    
}
//--------------------------------------------------------------

void Ball::draw(){
    radius1 = 20;
    radius2 = 30;
    gui.draw();
   
    
    //BALL 6
    //first, fill in the gradient with colors, left to right
    gradient.addColor( ofColor::red );
    gradient.addColor( ofColor::green );
    gradient.addColor( ofColor::yellow );
    
    //query the gradient for a color at a specific spot
    ofColor color6 = gradient.getColorAtPercent(.04);
    
    //rinse and repeat to draw the full gradient
    for(float i = 0.0f; i < 1.0f; i+= 0.1f){
        ofSetColor( gradient.getColorAtPercent(i) );
        //draw using that color
    }
    
   
    for (int i = 0; i < bands; i++){
         ofCircle(ofGetWidth()/2+50, ofGetHeight()/2-50, -(fftSmooth[i] * 150));
    }

    
    
    //GRADIENT-------
    //first, fill in the gradient with colors, left to right
    gradient.addColor( ofColor::red );
    gradient.addColor( ofColor::green );
    gradient.addColor( ofColor::yellow );
    
    //query the gradient for a color at a specific spot
    ofColor color = gradient.getColorAtPercent(gradientset);
    
    //rinse and repeat to draw the full gradient
    for(float i = 0.0f; i < 1.0f; i+= 0.1f){
        ofSetColor( gradient.getColorAtPercent(i) );
        //draw using that color
    }
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    for (int i = 0; i < bands; i++){
        ofCircle(sine, cosine,-(fftSmooth[i] * 150));
    }
    //GRADIENT2-------
    //first, fill in the gradient with colors, left to right
    gradient.addColor( ofColor::teal);
    gradient.addColor( ofColor::skyBlue );
    gradient.addColor( ofColor::blueSteel);
    
    //query the gradient for a color at a specific spot
    ofColor color2 = gradient.getColorAtPercent(0.2);
    
    //rinse and repeat to draw the full gradient
    for(float i = 0.0f; i < 1.0f; i+= 0.1f){
        ofSetColor( gradient.getColorAtPercent(i) );
        //draw using that color
    }
   for (int i = 0; i < bands; i++){
    ofCircle(sine2 * -(fftSmooth[i] * 150), cosine2, radius2);
   }
    
   
    
    //BALL 3 -----------------------
    
    //GRADIENT3-------
    //first, fill in the gradient with colors, left to right
    gradient.addColor( ofColor::teal);
    gradient.addColor( ofColor::skyBlue );
    gradient.addColor( ofColor::blueSteel);
    
    //query the gradient for a color at a specific spot
    ofColor color3 = gradient.getColorAtPercent(0.2);
    
    //rinse and repeat to draw the full gradient
    for(float i = 0.0f; i < 1.0f; i+= 0.1f){
        ofSetColor( gradient.getColorAtPercent(i) );
        //draw using that color
    }
    for (int i = 0; i < bands; i++){
        ofCircle(sine2, cosine2 * -(fftSmooth[i] * 150), radius2-10);
    }
    
    
    //BALL 4 -----------------------
    
    //GRADIENT3-------
    //first, fill in the gradient with colors, left to right
    gradient.addColor( ofColor::teal);
    gradient.addColor( ofColor::skyBlue );
    gradient.addColor( ofColor::blueSteel);
    
    //query the gradient for a color at a specific spot
    ofColor color4 = gradient.getColorAtPercent(0.2);
    
    //rinse and repeat to draw the full gradient
    for(float i = 0.0f; i < 1.0f; i+= 0.1f){
        ofSetColor( gradient.getColorAtPercent(i) );
        ofFill();
        //draw using that color
    }
    for (int i = 0; i < bands; i++){
        ofCircle(sine, cosine *  -(fftSmooth[i] * 300), -(fftSmooth[i] * 300));
    }

    
    //BALL 5
    //first, fill in the gradient with colors, left to right
    gradient.addColor( ofColor::blue );
    gradient.addColor( ofColor::green );
    gradient.addColor( ofColor::purple );
    
    //query the gradient for a color at a specific spot
    ofColor color5 = gradient.getColorAtPercent(.02);
    
    //rinse and repeat to draw the full gradient
    for(float i = 0.0f; i < 1.0f; i+= 0.1f){
        ofSetColor( gradient.getColorAtPercent(i), .09 );
        ofFill();
        //draw using that color
    }
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofCircle(sine, cosine, radius1);
    

    
    //BALL 7
    //first, fill in the gradient with colors, left to right
    gradient.addColor( ofColor::red );
    gradient.addColor( ofColor::green );
    gradient.addColor( ofColor::yellow );
    
    //query the gradient for a color at a specific spot
    ofColor color7 = gradient.getColorAtPercent(.08);
    
    //rinse and repeat to draw the full gradient
    for(float i = 0.0f; i < 1.0f; i+= 0.1f){
        ofSetColor( gradient.getColorAtPercent(i) );
        //draw using that color
    }
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofCircle(sine2, cosine2, radius2);


//BALL 8 -----------------------

//GRADIENT3-------
//first, fill in the gradient with colors, left to right
gradient.addColor( ofColor::yellow);
gradient.addColor( ofColor::gold);
gradient.addColor( ofColor::silver);

//query the gradient for a color at a specific spot
ofColor color8 = gradient.getColorAtPercent(0.2);

//rinse and repeat to draw the full gradient
for(float i = 0.0f; i < 1.0f; i+= 0.1f){
    ofSetColor( gradient.getColorAtPercent(i) );
    ofFill();
    //draw using that color
}
for (int i = 0; i < bands; i++){
    ofCircle(sine * -(fftSmooth[i] * 300), cosine *  -(fftSmooth[i] * 300), -(fftSmooth[i] * 300));
}

    //BALL 9 -----------------------
    
    //GRADIENT3-------
    //first, fill in the gradient with colors, left to right
    gradient.addColor( ofColor::teal);
    gradient.addColor( ofColor::skyBlue );
    gradient.addColor( ofColor::blueSteel);
    
    //query the gradient for a color at a specific spot
    ofColor color9 = gradient.getColorAtPercent(0.2);
    
    //rinse and repeat to draw the full gradient
    for(float i = 0.0f; i < 1.0f; i+= 0.1f){
        ofSetColor( gradient.getColorAtPercent(i) );
        //draw using that color
    }
   
    ofCircle(sine, cosine, radius1);
    ofCircle(sine2, cosine2, radius2);
    }



//--------------------------------------------------------------
void Ball::mouseDragged(int mouseX, int mouseY, int button){
    
}
    
    //--------------------------------------------------------------

void Ball::mouseMoved(int x, int y ){
    
}


//--------------------------------------------------------------
void Ball::keyPressed(int key){
    switch (key) {
        case '1':
            beat.play();
        break;
        
        case '2':
            beat.stop();
        break;

    }
        
    }
    
    //--------------------------------------------------------------
void Ball::keyReleased(int key){
        
    }
