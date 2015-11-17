//
//  Ball.h
//  sinocidal
//
//  Created by Dana Martens on 11/16/15.
//
//

#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxColorGradient.h"



class Ball : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void keyPressed(int key);
    void keyReleased(int key);
    
    ofxPanel gui;
    ofParameter<float> sinPar;
    ofParameter<float> cosPar;
    ofParameter<float> sinPar2;
    ofParameter<float> cosPar2;
    ofParameter<float> gradientset;
    ofParameter<float> speed;
    

    
    float sine;
    float cosine;
    float sine2;
    float cosine2;
    
    
    ofxColorGradient<ofColor> gradient;
   
    ofSoundPlayer beat;
    
    float * fftSmooth; //how fast/slow shapes moves
    int bands; //of frequency, you can have many bands
    
    
};
