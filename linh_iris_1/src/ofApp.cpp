#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    screenshot.allocate(ofGetWidth(),ofGetHeight(), OF_IMAGE_COLOR);
    for (int i = 0; i < 15; i++){
        
        ofPath ellipse;
        ellipse.setCircleResolution(100);
        ellipse.ellipse(0, (i*40/2), 30+5*i, i*40);
        ellipses.push_back(ellipse);
        
        ofPolyline outline;
        outline = ellipse.getOutline()[0];
        outline.close();
        outlines.push_back(outline);
        
    }
    
    ofEnableDepthTest();
    ofDisableArbTex();
    maskImg.allocate(1080, 719, OF_IMAGE_COLOR);
    maskImg.load("psychedelic.png");
    ofLoadImage(tex,"psychedelic.png");
    


}

//--------------------------------------------------------------
void ofApp::update(){
    
//    path.ellipse(0,150,0,100,300);
//    outline = path.getOutline()[0];
    

    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    ofBackground(0);
    ofTranslate(0, 200);
    ofRotateZDeg(180);
    ofFill();
    ofDrawAxis(200);
    

    
//    ofPushMatrix();
//    ofRotateXDeg(60);
//    ofScale(0.4, 0.4, 0.4);
//    for (int i = 0; i < 16; i++){
//        bounce = sin(ofGetElapsedTimef()*2 + PI/8*(i-9));
//        ofMesh theMesh;
////        theMesh.setMode(OF_PRIMITIVE_LINE_LOOP);
//        ofTessellator tess;
//        theMesh.enableColors();
//        for (int j = 0; j < outlines[i].size(); j++){
//            outlines[i][j].z = sqrt(outlines[i][j].y)*(30-2*i-bounce);
////            theMesh.addVertex(ofVec3f( outlines[i][j].x, outlines[i][j].y, outlines[i][j].z));
////            theMesh.addColor(ofFloatColor(255, 0, 0));
//        }
//        tess.tessellateToMesh(outlines[i], ofPolyWindingMode::OF_POLY_WINDING_ODD, theMesh, false);
////        outlines[i].draw();
//        theMesh.draw();
//
//    }
//    ofPopMatrix();

    
    
    //side skirt – right

    ofPushMatrix();
    ofTranslate(-30,0,30);
    ofRotateYDeg(20);
    for (int t = 0; t < 10; t++) {
        ofColor petal;
        petal.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 150, 255-t*25);
        ofColor petal_outline;
        petal_outline.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 255, 255-t*25);
        ofPushMatrix();
        ofRotateXDeg(-t*5);
        ofScale(1+t*0.1,1+t*0.7,1+t*0.4);

        ofMesh theMesh;
