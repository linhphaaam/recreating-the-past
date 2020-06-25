#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    hokusai.load("hokusai_fuji_1.jpg");
    red.load("red.gif");
    green.load("green_bird_2.gif");
    blue.load("blue_bird_2.gif");
    white.load("white_bird_2.gif");
    
    red_vid.load("red_vid.mp4");
    green_vid.load("green_vid.mp4");
    blue_vid.load("blue_vid.mp4");
    white_vid.load("white_vid.mp4");
    
    red_vid.play();
    green_vid.play();
    blue_vid.play();
    white_vid.play();

}

//--------------------------------------------------------------
void ofApp::update(){
    red_vid.update();
    green_vid.update();
    blue_vid.update();
    white_vid.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
        
    for (int i = 0; i < hokusai.getWidth(); i += 20) {
        for (int j = 0; j < hokusai.getHeight(); j += 20) {
            pixel_color = hokusai.getColor(i,j);
//            int img_brightness = img_color.getBrightness();
//            float circle_size = ofMap(img_brightness, 0, 255, 3,4);
//            ofTranslate(20*sin(ofGetElapsedTimef() + 5 * j), 0);
            
            white_vid.draw(i,j,20,20);
            
            if (pixel_color.r > 150 & pixel_color.g < 120 & pixel_color.b <100) {
                red_vid.draw(i,j,20,20);
            } else if (pixel_color.r < 100 & pixel_color.g < 100 & pixel_color.b > 50 & pixel_color.b > pixel_color.g) {
                blue_vid.draw(i,j,20,20);
            }
            
            if (pixel_color.r < 100 & pixel_color.g > 60 & pixel_color.b < 100) {
                green_vid.draw(i,j,20,20);
            }
            
//            if (pixel_color.r > 150 & pixel_color.g > 150 & pixel_color.b < 150) {
//                white_vid.draw(i,j,20,20);
//            }

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
