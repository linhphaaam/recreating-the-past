#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {
    public:
        void setup();
        void update();
        void draw();
        
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);

        // helper functions
        void addFace(ofMesh& mesh, const glm::vec3& a, const glm::vec3& b, const glm::vec3& c);
        void addFace(ofMesh& mesh, const glm::vec3& a, const glm::vec3& b, const glm::vec3& c, const glm::vec3& d);
        void addTexCoords(ofMesh& mesh, const glm::vec2& a, const glm::vec2& b, const glm::vec2& c);
        void addTexCoords(ofMesh& mesh, const glm::vec2& a, const glm::vec2& b, const glm::vec2& c, const glm::vec2& d);
        glm::vec3 getVertexFromImg(ofImage& img, int x, int y, float bounce_phase, int y_delta);
        
        ofEasyCam cam;
        ofMesh mesh;
    
        ofMesh mesh_1;
        ofMesh mesh_2;
        ofMesh mesh_3;
        ofMesh mesh_4;
        ofMesh mesh_5;
    
    
    
        ofVboMesh vboMesh;
        ofImage img;
    
        ofFbo mask_1;
        ofFbo mask_2;
        ofFbo mask_3;
        ofFbo mask_4;
        ofFbo mask_5;
    
        ofImage cropped_1;
        ofImage cropped_2;
        ofImage cropped_3;
        ofImage cropped_4;
        ofImage cropped_5;
    
    ofPath path;
    
    vector < ofImage > images;
    vector < ofFbo > masks;
    vector < ofMesh > meshes;
    
        int width;
        int height;
        int skip;
        int n;
    
    float scale;
    
    ofLight spotLight;
    int mouseZ;
    
    
};
