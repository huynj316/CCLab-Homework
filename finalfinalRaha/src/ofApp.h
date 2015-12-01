#include "ofxVectorGraphics.h"
//#include "ofxExampleTwitterClient.h"
#include "ofMain.h"
#include "ofxExplodingString.h"

class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    void touchDown(ofTouchEventArgs & touch);
    
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofTrueTypeFont font;
    ofxExplodingString * xplodingString;
    ofxVectorGraphics output;
    //    ofxExampleTwitterClient client;
    ofImage trump;
    bool capture;
    bool bFill;
    
    vector <ofPoint> pts;
    
    
};


