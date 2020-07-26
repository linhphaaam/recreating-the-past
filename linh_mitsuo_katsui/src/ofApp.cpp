#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofTrueTypeFontSettings settings("SourceHanSerif-Heavy.otf", 100);
    settings.antialiased = true;
    settings.contours = true;
    settings.dpi = 72;
    settings.addRanges(ofAlphabet::Japanese);
    font.load(settings);
    font.setLetterSpacing(0.98);

    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 4);
    img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    ofEnableDepthTest();
    paths = font.getStringAsPoints("雨");
    rect = font.getStringBoundingBox("雨", 0,0);
    count = 0;
    ofSetFrameRate(8);
    count_bool = true;
}

//--------------------------------------------------------------
void ofApp::update(){
//    count = count + 1;
    if (count_bool) {
        count++;
    } else {
        count--;
    }
    
    if (count > 10) {
        count_bool = false;
    }
    if (count < 1) {
        count_bool = true;
    }

}


//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    cam.enableOrtho();
    ofRotateXDeg(180);
//    fbo.begin();
    ofBackground(238, 235, 228); // same background color at mitsuo original

    ofPushMatrix();
    ofSetColor(30,27,27);
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
//    ofEnableBlendMode(OF_BLENDMODE_SUBTRACT); // for layers on white background to make black overlay areas
    ofTranslate(-300, 200, 0);
//    ofDrawRectangle(rect.x, rect.y, rect.width, rect.height);
    ofScale(6,6,6);
//
//    ofSetColor(30,27,27);
//    for (int i = 0; i < paths.size(); i++){
//        paths[i].draw();
//    }
    
    for (int k = 0; k < count; k++) {
        ofPushMatrix();
        ofTranslate(rect.width/2, rect.height/2, 0);
        color.setHsb(-10+k*25, 200, 200, 50);
//        color.setHsb(127, 200, 200);
        ofSetColor(color);
//        ofRotateYDeg(90 - (90*pow(1.0/1.4, k)));
        ofRotateYDeg(14*pow(k, 0.8));
        for (int i = 0; i < paths.size(); i++){
            paths[i].draw(-rect.width/2, -rect.height/2);
        }
        ofPopMatrix();
    }
    
    // ofRotateYDeg(180-(9*sqrt(k))); produces slightly off-screen, TV effect
    
    // ofRotateYDeg(180-(11*pow(k, 0.9))); k multiplier decreases as k increases
    
    // ofRotateYDeg(90 - (90*pow(1.0/1.3, k))); similar to above, but doesn't have to calculate another number and it can never go above 90
    
    for (int k = 0; k < count; k++) {
        ofPushMatrix();
        ofTranslate(rect.width/2, rect.height/2, 0);
//        color.setHsb(-20-20*sin(ofGetElapsedTimef())+k*25, 200, 200, 50);
        color.setHsb(-10+k*25, 200, 200, 50);
//        color.setHsb(127, 200, 200);
        ofSetColor(color);
        ofRotateYDeg(180-(14*pow(k, 0.8)));
//        ofRotateYDeg(180 - (90 - (90*pow(1.0/1.4, k))));
        for (int i = 0; i < paths.size(); i++){
            paths[i].draw(-rect.width/2, -rect.height/2);
        }
        ofPopMatrix();
    }
//    ofDrawRectangle(rect.x, rect.y, rect.width, rect.height);

    ofDisableAlphaBlending();
    ofPopMatrix();
    ofClearAlpha();
//    fbo.end();

    cam.end();
    
//    fbo.draw(0,0,ofGetWidth(), ofGetHeight());

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        img.save(ofGetTimestampString() + ".png");
//        ofPixels p;
//        fbo.readToPixels(p);
//        ofSaveImage(p, ofGetTimestampString() + ".png");
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
