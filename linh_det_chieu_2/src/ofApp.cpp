#include "ofApp.h"

void ofApp::weave_color(ofColor color_1, ofColor color_2, float i, int j, int modulo, int weave_freq, int weave_amp, float value_i){
    
    if (j % (modulo) == 0) {
        ofSetColor(color_1);
        ofDrawBox(i, weave_amp*sin(value_i*weave_freq), 0, 3, 3, 3);
    } else {
        ofSetColor(color_2);
        ofDrawBox(i, weave_amp*sin(value_i*weave_freq + PI), 0, 3, 3, 3);
    };
    
}

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
    
//    for (int j = 0; j < ofClamp(ofGetElapsedTimef()*10-20, 0, ofGetHeight()); j +=4) {
    for (int j = 0; j < ofGetHeight(); j +=4) {
        ofPushMatrix();
        ofTranslate(0,j);
        ofRotateXDeg(90);
        
//        for (float i = 0; i < ofClamp(ofGetElapsedTimef()*100-j*255 - 200, 0, ofGetWidth()); i += 3) {
        for (float i = 0; i < ofGetWidth(); i += 3) {
            int modulo = 4*2;
            int weave_freq = 10;
            int weave_amp = 4;
            float value_i = ofMap(i, 0, ofGetWidth(), 0, TWO_PI);
            int height_denom = 32;
            
            if (j < 4*ofGetHeight()/height_denom) {
                
                if (j >= 0*ofGetHeight()/height_denom & j < 0.5*ofGetHeight()/height_denom ||
                   j >= 1*ofGetHeight()/height_denom & j < 1.5*ofGetHeight()/height_denom ||
                   j >= 2*ofGetHeight()/height_denom & j < 2.5*ofGetHeight()/height_denom ||
                   j >= 3*ofGetHeight()/height_denom & j < 3.5*ofGetHeight()/height_denom) {
                   
                   weave_color(cream, green, i, j, modulo, weave_freq, weave_amp, value_i);
                   
               } else {
                   
                   weave_color(purple, red, i, j, modulo, weave_freq, weave_amp, value_i);
               }
                
                
            } else if (j >= 4*ofGetHeight()/height_denom & j < 7*ofGetHeight()/height_denom) {
                
                weave_color(yellow, green, i, j, modulo, weave_freq, weave_amp, value_i);
                
            } else if (j >= 7*ofGetHeight()/height_denom & j < 10*ofGetHeight()/height_denom) {
                
                weave_color(purple, red, i, j, modulo, weave_freq, weave_amp, value_i);
                    
            } else if (j >= 10*ofGetHeight()/height_denom & j < 13*ofGetHeight()/height_denom) {
                
                weave_color(yellow, green, i, j, modulo, weave_freq, weave_amp, value_i);
                
            } else if (j >= 13*ofGetHeight()/height_denom & j < 17*ofGetHeight()/height_denom) {
                
                if (j >= 13*ofGetHeight()/height_denom & j < 13.5*ofGetHeight()/height_denom ||
                    j >= 14*ofGetHeight()/height_denom & j < 14.5*ofGetHeight()/height_denom ||
                    j >= 15*ofGetHeight()/height_denom & j < 15.5*ofGetHeight()/height_denom ||
                    j >= 16*ofGetHeight()/height_denom & j < 16.5*ofGetHeight()/height_denom) {
                    
                    weave_color(cream, green, i, j, modulo, weave_freq, weave_amp, value_i);
                    
                } else {
                    
                    weave_color(purple, red, i, j, modulo, weave_freq, weave_amp, value_i);
                }
                
            } else if (j >= 17*ofGetHeight()/height_denom & j < 20*ofGetHeight()/height_denom){
                
                weave_color(red, yellow, i, j, modulo, weave_freq, weave_amp, value_i);
                
            } else if (j >= 20*ofGetHeight()/height_denom & j < 23*ofGetHeight()/height_denom) {
                
                weave_color(purple, red, i, j, modulo, weave_freq, weave_amp, value_i);
                
            } else if (j >= 23*ofGetHeight()/height_denom & j < 26*ofGetHeight()/height_denom) {
                
                weave_color(red, yellow, i, j, modulo, weave_freq, weave_amp, value_i);
                
            } else if (j >= 26*ofGetHeight()/height_denom & j < 30*ofGetHeight()/height_denom) {
                
                if (j >= 26*ofGetHeight()/height_denom & j < 26.5*ofGetHeight()/height_denom ||
                    j >= 27*ofGetHeight()/height_denom & j < 27.5*ofGetHeight()/height_denom ||
                    j >= 28*ofGetHeight()/height_denom & j < 28.5*ofGetHeight()/height_denom ||
                    j >= 29*ofGetHeight()/height_denom & j < 29.5*ofGetHeight()/height_denom) {
                    
                    weave_color(cream, green, i, j, modulo, weave_freq, weave_amp, value_i);
                    
                } else {
                    
                    weave_color(purple, red, i, j, modulo, weave_freq, weave_amp, value_i);
                }
                
            } else if (j >= 30*ofGetHeight()/height_denom & j < 32*ofGetHeight()/height_denom) {
                
                weave_color(yellow, green, i, j, modulo, weave_freq, weave_amp, value_i);
                
            } else {
                
                weave_color(purple, red, i, j, modulo, weave_freq, weave_amp, value_i);
                
            }
        }
        
        ofPopMatrix();
    }
    
    
    ofSetColor(cream);
    ofSetLineWidth(1.5);
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
