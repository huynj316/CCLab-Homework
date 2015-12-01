#include "ofApp.h"
int byteData;

//--------------------------------------------------------------
void ofApp::setup(){

    flock.setup(50, ofGetWidth()/2, ofGetHeight()/2, 100);
    
    flock.setBounds(0,0,ofGetWidth(), ofGetHeight());
    flock.setBoundmode(1);
    ofBackground(154,232,230);
    bird.loadImage("bird.png");
    birdSound.loadSound("birdSound.mp3");

    

    font.loadFont("verdana.ttf", 10);
    
    serial.setup("/dev/cu.usbmodem1451", 9600);


}

//--------------------------------------------------------------
void ofApp::update(){
    flock.update(   );
    
    if(ofGetFrameNum()%240==0){
        flock.removeBoid(0);
    }
    
    //Reading Arduino through serial
    if (serial.available() < 0) {
        msg = "Arduino Error";
    }
    else {
        //While statement looping through serial messages when serial is being provided.
        while (serial.available() > 0) {
            //byte data is being writen into byteData as int.
            byteData = serial.readByte();
            
            //byteData is converted into a string for drawing later.
            msg = "How close is the human: " + ofToString(byteData) + "cm away";
            
            
        }
        
    }
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //Drawing the flock of birds
        
    for(int i=0; i<flock.size(); i++){
        Boid2d * b = flock.get(i);
        
        bird.draw(b->x, b->y, 50,50);

        float lm = 10.f;
        ofSoundUpdate();

        birdSound.play();
        birdSound.setLoop(true);
    }
    
    //If proximity sensor reads human close
    if(byteData<10){
            flock.removeBoid(0);
        birdSound.stop();
        
        
            
        }else{
            
            
            
            
    }
    

    
    font.drawString(msg, 50, 100);
    
    //printing byteData into console.
    cout << byteData << endl;

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
    if(button==0)
        flock.add(x, y);
    else
        flock.removeBoid(0);
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
