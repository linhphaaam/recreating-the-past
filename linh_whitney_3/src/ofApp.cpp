#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofSetCircleResolution(100);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofSetColor(4,15,97);
    
    ofNoFill();
//    ofSetLineWidth(4);
    
    float time = ofGetElapsedTimef();
    
    
//    for (int i = 0; i < 11; i++) {
////        float x = ofMap(sin(ofGetElapsedTimef()), -1, 1, 10, 20);
//        ofDrawCircle(400,400, i*40 + (250-30*i)*abs(sin(ofGetElapsedTimef()*0.3)) + 30);
//        if (i < 3) {
//            ofSetColor(4,15,97);
//        }
//        if (i > 2 & i < 5) {
//            ofSetColor(170,145,159);
//        }
//        if (i > 4) {
//            ofSetColor(125,38,34);
//        }
//    }
    
    float transparency_r = ofMap(sin(1.2*ofGetElapsedTimef()), -1, 1, 100, 255);
    float transparency_g = ofMap(sin(0.7*ofGetElapsedTimef() + PI/2), -1, 1, 100, 255);
    float transparency_b = ofMap(sin(ofGetElapsedTimef() + PI/3), -1, 1, 100, 255);
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    
    ofSetLineWidth(3);
    ofSetColor(255,0,0,transparency_r);
    
    for (int i = 0; i < 11; i++) {
    //        float x = ofMap(sin(ofGetElapsedTimef()), -1, 1, 10, 20);
        ofDrawCircle(400,400, i*40 + (250-30*i)*abs(sin(ofGetElapsedTimef()*0.3 + i*.1)) + 30);
//        if (i < 3) {
//            ofSetColor(4,15,97);
//        }
//        if (i > 2 & i < 5) {
//            ofSetColor(170,145,159);
//        }
//        if (i > 4) {
//            ofSetColor(125,38,34);
//        }
    }
    
    ofSetColor(0,255,0,transparency_g);
    
    for (int i = 0; i < 11; i++) {
    //        float x = ofMap(sin(ofGetElapsedTimef()), -1, 1, 10, 20);
        ofDrawCircle(398,398, i*40 + (250-30*i)*abs(sin(ofGetElapsedTimef()*0.3 + i*.1)) + 30);
//        if (i < 3) {
//            ofSetColor(4,15,97);
//        }
//        if (i > 2 & i < 5) {
//            ofSetColor(170,145,159);
//        }
//        if (i > 4) {
//            ofSetColor(125,38,34);
//        }
    }
    
    ofSetColor(0,0,255,transparency_b);
    
    for (int i = 0; i < 11; i++) {
    //        float x = ofMap(sin(ofGetElapsedTimef()), -1, 1, 10, 20);
        ofDrawCircle(402,402, i*40 + (250-30*i)*abs(sin(ofGetElapsedTimef()*0.3)) + 30);
//        if (i < 3) {
//            ofSetColor(4,15,97);
//        }
//        if (i > 2 & i < 5) {
//            ofSetColor(170,145,159);
//        }
//        if (i > 4) {
//            ofSetColor(125,38,34);
//        }
    }
    
    ofDisableBlendMode();

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
