#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    float time = ofGetElapsedTimef();
    float xorig = 400;
    float yorig = 400;
    float angle = time*0.1;
    float radius = 200;
    
    for (int i = 0; i < 6; i++){
        ofSetColor(0,0,255);

        float x = xorig + radius * sin(10.5*(angle + (PI*i/2 * PI/10.5)));
        float y = yorig + radius * sin(7*(angle + (PI*i/2 * PI/10.5)));

        ofDrawCircle(x, y, 5);
        
//        if (i == 3) {
//            trail.addVertex(x,y);
//            trail.draw();
//        }

    }
    for (int i = 0; i < 6; i++){
        ofSetColor(255,0,0);
        
        float x = xorig + radius * sin(7.5*(angle + (PI*i/2 * PI/7.5)));
        float y = yorig + radius * sin(5*(angle + (PI*i/2 * PI/7.5)));
        

        ofDrawCircle(x, y, 5);
        
    }
    
    for (int i = 0; i < 6; i++){
        ofSetColor(0,255,0);

        float x = xorig + radius * sin(4.5*(angle + (PI*i/2 * PI/4.5)));
        float y = yorig + radius * sin(3*(angle + (PI*i/2 * PI/4.5)));

        ofDrawCircle(x, y, 5);

    }
////
    for (int i = 0; i < 6; i++){
        ofSetColor(255);

        float x = xorig + radius * sin(1.5*(angle + (PI*i/2 * PI/1.5)));
        float y = yorig + radius * sin(1*(angle + (PI*i/2 * PI/1.5)));

        ofDrawCircle(x, y, 5);

    }
    
//    for (int i = 0; i < 4; i++){
//        ofSetColor(255,200,150);
//
//        float x = xorig + radius * sin(13.5*(angle + (PI*i/2 * 1/13.5)));
//        float y = yorig + radius * sin(9*(angle + (PI*i/2 * 1/13.5)));
//
//        ofDrawCircle(x, y, 5);
//
//    }
//
//    for (int i = 0; i < 4; i++){
//        ofSetColor(0,100,100);
//
//        float x = xorig + radius * sin(16.5*(angle + PI*i));
//        float y = yorig + radius * sin(12*(angle + PI*i));
//
//        ofDrawCircle(x, y, 5);
//
//    }
    
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
