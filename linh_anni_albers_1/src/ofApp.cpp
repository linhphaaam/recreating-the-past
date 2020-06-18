#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    light_cream = ofColor(228, 218, 198);
    cream = ofColor(201, 175, 135);
    ofSetFrameRate(3);
    
    ry.reserve(20);
    rx.reserve(20);
    
    path.rectangle(128,128,760,320);
    mask.allocate(ofGetWidth(),ofGetHeight(),GL_RGBA); //or GL_RED if you are using the programmable renderer
    mask.begin();
    ofClear(0,0,0,0);
    ofSetColor(255);
    path.draw();
    mask.end();
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 4);
    background.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 4);
    fbo.getTexture().setAlphaMask(mask.getTexture());
}

//--------------------------------------------------------------
void ofApp::update(){
}

void ofApp::cream_vertical(){
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i % 3 == 0) {
                ofSetColor(cream);
                ofDrawRectangle(i+(float)ofRandom(-0.2,0.2), j, 1+(float)ofRandom(-0.2,0.2), 1+(float)ofRandom(-0.2,0.2));
            }
        }
    }

}

void ofApp::black_vertical(){
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i % 4 < 2) {
                ofSetColor(0);
                ofDrawRectangle(i+(float)ofRandom(-0.2,0.2), j, 1+(float)ofRandom(-0.2,0.2), 1+(float)ofRandom(-0.2,0.2));
            }
        }
    }

}

void ofApp::black_horizontal(){
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (j % 4 < 2) {
                ofSetColor(0);
                ofDrawRectangle(i, j+(float)ofRandom(-0.2,0.2), 1+(float)ofRandom(-0.2,0.2), 1+(float)ofRandom(-0.2,0.2));
            }
        }
    }

}

void ofApp::light_cream_vertical(){
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i % 3 == 0) {
                ofSetColor(light_cream);
                ofDrawRectangle(i+(float)ofRandom(-0.2,0.2), j, 1+(float)ofRandom(-0.2,0.2), 1+(float)ofRandom(-0.2,0.2));
            }
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    background.begin();
//    ofBackground(182,173,151);
    for (int i = 0; i < 1010; i++){
        for (int j = 0; j < 576; j++) {
            int color_rand = ofRandom(-40,20);
            float temp_noise = ofNoise(ofGetElapsedTimef());
            float noise = ofMap(temp_noise, 0.0,1.0,-40.0,20.0);
            cout << noise << endl;
            ofSetColor(182+noise,173+noise,161+noise);
            ofDrawRectangle(i, j, 1, 1);
            if (i % 7 < 2) {
                ofSetColor(light_cream);
                float temp_rand = ofRandom(-1,1);
                float temp_noise = ofNoise(ofGetElapsedTimef()) * 10;
                ofDrawRectangle(i+temp_rand, j, 1, 1);
            }
            if (j % 7 < 2) {
                ofSetColor(light_cream);
                float temp_rand = ofRandom(-1,1);
                float temp_noise = ofNoise(ofGetElapsedTimef());
                ofDrawRectangle(i+temp_rand, j, 1, 1);
            }
            
        }
    }
    background.end();
    
    background.draw(0,0,ofGetWidth(),ofGetHeight());
    
    for (int i = 0; i < 20; i++) {
        int temp_random = ofRandom(-20, 220);
        ry[i] = temp_random;
    }
    
    for (int i = 0; i < 20; i++) {
        int temp_random = ofRandom(700);
        rx[i] = temp_random;
    }
    
    ofSeedRandom(mouseX*0.1);
    
