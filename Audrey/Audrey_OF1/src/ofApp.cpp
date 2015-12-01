#include "ofApp.h"
#include "Ball.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    petri.load("images/petri.jpg");
    
    ofTrueTypeFont::setGlobalDpi(72);
    
    verdana14.load("verdana.ttf", 14, true, true);
    verdana14.setLineHeight(18.0f);
    verdana14.setLetterSpacing(1.037);

    
    for (int i=0; i < NUMBEROFBALLS ; i++){
        arrayOfBalls[i].setup();
    }
    ball.setup();


}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(255);
    
    
    for (int i=0; i < NUMBEROFBALLS ; i++){
        arrayOfBalls[i].update();
    }
    ball.update();
    
    ofEllipse(ofGetWidth()/2, ofGetHeight()/2, 700, 500);
    ofSetColor(200, 80, 30, 50);
    

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofSetColor(255);
    
    petri.draw(0, 0);
    
    ofSetColor(90, 150, 80, 50);
    for (int i=0; i < NUMBEROFBALLS ; i++){
        arrayOfBalls[i].draw();
    }

    ball.draw();
    
    ofSetColor(0);
    verdana14.drawString("SPECIMEN : 4A", 30, 35);


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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
