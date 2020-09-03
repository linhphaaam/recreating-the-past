#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest();


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //------(h)--------------------------------------
    //
    //         holes / ofNextContour
    //
    //         with ofNextContour we can create multi-contour shapes
    //         this allows us to draw holes, for example...
    //
//    ofFill();
//    ofSetHexColor(0xd3ffd3);
//    ofDrawRectangle(80,480,140,70);
//    ofSetHexColor(0xff00ff);
//
//    ofBeginShape();
//
//        ofVertex(100,500);
//        ofVertex(180,550);
//        ofVertex(100,600);
//
//        ofNextContour(true);
//
//        ofVertex(120,520);
//        ofVertex(160,550);
//        ofVertex(120,580);
//
//    ofEndShape(true);
    //-------------------------------------
    
    
    //------(i)--------------------------------------
    //
    //         CSG / ofNextContour
    //
    //         with different winding rules, you can even use ofNextContour to
    //         perform constructive solid geometry
    //
    //         be careful, the clockwiseness or counter clockwisenss of your multiple
    //         contours matters with these winding rules.
    //
    //         for csg ideas, see : http://glprogramming.com/red/chapter11.html
    //
    //         info about the winding rules is here:
    //        http://glprogramming.com/red/images/Image128.gif
    //
//    ofNoFill();
    
    
//    ofPushMatrix();
//
//    ofSetPolyMode(OF_POLY_WINDING_ODD);
//
//    ofBeginShape();
//
//        ofVertex(300,500);
//        ofVertex(380,550);
//        ofVertex(300,600);
//
//        ofNextContour(true);
//
//        for (int i = 0; i < 20; i++){
//            float anglef = ((float)i / 19.0f) * TWO_PI;
//            float x = 340 + 30 * cos(anglef);
//            float y = 550 + 30 * sin(anglef);
//            ofVertex(x,y);
////            radius     += radiusAdder;
//        }
//
//
//    ofEndShape(true);
//
//    ofTranslate(100,0,0);
//
//    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
//    ofBeginShape();
//
//        ofVertex(300,500);
//        ofVertex(380,550);
//        ofVertex(300,600);
//
//        ofNextContour(true);
//
//        for (int i = 0; i < 20; i++){
//            float anglef = ((float)i / 19.0f) * TWO_PI;
//            float x = 340 + 30 * cos(anglef);
//            float y = 550 + 30 * sin(anglef);
//            ofVertex(x,y);
//            radius     += radiusAdder;
//        }
//
//    ofEndShape(true);
//
//    ofTranslate(100,0,0);
//    ofSetPolyMode(OF_POLY_WINDING_ABS_GEQ_TWO);
//    ofBeginShape();
//        ofVertex(300,500);
//        ofVertex(380,550);
//        ofVertex(300,600);
//        ofNextContour(true);
//
//        for (int i = 0; i < 20; i++){
//            float anglef = ((float)i / 19.0f) * TWO_PI;
//            float x = 340 + 30 * cos(anglef);
//            float y = 550 + 30 * sin(anglef);
//            ofVertex(x,y);
////            radius     += radiusAdder;
//        }
//
//
//    ofEndShape(true);
//
//    ofPopMatrix();
//
    
    
    // try a cube
    
    cam.begin();
    ofPushMatrix();
    light.enable();
    light.setSpotlight();
    light.setGlobalPosition(300, 300, 500);
    light.lookAt(ofVec3f(0,0,0));
        
//    ofSetPolyMode(OF_POLY_WINDING_ODD);
//    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofDrawRectangle(0, 0, 0, 300, 300);
    ofDrawRectangle(0, 0, -300, 300,300);
    ofPushMatrix();
    ofRotateYDeg(90);
    ofDrawRectangle(0, 0, 0, 300, 300);
    ofRotateYDeg(-90);
    ofDrawRectangle(-300, 0, -300, 300, 300);
    ofPopMatrix();
    
//    path.draw();
    
    ofPopMatrix();
    cam.end();

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