//    for (int i; i < 20; i++) {
//        int temp_random = ofRandom(760);
//        random_num_x[i] = temp_random;
//    }
    
    
//    ofBackground(182,173,151);
//    for (int i = 0; i < 1010; i++){
//        for (int j = 0; j < 576; j++) {
//
//            if (i % 6 == 0) {
//                ofSetColor(light_cream);
//                ofDrawRectangle(i+(float)ofRandom(-0.5,0.5), j, 1, 1);
//            }
//            if (j % 6 == 0) {
//                ofSetColor(light_cream);
//                ofDrawRectangle(i+(float)ofRandom(-0.5,0.5), j, 1, 1);
//            }
////
//        }
//    }
    
    fbo.begin();
    
    ofPushMatrix();
    ofTranslate(128,128);
    for (int i = 0; i < 760; i++){
        for (int j = 0; j < 320; j++) {
            ofSetColor(0);
            
            // vertical lines - bg
            if (i % 3 == 0) {
                ofSetColor(light_cream);
            }

            // cream horizontal lines

            if (j < 90 & j % 5 < 3) {
                ofSetColor(cream);
            }
            
//            if (j > 140 & j < 220 & j % 3 == 0) {
//                ofSetColor(cream);
//            }
            
            if (j > 219 & j < 280 & j % 5 < 3) {
                ofSetColor(cream);
            }
            
            // cream block
//
//            if (j > 140 & j < 220 & i > 20 & i < 100 & j % 3 == 0) {
//                ofSetColor(cream);
//            }
//
//            if (j > 140 & j < 220 & i > 320 & i < 380 & j % 3 == 0) {
//                ofSetColor(cream);
//            }
            
            // black & cream horizontal lines

            if (j > 70 & j < 120) {
                if (j % 4 == 0){
                    ofSetColor(light_cream);
                } else {
                    ofSetColor(0);
                }
            }
            
            if (j > 280) {
                if (j % 4 == 0){
                    ofSetColor(light_cream);
                } else {
                    ofSetColor(0);
                }
            }
            
//             black horizontal lines
            if (j > 120 & j < 140 & j % 3 < 2) {
                ofSetColor(0);
            }

            // light cream vertical lines

            int color_code [12] = { 0, 3, 6, 9, 12, 15, 18, 21, 24};

            auto columns_light = std::find(std::begin(color_code), std::end(color_code), (i-20) % 120);
            if (columns_light != std::end(color_code)) {
                ofSetColor(light_cream);
            }
            auto columns_light_2 = std::find(std::begin(color_code), std::end(color_code), (i-20) % 460);
            if (columns_light_2 != std::end(color_code)) {
                ofSetColor(light_cream);
            }
            auto columns_light_3 = std::find(std::begin(color_code), std::end(color_code), (i-20) % 386);
            if (columns_light_3 != std::end(color_code)) {
                ofSetColor(light_cream);
            }
            
            // horizontal cream - left corner
//
//            if (j > 140 & j < 220 & i > 20 & i < 120 & j % 3 == 0) {
//                ofSetColor(cream);
//            }
//
            // black horizontal line – 1st column
//            if (i > 120 & i < 140 & j > 140 & j < 180 & j % 3 < 2) {
//                ofSetColor(0);
//            }
//
            // black horizontal line – right
//            if (i > 160 & i < 200 & j > 200 & j < 280 & j % 3 < 2) {
//                ofSetColor(0);
//            }
//
//            if (i > 560 & i < 740 & j > 117 & j < 180 & j % 3 < 2) {
//                ofSetColor(0);
//            }
            
            // vertical black lines
            
//            if (i > 220 & i < 260 & j > 20 & j < 240 & i % 2 == 0) {
//                ofSetColor(0);
//            }
////
//            if (i > 320 & i < 360 & j > 20 & j < 220 & i % 2 == 0) {
//                ofSetColor(0);
//            }
//
//            if (i > 100 & i < 260 & j > 140 & j < 220 & i % 3 < 2) {
//                ofSetColor(0);
//            }
////
//            if (i > 500 & i < 720 & j > 20 & j < 60 & i % 3 == 0) {
//                ofSetColor(0);
//            }
            
            
            ofDrawRectangle(i+(float)ofRandom(-0.2,0.2), j+(float)ofRandom(-0.2,0.2), 1, 1);
            }

        }
    
    for (int t = 0; t < 10; t++) {
        ofPushMatrix();
        ofTranslate(rx[1+t], ry[1+t]);
        for (int i = 0; i < 4+t; i++ ){
            ofTranslate(0, 20);
            ofPushMatrix();
            for (int j = 0; j < 6-t; j ++){
                ofTranslate(20, 0);
                cream_vertical();
            }
            ofPopMatrix();
        }
        ofPopMatrix();
    }
    
    
    for (int t = 0; t < 10; t++) {
        ofPushMatrix();
        ofTranslate(rx[3+t], ry[3+t]);
        for (int i = 0; i < 2+t; i++ ){
            ofTranslate(0, 20);
            ofPushMatrix();
            for (int j = 0; j < 7-t; j ++){
                ofTranslate(20, 0);
                black_horizontal();
            }
            ofPopMatrix();
        }
        ofPopMatrix();
    }
    
    ofPushMatrix();
    ofTranslate(rx[8], ry[8]);
    for (int i = 0; i < 5; i++ ){
        ofTranslate(0, 20);
        ofPushMatrix();
        for (int j = 0; j < 5; j ++){
            ofTranslate(20, 0);
            black_horizontal();
        }
        ofPopMatrix();
    }
    ofPopMatrix();
    
    for (int t = 0; t < 10; t++) {
        ofPushMatrix();
        ofTranslate(rx[9+t], ry[9+t]);
        for (int i = 0; i < 1+t; i++ ){
            ofTranslate(0, 20);
            ofPushMatrix();
            for (int j = 0; j < 7-t; j ++){
                ofTranslate(20, 0);
                black_vertical();
            }
            ofPopMatrix();
        }
        ofPopMatrix();
    }
    
    for (int t = 0; t < 10; t++) {
        ofPushMatrix();
        ofTranslate(rx[14+t], ry[14+t]);
        for (int i = 0; i < 2*t; i++ ){
            ofTranslate(0, 20);
            ofPushMatrix();
            for (int j = 0; j < 4/t; j ++){
                ofTranslate(20, 0);
                light_cream_vertical();
            }
            ofPopMatrix();
        }
        ofPopMatrix();
    }
    
    
    ofPushMatrix();
    ofTranslate(rx[18], ry[18]);
    for (int i = 0; i < 5; i++ ){
        ofTranslate(0, 20);
        ofPushMatrix();
        for (int j = 0; j < 5; j ++){
            ofTranslate(20, 0);
            cream_vertical();
        }
        ofPopMatrix();
    }
    ofPopMatrix();
    
    
    ofPushMatrix();
    ofTranslate(rx[19], ry[19]);
    for (int i = 0; i < 6; i++ ){
        ofTranslate(0, 20);
        ofPushMatrix();
        for (int j = 0; j < 3; j ++){
            ofTranslate(20, 0);
            cream_vertical();
        }
        ofPopMatrix();
    }
    ofPopMatrix();
    
    ofPopMatrix();
    ofClearAlpha();
    fbo.end();
    
    fbo.draw(0,0,ofGetWidth(),ofGetHeight());
//    mask.draw(0,0,ofGetWidth(),ofGetHeight());
    
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
