#include "ofApp.h"

/*
 This code demonstrates the difference between using an ofMesh and an ofVboMesh.
 The ofMesh is uploaded to the GPU once per frame, while the ofVboMesh is
 uploaded once. This makes it much faster to draw multiple copies of an
 ofVboMesh than multiple copies of an ofMesh.
 */

/*
 These functions are for adding quads and triangles to an ofMesh -- either
 vertices, or texture coordinates.
 */
//--------------------------------------------------------------
void ofApp::addFace(ofMesh& mesh, const glm::vec3& a, const glm::vec3& b, const glm::vec3& c) {
    mesh.addVertex(a);
    mesh.addVertex(b);
    mesh.addVertex(c);
}

//--------------------------------------------------------------
void ofApp::addFace(ofMesh& mesh, const glm::vec3& a, const glm::vec3& b, const glm::vec3& c, const glm::vec3& d) {
    addFace(mesh, a, b, c);
    addFace(mesh, a, c, d);
}

//--------------------------------------------------------------
void ofApp::addTexCoords(ofMesh& mesh, const glm::vec2& a, const glm::vec2& b, const glm::vec2& c) {
    mesh.addTexCoord(a);
    mesh.addTexCoord(b);
    mesh.addTexCoord(c);
}

//--------------------------------------------------------------
void ofApp::addTexCoords(ofMesh& mesh, const glm::vec2& a, const glm::vec2& b, const glm::vec2& c, const glm::vec2& d) {
    addTexCoords(mesh, a, b, c);
    addTexCoords(mesh, a, c, d);
}

/*
 The 3d data is stored in an image where alpha represents depth. Here we create
 a 3d point from the current x,y image position.
 */
//--------------------------------------------------------------
glm::vec3 ofApp::getVertexFromImg(ofImage& img, int x, int y, float bounce_phase, int y_delta) {
    ofColor color = img.getColor(x, y);
    float bounce = ofMap(sin(ofGetElapsedTimef()+PI/4*bounce_phase), -1, 1, 0.2, 1.5);
    if(color.a > 0) {
//        float z = ofMap(color.a, 0, 255, -480, 480);
        float z = 0.08*y - (0.04*y)*(0.04*y) * bounce;
        return glm::vec3(x - img.getWidth() / 2, y - img.getHeight() / 2, z - y_delta);
    } else {
        return glm::vec3(0, 0, 0);
    }
}

//--------------------------------------------------------------
void ofApp::setup() {
    


    #ifdef TARGET_OPENGLES
    // While this will will work on normal OpenGL as well, it is
    // required for OpenGL ES because ARB textures are not supported.
    // If this IS set, then we conditionally normalize our
    // texture coordinates below.
    ofEnableNormalizedTexCoords();
    #endif
    
    

    img.load("petal_black_yellow.png");
    cropped_1.load("marble_cropped_1.png");
    cropped_2.load("marble_cropped_2.png");
    cropped_3.load("marble_cropped_3.png");
    cropped_4.load("marble_cropped_4.png");
    cropped_5.load("marble_cropped_5.png");
    
    
    images.push_back(cropped_1);
    images.push_back(cropped_2);
    images.push_back(cropped_3);
    images.push_back(cropped_4);
    images.push_back(cropped_5);
    
    // allocate fbos and images;
    
    mask_1.allocate(img.getWidth(), img.getHeight(), GL_RGBA);
    mask_2.allocate(img.getWidth(), img.getHeight(), GL_RGBA);
    mask_3.allocate(img.getWidth(), img.getHeight(), GL_RGBA);
    mask_4.allocate(img.getWidth(), img.getHeight(), GL_RGBA);
    mask_5.allocate(img.getWidth(), img.getHeight(), GL_RGBA);
    
    
    masks.push_back(mask_1);
    masks.push_back(mask_2);
    masks.push_back(mask_3);
    masks.push_back(mask_4);
    masks.push_back(mask_5);
    
    
    mesh_1.setMode(OF_PRIMITIVE_TRIANGLES);
    mesh_2.setMode(OF_PRIMITIVE_TRIANGLES);
    mesh_3.setMode(OF_PRIMITIVE_TRIANGLES);
    mesh_4.setMode(OF_PRIMITIVE_TRIANGLES);
    mesh_5.setMode(OF_PRIMITIVE_TRIANGLES);
    
    
    // append mesh to vector meshes
    meshes.push_back(mesh_1);
    meshes.push_back(mesh_2);
    meshes.push_back(mesh_3);
    meshes.push_back(mesh_4);
    meshes.push_back(mesh_5);
    
    
    
    
    // assign variables
    
    skip = 10; // this controls the resolution of the mesh
    n = 7; // make a 5x5 grid
    width = img.getWidth();
    height = img.getHeight();
    scale = 1;

    // OF_PRIMITIVE_TRIANGLES means every three vertices create a triangle
    
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    
    
    // create a vector of masked images
//    for (int k = 0; k < 5; k++) {
//        ofPath new_path;
//        new_path.ellipse(mask_1.getWidth()/2, mask_1.getHeight()/2, 100, 100 + 100*k);
//
//         // create fbo
//        masks[k].begin();
//        ofClear(0, 0, 0, 0);
//        ofSetColor(255);
//        new_path.draw();
//        masks[k].end();
//
//        images[k].getTexture().setAlphaMask(masks[k].getTexture());
//    }
    
}

//--------------------------------------------------------------
void ofApp::update() {

    

    vboMesh = mesh;

}