//        theMesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
//        theMesh.clear();
//        theMesh.enableColors();
        for (int i = 0; i < 2; i++){
            bounce = sin(ofGetElapsedTimef()*2 + PI/4*t);

            ofTessellator tess;

            for (int j = 0; j < outlines[i].size(); j++){
                outlines[i][j].z = sqrt(outlines[i][j].y)*(30-2*t-bounce);
//                theMesh.addVertex(outlines[i].getVertices()[j]);
//                theMesh.getVertices()[j] = outlines[i].getVertices()[j];
//                theMesh.clearTexCoords();
//                theMesh.addTexCoord(tex.getCoordFromPercent(0,0));
//                theMesh.addTexCoord(tex.getCoordFromPercent(1,0));
            }
//            theMesh = ofMesh::plane(maskImg.getWidth()/5, maskImg.getHeight()/5);

            ofSetColor(petal_outline);
            tess.tessellateToMesh(outlines[i], ofPolyWindingMode::OF_POLY_WINDING_ODD, theMesh, false);
            outlines[i].draw();
            ofSetColor(petal);

//            theMesh.addVertex(outlines[i].getPointAtPercent(.2));
//            theMesh.addVertex(outlines[i].getPointAtPercent(.8));
//            theMesh.addVertex(outlines[i].getPointAtPercent(.45));
//            theMesh.addVertex(outlines[i].getPointAtPercent(.55));
////
//            theMesh.addTexCoord(tex.getCoordFromPercent(0,1));
//            theMesh.addTexCoord(tex.getCoordFromPercent(1,1));

//            tex.bind();
            theMesh.draw();
//            tex.unbind();
        }
        ofPopMatrix();
    }
    ofPopMatrix();
    
    // side skirt – left
    ofPushMatrix();
    ofTranslate(30,0,-30);
    ofRotateYDeg(70);
    for (int t = 0; t < 10; t++) {
        ofColor petal;
        petal.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 150, 255-t*25);
        ofColor petal_outline;
        petal_outline.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 255, 255-t*25);
        ofPushMatrix();
        ofRotateXDeg(-t*5);
        ofScale(1+t*0.1,1+t*0.7,1+t*0.4);
        for (int i = 0; i < 2; i++){
            bounce = sin(ofGetElapsedTimef()*2 + PI/4*t);
            ofMesh theMesh;

            ofTessellator tess;
            theMesh.enableColors();
            for (int j = 0; j < outlines[i].size(); j++){
                outlines[i][j].z = sqrt(outlines[i][j].y)*(30-2*t-bounce);

            }
            tess.tessellateToMesh(outlines[i], ofPolyWindingMode::OF_POLY_WINDING_ODD, theMesh, false);
            ofSetColor(petal_outline);
            outlines[i].draw();
            ofSetColor(petal);
            theMesh.draw();
        }
        ofPopMatrix();
    }
    ofPopMatrix();
    
    // bodice - right
    
    ofPushMatrix();
    ofTranslate(20,0,20);
    ofRotateYDeg(20);
    ofRotateXDeg(60);
    ofScale(0.5,0.5,0.5);
    for (int t = 0; t < 10; t++) {
        ofColor petal;
        petal.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 150, 255-t*20);
        ofColor petal_outline;
        petal_outline.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 255, 255-t*20);
//        ofSetColor(petal);
        ofPushMatrix();
        ofRotateXDeg(-t*5);
        ofScale(1+t*0.3,1+t*0.7,1+t*0.4);
        for (int i = 0; i < 2; i++){
            bounce = sin(ofGetElapsedTimef()*2 + PI/4*t);
            ofMesh theMesh;

            ofTessellator tess;
            theMesh.enableColors();
            for (int j = 0; j < outlines[i].size(); j++){
                outlines[i][j].z = sqrt(outlines[i][j].y)*(25-2*t-bounce);

            }
            tess.tessellateToMesh(outlines[i], ofPolyWindingMode::OF_POLY_WINDING_ODD, theMesh, false);
            ofSetColor(petal_outline);
            outlines[i].draw();
            ofSetColor(petal);
            theMesh.draw();
        }
        ofPopMatrix();
    }
    ofPopMatrix();
    
    // bodice - left
    
    ofPushMatrix();
    ofTranslate(20,0,20);
    ofRotateYDeg(70);
    ofRotateXDeg(60);
    ofScale(0.5,0.5,0.5);
    for (int t = 0; t < 10; t++) {
        ofColor petal;
        petal.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 150, 255-t*15);
        ofColor petal_outline;
        petal_outline.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 255, 255-t*15);
//        ofSetColor(petal);
        ofPushMatrix();
        ofRotateXDeg(-t*5);
        ofScale(1+t*0.3,1+t*0.7,1+t*0.4);
        for (int i = 0; i < 2; i++){
            bounce = sin(ofGetElapsedTimef()*2 + PI/4*t);
            ofMesh theMesh;

            ofTessellator tess;
            theMesh.enableColors();
            for (int j = 0; j < outlines[i].size(); j++){
                outlines[i][j].z = sqrt(outlines[i][j].y)*(25-2*t-bounce);

            }
            tess.tessellateToMesh(outlines[i], ofPolyWindingMode::OF_POLY_WINDING_ODD, theMesh, false);
            ofSetColor(petal_outline);
            outlines[i].draw();
            ofSetColor(petal);
            theMesh.draw();
        }
        ofPopMatrix();
    }
    ofPopMatrix();
    
    // shoulder - right
    
    ofPushMatrix();
    ofTranslate(-50, -50,50);
    ofRotateYDeg(-30);
    ofRotateXDeg(55);
    ofRotateZDeg(55);
    ofScale(0.4,0.4,0.4);
    for (int t = 0; t < 10; t++) {
        ofColor petal;
        petal.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 150, 255-t*25);
        ofColor petal_outline;
        petal_outline.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 255, 255-t*15);
