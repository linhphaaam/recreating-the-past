#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ww = ofGetWidth();
    hh = ofGetHeight();
    
    slit_location = 0;
    frame_location = 0;
    
    // allocate images
    
    img.allocate(ww, hh, OF_IMAGE_COLOR);
    img_left.allocate(ww, hh, OF_IMAGE_COLOR);
    back_img.allocate(ww, hh, OF_IMAGE_COLOR);
    back_img_2.allocate(ww, hh, OF_IMAGE_COLOR);
    back_img_left.allocate(ww, hh, OF_IMAGE_COLOR);
    back_img_left_2.allocate(ww, hh, OF_IMAGE_COLOR);
    screenshot.allocate(ww, hh, OF_IMAGE_COLOR);
    slit_img.allocate(ww, hh, OF_IMAGE_COLOR);
    slit_img_left.allocate(ww, hh, OF_IMAGE_COLOR);
    
    // allocate fbos
    
    slit.allocate(ww, hh, GL_RGBA);
    slit_left.allocate(ww, hh, GL_RGBA);
    back_fbo.allocate(ww, hh, GL_RGBA);
    back_fbo_left.allocate(ww, hh, GL_RGBA);
    
    // load back image
    
    back_img.load("source/psychedelic_2.jpg");
    back_img.resize(ww, hh);
    
    back_img_left.load("source/psychedelic_2.jpg");
    back_img_left.resize(ww, hh);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    // set amount to translate slit
    slit_location +=10;
    
    
    if (slit_location > 1350) {
        // reset the slit translate amount to zero once the slit hits the edge
        slit_location = 0;
        
        // set amount to translate the back image for next frame
        frame_location +=10;
        
        // save frame as image once the frame is done / once the slit hits the edge
        screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        screenshot.save("psychedelic_2/" + ofGetTimestampString() + ".png");
    }
    
    // create right slit fbo (mask)
    
    slit.begin();
    ofEnableDepthTest();
    ofBackground(0);
    ofSetColor(255);
    
    // move slit mask closer to viewpoint and slightly to the right
    
    ofDrawRectangle(slit.getWidth()/2 + slit_location/15, 0, -500+slit_location, 15, slit.getHeight());
    ofDisableDepthTest();
    slit.end();
    
    // convert slit fbo to img
    
    slit.readToPixels(pixels);
    slit_img.setFromPixels(pixels);
    slit_img.update();
    
    
    // create left slit fbo (mask)
    
    slit_left.begin();
    ofEnableDepthTest();
    ofBackground(0);
    ofSetColor(255);
    
    // move slit mask closer to viewpoint and slightly to the left
    
    ofDrawRectangle((slit.getWidth()/3) + slit_location/15 + 213, 0, 850-slit_location, 15, slit.getHeight());

    ofDisableDepthTest();
    slit_left.end();
    
    // convert slit fbo to img
    
    slit_left.readToPixels(pixels_left);
    slit_img_left.setFromPixels(pixels_left);
    slit_img_left.update();
    
    
    
    // create back image fbo (right)
    
    back_fbo.begin();
    ofEnableDepthTest();
    ofBackground(0);
    
    // move back graphic closer to viewpoint and slightly to the right
    // the back graphic neesd to move right slower than the slit
    
    back_img.draw(-700+slit_location/20 + frame_location, 0, -600+slit_location);
    ofDisableDepthTest();
    back_fbo.end();
    
    // convert back image fbo to img
    
    back_fbo.readToPixels(pixels_back);
    back_img_2.setFromPixels(pixels_back);
    back_img_2.update();
    
    
    // create back image fbo (left)
    
    back_fbo_left.begin();
    ofEnableDepthTest();
    ofBackground(0);
    
    // move back graphic closer to viewpoint and slightly to the left
    // the back graphic neesd to move left faster than the slit
    
    back_img_left.draw(0-slit_location/10 + frame_location, 0, 750-slit_location);
    ofDisableDepthTest();
    back_fbo_left.end();
    
    // convert back image fbo to img
    
    back_fbo_left.readToPixels(pixels_back_left);
    back_img_left_2.setFromPixels(pixels_back_left);
    back_img_left_2.update();
    
    
    // create the frame (right)
    
    for (int x = ofGetWidth()/2; x < ofGetWidth(); x++) {
        
        for (int y = 0; y < ofGetHeight(); y++) {
            float brightness = slit_img.getPixels().getColor(x,y).getBrightness();
            if (brightness > 127) {
                ofColor color = back_img_2.getColor(x,y);
                img.setColor(x, y, color);
            }
        }
            
    }
    
    img.update();
    
    // create the frame (left)
    
    for (int x = 0; x < ofGetWidth()/2; x++) {
        
        for (int y = 0; y < ofGetHeight(); y++) {
            float brightness = slit_img_left.getPixels().getColor(x,y).getBrightness();
            if (brightness > 127) {
                ofColor color = back_img_left_2.getColor(x,y);
                img_left.setColor(x, y, color);
            }
        }
            
    }
    
    img_left.update();
    


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofBackground(0);
    img_left.draw(0, 0);
    img.draw(0, 0);
//    back_img_2.draw(0,0);
//    back_img_left_2.draw(0,0);
//    slit.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' ') {
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
