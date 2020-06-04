#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);
    ofSetFrameRate(10);

}

//--------------------------------------------------------------
void ofApp::update(){
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSeedRandom(0);

    
    ofPushMatrix();
    ofSetColor(230,207,204);
    ofDrawRectangle(25,25,750,750);
    ofPopMatrix();
    
    ofSetColor(82,62,169);
    
    for (int a = 0; a < 29; a++) {
        for (int b = 0; b < 29; b++) {
            float x = ofMap(a, 0, 28, 50, 750);
            float y = ofMap(b, 0, 28, 50, 750);
            
            ofPushMatrix();
            ofTranslate(x,y);
            
            if (15*b - 75 < pow(a-14, 2)) {
                ofSetLineWidth(7);
                ofRotateDeg(ofRandom(-35,35));
                ofDrawCircle(0, -35, 3.5);
                ofDrawCircle(0, 35, 3.5);
            } else if (b > 24) {
                ofSetLineWidth(2);
                ofRotateDeg(ofRandom(55,125));
                ofDrawCircle(0, -35, 1);
                ofDrawCircle(0, 35, 1);
            } else {
                ofSetLineWidth(14);
                ofRotateDeg(ofRandom(-100,100));
                ofDrawCircle(0, -35, 7);
                ofDrawCircle(0, 35, 7);
            }
            
            ofDrawLine(0, -35, 0, 35);
            ofPopMatrix();
            
            
        }
    }
    
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
