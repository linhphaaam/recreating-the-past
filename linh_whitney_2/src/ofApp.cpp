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
    
    ofSetColor(213,161,184);
    ofNoFill();
    ofSetLineWidth(3);
    
    float time = ofGetElapsedTimef();
    float xorig = 400;
    float yorig = 400;
    float angle = time*0.5;
    float radius = 200;
    
    float speed_overall = sin(time*0.07);
    float speed_map = ofMap(speed_overall, -1, 1, 0.4, 0.9);
    
    
    for (int i = 0; i < 4; i++){
//        ofSetColor(0,0,255);
        ofSetColor(213,161,184);
        
        float speed_scaler = 0.5;
        float speed_scaler_2 = 0.5*speed_map;
        float size_overall = sin(time*0.1 - 7*(PI/8));
        float size_map = ofMap(size_overall, -1, 1, -75, 100);
        
        float x = xorig + radius * sin(speed_scaler_2*3*(angle + (PI*i/2)/speed_scaler_2));
        float y = yorig + radius * sin(speed_scaler_2*2*(angle + (PI*i/2)/speed_scaler_2));
        
        ofPushMatrix();
        ofTranslate(x, y);
        ofRotateDeg(30);

        ofDrawCircle(0, 0, 100 + size_map);
        
        ofPopMatrix();
        
        
//        if (i == 3) {
//            trail.addVertex(x,y);
//            trail.draw();
//        }

    }
    
    for (int i = 0; i < 4; i++){
//        ofSetColor(255,0,0);
        float speed_scaler = 0.75;
        float speed_scaler_2 = 0.75*speed_map;
        float size_overall = sin(time*0.1 - 6*(PI/8));
        float size_map = ofMap(size_overall, -1, 1, -75, 100);

        float x = xorig + radius * sin(speed_scaler_2*3*(angle + (PI*i/2)/speed_scaler_2));
        float y = yorig + radius * sin(speed_scaler_2*2*(angle + (PI*i/2)/speed_scaler_2));

        ofPushMatrix();
        ofTranslate(x, y);
        ofRotateDeg(30);

        ofDrawCircle(0, 0, 100 + size_map);

        ofPopMatrix();

    }

    for (int i = 0; i < 4; i++){
//        ofSetColor(0,255,0);

        float speed_scaler = 1;
        float speed_scaler_2 = 1*speed_map;
        float size_overall = sin(time*0.1 - 5*(PI/8));
        float size_map = ofMap(size_overall, -1, 1, -75, 100);

        float x = xorig + radius * sin(speed_scaler_2*3*(angle + (PI*i/2)/speed_scaler_2));
        float y = yorig + radius * sin(speed_scaler_2*2*(angle + (PI*i/2)/speed_scaler_2));

        ofPushMatrix();
        ofTranslate(x, y);
        ofRotateDeg(30);

        ofDrawCircle(0, 0, 100 + size_map);

        ofPopMatrix();

    }

    for (int i = 0; i < 4; i++){
//        ofSetColor(255);
        float speed_scaler = 1.25;
        float speed_scaler_2 = 1.25*speed_map;
        float size_overall = sin(time*0.1 - 4*(PI/8));
        float size_map = ofMap(size_overall, -1, 1, -75, 100);

        float x = xorig + radius * sin(speed_scaler_2*3*(angle + (PI*i/2)/speed_scaler_2));
        float y = yorig + radius * sin(speed_scaler_2*2*(angle + (PI*i/2)/speed_scaler_2));

        ofPushMatrix();
        ofTranslate(x, y);
        ofRotateDeg(30);

        ofDrawCircle(0, 0, 100 + size_map);

        ofPopMatrix();

    }

    for (int i = 0; i < 4; i++){
//        ofSetColor(255,200,150);
        float speed_scaler = 1.5;
        float speed_scaler_2 = 1.5*speed_map;
        float size_overall = sin(time*0.1 - 3*(PI/8));
        float size_map = ofMap(size_overall, -1, 1, -75, 100);

        float x = xorig + radius * sin(speed_scaler_2*3*(angle + (PI*i/2)/speed_scaler_2));
        float y = yorig + radius * sin(speed_scaler_2*2*(angle + (PI*i/2)/speed_scaler_2));

        ofPushMatrix();
        ofTranslate(x, y);
        ofRotateDeg(30);

        ofDrawCircle(0, 0, 100 + size_map);

        ofPopMatrix();

    }

    for (int i = 0; i < 4; i++){
//        ofSetColor(0,100,100);
        float speed_scaler = 1.75;
        float speed_scaler_2 = 1.75*speed_map;
        float size_overall = sin(time*0.1 - 2*(PI/8));
        float size_map = ofMap(size_overall, -1, 1, -75, 100);

        float x = xorig + radius * sin(speed_scaler_2*3*(angle + (PI*i/2)/speed_scaler_2));
        float y = yorig + radius * sin(speed_scaler_2*2*(angle + (PI*i/2)/speed_scaler_2));

        ofPushMatrix();
        ofTranslate(x, y);
        ofRotateDeg(30);

        ofDrawCircle(0, 0, 100 + size_map);

        ofPopMatrix();

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
