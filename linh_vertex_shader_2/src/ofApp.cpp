#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    shader.load("shader.vert", "shader.frag");
    height = ofGetHeight();
    width = ofGetWidth();

    int planeWidth = width;
    int planeHeight = height;
//    int planeGridSize = 200;
    int planeColums = 100;
    int planeRows = 100;
    
    plane.set(planeWidth, planeHeight, planeColums, planeRows, OF_PRIMITIVE_POINTS);
    
    mesh = plane.getMesh();
    
//    mesh.setMode(OF_PRIMITIVE_POINTS);
    for (int i = 0; i < mesh.getVertices().size(); i++) {
//        mesh.addColor(ofFloatColor(
//                                   0.5 + 0.25*sin(ofGetElapsedTimef() + i*0.04),
//                                   0.5 + 0.25*sin(ofGetElapsedTimef() + i*0.06),
//                                   0.5 + 0.25*sin(ofGetElapsedTimef() + i*0.012)));
        vertices.push_back(mesh.getVertices()[i]);
        
    }
//    for (int y = 0; y < height; y+=100){
//        for (int x = 0; x < width; x+=100){
//            mesh_2.addVertex(ofPoint(x,y,0)); // make a new vertex
//            mesh_2.addColor(ofFloatColor(ofRandom(1.),ofRandom(1.),ofRandom(1.)));  // add a color at that vertex
//        }
//    }
//    for (int i = 0; i < vertices.size(); i++) {
//        mesh_2.addVertex(vertices[i]);
//        mesh_2.addColor(ofFloatColor(ofRandom(1.),ofRandom(1.),ofRandom(1.)));
//    }
//
//    for (int y = 0; y<height-1; y+=10){
//        for (int x=0; x<width-1; x+=10){
//            mesh_2.addIndex(x+y*width);               // 0
//            mesh_2.addIndex((x+1)+y*width);           // 1
//            mesh_2.addIndex(x+(y+1)*width);           // 10
//
//            mesh_2.addIndex((x+1)+y*width);           // 1
//            mesh_2.addIndex((x+1)+(y+1)*width);       // 11
//            mesh_2.addIndex(x+(y+1)*width);           // 10
//        }
//    }
    
    img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (ofGetFrameNum() % 60) shader.load("shader.vert","shader.frag");

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    shader.begin();
    
    // center screen.
    float cx = ofGetWidth() / 2.0;
    float cy = ofGetHeight() / 2.0;
    
    
    cout << vertices.size() << endl;
//
    
    // set shader uniforms
    
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform2f("screenSize", ofGetWidth(), ofGetHeight());
    
    ofTranslate(cx, cy);
    
    cam.begin();
    ofEnableDepthTest();
//    ofBeginShape();
//    ofEndShape();
//    mesh.draw();
    mesh.draw();
    cam.end();
    
    shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        img.save("screenshot/" + ofGetTimestampString() + ".png");
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
