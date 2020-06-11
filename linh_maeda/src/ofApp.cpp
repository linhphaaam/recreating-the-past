#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofTrueTypeFontSettings settings("CP-Font-morisawa-edited.ttf", 159);
    settings.antialiased = true;
    settings.contours = true;
    settings.dpi = 72;
    settings.addRanges(ofAlphabet::Japanese);
    font.load(settings);
    ofBackground(255);
    font.setLetterSpacing(0.98);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofEnableSmoothing();
    total_y = -5;
    ofSetColor(0);
    vector < ofPath > paths = font.getStringAsPoints("モリサワ");
    
    for (float j = 0; j < 340; j++){
        int current_y = 141/((j*0.98)+1);
        if (j < 40) {
            total_y = total_y + current_y;
        } else {
            total_y = total_y + 141/(j*.98);
        }
        tile_width = 625/(j+1);
        for (int m = 0; m < (j+1); m++){
//        for (int i = 0; i < paths.size(); i++){
//            ofPushMatrix();
//            ofTranslate(600 - tile_width,total_y);
//            ofScale(1/(j+1),1/(j+1),1);
//            paths[i].draw();
//            ofPopMatrix();
//        }
            for (int i = 0; i < paths.size(); i++){
                ofPushMatrix();
                ofTranslate(5+m*tile_width,total_y);
                ofScale(1/(j+1),1/(j+1),1);
                paths[i].draw();
                ofPopMatrix();
            }
        }
    }
    
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
