#include "ofApp.h"


void ofApp::subtract(ofImage & imgA, ofImage & imgB){
    // subtract b from a, storing in a
    for (int i = 0; i < imgA.getWidth(); i++){
        for (int j = 0; j < imgA.getHeight(); j++){
            float delta = MAX(0, imgA.getColor(i, j).getBrightness() -
                              imgB.getColor(i, j).getBrightness());
            imgA.setColor(i, j, ofColor(delta));
        }
    }
}

void ofApp::erosion(ofImage & imgSrc, ofImage & imgDest, float step){
    
    // assumption
    // img1 / img2 same w/h
    // both grayscale / binary images
    
    for (int i = 0; i < imgSrc.getWidth(); i++) {
        for (int j = 0; j < imgSrc.getHeight(); j++) {

            //edge
            
            int i_m_1 = ofClamp(i-step, 0, ofGetWidth()-1);
            int i_p_1 = ofClamp(i+step, 0, ofGetWidth()-1);
            int j_m_1 = ofClamp(j-step, 0, ofGetHeight()-1);
            int j_p_1 = ofClamp(j+step, 0, ofGetHeight()-1);
            
            // neighbor values
            
            
            ofColor n_ = imgSrc.getColor(i,j_m_1);
            ofColor ne = imgSrc.getColor(i_p_1,j_m_1);
            ofColor e_ = imgSrc.getColor(i_p_1,j);
            ofColor se = imgSrc.getColor(i_p_1,j_p_1);
            ofColor s_ = imgSrc.getColor(i,j_p_1);
            ofColor sw = imgSrc.getColor(i_m_1,j_p_1);
            ofColor w_ = imgSrc.getColor(i_m_1,j);
            ofColor nw = imgSrc.getColor(i_m_1,j_m_1);
            ofColor center = imgSrc.getColor(i,j);
            
            int sum_brightness_binary = n_.getBrightness()/255 + ne.getBrightness()/255 + e_.getBrightness()/255 + se.getBrightness()/255 + s_.getBrightness()/255 + sw.getBrightness()/255 + w_.getBrightness()/255 + nw.getBrightness()/255;
            
//            if ( sum_brightness_binary < 5 ) {
//                imgDest.setColor(i,j,ofColor(0));
//            }
//
            if ( sum_brightness_binary > 7) {
                imgDest.setColor(i,j,ofColor(255));
            } else if  ( sum_brightness_binary > 0) {
                imgDest.setColor(i,j,ofColor(0));
            } else {
                imgDest.setColor(i,j,ofColor(0));
            }
            
            
//            if ( n_.getBrightness() < 127 ||
//                ne.getBrightness() < 127 ||
//                e_.getBrightness() < 127 ||
//                se.getBrightness() < 127 ||
//                s_.getBrightness() < 127 ||
//                sw.getBrightness() < 127 ||
//                w_.getBrightness() < 127 ||
//                nw.getBrightness() < 127) {
//                imgDest.setColor(i,j,ofColor(0));
//            } else{
//                imgDest.setColor(i,j,ofColor(255));
//            }
        }
    }
    
    imgDest.update();
    
}

