//
//  demoParticle.hpp
//  mySketch
//
//  Created by Jourdan Bousfield on 2015-11-10.
//
//

#ifndef demoParticle_hpp
#define demoParticle_hpp

#include <stdio.h>

#include "ofMain.h"

#endif /* demoParticle_hpp */


enum particleMode{
    PARTICLE_MODE_ATTRACT = 0,
    PARTICLE_MODE_REPEL,
    PARTICLE_MODE_NEAREST_POINTS,
    PARTICLE_MODE_NOISE
};

class demoParticle{
    
public:
    demoParticle();
    
    void setMode(particleMode newMode);
    void setAttractPoints( vector <ofPoint> * attract );
    
    void reset();
    void update();
    void draw();
    
    ofPoint pos;
    ofPoint vel;
    ofPoint frc;
    
    float drag;
    float uniqueVal;
    float scale;
    
    particleMode mode;
    
    vector <ofPoint> * attractPoints; 
};