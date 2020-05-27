#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255,230,185);
    ofSetFrameRate(10);

}

//--------------------------------------------------------------
void ofApp::update(){
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSeedRandom(0);
    
    ofSetColor(119,54,87);
    
    for (int a = 0; a < 28; a++) {
        for (int b = 0; b < 28; b++) {
            float x = ofMap(a, 0, 27, 25, 775);
            float y = ofMap(b, 0, 27, 25, 775);
            
            ofPushMatrix();
            ofTranslate(x,y);
            
            if (14*b - 80 < pow(a-14, 2)) {
                ofSetLineWidth(8);
                ofRotateDeg(ofRandom(-35,35));
                ofDrawCircle(0, -35, 4);
                ofDrawCircle(0, 35, 4);
//            } else if (20*pow(b,2) < 19) {
//                ofSetLineWidth(8);
//                ofSetColor(119,54,87);
//                ofRotateDeg(ofRandom(-35,35));
//                ofDrawCircle(0, -35, 4);
//                ofDrawCircle(0, 35, 4);
            } else if (b > 23) {
                ofSetLineWidth(4);
                ofRotateDeg(ofRandom(55,125));
                ofDrawCircle(0, -35, 2);
                ofDrawCircle(0, 35, 2);
            } else {
                ofSetLineWidth(15);
                ofRotateDeg(ofRandom(-70,70));
                ofDrawCircle(0, -35, 7.5);
                ofDrawCircle(0, 35, 7.5);
            }
            
//            else {
//                ofSetLineWidth(1);
//            }
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
