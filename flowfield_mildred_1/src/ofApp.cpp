#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    for (int i = 0; i < 500; i++) {
        Vehicle v;
        v.setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        vehicles.push_back(v);
    }

    flowfield.flowfield(20);
    ofBackground(0, 0, 0);
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofBackground(0);
    for (int i = 0; i < vehicles.size(); i++) {
        vehicles[i].update();
        vehicles[i].follow(flowfield);
//        vehicles[i].separate(vehicles);
//        vehicles[i].arrive(ofVec2f(mouseX, mouseY));
        vehicles[i].draw(ofColor(0+i*0.5, 100, 255), 1);
    }

//    flowfield.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        img.save("screenshot/" + ofGetTimestampString() + ".png");
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
