#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void cream_vertical();
        void black_vertical();
        void black_horizontal();
        void light_cream_vertical();

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
    
    ofFbo fbo;
    ofFbo mask;
    ofFbo background;
    ofColor light_cream;
    ofColor cream;
    
    ofPath path;
    ofImage img;
//
//    int random_num_x[20] = {};
//    int random_num_y[20] = {};
    vector<int> ry;
    vector<int> rx;
    
		
};
