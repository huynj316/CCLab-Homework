#include "ofApp.h"


int byteData;

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    font.loadFont("Verdana.ttf", 14);
    
    
    serial.setup("/dev/tty.usbmodem1421", 9600);
    
    birds.load("birds.mp3");
    birds.play();
    birds.setLoop(true);
    
    traffic.load("traffic.wav");
    traffic.play();
    traffic.setLoop(true);
    traffic.setVolume(0);
    
    butterfly.load("butterfly.png");
    drop.load("oilp.png");
    
   
    
    gui.setup();
    gui.add(positionX.set("X", 20.0, 0.0, 30.0));
    gui.add(positionY.set("Y", 29.0, 0.0, 30.0));
    
    ofSetBackgroundAuto(true);
    fundo.load("background.jpg");
    
    
  }

//--------------------------------------------------------------
void ofApp::update(){
    if(serial.available()<0){
        msg = "Arduino Error";
    }
    else{
        while(serial.available()>0){
            byteData = serial.readByte();
            msg = "cm" + ofToString(byteData);
        }
        
        if(int(byteData) < 20){
            ofDrawCircle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 30);
            
        
            birds.setVolume(0);
            traffic.setVolume(2);
           
            
            
        } else{
            traffic.setVolume(0);
            birds.setVolume(1);
           
            }
       }
  
    
}

    
//--------------------------------------------------------------
void ofApp::draw(){
    
    fundo.draw(0,0, 1200, 720 );
    
    gui.draw();
    
    ofDrawBitmapString("time:" + ofToString(ofGetElapsedTimef()), 30,30);
   
    if(int(byteData)<20){
        float x = -1;
        float y = -1;
        positionX = 0;
        positionY= 0;
        butterfly.draw(-10,-10, 0,0);
        
        ofBackground(0);
        
    }
    else{
        float time = ofGetElapsedTimef();
        for (int i = 0; i <150; i ++ ) {
            float width = ofGetWidth();
            float height = ofGetHeight();
            float speed = 0.1;
            float posX = i * positionX;
            float posY = i * positionY;
            
            float x = width * ofNoise(time * speed + posX);
            float y = height * ofNoise(time * speed + posY);
            
            
            butterfly.draw(x, y, 40, 40);
        }
        
    }
    
    font.drawString(msg, 50, 100);
    cout <<byteData << endl;
    
    

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
