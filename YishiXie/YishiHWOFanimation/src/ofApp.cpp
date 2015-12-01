//Yishi Xie
//Fall 2015
//Animation
//Inspired by Sine animation tutorial by Oleg Pashkovsky
//http://www.pshkvsky.com/gif2code/sinewaves-animation-tutorial-openframeworks/

#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    //set initial position
    anim.reset( 0.0f );
    
    //set repeating style
    anim.setRepeatType(LOOP_BACK_AND_FORTH);
    
    //set animation curve
    anim.setCurve(EASE_IN_EASE_OUT);
    
    //start the animation, go from current val to the specified val
    anim.animateTo( 1.0f );
    
    
    
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(30);// draw grey background
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2); // move initital drawing postion to the center of the screen
    int circle_resolution=1600; // amount of points circle is made of, more points - better quality
    int radius=150;
    int smoothing_amount=30;
    
    ofPolyline circle_sin;
    ofPolyline circle_cos;
    ofPolyline circle_un_cos;
    ofPolyline circle_sin1;
    ofPolyline circle_cos1;
    ofPolyline circle_un_cos1;
    ofPolyline circle_sin2;
    ofPolyline circle_cos2;
    ofPolyline circle_un_cos2;
    ofPolyline circle_sin3;
    ofPolyline circle_cos3;
    ofPolyline circle_un_cos3;
    
    
    int wave_height=radius*0.5;
    int anim_shape=1;
    float sine_pct=0.1; // setting in percantage how big is the part
    
    float speed_increment=ofGetElapsedTimef();
    
    int line_w=5;
    int radius_cos=radius+line_w-1;
    int radius_un_cos=radius+(line_w-1)*2;
    for(int i=0; i<circle_resolution; i++)
    {
        
        float angle=TWO_PI/circle_resolution*i;
        float raidus_addon=wave_height*sin((angle+speed_increment)*anim_shape);
        
        float x=cos(angle+speed_increment)*radius;
        float y=sin(angle+speed_increment)*radius;
        
        // drawing sine wave on a part of the circle
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius+raidus_addon);
            y=sin(angle+speed_increment)*(radius+raidus_addon);
        }
        circle_sin.addVertex(ofPoint(x-ofGetWidth()/4,y));
        
        
        raidus_addon=wave_height*cos((angle+speed_increment)*anim_shape);
        x=cos(angle+speed_increment)*(radius_cos);
        y=sin(angle+speed_increment)*(radius_cos);
        
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius_cos+raidus_addon);
            y=sin(angle+speed_increment)*(radius_cos+raidus_addon);
        }
        
        circle_cos.addVertex(ofPoint(x-ofGetWidth()/4,y));
        
        
        //increment a wave angle to flip the wave
        raidus_addon=wave_height*cos((angle+TWO_PI/3+speed_increment)*anim_shape);
        x=cos(angle+speed_increment)*(radius_un_cos);
        y=sin(angle+speed_increment)*(radius_un_cos);
        
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius_un_cos+raidus_addon);
            y=sin(angle+speed_increment)*(radius_un_cos+raidus_addon);
        }
        
        circle_un_cos.addVertex(ofPoint(x-ofGetWidth()/4,y));
        
        
        
        
        raidus_addon=wave_height*sin((angle-speed_increment)*anim_shape);
         x=cos(angle-speed_increment)*radius;
         y=sin(angle-speed_increment)*radius;
        
        
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle-speed_increment)*(radius-raidus_addon);
            y=sin(angle-speed_increment)*(radius-raidus_addon);
        }
        circle_sin1.addVertex(ofPoint(x+ofGetWidth()/4,y));
        
        
        raidus_addon=wave_height*cos((angle-speed_increment)*anim_shape);
        x=cos(angle-speed_increment)*(radius_cos);
        y=sin(angle-speed_increment)*(radius_cos);
        
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle-speed_increment)*(radius_cos-raidus_addon);
            y=sin(angle-speed_increment)*(radius_cos-raidus_addon);
        }
        
        circle_cos1.addVertex(ofPoint(x+ofGetWidth()/4,y));
        
        
        //increment a wave angle to flip the wave
        raidus_addon=wave_height*cos((angle+TWO_PI/3-speed_increment)*anim_shape);
        x=cos(angle-speed_increment)*(radius_un_cos);
        y=sin(angle-speed_increment)*(radius_un_cos);
        
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle-speed_increment)*(radius_un_cos-raidus_addon);
            y=sin(angle-speed_increment)*(radius_un_cos-raidus_addon);
        }
        
        circle_un_cos1.addVertex(ofPoint(x+ofGetWidth()/4,y));
        
        
        
        
        
        raidus_addon=wave_height*sin((angle+speed_increment)*anim_shape);
        
         x=cos(angle+speed_increment)*radius;
         y=sin(angle+speed_increment)*radius;
        
        // drawing sine wave only on a part of the circle
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius+raidus_addon);
            y=sin(angle+speed_increment)*(radius+raidus_addon);
        }
        circle_sin2.addVertex(ofPoint(x,y-ofGetHeight()/4));
        
        
        raidus_addon=wave_height*cos((angle+speed_increment)*anim_shape);
        x=cos(angle+speed_increment)*(radius_cos);
        y=sin(angle+speed_increment)*(radius_cos);
        
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius_cos+raidus_addon);
            y=sin(angle+speed_increment)*(radius_cos+raidus_addon);
        }
        
        circle_cos2.addVertex(ofPoint(x,y-ofGetHeight()/4));
        
        
        //increment a wave angle to flip the wave
        raidus_addon=wave_height*cos((angle+TWO_PI/3+speed_increment)*anim_shape);
        x=cos(angle+speed_increment)*(radius_un_cos);
        y=sin(angle+speed_increment)*(radius_un_cos);
        
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius_un_cos+raidus_addon);
            y=sin(angle+speed_increment)*(radius_un_cos+raidus_addon);
        }
        
        circle_un_cos2.addVertex(ofPoint(x,y-ofGetHeight()/4));
        
        
        raidus_addon=wave_height*sin((angle-speed_increment)*anim_shape);
        x=cos(angle-speed_increment)*radius;
        y=sin(angle-speed_increment)*radius;
        
        
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle-speed_increment)*(radius-raidus_addon);
            y=sin(angle-speed_increment)*(radius-raidus_addon);
        }
        circle_sin3.addVertex(ofPoint(x,y+ofGetHeight()/4));
        
        
        raidus_addon=wave_height*cos((angle-speed_increment)*anim_shape);
        x=cos(angle-speed_increment)*(radius_cos);
        y=sin(angle-speed_increment)*(radius_cos);
        
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle-speed_increment)*(radius_cos-raidus_addon);
            y=sin(angle-speed_increment)*(radius_cos-raidus_addon);
        }
        
        circle_cos3.addVertex(ofPoint(x,y+ofGetHeight()/4));
        
        
        //increment a wave angle to flip the wave
        raidus_addon=wave_height*cos((angle+TWO_PI/3-speed_increment)*anim_shape);
        x=cos(angle-speed_increment)*(radius_un_cos);
        y=sin(angle-speed_increment)*(radius_un_cos);
        
        if(i<sine_pct*circle_resolution)
        {
            x=cos(angle-speed_increment)*(radius_un_cos-raidus_addon);
            y=sin(angle-speed_increment)*(radius_un_cos-raidus_addon);
        }
        
        circle_un_cos3.addVertex(ofPoint(x,y+ofGetHeight()/4));
        
        
    }
    
    ofSetLineWidth(line_w);
    
    ofColor clr=ofColor(40);
    ofSetColor(clr);
    circle_sin.close(); // to connect first and last point of our shape we need to use ÔcloseÕ function
    circle_sin= circle_sin.getSmoothed(smoothing_amount);
    circle_sin.draw();
    
    clr=ofColor(50);
    ofSetColor(clr);
    circle_cos.close();
    circle_cos= circle_cos.getSmoothed(smoothing_amount);
    circle_cos.draw();
    
    
    clr=ofColor(60);
    ofSetColor(clr);
    circle_un_cos.close();
    circle_un_cos= circle_un_cos.getSmoothed(smoothing_amount);
    circle_un_cos.draw();
    
    
    clr=ofColor(70);
    ofSetColor(clr);
    circle_sin1.close();
    circle_sin1= circle_sin1.getSmoothed(smoothing_amount);
    circle_sin1.draw();
    
    clr=ofColor(80);
    ofSetColor(clr);
    circle_cos1.close();
    circle_cos1= circle_cos1.getSmoothed(smoothing_amount);
    circle_cos1.draw();
    
    
    clr=ofColor(90);
    ofSetColor(clr);
    circle_un_cos1.close();
    circle_un_cos1= circle_un_cos1.getSmoothed(smoothing_amount);
    circle_un_cos1.draw();
    
    
    clr=ofColor(100);
    ofSetColor(clr);
    circle_sin2.close();
    circle_sin2= circle_sin2.getSmoothed(smoothing_amount);
    circle_sin2.draw();
    
    clr=ofColor(110);
    ofSetColor(clr);
    circle_cos2.close();
    circle_cos2= circle_cos2.getSmoothed(smoothing_amount);
    circle_cos2.draw();
    
    
    clr=ofColor(120);
    ofSetColor(clr);
    circle_un_cos2.close();
    circle_un_cos2= circle_un_cos2.getSmoothed(smoothing_amount);
    circle_un_cos2.draw();
    
    
    clr=ofColor(130);
    ofSetColor(clr);
    circle_sin3.close();
    circle_sin3= circle_sin3.getSmoothed(smoothing_amount);
    circle_sin3.draw();
    
    clr=ofColor(140);
    ofSetColor(clr);
    circle_cos3.close();
    circle_cos3= circle_cos3.getSmoothed(smoothing_amount);
    circle_cos3.draw();
    
    
    clr=ofColor(150);
    ofSetColor(clr);
    circle_un_cos3.close();
    circle_un_cos3= circle_un_cos3.getSmoothed(smoothing_amount);
    circle_un_cos3.draw();

    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