//        ofSetColor(petal);
        ofPushMatrix();
        ofRotateXDeg(-t*5);
        ofScale(1+t*0.3,1+t*0.5,1+t*0.2);
        for (int i = 0; i < 2; i++){
            bounce = sin(ofGetElapsedTimef()*2 + PI/4*t);
            ofMesh theMesh;

            ofTessellator tess;
            theMesh.enableColors();
            for (int j = 0; j < outlines[i].size(); j++){
                outlines[i][j].z = sqrt(outlines[i][j].y)*(30-2*t-bounce);

            }
            tess.tessellateToMesh(outlines[i], ofPolyWindingMode::OF_POLY_WINDING_ODD, theMesh, false);
            ofSetColor(petal_outline);
            outlines[i].draw();
            ofSetColor(petal);
            theMesh.draw();
        }
        ofPopMatrix();
    }
    ofPopMatrix();
    
    // shoulder - left
    
    ofPushMatrix();
    ofTranslate(50, -50, -50);
    ofRotateYDeg(120);
    ofRotateXDeg(55);
    ofRotateZDeg(-55);
    ofScale(0.4,0.4,0.4);
    for (int t = 0; t < 10; t++) {
        ofColor petal;
        petal.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 150, 255-t*25);
        ofColor petal_outline;
        petal_outline.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 255, 255-t*15);
//        ofSetColor(petal);
        ofPushMatrix();
        ofRotateXDeg(-t*5);
        ofScale(1+t*0.3,1+t*0.5,1+t*0.2);
        for (int i = 0; i < 2; i++){
            bounce = sin(ofGetElapsedTimef()*2 + PI/4*t);
            ofMesh theMesh;

            ofTessellator tess;
            theMesh.enableColors();
            for (int j = 0; j < outlines[i].size(); j++){
                outlines[i][j].z = sqrt(outlines[i][j].y)*(30-2*t-bounce);

            }
            tess.tessellateToMesh(outlines[i], ofPolyWindingMode::OF_POLY_WINDING_ODD, theMesh, false);
            ofSetColor(petal_outline);
            outlines[i].draw();
            ofSetColor(petal);
            theMesh.draw();
        }
        ofPopMatrix();
    }
    ofPopMatrix();
    
    // chest - right
    
    ofPushMatrix();
    ofTranslate(-20, 0, 20);
    ofRotateYDeg(200);
    ofRotateXDeg(-200);
//    ofRotateZDeg(40);
    ofScale(0.4,0.4,0.4);
    for (int t = 4; t < 9; t++) {
        ofColor petal;
        petal.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 150, 255-(t-3)*25);
        ofColor petal_outline;
        petal_outline.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 255, 255-(t-3)*15);
//        ofSetColor(petal);
        ofPushMatrix();
        ofRotateXDeg(-t*5);
        ofScale(1+t*0.7,1+t*0.1,1+t*0.1);
        for (int i = 0; i < 2; i++){
            bounce = sin(ofGetElapsedTimef()*2 + PI/4*t);
            ofMesh theMesh;

            ofTessellator tess;
            theMesh.enableColors();
            for (int j = 0; j < outlines[i].size(); j++){
                outlines[i][j].z = sqrt(outlines[i][j].y)*(30-t-bounce);

            }
            tess.tessellateToMesh(outlines[i], ofPolyWindingMode::OF_POLY_WINDING_ODD, theMesh, false);
            ofSetColor(petal_outline);
            outlines[i].draw();
            ofSetColor(petal);
            theMesh.draw();
        }
        ofPopMatrix();
    }
    ofPopMatrix();
    
    // chest - left
    
    ofPushMatrix();
    ofTranslate(20, 0, -20);
    ofRotateYDeg(250);
    ofRotateXDeg(-200);
