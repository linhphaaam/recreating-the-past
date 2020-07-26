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
        
    
    ofEasyCam cam;

    ofImage screenshot;
    ofImage maskImg;
    
    ofMesh mesh;
    ofMesh mesh_from_poly;
    ofPath path;
    ofPolyline polyline;
    
    ofTexture texture;
    
    ofPoint bound_coords;
    ofPoint top_left;
    ofPoint top_right;
    ofPoint bottom_left;
    ofPoint bottom_right;
    
    int x1;
    int x2;
    int y1;
    int y2;
    
    void getMeshBoundingBoxDimension(const ofMesh &mesh);
    
    float bounce;
    
    ofRectangle bounds;
    ofTessellator tess;
};
