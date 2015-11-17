#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
  
    
    
    
    ofBackground(0,0,0);
    
    camWidth 		= 640;	// try to grab at this size.
    camHeight 		= 480;
    
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(camWidth,camHeight);
    
    
    
    
    ofEnableAlphaBlending();


    ofTrueTypeFont::setGlobalDpi(72);
    
    verdana30.loadFont("verdana.ttf", 30, true, true);
    verdana30.setLineHeight(34.0f);
    verdana30.setLetterSpacing(1.035);


}

//--------------------------------------------------------------
void ofApp::update(){
    
    vidGrabber.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // change background video alpha value based on the mouse position
    float videoAlphaValue = ofMap(mouseX, 0,ofGetWidth(),0,255);
    
    // set a white fill color with the alpha generated above
    ofSetColor(255,255,255,videoAlphaValue);
    
    // draw the raw video frame with the alpha value generated above
    vidGrabber.draw(0,0);
    
    ofPixelsRef pixelsRef = vidGrabber.getPixelsRef();
    
    ofSetHexColor(0xffffff);
    
    for (int i = 0; i < camWidth; i+= 7){
        for (int j = 0; j < camHeight; j+= 9){
            // get the pixel and its lightness (lightness is the average of its RGB values)
            float lightness = pixelsRef.getColor(i,j).getLightness();
            // calculate the index of the character from our asciiCharacters array
            // draw the character at the correct location
            
        }
    }



    


    
    ofPushMatrix();
    string rotZ = "Shikha Singh";
    ofRectangle bounds = verdana30.getStringBoundingBox(rotZ, 0, 0);
    ofSetColor(255);
    ofTranslate(110 + bounds.width/2, 200 + bounds.height / 2, 0);
    ofRotateZ(ofGetElapsedTimef() * -30.0);
				
    verdana30.drawString(rotZ, -bounds.width/2, bounds.height/2 );
    ofPopMatrix();


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
