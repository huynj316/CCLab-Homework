#include "ofApp.h"
#include <iostream>
using namespace std;

string text = "particleflow.jpg";

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
  
    
    
    //--- Load Image
    
    bool succ = true;
    succ = image.loadImage(text); //load image if succesfull, print error if not
    if (!succ) {
        cerr << "loading image failed...\n";
    }
    image.resize(200,200); //resize image
    
    
    
    //---- Set Up Our Mesh (again)
    mesh.setMode(OF_PRIMITIVE_LINES);
    float intensityThreshold = 50.0;
    int w = image.getWidth();
    int h = image.getHeight();
    
    
    for (int x = 0; x<w; x++) { //draws array of points on mesh where lightness of image is above a certain threshold, aka the stars and their glow
        //this is bc pixels in image no longer 1 to 1 w/ window size
        //for 3d purposes, we use saturation of color to change z component and add 3d depth
        //This code pushes brighter colors in postive z, and darker white in negative using ofMap to RGB range of 255.
        for (int y = 0; y<h; y++){
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -100, 100);
                ofVec3f pos(4*x, 4*y, z);
                mesh.addVertex(pos);
                mesh.addColor(c);
                offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0, 100000), ofRandom(0, 100000))); //allows us to move x, y, z coordinates of each vertex independently by creating variable offsets which is a vecor of ofVec3fs that contains random values allowing us to move verteces seemingly independently of other ones
            }
        }
    }

    float connectionDistance = 30;
    int numVerts = mesh.getNumVertices();
    for (int a=0; a<numVerts; ++a) { //get unique pairs of vecotors by using 2 for loops to find each pair of vertices (end points)
        ofVec3f verta = mesh.getVertex(a);
        for (int b=a+1; b<numVerts; ++b) {
            ofVec3f vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);//find distance betwen verteces
            if (distance <= connectionDistance) {
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }

    }}

//--------------------------------------------------------------
void ofApp::update(){
    int numVerts = mesh.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = mesh.getVertex(i); //get location of vertex and store it in vert
        
        float time = ofGetElapsedTimef(); //set paramaters for signed noise sto move x,y,z values of vert
        float timeScale = 5.0;
        float displacementScale = 0.75;
        ofVec3f timeOffsets = offsets[i];
        
        //---create Perlin noise with above variables.
        
        //note from example
        // A typical design pattern for using Perlin noise uses a couple parameters:
        // ofSignedNoise(time*timeScale+timeOffset)*displacementScale
        //     ofSignedNoise(time) gives us noise values that change smoothly over time
        //     ofSignedNoise(time*timeScale) allows us to control the smoothness of our noise (smaller timeScale, smoother values)
        //     ofSignedNoise(time+timeOffset) allows us to use the same Perlin noise function to control multiple things and have them look as if they are moving independently
        //     ofSignedNoise(time)*displacementScale allows us to change the bounds of the noise from [-1, 1] to whatever we want
        // Combine all of those parameters together, and you've got some nice control over your noise
        
        
        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
        mesh.setVertex(i, vert); //upadte position of vertex using mesh.sexVertex. gives us a wobbly mesh
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
   
    
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor = (0,0,0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR); //creates gradient using colors set above
    
    
    cam.begin();
        ofPushMatrix(); //of pushmatrix, popmatrix and translate center in cameras view...
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
        mesh.draw();
    ofPopMatrix();
    cam.end();
    
    cout << mesh.getNumVertices() << endl; //just a command to check number of vertices and print to the console. first time i saw print to console, so wanted to try it here. Original example had 64,000, so we need to shring image from 800 x 800 to its new size, 300 x 300.

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    int button = ofGetKeyPressed();
    
    if (button == 49) {
        text = "stars.png";
    } else if (button ==50) {
        text = "starfield.jpg";
    } else if (button ==51) {
        text = "squares.jpg";
    } else if (button ==52) {
        text = "warp.jpg";
    } else if (button ==53) {
        text = "particleflow.jpg";
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
