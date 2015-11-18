//
//  Ball.hpp
//  mySketch
//
//  Created by Raha Ghassemi on 11/3/15.
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
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    int xPos;
    int yPos;
    int xVel;
    int yVel;
    
};

#endif /* Ball_h */
