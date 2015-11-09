//
//  Ball.h
//  InClassSketch
//
//  Created by Yishi Xie on 11/3/15.
//
//

#ifndef Ball_h
#define Ball_h

#include "ofMain.h"

class Ball : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    int xPos;
    int xVel;
    float 	counter;
};

#endif /* Ball_h */


