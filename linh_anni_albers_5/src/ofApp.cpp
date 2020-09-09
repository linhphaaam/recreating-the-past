#include "ofApp.h"
#include "Walker.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    walker.setup();
    ofBackground(236, 224, 191, 255);
    ofEnableDepthTest();

    ofSetBackgroundAuto(false);
    color = ofColor(228, 198, 97);
    zoffset = 0;
    fbo.allocate(ofGetWidth()-80, ofGetHeight()-80, GL_RGBA, 4);
    fbo.begin();
    ofClear(100,100,100,0);
    fbo.end();

}

//--------------------------------------------------------------
void ofApp::update(){
    walker.update(mouseX,mouseY, sin(ofGetElapsedTimef()*0.35)*2);
//    walker.update(500+(sin(ofGetElapsedTimef()*1/1.5))*370+ofSignedNoise(ofGetElapsedTimef()*0.5)*85, (sin(ofGetElapsedTimef()*3/(2*1.5)))*350+ofSignedNoise(ofGetElapsedTimef()*0.4)*80, sin(ofGetElapsedTimef()*0.7 + PI/6)*1.3);
//    walker.update(500+(sin(ofGetElapsedTimef())*370)+ofSignedNoise(ofGetElapsedTimef()*0.5)*65, ofSignedNoise(ofGetElapsedTimef()*0.3)*960, sin(ofGetElapsedTimef()*0.7 + PI/6)*1.3);
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(224, 207, 196);
    ofDrawRectangle(40, 40, ofGetWidth()-80, ofGetHeight()-80);
    fbo.begin();
    ofEnableDepthTest();
    ofSetBackgroundAuto(false);
    
    ofColor new_color;
    
    new_color.r = color.r + ofSignedNoise(ofGetElapsedTimef())*20;
    new_color.g = color.g + ofSignedNoise(ofGetElapsedTimef())*20;
    new_color.b = color.b + ofSignedNoise(ofGetElapsedTimef())*20;
    
    walker.draw(new_color, 0);
    ofDisableDepthTest();
    fbo.end();
    
    fbo.draw(40,40, ofGetWidth()-80, ofGetHeight()-80);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'y'){
        color = ofColor(200, 168, 89);
    }
    if (key == 'r'){
        color = ofColor(166, 81, 63);
    }
    if (key == 'b'){
        color = ofColor(132, 174, 220);
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
