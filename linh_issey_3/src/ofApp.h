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
        
    vector < ofPolyline > circles;
    vector < ofPolyline > circles_arm;
    vector < ofPolyline > circles_arm_right;
    vector < ofColor > colors;
    
    ofImage screenshot;
    
    ofEasyCam cam;
    
    ofColor color;
    
    float stretch;
    float expand;
    
    ofColor black;
    ofColor blue;
    ofColor orange;
    ofColor red;
    ofColor green;
    ofColor purple;
    ofColor brown;
    ofColor yellow;
    
    
};
