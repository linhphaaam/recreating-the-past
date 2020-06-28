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
    
    void weave_color(ofColor color_1, ofColor color_2, float i, int j, int modulo, int weave_freq, int weave_amp, float value_i);
    
    ofColor red;
    ofColor yellow;
    ofColor green;
    ofColor purple;
    ofColor cream;
    
    ofImage img;
    
    int z;
		
};
