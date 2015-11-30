//Yishi Xie
//Fall 2015
//Sound RGB Oscillation
//Math Sinusoidal motion + sound
//Shapes and colors were animated by the audio input
//Credit:
//Inspired by Sine animation tutorial by Oleg Pashkovsky
//http://www.pshkvsky.com/gif2code/sinewaves-animation-tutorial-openframeworks/
//Inspired by AudioInputExample


#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(80);
    
    
    // 0 output channels,
    // 2 input channels
    // 44100 samples per second
    // 256 samples per buffer
    // 4 num buffers (latency)
    
    soundStream.listDevices();
    
    int bufferSize = 500;
    
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter	= 0;
    drawCounter		= 0;
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //lets scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
    //lets record the volume into an array
    volHistory.push_back( scaledVol );
    
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(50);// draw grey background
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2); // move initital drawing postion to the center of the screen
    int circle_resolution=1600; // amount of points circle is made of, more points - better quality
    int radius=scaledVol * 300.0f +125; //R changes according to the volumn
    int smoothing_amount=50;
    //ofDrawBitmapString("Radius" + ofToString(radius), 10, 10);
    
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
    
    
    int wave_height=radius*0.2 + scaledVol * 1.0f;
    int anim_shape=3;
    
    float sine_pct1= 0.04;
    // setting in percantage how big is the part acoording to left volumn
    for (unsigned int i = 0; i < left.size(); i++){
        sine_pct1= 0.04 + left[i]*5.0f;
    }
    float sine_pct2 = 0.04;
    // setting in percantage how big is the part acoording to right volumn
    for (unsigned int i = 0; i < right.size(); i++){
        sine_pct2 = 0.04 + right[i]*5.0f;
    }
    
    float speed_increment=ofGetElapsedTimef();
    
    int line_w=4;
    int radius_cos=radius+line_w-1;
    int radius_un_cos=radius+(line_w-1)*2;
    for(int i=0; i<circle_resolution; i++)
    {
        
        float angle=TWO_PI/circle_resolution*i;
        float raidus_addon=wave_height*sin((angle+speed_increment)*anim_shape);
        
        float x=cos(angle-speed_increment)*radius;
        float y=sin(angle-speed_increment)*radius;
        
        
        
        //First
        if(i<sine_pct2*circle_resolution)
        {
            x=cos(angle-speed_increment)*(radius-raidus_addon);
            y=sin(angle-speed_increment)*(radius-raidus_addon);
        }
        circle_sin1.addVertex(ofPoint(x-ofGetWidth()/6,y+ofGetHeight()/8));
        
        
        raidus_addon=wave_height*cos((angle-speed_increment)*anim_shape);
        x=cos(angle-speed_increment)*(radius_cos);
        y=sin(angle-speed_increment)*(radius_cos);
        
        if(i<sine_pct2*circle_resolution)
        {
            x=cos(angle-speed_increment)*(radius_cos-raidus_addon);
            y=sin(angle-speed_increment)*(radius_cos-raidus_addon);
        }
        
        circle_cos1.addVertex(ofPoint(x-ofGetWidth()/6,y+ofGetHeight()/8));
        
        // increment a wave angle to flip the wave
        raidus_addon=wave_height*cos((angle+TWO_PI/3-speed_increment)*anim_shape);
        x=cos(angle-speed_increment)*(radius_un_cos);
        y=sin(angle-speed_increment)*(radius_un_cos);
        
        if(i<sine_pct2*circle_resolution)
        {
            x=cos(angle-speed_increment)*(radius_un_cos-raidus_addon);
            y=sin(angle-speed_increment)*(radius_un_cos-raidus_addon);
        }
        
        circle_un_cos1.addVertex(ofPoint(x-ofGetWidth()/6,y+ofGetHeight()/8));
        
        
        
        
        
        // Second
        raidus_addon=wave_height*sin((angle+speed_increment)*anim_shape);
        
        x=cos(angle+speed_increment)*radius;
        y=sin(angle+speed_increment)*radius;
        
        //drawing sine wave only on a part of the circle
        if(i<sine_pct1*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius+raidus_addon);
            y=sin(angle+speed_increment)*(radius+raidus_addon);
        }
        circle_sin2.addVertex(ofPoint(x,y-ofGetHeight()/6));
        
        
        raidus_addon=wave_height*cos((angle+speed_increment)*anim_shape);
        x=cos(angle+speed_increment)*(radius_cos);
        y=sin(angle+speed_increment)*(radius_cos);
        
        if(i<sine_pct1*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius_cos+raidus_addon);
            y=sin(angle+speed_increment)*(radius_cos+raidus_addon);
        }
        
        circle_cos2.addVertex(ofPoint(x,y-ofGetHeight()/6));
        
        
        //increment a wave angle to flip the wave
        raidus_addon=wave_height*cos((angle+TWO_PI/3+speed_increment)*anim_shape);
        x=cos(angle+speed_increment)*(radius_un_cos);
        y=sin(angle+speed_increment)*(radius_un_cos);
        
        if(i<sine_pct1*circle_resolution)
        {
            x=cos(angle+speed_increment)*(radius_un_cos+raidus_addon);
            y=sin(angle+speed_increment)*(radius_un_cos+raidus_addon);
        }
        
        circle_un_cos2.addVertex(ofPoint(x,y-ofGetHeight()/6));
        
        
        
        
        
        //Third
        raidus_addon=wave_height*sin((angle-speed_increment)*anim_shape);
        x=cos(angle-speed_increment)*radius;
        y=sin(angle-speed_increment)*radius;
        
        
        if(i<sine_pct2*circle_resolution)
        {
            x=cos(angle-speed_increment)*(radius-raidus_addon);
            y=sin(angle-speed_increment)*(radius-raidus_addon);
        }
        circle_sin3.addVertex(ofPoint(x+ofGetWidth()/6,y+ofGetHeight()/8));
        
        
        raidus_addon=wave_height*cos((angle-speed_increment)*anim_shape);
        x=cos(angle-speed_increment)*(radius_cos);
        y=sin(angle-speed_increment)*(radius_cos);
        
        if(i<sine_pct2*circle_resolution)
        {
            x=cos(angle-speed_increment)*(radius_cos-raidus_addon);
            y=sin(angle-speed_increment)*(radius_cos-raidus_addon);
        }
        
        circle_cos3.addVertex(ofPoint(x+ofGetWidth()/6,y+ofGetHeight()/8));
        
        
        //increment a wave angle to flip the wave
        raidus_addon=wave_height*cos((angle+TWO_PI/3-speed_increment)*anim_shape);
        x=cos(angle-speed_increment)*(radius_un_cos);
        y=sin(angle-speed_increment)*(radius_un_cos);
        
        if(i<sine_pct2*circle_resolution)
        {
            x=cos(angle-speed_increment)*(radius_un_cos-raidus_addon);
            y=sin(angle-speed_increment)*(radius_un_cos-raidus_addon);
        }
        
        circle_un_cos3.addVertex(ofPoint(x+ofGetWidth()/6,y+ofGetHeight()/8));
        
        
    }
    
    
    
    ofSetLineWidth(line_w + (scaledVol * 20));
    
    ofColor clr=ofColor(100, scaledVol * 155+100, 100,  255-scaledVol * 230);
    ofSetColor(clr);
    ofFill();
    circle_sin1.close();
    circle_sin1= circle_sin1.getSmoothed(smoothing_amount);
    circle_sin1.draw();
    
    clr=ofColor(80, scaledVol * 175+80, 80,  255-scaledVol * 230);
    ofSetColor(clr);
    ofFill();
    circle_cos1.close();
    circle_cos1= circle_cos1.getSmoothed(smoothing_amount);
    circle_cos1.draw();
    
    
    clr=ofColor(60, scaledVol * 195+60, 60, 255-(scaledVol * 230));
    ofSetColor(clr);
    ofFill();
    circle_un_cos1.close();
    circle_un_cos1= circle_un_cos1.getSmoothed(smoothing_amount);
    circle_un_cos1.draw();
    
    
    //R
    clr=ofColor(scaledVol * 155+100, 100,100,  255-scaledVol * 230);
    ofSetColor(clr);
    circle_sin2.close();
    circle_sin2= circle_sin2.getSmoothed(smoothing_amount);
    circle_sin2.draw();
    
    clr=ofColor(scaledVol * 175+80, 80,80,  255-scaledVol * 230);
    ofSetColor(clr);
    circle_cos2.close();
    circle_cos2= circle_cos2.getSmoothed(smoothing_amount);
    circle_cos2.draw();
    
    
    clr=ofColor(scaledVol * 195+60, 60,60,  255-scaledVol * 230);
    ofSetColor(clr);
    circle_un_cos2.close();
    circle_un_cos2= circle_un_cos2.getSmoothed(smoothing_amount);
    circle_un_cos2.draw();
    
    
    
    //B
    clr=ofColor(100,100,scaledVol * 155+100,  255-scaledVol * 230);
    ofSetColor(clr);
    circle_sin3.close();
    circle_sin3= circle_sin3.getSmoothed(smoothing_amount);
    circle_sin3.draw();
    
    clr=ofColor(80,80,scaledVol * 175+80,  255-scaledVol * 230);
    ofSetColor(clr);
    circle_cos3.close();
    circle_cos3= circle_cos3.getSmoothed(smoothing_amount);
    circle_cos3.draw();
    
    
    clr=ofColor(60,60,scaledVol * 195+60,  255-scaledVol * 230);
    ofSetColor(clr);
    circle_un_cos3.close();
    circle_un_cos3= circle_un_cos3.getSmoothed(smoothing_amount);
    circle_un_cos3.draw();
    
    
    // draw the left channel:
    //    ofTranslate(0,0);
    //    ofSetColor(245, 58, 135,100);
    //    ofSetLineWidth(300);
    //
    //    ofBeginShape();
    //    for (unsigned int i = 0; i < left.size(); i++){
    //        ofVertex(i, left[i]*180.0f);
    //    }
    //    ofEndShape(false);
    
    
    
    // draw the right channel:
    //    ofTranslate(0,0);
    //
    //    ofBeginShape();
    //    for (unsigned int i = 0; i < right.size(); i++){
    //        ofVertex(i*2,right[i]*180.0f);
    //    }
    //    ofEndShape(false);
    //
    
}

void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    
    // samples are "interleaved"
    int numCounted = 0;
    
    //lets go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2];
        right[i]	= input[i*2+1];
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    //this is how we get the mean of rms :)
    curVol /= (float)numCounted;
    
    // this is how we get the root of rms :)
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    
    bufferCounter++;
    
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
