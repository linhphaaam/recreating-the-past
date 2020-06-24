#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    decrease_size = 0;
    ofSetFrameRate(1);
    
    seed_i = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    decrease_size = decrease_size + 12;
    ofSeedRandom(seed_i);
    ran_col = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
    
    seed_i = seed_i + 1;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(0);
    ofEnableDepthTest();
    cam.enableOrtho();
    cam.setPosition(600, 400, 300);
    cam.begin();
    ofDrawAxis(200);
    for (int i = 0; i < 200; i++) {
        ofPushMatrix();
//        ofSetColor(216,143,51);
        int ran_x = ofRandom(1050);
        int ran_y = ofRandom(900);
        int ran_w = ofRandom(50,250);
        int w = ofClamp(ran_w - decrease_size, 0, ran_w);
        ofSetColor(ran_col);
        ofTranslate(ran_x, ran_y);
        ofRotateDeg(45);
        ofDrawRectangle(0-(w/2), 0-(w/2),-100,w, w);
        ofSetColor(0);
        ofDrawRectangle(0-(w*0.8/2), 0-(w*0.8/2),-50, w*0.8, w*0.8);
        ofSetColor(ran_col);
        ofDrawRectangle(0-(w*0.6/2), 0-(w*0.6/2),0, w*0.6, w*0.6);
        ofSetColor(0);
        ofDrawRectangle(0-(w*0.4/2), 0-(w*0.4/2),50, w*0.4, w*0.4);
        ofSetColor(ran_col);
        ofDrawRectangle(0-(w*0.2/2), 0-(w*0.2/2), 100, w*0.2, w*0.2);
        
        ofPopMatrix();
        
    };
    ofDisableDepthTest();
    
    for (int i = 0; i < 30; i++) {
        ofPushMatrix();
        ofSetColor(ran_col);
        int ran_x = ofRandom(1050);
        int ran_y = ofRandom(900);
        int ran_w = ofRandom(30,120);
        int w = ofClamp(ran_w - decrease_size, 0, ran_w);
        ofTranslate(ran_x, ran_y);
        ofRotateDeg(45);
        ofDrawRectangle(0-(w/2), 0-(w/2),w, w);
        ofSetColor(0);
        ofDrawRectangle(0-(w*0.8/2), 0-(w*0.8/2),w*0.8, w*0.8);
        ofSetColor(ran_col);
        ofDrawRectangle(0-(w*0.6/2), 0-(w*0.6/2),w*0.6, w*0.6);
        ofSetColor(0);
        ofDrawRectangle(0-(w*0.4/2), 0-(w*0.4/2),w*0.4, w*0.4);
//        ofSetColor(216,143,51);
//        ofDrawRectangle(0-(ran_w*0.2/2), 0-(ran_w*0.2/2), ran_w*0.2, ran_w*0.2);
        
        ofPopMatrix();
        
    };
    
    
    
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' ') {
//        ofPixels p;
//        fbo.readToPixels(p);
//        ofSaveImage(p, ofGetTimestampString() + ".png");
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        img.save(ofGetTimestampString() + ".png");
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
