#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    screenshot.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    
    ofEnableDepthTest();
    

    black = ofColor(0, 0, 0);
    blue = ofColor(57,131,212);
    orange = ofColor(243,104,50);
    red = ofColor(171, 34, 35);
    green = ofColor(28, 67, 55);
    yellow = ofColor(240, 210, 72);
    brown = ofColor(100, 68, 55);
    purple = ofColor(57, 29, 96);
    
    
    colors.push_back(ofColor(255));
    colors.push_back(black);
    colors.push_back(black);
    colors.push_back(blue);
    colors.push_back(blue);
    colors.push_back(orange);
    colors.push_back(orange);
    colors.push_back(red);
    colors.push_back(red);
    colors.push_back(green);
    colors.push_back(green);
    colors.push_back(yellow);
    colors.push_back(yellow);
    colors.push_back(purple);
    colors.push_back(purple);
    colors.push_back(brown);
    colors.push_back(brown);
    colors.push_back(blue);
    colors.push_back(blue);
    colors.push_back(orange);
    colors.push_back(orange);
    colors.push_back(red);
    colors.push_back(red);
    colors.push_back(green);
    colors.push_back(green);
    colors.push_back(yellow);
    colors.push_back(yellow);
    colors.push_back(purple);
    colors.push_back(purple);
    
//    stretch = 5*sin(ofGetElapsedTimef());
}

//--------------------------------------------------------------
void ofApp::update(){
    stretch = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 300);
    expand = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 100);
    
    circles.clear();
    
    for (int i = 0; i < 30; i++) {
        ofPath path;
        path.setMode(ofPath::POLYLINES);
        path.setCircleResolution(100);
        if (i == 0) {
            path.circle(0, 0, 60*i, 50);
        }
        if (i % 2 && i > 0) {
            path.circle(0, 0, 60*i, 300);
            path.rotateDeg(i*sin(ofGetElapsedTimef()+PI/4*i*0.1), ofVec3f(0,1,0));
            path.rotateDeg(i*sin(ofGetElapsedTimef()+PI/4*i*0.1), ofVec3f(1,0,0));
        } else {
            path.circle(0, 0, 60*i, 150);
            path.rotateDeg(i*sin(ofGetElapsedTimef()+PI/4*i*0.1), ofVec3f(0,1,0));
            path.rotateDeg(i*sin(ofGetElapsedTimef()+PI/4*i*0.1), ofVec3f(1,0,0));
        }
        
        ofPolyline circle;
        circle = path.getOutline()[0];
        circles.push_back(circle);
    }
    
    circles_arm.clear();
    
    for (int i = 0; i < 30; i++) {
        ofPath path;
        path.setMode(ofPath::POLYLINES);
        path.setCircleResolution(100);
        if (i == 0) {
            path.circle(0, 0, 100*i, 50);
        }
        if (i % 2 && i > 0) {
            path.circle(0, 0, 100*i, 300);
            path.rotateDeg(i*sin(ofGetElapsedTimef()+PI/4*i*0.2), ofVec3f(0,1,0));
            path.rotateDeg(i*sin(ofGetElapsedTimef()+PI/4*i*0.2), ofVec3f(1,0,0));
        } else {
            path.circle(0, 0, 100*i, 150);
            path.rotateDeg(i*sin(ofGetElapsedTimef()+PI/4*i*0.2), ofVec3f(0,1,0));
            path.rotateDeg(i*sin(ofGetElapsedTimef()+PI/4*i*0.2), ofVec3f(1,0,0));
        }
        
        ofPolyline circle;
        circle = path.getOutline()[0];
        circles_arm.push_back(circle);
    }
    
    circles_arm_right.clear();
    
    for (int i = 0; i < 30; i++) {
        ofPath path;
        path.setMode(ofPath::POLYLINES);
        path.setCircleResolution(100);
        if (i == 0) {
            path.circle(0, 0, 100*i, 50);
        }
        if (i % 2 && i > 0) {
            path.circle(0, 0, 35+100*i, 300);
            path.rotateDeg(i*sin(ofGetElapsedTimef()+PI/2*i*0.2), ofVec3f(0,1,0));
            path.rotateDeg(i*sin(ofGetElapsedTimef()+PI/2*i*0.2), ofVec3f(1,0,0));
        } else {
            path.circle(0, 0, 35+100*i, 150);
            path.rotateDeg(i*sin(ofGetElapsedTimef()+PI/2*i*0.2), ofVec3f(0,1,0));
            path.rotateDeg(i*sin(ofGetElapsedTimef()+PI/2*i*0.2), ofVec3f(1,0,0));
        }
        
        ofPolyline circle;
        circle = path.getOutline()[0];
        circles_arm_right.push_back(circle);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofBackgroundGradient(ofColor(255), ofColor(210));
    ofSetColor(255);

    cam.begin();
    ofTranslate(0, 700, -600);
    ofRotateXDeg(60);
    ofSetLineWidth(5);
    
    for (int i = 0; i < 29; i++) {
        ofSetColor(colors[i]);
        for (int j = 0; j < circles[i].size(); j++) {

            if (i < 28 ){
                ofDrawLine(circles[i][j], circles[i+1][j]);
            }
        }
        circles[i].draw();
    }
    
    // left arm
    
    for (int i = 0; i < 23; i++) {
        ofPushMatrix();
        ofTranslate(-300,-50,100);
        ofScale(0.4, 0.4, 0.4);
        ofRotateYDeg(-50*sin(ofGetElapsedTimef()));
        ofRotateZDeg(-200*sin(ofGetElapsedTimef()));
        
        ofSetColor(colors[i]);
        for (int j = 0; j < circles_arm[i].size(); j++) {

            if (i < 22 ){
                ofDrawLine(circles_arm[i][j], circles_arm[i+1][j]);
            }
        }
        circles_arm[i].draw();
        ofPopMatrix();
    }
    
    // right arm
    
    for (int i = 0; i < 23; i++) {
        ofPushMatrix();
        ofTranslate(300,-50,100);
        ofScale(0.4, 0.4, 0.4);
        ofRotateYDeg(25);
        ofRotateZDeg(25*sin(ofGetElapsedTimef()));

        
        ofSetColor(colors[i]);
        for (int j = 0; j < circles_arm_right[i].size(); j++) {

            if (i < 22 ){
                ofDrawLine(circles_arm_right[i][j], circles_arm_right[i+1][j]);
            }
        }
        circles_arm_right[i].draw();
        ofPopMatrix();
    }
        
    
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
//        ofPixels p;
//        fbo.readToPixels(p);
//        ofSaveImage(p, ofGetTimestampString() + ".jpg");
        screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        screenshot.save(ofGetTimestampString() + ".png");
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
