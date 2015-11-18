//
//  Ball.hpp
//  myFirstSketchClass
//
//  Created by Dana Martens on 11/3/15.
//
//


#pragma once

#include "ofMain.h"

class Ball : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int mouseButton);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    
    ofSoundPlayer synth;
    ofSoundPlayer boing;
    
    ofEasyCam cam2;

    
};


