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

    
    ofImage img;
    ofImage img_left;
    
    ofImage back_img;
    ofImage back_img_2;
    ofImage back_img_left;
    ofImage back_img_left_2;
    
    ofImage slit_img;
    ofImage slit_img_left;
    ofImage screenshot;
    
    ofFbo slit;
    ofFbo slit_left;
    ofFbo back_fbo;
    ofFbo back_fbo_left;
    
    ofPixels pixels;
    ofPixels pixels_left;
    
    ofPixels pixels_back;
    ofPixels pixels_back_left;
    
    float slit_location;
    float frame_location;
    
    float ww;
    float hh;
    
        
};