//    ofRotateZDeg(100);
    ofScale(0.4,0.4,0.4);
    for (int t = 4; t < 9; t++) {
        ofColor petal;
        petal.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 150, 255-(t-3)*25);
        ofColor petal_outline;
        petal_outline.setHsb(ofMap(sin(ofGetElapsedTimef()*0.1), -1, 1, 0, 255), 255, 255-(t-3)*15);
//        ofSetColor(petal);
        ofPushMatrix();
        ofRotateXDeg(-t*5);
        ofScale(1+t*0.7,1+t*0.1,1+t*0.1);
        for (int i = 0; i < 2; i++){
            bounce = sin(ofGetElapsedTimef()*2 + PI/4*t);
            ofMesh theMesh;

            ofTessellator tess;
            theMesh.enableColors();
            for (int j = 0; j < outlines[i].size(); j++){
                outlines[i][j].z = sqrt(outlines[i][j].y)*(30-t-bounce);

            }
            tess.tessellateToMesh(outlines[i], ofPolyWindingMode::OF_POLY_WINDING_ODD, theMesh, false);
            ofSetColor(petal_outline);
            outlines[i].draw();
            ofSetColor(petal);
            theMesh.draw();
        }
        ofPopMatrix();
    }
    ofPopMatrix();

    
//    for (int i = 0; i < outlines.size(); i++){
//        ofPushMatrix();
//        ofRotateYDeg(90);
//        bounce = sin(ofGetElapsedTimef()*2 + PI/4*i);
//        for (int j = 0; j < outlines[i].size(); j++){
//            outlines[i][j].z = sqrt(outlines[i][j].y)*(30-2*i-bounce);
//        }
//        outlines[i].draw();
//        ofPopMatrix();
//    }
    
         // ofMesh
//    theMesh.setMode(OF_PRIMITIVE_POINTS);
    //            theMesh.addVertex(outlines[i][j]);
//        theMesh.draw();
//        cout << theMesh.getNumVertices() << endl;
        
        // openGL
//        ofSetColor(255-20*i);
//        ofBeginShape();
//            for( int k = 0; k < outlines[i].getVertices().size(); k++) {
//                ofVertex(outlines[i].getVertices().at(k).x, outlines[i].getVertices().at(k).y, outlines[i].getVertices().at(k).z);
//            }
//        ofEndShape();
        
        //ofPath
        
//        ofPath path;
//        for( int k = 0; k < outlines[i].getVertices().size(); k++) {
//            if (k == 0) {
//                path.newSubPath();
//                path.moveTo(outlines[i].getVertices()[k] );
//            } else {
//                path.lineTo( outlines[i].getVertices()[k] );
//            }
//        }
////
////
//////
//        path.close();
//        path.simplify();
//
//        path.setColor(255-i*20);
//        path.draw();


//        ofMesh theMesh;
//        ofTessellator tess;
//        theMesh.setMode(OF_PRIMITIVE_POINTS);
    

        // **** convert poly to mesh ****
//        tess.tessellateToMesh(outlines[i], ofPolyWindingMode::OF_POLY_WINDING_ODD, theMesh, false);
//
//        theMesh.draw();
//        theMesh.drawVertices();
//    }
    
    
    
//    ofPath path;
//
//    for (int i = 0; i < outlines.size(); i++) {
//        for (int j = 0; j < outlines[i].getVertices().size(); j++) {
//          if (j == 0) {
//              path.newSubPath();
//              path.moveTo(outlines[i].getVertices()[j] );
//          } else {
//              path.lineTo(outlines[i].getVertices()[j] );
//          }
//        }
//    }
//
//    path.close();
//    path.simplify();
//
//    path.draw();
    
//    for (int i = 0; i < outline.size(); i++){
//        outline[i].z = sqrt(outline[i].y)*10;
//    }
//    outline.draw();
    
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        screenshot.save("screenshot/" + ofGetTimestampString() + ".png");
    }
    
//    if (key == 'm') {
//        mode++;
//        if( mode > 4 ) mode = 0;
//
//        path.setPolyWindingMode((ofPolyWindingMode) mode);
//    }

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
