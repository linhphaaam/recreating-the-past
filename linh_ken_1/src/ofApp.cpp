#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    linh.load("hokusai_fuji_1.jpg");
//    linh.resize(1504,1004);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    linh.draw(0,0);
    ofSetLineWidth(4);
    ofBackground(0);
    ofTranslate(75,75);
    
    for (int i = 0; i < 1200; i += 10) {
        for (int j = 0; j < 837; j += 10) {
            ofPushMatrix();
            ofColor img_color = linh.getColor(i,j);
            int img_brightness = img_color.getBrightness();
//            float circle_size = ofMap(img_brightness, 0, 255, 3,4);
            float rotation = ofMap(img_brightness, 0, 255, 0,TWO_PI);
            ofPushMatrix();
            ofTranslate(i,j);
            ofRotateRad(rotation+sin(ofGetElapsedTimef()));
//            ofTranslate(20*sin(ofGetElapsedTimef() + 5 * j), 0);
            ofSetColor(img_color);
            ofDrawCircle(-8, 0, 2);
            ofDrawCircle(8, 0, 2);
            ofDrawLine(-8, 0, 8, 0);
            ofPopMatrix();
            ofPopMatrix();

        }
    }

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
