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
//    decrease_size = decrease_size + 15;
    ofSeedRandom(seed_i);
    
    if (count == 20) {
        decrease_size = decrease_size + 15;
        count = 0;
    }
    
//    float sin_col_r = ofMap(sin(ofGetElapsedTimef()), -1, 1, 80, 250);
//    float sin_col_g = ofMap(sin(ofGetElapsedTimef()*2), -1, 1, 80, 250);
//    float sin_col_b = ofMap(sin(ofGetElapsedTimef()+PI/2), -1, 1, 80, 250);
//
    //ran_col = ofColor(sin_col_r,sin_col_g,ofRandom(120,255));
    
    seed_i = seed_i + 1;
}

//--------------------------------------------------------------
void ofApp::draw(){
    // See: https://www.robinsloan.com/notes/optical-printing/
//    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
//    // Play with these numbers to shorten or length the "afterlife" of each color.
//    // 0 means no ghosting, 255 means that color will stick around forever.
//    // In this example, red will fade the fastest, and blue will fade the slowest
//    ofSetColor(120, 120, 120);
//    // Full screen rectangle to fade all colors
//    fbo.draw(0,0);
//    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    // Switch back to the normal blend mode
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(255, 255, 255, 17);
    fbo.draw(0,0);

    //sin_col = ofMap(sin(ofGetElapsedTimef()*0.25), -1, 1, 0, 255);
    
    hsb_col.setHsb(0+(ofGetElapsedTimef() * 12), 255, 255);
//
//
    ofSeedRandom(0);

    
    fbo.begin();
    ofEnableDepthTest();
    ofBackground(0);
    for (int i = 0; i < 200; i++) {
        ofPushMatrix();
//        ofSetColor(216,143,51);
        
        
        // draw squares
        int ran_x = ofRandom(950);
        int ran_y = ofRandom(750);
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
    
    for (int i = 0; i < 100; i++) {
        ofPushMatrix();
        int ran_x = ofRandom(1050);
        int ran_y = ofRandom(800);
        int ran_w = ofRandom(30,150);
        int w = ofClamp(ran_w - decrease_size, 0, ran_w);
        ofTranslate(ran_x, ran_y);
        ofRotateDeg(45);
        
        ofSetColor(hsb_col);
        ofDrawRectangle(0-(w/2), 0-(w/2),w, w);
        ofSetColor(0);
        ofDrawRectangle(0-(w*0.8/2), 0-(w*0.8/2),w*0.8, w*0.8);
        ofSetColor(hsb_col);
        ofDrawRectangle(0-(w*0.6/2), 0-(w*0.6/2),w*0.6, w*0.6);
        ofSetColor(0);
        ofDrawRectangle(0-(w*0.4/2), 0-(w*0.4/2),w*0.4, w*0.4);
//        ofSetColor(216,143,51);
//        ofDrawRectangle(0-(ran_w*0.2/2), 0-(ran_w*0.2/2), ran_w*0.2, ran_w*0.2);

        ofPopMatrix();

    };
    
    fbo.end();
    
    
    fbo.draw(0,0);
    
//    cam.enableOrtho();
//    cam.setPosition(600, 400, 300);
//    cam.begin();
////
//
//    for (int i = 0; i < 200; i++) {
//        ofPushMatrix();
////        ofSetColor(216,143,51);
//        int ran_x = ofRandom(1050);
//        int ran_y = ofRandom(900);
//        int ran_w = ofRandom(50,250);
//        int w = ofClamp(ran_w - decrease_size, 0, ran_w);
//        ofSetColor(ran_col);
//        ofTranslate(ran_x, ran_y);
//        ofRotateDeg(45);
//        ofDrawRectangle(0-(w/2), 0-(w/2),-100,w, w);
//        ofSetColor(0);
//        ofDrawRectangle(0-(w*0.8/2), 0-(w*0.8/2),-50, w*0.8, w*0.8);
//        ofSetColor(ran_col);
//        ofDrawRectangle(0-(w*0.6/2), 0-(w*0.6/2),0, w*0.6, w*0.6);
//        ofSetColor(0);
//        ofDrawRectangle(0-(w*0.4/2), 0-(w*0.4/2),50, w*0.4, w*0.4);
//        ofSetColor(ran_col);
//        ofDrawRectangle(0-(w*0.2/2), 0-(w*0.2/2), 100, w*0.2, w*0.2);
//
//        ofPopMatrix();
//
//    };
////
//    for (int i = 0; i < 30; i++) {
//        ofPushMatrix();
//        ofSetColor(ran_col);
//        int ran_x = ofRandom(1050);
//        int ran_y = ofRandom(900);
//        int ran_w = ofRandom(30,120);
//        int w = ofClamp(ran_w - decrease_size, 0, ran_w);
//        ofTranslate(ran_x, ran_y);
//        ofRotateDeg(45);
//        ofDrawRectangle(0-(w/2), 0-(w/2),w, w);
//        ofSetColor(0);
//        ofDrawRectangle(0-(w*0.8/2), 0-(w*0.8/2),w*0.8, w*0.8);
//        ofSetColor(ran_col);
//        ofDrawRectangle(0-(w*0.6/2), 0-(w*0.6/2),w*0.6, w*0.6);
//        ofSetColor(0);
//        ofDrawRectangle(0-(w*0.4/2), 0-(w*0.4/2),w*0.4, w*0.4);
////        ofSetColor(216,143,51);
////        ofDrawRectangle(0-(ran_w*0.2/2), 0-(ran_w*0.2/2), ran_w*0.2, ran_w*0.2);
//
//        ofPopMatrix();
//
//    };
//
//
    
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
