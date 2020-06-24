#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

//    ofImage original;
    ofImage new_image;
    ofImage hokusai;
    ofImage hokusai_pixel;
    
    ofImage img;
    
    ofFbo original;
    
    ofImage original_img;
    ofImage original_img_temp;
    ofPixels p;
    
    ofEasyCam cam;
    
    ofColor ran_col;
    
    int seed_i;
    
    int ran_x;
    int ran_y;
    int ran_w;
    int w;
    
    float step;
    
    void erosion (ofImage & imgSrc, ofImage & imgDest, float step);
    void dilate (ofImage & imgSrc, ofImage & imgDest, float step);
    void subtract(ofImage & imgA, ofImage & imgB);
};
