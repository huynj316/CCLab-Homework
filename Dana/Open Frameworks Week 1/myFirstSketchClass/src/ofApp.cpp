#include "ofApp.h"

//--------------------------------------------------------------




void ofApp::setup(){
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor = (0,0,0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR); //creates gradient using colors set above
    ball.setup();
    square.setup();
    ofSetFrameRate(60);
    
    //--------- Easy Cam Setup
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    cam.setDistance(100);
    ofSetCircleResolution(64);
    bShowHelp = true;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ball.update();
    square.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
//    ofBackgroundGradient(ofColor::white, ofColor::gray);
    ofRotateX(ofRadToDeg(.5));
    ofRotateY(ofRadToDeg(-.5));
    ofBackground(0);
    ofSetColor(255, 0, 0);
    ofFill();
   
    ofDrawBox(30);
    ofNoFill();
    ofSetColor(0);
    ofDrawBox(30);
    ofPushMatrix();
    ball.draw();
    square.draw();
    ofTranslate(0,0,20);
    ofSetColor(0,0,255);
    ofFill();
    ofDrawBox(5);
    ofNoFill();
    ofSetColor(0);
    ofDrawBox(5);
    ofPopMatrix();
    cam.end();
    drawInteractionArea();
    ofSetColor(255);
    
    
  
}

//---------------------------
void ofApp::drawInteractionArea(){
    
    ofRectangle vp = ofGetCurrentViewport();
    
    float r = MIN(vp.width, vp.height) * 0.5f;
    
    float x = vp.width * 0.5f;
    
    float y = vp.height * 0.5f;
    
    
    ofPushStyle();
    
    ofSetLineWidth(3);
    
    ofSetColor(255, 255, 0);
    
    ofNoFill();
    
    glDepthMask(false);
    
    ofCircle(x, y, r);
    
    glDepthMask(true);
    
    ofPopStyle();
    
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
void ofApp::mouseDragged(int x, int y, int mouseButton){
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ball.mousePressed(x, y, button);
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
