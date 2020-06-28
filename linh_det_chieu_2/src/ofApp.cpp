#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    red = ofColor(213,48,71);
    purple = ofColor(71,48,183);
    yellow = ofColor(233,226,75);
    green = ofColor(53,123,93);
    cream = ofColor(229,227,221);
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
//    ofRotateXDeg(90);
//    ofSetColor(255);
    
    for (int j = 0; j < ofClamp(ofGetElapsedTimef()*10-20, 0, ofGetHeight()); j +=4) {
        ofPushMatrix();
        ofTranslate(0,j);
        ofRotateXDeg(90);
        
        for (float i = 0; i < ofClamp(ofGetElapsedTimef()*100-j*255 - 200, 0, ofGetWidth()); i += 3) {
            int modulo = 4*2;
            int weave_freq = 10;
            int weave_amp = 4;
            float value_i = ofMap(i, 0, ofGetWidth(), 0, TWO_PI);
            if (j < ofGetHeight()/4) {
                
                if (j % (modulo) == 0) {
                    ofSetColor(yellow);
                    ofDrawBox(i, weave_amp*sin(value_i*weave_freq), 0, 3, 3, 3);
                } else {
                    ofSetColor(green);
                    ofDrawBox(i, weave_amp*sin(value_i*weave_freq + PI), 0, 3, 3, 3);
                }
                
            } else if (j > ofGetHeight()/4-1 & j < ofGetHeight()/2) {
                if (j % (modulo) == 0) {
                    ofSetColor(purple);
                    ofDrawBox(i, weave_amp*sin(value_i*weave_freq), 0, 3, 3, 3);
                } else {
                    ofSetColor(red);
                    ofDrawBox(i, weave_amp*sin(value_i*weave_freq + PI), 0, 3, 3, 3);
                }
                    
            } else if (j > ofGetHeight()/2-1 & j < 3*ofGetHeight()/4) {
                if (j % (modulo) == 0) {
                    ofSetColor(red);
                    ofDrawBox(i, weave_amp*sin(value_i*weave_freq), 0, 3, 3, 3);
                } else {
                    ofSetColor(yellow);
                    ofDrawBox(i, weave_amp*sin(value_i*weave_freq + PI), 0, 3, 3, 3);
                }
                
            } else {
                if (j > 3*ofGetHeight()/4 - 1 & j < 25*ofGetHeight()/32 || j > 26*ofGetHeight()/32 - 1 & j < 27*ofGetHeight()/32 || j > 28*ofGetHeight()/32 - 1 & j < 29*ofGetHeight()/32 || j > 30*ofGetHeight()/32 - 1 & j < 31*ofGetHeight()/32) {
                    if (j % (modulo) == 0) {
                        ofSetColor(cream);
                        ofDrawBox(i, weave_amp*sin(value_i*weave_freq), 0, 3, 3, 3);
                    } else {
                        ofSetColor(green);
                        ofDrawBox(i, weave_amp*sin(value_i*weave_freq + PI), 0, 3, 3, 3);
                    }
                } else {
                    if (j % (modulo) == 0) {
                        ofSetColor(purple);
                        ofDrawBox(i, weave_amp*sin(value_i*weave_freq), 0, 3, 3, 3);
                    } else {
                        ofSetColor(red);
                        ofDrawBox(i, weave_amp*sin(value_i*weave_freq + PI), 0, 3, 3, 3);
                    }
                }
            }
            
//            if (j % (6*2) == 0) {
////                ofDrawBox(i, (40*sin(ofGetElapsedTimef()))*sin(value_i*10), 0, 3, 3, 3);
//                ofDrawBox(i, 2*sin(value_i*10), 0, 3, 3, 3);
//            } else {
////                ofDrawBox(i, (40*sin(ofGetElapsedTimef()))*sin(value_i*10 + PI), 0, 3, 3, 3);
//                ofDrawBox(i, 2*sin(value_i*10 + PI), 0, 3, 3, 3);
//            }
        }
        
        ofPopMatrix();
    }
    
    
    ofSetColor(cream);
    ofSetLineWidth(2);
    for (float i = 26; i < ofGetWidth(); i += 51) {
        ofDrawLine(i, 0, i, ofGetHeight());
    }
    
    ofDisableDepthTest();

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
