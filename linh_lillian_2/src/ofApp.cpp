#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofBackground(0);
    
    decrease_size = 0;
    ofSetFrameRate(10);
    
    seed_i = 0;
    
    hsb_col.setHsb(0, 255, 255);
    
    count = 0;
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update(){

    ofSeedRandom(seed_i);
    
    if (count == 20) {
        decrease_size = decrease_size + 15;
        count = 0;
    }
    
    seed_i = seed_i + 1;
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(255, 255, 255, 17);
    fbo.draw(0,0);

    
    hsb_col.setHsb(0+(ofGetElapsedTimef() * 12), 255, 255);

    ofSeedRandom(0);

    
    fbo.begin();
    ofEnableDepthTest();
    ofBackground(0);
    for (int i = 0; i < 250; i++) {
        ofPushMatrix();
    
        // draw squares
        int ran_x = ofRandom(1050);
        int ran_y = ofRandom(900);
        int ran_w = ofRandom(50,300);
        int w = ofClamp(ran_w - decrease_size, 0, ran_w);
        ofSetColor(hsb_col);
        ofTranslate(ran_x, ran_y);
        ofRotateDeg(45);
        ofDrawRectangle(0-(w/2), 0-(w/2), -1, w, w);
        ofSetColor(0);
        ofDrawRectangle(0-(w*0.8/2), 0-(w*0.8/2), -0.5, w*0.8, w*0.8);
        ofSetColor(hsb_col);
        ofDrawRectangle(0-(w*0.6/2), 0-(w*0.6/2), 0, w*0.6, w*0.6);
        ofSetColor(0);
        ofDrawRectangle(0-(w*0.4/2), 0-(w*0.4/2), 0.5, w*0.4, w*0.4);

        ofSetColor(hsb_col);
        ofDrawRectangle(0-(w*0.2/2), 0-(w*0.2/2), 1, w*0.2, w*0.2);

        ofPopMatrix();

    };
    ofDisableDepthTest();
    fbo.end();
    
    
    fbo.draw(0,0);
    
//    cam.enableOrtho();
//    cam.setPosition(600, 400, 300);
//    cam.begin();

    
//    cam.end();
    
    count = count + 1;

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
