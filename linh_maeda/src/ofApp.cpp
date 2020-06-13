#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofTrueTypeFontSettings settings("CP-Font-morisawa-edited.ttf", 158);
    settings.antialiased = true;
    settings.contours = true;
    settings.dpi = 72;
    settings.addRanges(ofAlphabet::Japanese);
    font.load(settings);
    font.setLetterSpacing(0.98);
    
    fbo.allocate(ofGetWidth()*8, ofGetHeight()*8, GL_RGBA, 4);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    fbo.begin();
    ofBackground(255,255,255,255);
    ofPushMatrix();
    ofScale(8,8);
    total_y = -3;
    ofSetColor(30,27,27);
    vector < ofPath > paths = font.getStringAsPoints("モリサワ");
    
    for (float j = 0; j < 350; j++){
        float current_y = 139/(j+1);
        total_y = total_y + current_y;
        tile_width = 621/(j+1);
        for (int m = 0; m < (j+1); m++){
            for (int i = 0; i < paths.size(); i++){
                ofPushMatrix();
                ofTranslate(7+m*tile_width,total_y);
                ofScale(1/(j+1),1/(j+1),1);
                paths[i].draw();
                ofPopMatrix();
            }
        }
    }
    
    ofPopMatrix();
    ofClearAlpha();
    fbo.end();
    
    fbo.draw(0,0,ofGetWidth(), ofGetHeight());
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' ') {
        ofPixels p;
        fbo.readToPixels(p);
        ofSaveImage(p, ofGetTimestampString() + ".png");
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
