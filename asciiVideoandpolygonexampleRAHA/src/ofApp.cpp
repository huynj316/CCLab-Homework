#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
    ofBackground(0,0,0);
	
	camWidth 		= 640;	// try to grab at this size. 
	camHeight 		= 480;
	
	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(camWidth,camHeight);

    font.loadFont("Courier New Bold.ttf", 9);
    
    // this set of characters comes from processing: 
    //http://processing.org/learning/library/asciivideo.html
    
	// changed order slightly to work better for mapping
//    asciiCharacters =  string("  ..,,,'''``--_:;^^**""=+<>iv%&xclrs)/){}I?!][1taeo7zjLunT#@JCwfy325Fp6mqSghVd4EgXPGZbYkOA8U$KHDBWNMR0Q");
    
	
    ofEnableAlphaBlending();
}


//--------------------------------------------------------------
void ofApp::update(){
	vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    float xPct = (float)(mouseX) / (float)(ofGetWidth());
    float yPct = (float)(mouseY) / (float)(ofGetHeight());
    int nTips = 5 + xPct * 60;
    int nStarPts = nTips * 2;
    float angleChangePerPt = TWO_PI / (float)nStarPts;
    float innerRadius = 0 + yPct*80;
    float outerRadius = 80;
    float origx = 525;
    float origy = 100;
    float angle = 0;
    
    ofSetHexColor(0xa16bca);
    ofBeginShape();
    for (int i = 0; i < nStarPts; i++){
        if (i % 2 == 0) {
            // inside point:
            float x = origx + innerRadius * cos(angle);
            float y = origy + innerRadius * sin(angle);
            ofVertex(x,y);
        } else {
            // outside point
            float x = origx + outerRadius * cos(angle);
            float y = origy + outerRadius * sin(angle);
            ofVertex(x,y);
        }
        angle += angleChangePerPt;
    }
    ofEndShape();
	
    
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
            int character = powf( ofMap(lightness, 0, 255, 0, 1), 2.5) * asciiCharacters.size();
            // draw the character at the correct location
            font.drawString(ofToString(asciiCharacters[character]), i, j);
        }
    }
    
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	
	// in fullscreen mode, on a pc at least, the 
	// first time video settings the come up
	// they come up *under* the fullscreen window
	// use alt-tab to navigate to the settings
	// window. we are working on a fix for this...
	
	if (key == 's' || key == 'S'){
		vidGrabber.videoSettings();
	}
	
	
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
