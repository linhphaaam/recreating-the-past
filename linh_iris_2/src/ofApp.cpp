#include "ofApp.h"

void ofApp::getMeshBoundingBoxDimension(const ofMesh &mesh) {
    
    auto xExtremes = minmax_element(mesh.getVertices().begin(), mesh.getVertices().end(),
                                         [](const ofPoint& lhs, const ofPoint& rhs) {
                                             return lhs.x < rhs.x;
                                         });
    auto yExtremes = minmax_element(mesh.getVertices().begin(), mesh.getVertices().end(),
                                         [](const ofPoint& lhs, const ofPoint& rhs) {
                                             return lhs.y < rhs.y;
                                         });
    auto zExtremes = minmax_element(mesh.getVertices().begin(), mesh.getVertices().end(),
                                         [](const ofPoint& lhs, const ofPoint& rhs) {
                                             return lhs.z < rhs.z;
                                         });
    return ofVec3f(xExtremes.second->x - xExtremes.first->x,
                   yExtremes.second->y - yExtremes.first->y,
                   zExtremes.second->z - zExtremes.first->z);
}


//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest();
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    screenshot.allocate(ofGetWidth(),ofGetHeight(), OF_IMAGE_COLOR);
    path.ellipse(300, 300, 100, 500);
    mesh = path.getTessellation();
    polyline = path.getOutline()[0];
    

    
    ofDisableArbTex();
    maskImg.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    maskImg.load("psychedelic.png");
    ofPixels pixels = maskImg.getPixels();
    texture.loadData(pixels);
    
    top_left = ofPoint(250, 50);
    top_right = ofPoint(350, 50);
    bottom_left = ofPoint(250, 550);
    bottom_right = ofPoint(350, 550);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
//    bounce = sin(ofGetElapsedTimef()*2 + PI/4);
//    for (int j = 0; j < polyline.size(); j++){
////        polyline[j].z = sqrt(polyline[j].y)*(30-bounce);
////       polyline[j].x++;
//
//    }
        
    bounds = polyline.getBoundingBox();
    x1 = bounds.getMinX();
    y1 = bounds.getMinY();
    x2 = bounds.getMaxX();
    y2 = bounds.getMaxY();
    
    cout << x1 << endl;
    cout << x2 << endl;
    cout << y1 << endl;
    cout << y2 << endl;
//
//    mesh.clearVertices();
//    mesh.clearTexCoords();
//    mesh.clearIndices();

    mesh.addVertex(top_left);
    mesh.addVertex(top_right);
    mesh.addVertex(bottom_left);
    mesh.addVertex(bottom_right);
//
    mesh.addIndex(0);
    mesh.addIndex(1);
    mesh.addIndex(2);
    mesh.addIndex(3);
//
    mesh.addTexCoord(texture.getCoordFromPercent(0,0));
    mesh.addTexCoord(texture.getCoordFromPercent(1,0));
    mesh.addTexCoord(texture.getCoordFromPercent(0,1));
    mesh.addTexCoord(texture.getCoordFromPercent(1,1));
    
//    for (int i = mesh_from_poly.getNumVertices()-4; i < mesh_from_poly.getNumVertices(); i++){
//
//        mesh_from_poly.clearVertex(i);
//
//    }
    
//    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
//    mesh_from_poly.clearVertices();
//    tess.tessellateToMesh(polyline, ofPolyWindingMode::OF_POLY_WINDING_ODD, mesh_from_poly, false);
//
//    mesh_from_poly.addVertex(ofPoint(x1, y1));
//    mesh_from_poly.addVertex(ofPoint(x1, y2));
//    mesh_from_poly.addVertex(ofPoint(x1, y2));
//    mesh_from_poly.addVertex(ofPoint(x2, y2));
//
//    mesh_from_poly.addIndex(0);
//    mesh_from_poly.addIndex(1);
//    mesh_from_poly.addIndex(2);
//    mesh_from_poly.addIndex(1);
//    mesh_from_poly.addIndex(2);
//    mesh_from_poly.addIndex(3);
//
//    mesh_from_poly.addTexCoord(texture.getCoordFromPercent(0,0));
//    mesh_from_poly.addTexCoord(texture.getCoordFromPercent(1,0));
//    mesh_from_poly.addTexCoord(texture.getCoordFromPercent(0,1));
//    mesh_from_poly.addTexCoord(texture.getCoordFromPercent(1,1));
    
//    for (int i = 0; i < 10; i++){
//        mesh.setVertex(i, mesh.getVertex(i) + ofVec3f(0,0,sin(ofGetElapsedTimef()*0.5)));
//    }
//


}

//--------------------------------------------------------------
void ofApp::draw(){
//    maskImg.draw(0,0);

    cam.begin();
    ofSetColor(155);
    ofTranslate(-300,-300);
    ofDrawAxis(200);
//    ofDrawRectangle(x1,y1,(x2-x1), (y2-y1));
    ofSetColor(255);
    polyline.draw();
    texture.bind();

    mesh.draw();
//    mesh_from_poly.draw();
    texture.unbind();
    ofSetColor(255,0,0);
//    mesh_from_poly.drawVertices();
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        screenshot.save("screenshot/" + ofGetTimestampString() + ".png");
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