void ofApp::dilate(ofImage & imgSrc, ofImage & imgDest, float step){
    
    // assumption
    // img1 / img2 same w/h
    // both grayscale / binary images
    
    for (int i = 0; i < imgSrc.getWidth(); i++) {
        for (int j = 0; j < imgSrc.getHeight(); j++) {

            //edge
            
            int i_m_1 = ofClamp(i-step, 0, ofGetWidth()-1);
            int i_p_1 = ofClamp(i+step, 0, ofGetWidth()-1);
            int j_m_1 = ofClamp(j-step, 0, ofGetHeight()-1);
            int j_p_1 = ofClamp(j+step, 0, ofGetHeight()-1);
            
            // neighbor values
            
            
            ofColor n_ = imgSrc.getColor(i,j_m_1);
            ofColor ne = imgSrc.getColor(i_p_1,j_m_1);
            ofColor e_ = imgSrc.getColor(i_p_1,j);
            ofColor se = imgSrc.getColor(i_p_1,j_p_1);
            ofColor s_ = imgSrc.getColor(i,j_p_1);
            ofColor sw = imgSrc.getColor(i_m_1,j_p_1);
            ofColor w_ = imgSrc.getColor(i_m_1,j);
            ofColor nw = imgSrc.getColor(i_m_1,j_m_1);
            ofColor center = imgSrc.getColor(i,j);
            
            int sum_brightness_binary = n_.getBrightness()/255 + ne.getBrightness()/255 + e_.getBrightness()/255 + se.getBrightness()/255 + s_.getBrightness()/255 + sw.getBrightness()/255 + w_.getBrightness()/255 + nw.getBrightness()/255;
            
            if ( sum_brightness_binary > 7){
                imgDest.setColor(i,j,ofColor(0));
            } else if (sum_brightness_binary > 0 ) {
                imgDest.setColor(i,j,ofColor(255));
            } else {
                imgDest.setColor(i,j,ofColor(0));
            }
            
            
//            if ( n_.getBrightness() < 127 ||
//                ne.getBrightness() < 127 ||
//                e_.getBrightness() < 127 ||
//                se.getBrightness() < 127 ||
//                s_.getBrightness() < 127 ||
//                sw.getBrightness() < 127 ||
//                w_.getBrightness() < 127 ||
//                nw.getBrightness() < 127) {
//                imgDest.setColor(i,j,ofColor(0));
//            } else{
//                imgDest.setColor(i,j,ofColor(255));
//            }
        }
    }
    
    imgDest.update();
    
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    step = 0;
    
    original.allocate(500, 500, GL_RGBA);
    original_img.allocate(original.getWidth(), original.getHeight(), OF_IMAGE_GRAYSCALE);
    original_img_temp.allocate(original.getWidth(), original.getHeight(), OF_IMAGE_GRAYSCALE);
    new_image.allocate(original.getWidth(), original.getHeight(), OF_IMAGE_GRAYSCALE);
    
    // create fbos
    
//    original.begin();
////    ofNoFill();
//    ofBackground(0);
//    ofSetColor(255);
//    ofDrawRectangle(20, 20, 300, 300);
//    ofSetColor(0);
//    ofDrawRectangle(40, 40, 260, 260);
//    ofSetColor(255);
//    ofDrawRectangle(60, 60, 220, 220);
//    ofSetColor(0);
//    ofDrawRectangle(80, 80, 180, 180);
//    ofSetColor(255);
//    ofDrawRectangle(100, 100, 140, 140);
//    ofSetColor(0);
//    ofDrawRectangle(120, 120, 100, 100);
//    ofSetColor(255);
//    ofDrawRectangle(140, 140, 60, 60);
//    ofSetColor(0);
//    ofDrawRectangle(160, 160, 20, 20);
//    original.end();
    
    original.begin();
    ofBackground(0);
    ofSeedRandom(0);
    for (int i = 0; i < 5; i++) {
        ofPushMatrix();
//        ofSetColor(216,143,51);
        ran_x = ofRandom(600);
        ran_y = ofRandom(600);
//        ran_w = 100;
        ran_w = ofRandom(50,150);
        w = ofClamp(ran_w, 0, ran_w);
        ofSetColor(255);
        ofTranslate(ran_x, ran_y);
//        ofRotateDeg(45);
        ofDrawRectangle(0-(w/2), 0-(w/2),w, w);
        ofSetColor(0);
        ofDrawRectangle(0-(w*0.8/2), 0-(w*0.8/2), w*0.8, w*0.8);
        ofSetColor(255);
        ofDrawRectangle(0-(w*0.6/2), 0-(w*0.6/2),w*0.6, w*0.6);
        ofSetColor(0);
        ofDrawRectangle(0-(w*0.4/2), 0-(w*0.4/2),w*0.4, w*0.4);
        ofSetColor(255);
        ofDrawRectangle(0-(w*0.2/2), 0-(w*0.2/2), w*0.2, w*0.2);

        cout << w*0.2 << endl;

        ofPopMatrix();

    }
    original.end();
    
    original.readToPixels(p);
    original_img.setFromPixels(p);
    
    
    erosion(original_img, new_image, 1);
//    cout << w*0.2 << endl;

    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
//    ofScale(5,5);
//    original.draw(0,0);
    original_img.draw(0,0);
    new_image.draw(original_img.getWidth(),0);
    
//    for (int i = 0; i < ofGetWidth(); i+=20) {
//        for (int j = 0; j < ofGetHeight(); j+=20) {
//            ofPushMatrix();
//            ofSetColor(255,0,0);
//            ofDrawLine(i,0,i,ofGetHeight());
//            ofDrawLine(0,j,ofGetWidth(),j);
//            ofSetColor(255);
//            ofPopMatrix();
//        }
//    }
    
//    ofSetColor(255);
//    ofDrawRectangle(300, 300, 300, 300);
//    ofSetColor(0);
//    ofDrawRectangle(325, 325, 250, 250);
//    ofSetColor(255);
//    ofDrawRectangle(350, 350, 200, 200);
//    ofSetColor(0);
//    ofDrawRectangle(375, 375, 150, 150);
//    ofSetColor(255);
//    ofDrawRectangle(400, 400, 100, 100);
//    ofSetColor(0);
//    ofDrawRectangle(425, 425, 50, 50);
    
    
    
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
    
    if (key == 'm') {
        erosion(original_img, new_image, 1);
        original_img.setFromPixels(new_image);
    }
    
//    if (key == 'm') {
//        original_img_temp.setFromPixels(original_img);
//        erosion(original_img_temp, new_image, 30);
////        dilate(original_img, new_image, 1);
//        original_img_temp.setFromPixels(new_image);
//        subtract(original_img_temp, original_img);
//        original_img.setFromPixels(original_img_temp);
//    }
    
    if (key == 'n') {
        dilate(original_img, new_image, 1);
        original_img.setFromPixels(new_image);
    }
    
//   if (key == 'n') {
//       original_img_temp.setFromPixels(original_img);
//        dilate(original_img_temp, new_image, 1);
////        original_img.setFromPixels(new_image);
//       original_img_temp.setFromPixels(new_image);
//       subtract(original_img_temp, original_img);
//       original_img.setFromPixels(original_img_temp);
//    }

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
