#include "ofApp.h"

int x = 100;
int y = 300;
string text = "Donald Trump";

//--------------------------------------------------------------
void ofApp::setup(){
    
    capture = false;
    bFill	= true;
    trump.loadImage("trump.jpg");
    //    client.setup("DCC19ud4bxcdqVHXIWDDXMJJH","sEB3UYGksBddeg2mmNTFLm2Vy8bze41cWHqm4fMJddwSzHHXBR");
    

    ofEnableAlphaBlending();
    ofBackground(0);
    
    font.loadFont("NOVASOLID ___.ttf", 50, true, true, true);
    xplodingString = new ofxExplodingString( &font, ofColor(0) );
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(255, 255, 255);
    xplodingString->update(0.01666);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //we don't want to capture every frame
    //so we only capture one frame when capture
    //is set to true
    trump.draw(0,0);
    if(capture){
        output.beginEPS("test.ps");
    }
    
    //do we want filled shapes or outlines?
    if(bFill)output.fill();
    else output.noFill();
    
    
    //--------------------
    // some lines - lets make a grid!
    //
    
    int numX = ofGetWidth() / 10;
    int numY = ofGetHeight() / 10;
    
    output.setColor(0xEEEEEE);
    
    for(int y = 0; y < numY; y++){
        output.line(0, y * 10, ofGetWidth(), y * 10);
    }
    
    for(int x = 0; x < numX; x++){
        output.line(x * 10, 0, x * 10, ofGetHeight() );
    }
    
    
    //--------------------
    // basic shapes
    //
    
    
    
    
    
    
    //--------------------
    //--------------------
    //--------------------
    // advanced shapes
    // these shapes can have an unlmited number of vertices
    
    
    
    
    // -----------------------------------
    // j - polygon shape based on mouse position
    // -----------------------------------
    ofSetHexColor(0xCC0000);
    
    
    output.setColor(0x6b6b6b);
    output.beginShape();
    
    //set number of sides based on mouse position
    int numSteps = ( (float)mouseX / ofGetWidth() )* 12.0;
    
    //make sure we don't go bellow 3 sides
    numSteps = MAX(3, numSteps);
    
    
    float step		= TWO_PI / (numSteps);
    float angle		= 0.0;
    float cenX		= 110;
    float cenY		= 430;
    float radius	= 50;
    
    
    
    
    
    
    
    
    // -----------------------------------
    // l - bezier shape based on mouse position
    // -----------------------------------
    ofSetHexColor(0);
    
    
    // we specify control points that shape each part of the shape
    output.setColor(0x99CC33);
    output.beginShape();
    
    //set number of sides based on mouse position
    numSteps = ( (float)mouseX / ofGetWidth() )* 12.0;
    
    //make sure we don't go bellow 3 sides
    numSteps = MAX(3, numSteps);
    
    step		= TWO_PI / (numSteps);
    angle		= 0.0;
    cenX		= 690;
    cenY		= 540.0;
    radius		= 60.0;
    float scale = 1.0 + 0.6 * sin(ofGetElapsedTimef());
    
    for(int i = 0; i < numSteps; i++){
        float rx = cenX + cos(angle) * radius;
        float ry = cenY + sin(angle) * radius;
        
        if(i == 0){
            output.polyVertex(rx, ry);
        }
        
        float rx2 = cenX + cos(angle+step) * radius;
        float ry2 = cenY + sin(angle+step) * radius;
        
        //lets make our control points in between each side and out a little way
        float cx = cenX + cos(angle + step*0.5) * radius * scale;
        float cy = cenY + sin(angle + step*0.5) * radius * scale;
        
        output.bezierVertex(cx, cy, cx, cy, rx2, ry2);
        
        angle += step;
    }
    
    output.endShape(true);
    
    
    
    
    //----------------------------
    //----------------------------
    //----------------------------
    // Bonuse :)
    // Mouse draw - with curved line
    //
    
    if( pts.size() > 0 ){
        
        int numPts = pts.size();
        
        output.setColor(0x99CC33);
        output.noFill();
        output.beginShape();
        
        //catmull curves create nice smooth curves between points
        //so actually a lower resolution creates a smoother line
        //and reduce the number of poiints in our eps file.
        int rescaleRes = 6;
        
        for(int i = 0; i < numPts; i++){
            
            //we need to draw the first and last point
            //twice for a catmull curve
            if(i == 0 || i == numPts -1){
                output.curveVertex(pts[i].x, pts[i].y);
            }
            
            if(i % rescaleRes == 0) output.curveVertex(pts[i].x, pts[i].y);
        }
        
        output.endShape();
    }
    
    
    
    //-------------------------
    //-------------------------
    // End capture!
    //
    
    //once we have done all our drawing
    //we end the ouput which saves the file
    //and then we stop capturing
    if(capture){
        output.endEPS();
        capture =false;
    }
    
    //
    // End capture!
    //-------------------------
    //-------------------------
    
    
    //we don't save this to eps - just info for the app
    
    ofFill();
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofSetHexColor(0x000000);
    ofRect(160, 30, 630,60);
    
    //some text to explain whats what
    ofSetHexColor(0xDDDDDD);
    ofDrawBitmapString("Everything that comes out of his mouth is basically vomit. Draw on his face.", 175, 65);
    
    
    
    //    if(client.isAuthorized())
    //    {
    //        ofBackground(0,255,0);
    //    }
    //    else
    //    {
    //        ofBackground(255,0,0);
    //    }
    
    ofSetColor(255, 64);
    font.drawString(text, x, y);
    xplodingString->draw();
    
    
    
    
    
}

void ofApp::touchDown(ofTouchEventArgs & touch){
    x = touch.x;
    y = touch.y;
    xplodingString->explode(text, x, y);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        capture = true;
        //        if(client.isAuthorized())
        //        {
        //            // Get tweets.
        //            std::string s = client.exampleMethod();
        
        // Post new status
        // std::string s = client.exampleUpdateStatusMethod("Hi from OF!");
        
        // Post status & image
        // std::string s = client.exampleUpdateStatusWithPhotoMethod("Hi from OF!", "buses.jpg");
        //            ofLogNotice("testApp::keyPressed") << s;
        //        }
        //        else
        //        {
        //            ofLogWarning("testApp::keyPressed") << "Not authorized yet.";
        //        }
        //
        //    }else if(key =='f'){
        //        bFill = !bFill;
        //    }
        //
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
    
    //we add a new point to our line
    
    pts.push_back(ofPoint());
    int last = pts.size()-1;
    
    pts[last].x = x;
    pts[last].y = y;
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    pts.clear();
    
    //lets store the first point of the line
    pts.push_back(ofPoint());
    pts[0].x = x;
    pts[0].y = y;
    
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