//--------------------------------------------------------------
void ofApp::draw() {
    
    
    ofBackground(0);
//    for (int k = 0; k < 5; k++) {
//        images[k].draw(k*100, 0);
//    }

//    ofBackgroundGradient(ofColor(64), ofColor(0));
    cam.begin();
    ofRotateXDeg(270);
    ofTranslate(0,200);
    ofDrawAxis(200);
    ofEnableDepthTest();


    ofSetColor(255);
//    ofRotateYDeg(ofGetElapsedTimef() * 30); // slowly rotate the model

    ofScale(1, -1, 1); // make y point down
    ofScale(.5, .5, .5); // make everything a bit smaller
    glm::vec2 spacing(img.getWidth(), img.getHeight()/3); // spacing between meshes
//    ofTranslate(-spacing.x * n / 2, -spacing.y * n / 2, 0); // center the grid
    glm::vec3 zero(0, 0, 0);
    
    glm::vec2 imageSize(width, height);
    
    ofPushMatrix();
    ofTranslate(150,50,0);
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofScale(0.3, 0.3, 0.3);
    
    for (int i = 0; i < 8; i++) {
        ofSetColor(255-i*10);
        ofTranslate(0,i*7,0);
        ofRotateXDeg(-i);
        ofScale(1+i*0.02, 1+i*0.04, 1+i*0.02);
        mesh.clearVertices();
        for (int y = 0; y < height - skip; y += skip) {
            for (int x = 0; x < width - skip; x += skip) {
                /*
                 To construct a mesh, we have to build a collection of quads made up of
                 the current pixel, the one to the right, to the bottom right, and
                 beneath. These are called nw, ne, se and sw. To get the texture coords
                 we need to use the actual image indices.
                 */
                glm::vec3 nw = getVertexFromImg(img, x, y, i*0.2, i*10);
                glm::vec3 ne = getVertexFromImg(img, x + skip, y, i*0.2, i*10);
                glm::vec3 sw = getVertexFromImg(img, x, y + skip, i*0.2, i*10);
                glm::vec3 se = getVertexFromImg(img, x + skip, y + skip, i*0.2, i*10);
                glm::vec2 nwi(x, y);
                glm::vec2 nei(x + skip, y);
                glm::vec2 swi(x, y + skip);
                glm::vec2 sei(x + skip, y + skip);

                // ignore any zero-data (where there is no depth info)
                if(nw != zero && ne != zero && sw != zero && se != zero) {
                    addFace(mesh, nw, ne, se, sw);

                    // Normalize our texture coordinates if normalized
                    // texture coordinates are currently enabled.
                    if(ofGetUsingNormalizedTexCoords()) {
                        nwi /= imageSize;
                        nei /= imageSize;
                        sei /= imageSize;
                        swi /= imageSize;
                    }

                    addTexCoords(mesh, nwi, nei, sei, swi);
                }
            }
        }
        ofTranslate(0,0,-15);
        
        img.bind();
        
        if(ofGetKeyPressed()) {
            vboMesh.draw(); // draw a vboMesh (faster) when a key is pressed
        } else {
            mesh.draw(); // draw an ofMesh (slower) when no key is pressed
        }
        
        img.unbind();
        
    }
    
    ofPopMatrix();
    
    
    ofPushMatrix();
//    ofRotateXDeg(120);
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_SCREEN);
    ofScale(0.3, 0.3, 0.3);
    ofRotateZDeg(90);
//    ofTranslate(0,300,0);
    for (int i = 0; i < 8; i++) {
        ofSetColor(255-i*10);
        ofTranslate(0,i*7,0);
        ofRotateXDeg(-i);
        ofScale(1+i*0.02, 1+i*0.04, 1+i*0.02);
        mesh.clearVertices();
        for (int y = 0; y < height - skip; y += skip) {
            for (int x = 0; x < width - skip; x += skip) {
                /*
                 To construct a mesh, we have to build a collection of quads made up of
                 the current pixel, the one to the right, to the bottom right, and
                 beneath. These are called nw, ne, se and sw. To get the texture coords
                 we need to use the actual image indices.
                 */
                glm::vec3 nw = getVertexFromImg(img, x, y, i*0.2, i*10);
                glm::vec3 ne = getVertexFromImg(img, x + skip, y, i*0.2, i*10);
                glm::vec3 sw = getVertexFromImg(img, x, y + skip, i*0.2, i*10);
                glm::vec3 se = getVertexFromImg(img, x + skip, y + skip, i*0.2, i*10);
                glm::vec2 nwi(x, y);
                glm::vec2 nei(x + skip, y);
                glm::vec2 swi(x, y + skip);
                glm::vec2 sei(x + skip, y + skip);

                // ignore any zero-data (where there is no depth info)
                if(nw != zero && ne != zero && sw != zero && se != zero) {
                    addFace(mesh, nw, ne, se, sw);

                    // Normalize our texture coordinates if normalized
                    // texture coordinates are currently enabled.
                    if(ofGetUsingNormalizedTexCoords()) {
                        nwi /= imageSize;
                        nei /= imageSize;
                        sei /= imageSize;
                        swi /= imageSize;
                    }

                    addTexCoords(mesh, nwi, nei, sei, swi);
                }
            }
        }
        ofTranslate(0,0,-15);
        
        img.bind();
        
        if(ofGetKeyPressed()) {
            vboMesh.draw(); // draw a vboMesh (faster) when a key is pressed
        } else {
            mesh.draw(); // draw an ofMesh (slower) when no key is pressed
        }
        
        img.unbind();
        
    }
    ofPopMatrix();




    ofDisableDepthTest();
    cam.end();

    // draw the framerate in the top left corner
    ofDrawBitmapString(ofToString((int) ofGetFrameRate()) + " fps", 10, 20);
    ofDrawBitmapString("Hold any key for ofVboMesh mode.", 10, 40);
    string mode = (ofGetKeyPressed() ? "ofVboMesh" : "ofMesh");
    ofDrawBitmapString("Current mode: " + mode, 10, 60);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == ' ') {
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
