#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    shader.load("shader.vert", "shader.frag");

    int planeWidth = ofGetWidth();
    int planeHeight = ofGetHeight();
    int planeGridSize = 20;
    int planeColums = planeWidth / planeGridSize;
    int planeRows = planeHeight / planeGridSize;
    
    plane.set(planeWidth, planeHeight, planeColums, planeRows, OF_PRIMITIVE_TRIANGLES);
    
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
    
    // the plane is being position in the middle of the screen,
    // so we have to apply the same offset to the mouse coordinates before passing into the shader.
    float mx = mouseX - cx;
    float my = mouseY - cy;
    
    // we can pass in a single value into the shader by using the setUniform1 function.
    // if you want to pass in a float value, use setUniform1f.
    // if you want to pass in a integer value, use setUniform1i.
    shader.setUniform1f("mouseRange", 250);
    shader.setUniform1f("time", ofGetElapsedTimef());
    
    mesh = plane.getMesh();
//    for (int i = 0; i < mesh.getVertices().size(); i++) {
//        mesh.getVertices()[i].z = mesh.getVertices()[i].z + 5*sin(0.5*ofGetElapsedTimef() + mesh.getVertices()[i].x*mesh.getVertices()[i].y*0.01);
//    }
//    
    // we can pass in two values into the shader at the same time by using the setUniform2 function.
    // inside the shader these two values are set inside a vec2 object.
    shader.setUniform2f("mousePos", mx, my);
    
    // color changes from magenta to blue when moving the mouse from left to right.
    float percentX = mouseX / (float)ofGetWidth();
    percentX = ofClamp(percentX, 0, 1);
    ofFloatColor colorLeft = ofColor::magenta;
    ofFloatColor colorRight = ofColor::blue;
    ofFloatColor colorMix = colorLeft.getLerped(colorRight, percentX);
    
    // create a float array with the color values.
    float mouseColor[4] = {colorMix.r, colorMix.g, colorMix.b, colorMix.a};
    
    // we can pass in four values into the shader at the same time as a float array.
    // we do this by passing a pointer reference to the first element in the array.
    // inside the shader these four values are set inside a vec4 object.
    shader.setUniform4fv("mouseColor", mouseColor);
    shader.setUniform2f("screenSize", ofGetWidth(), ofGetHeight());
    
    ofTranslate(cx, cy);
    
    cam.begin();
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
