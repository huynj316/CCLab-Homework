#include "ofApp.h"


void ofApp::setup()
{
    std::string url = "http://www.opensecrets.org/api/?method=orgSummary&id=D000027998&cycle=2014&apikey=d4a10a8528aecacdbcee31bb452de006";
    
    // Now parse the JSON
    bool parsingSuccessful = json.open(url);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
}


void ofApp::draw()
{
    ofBackground(0);
    ofSetColor(255);
    
    for (Json::ArrayIndex i = 0; i < json["response"]["orgname"].size(); ++i)
    {
        std::string dems  = json["response"]["dems"].asString();
        std::string repubs = json["response"]["repubs"].asString();
        
        std::string text   = dems + " - " + repubs;
        ofDrawBitmapString(text, 20, i * 24 + 40);
    }
}
