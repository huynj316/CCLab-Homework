#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ball.setup();
    
    
    //--- Load Image
    
    bool succ = true;
    succ = image.loadImage("bigbang.png"); //load image if succesfull, print error if not
    if (!succ) {
        cerr << "loading image failed...\n";
    }
    image.resize(1280,525); //resize image
}

//--------------------------------------------------------------
void ofApp::update(){
    ball.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    image.draw(ofGetWidth()/2-600, ofGetHeight()/2 - 200);
    ball.draw();
   
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
ball.keyPressed(key);
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
