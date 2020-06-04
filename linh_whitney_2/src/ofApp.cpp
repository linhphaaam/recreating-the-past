#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofSetFrameRate(30);
    ofSetCircleResolution(6);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    ofNoFill();
    ofSetLineWidth(2);
    
    float time = ofGetElapsedTimef();
    float xorig = 400;
    float yorig = 400;
    float angle = time*0.5;
    float radius = 200;
    
    for (int i = 0; i < 4; i++){
//        ofSetColor(0,0,255);
        
        float speed_scaler = 1;
        
        float x = xorig + radius * sin(speed_scaler*3*(angle + (PI*i/2)/speed_scaler));
        float y = yorig + radius * sin(speed_scaler*2*(angle + (PI*i/2)/speed_scaler));

        ofDrawCircle(x, y, speed_scaler*30);
        
        
//        if (i == 3) {
//            trail.addVertex(x,y);
//            trail.draw();
//        }

    }
    for (int i = 0; i < 4; i++){
//        ofSetColor(255,0,0);

        float speed_scaler = 1.25;

        float x = xorig + radius * sin(speed_scaler*3*(angle + (PI*i/2)/speed_scaler));
        float y = yorig + radius * sin(speed_scaler*2*(angle + (PI*i/2)/speed_scaler));


        ofDrawCircle(x, y, speed_scaler*30);

    }

    for (int i = 0; i < 4; i++){
//        ofSetColor(0,255,0);

        float speed_scaler = 1.5;

        float x = xorig + radius * sin(speed_scaler*3*(angle + (PI*i/2)/speed_scaler));
        float y = yorig + radius * sin(speed_scaler*2*(angle + (PI*i/2)/speed_scaler));

        ofDrawCircle(x, y, speed_scaler*30);

    }

    for (int i = 0; i < 4; i++){
//        ofSetColor(255);

        float speed_scaler = 1.75;

        float x = xorig + radius * sin(speed_scaler*3*(angle + (PI*i/2)/speed_scaler));
        float y = yorig + radius * sin(speed_scaler*2*(angle + (PI*i/2)/speed_scaler));

        ofDrawCircle(x, y, speed_scaler*30);

    }

    for (int i = 0; i < 4; i++){
//        ofSetColor(255,200,150);

        float speed_scaler = 2;

        float x = xorig + radius * sin(speed_scaler*3*(angle + (PI*i/2)/speed_scaler));
        float y = yorig + radius * sin(speed_scaler*2*(angle + (PI*i/2)/speed_scaler));

        ofDrawCircle(x, y, speed_scaler*30);

    }

    for (int i = 0; i < 4; i++){
//        ofSetColor(0,100,100);

        float speed_scaler = 2.25;

        float x = xorig + radius * sin(speed_scaler*3*(angle + (PI*i/2)/speed_scaler));
        float y = yorig + radius * sin(speed_scaler*2*(angle + (PI*i/2)/speed_scaler));

        ofDrawCircle(x, y, speed_scaler*30);

    }
    
//    if (trail.size() > 5) {
//        trail.getVertices().erase(trail.getVertices().begin());
//    }
//
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
