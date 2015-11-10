//
//  beatsquare.h
//  myFirstSketchClass
//
//  Created by Dana Martens on 11/5/15.
//
//

#pragma once

#include "ofMain.h"

class Beat : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    
    ofSoundPlayer  beat;
    ofSoundPlayer hit;
    
    ofEasyCam cam3;
    
    
};

