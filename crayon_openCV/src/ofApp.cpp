#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    grabber.listDevices();
    grabber.setDeviceID(4);
    grabber.initGrabber(640, 480);
    
    camGray.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
    thresImg.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_GRAYSCALE);
    
    shader.load("", "shader.frag");
    rock.load("rock.jpg");
    fbo.allocate(thresImg.getWidth()*2, thresImg.getHeight()*2);
    
    ofSetFrameRate(10);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (ofGetFrameNum() % 60) shader.load("","shader.frag");
    
    grabber.update();
    if (grabber.isFrameNew()) {
        convertColor(grabber, camGray, CV_RGB2GRAY);
        camGray.update();
        
        for (int i = 0; i < grabber.getWidth(); i++) {
            for (int j = 0; j < grabber.getHeight(); j++) {
                ofColor color = grabber.getPixels().getColor(i, j);
                if (color.getBrightness() > mouseX/10) {
                    thresImg.setColor(i, j, ofColor(0));
                } else {
                    thresImg.setColor(i, j, ofColor(255));
                }
            }
        }
        
        
//        thresImg.setFromPixels(camGray.getPixels());
//        threshold(thresImg, mouseX/10);
        thresImg.update();
        finder.findContours(thresImg);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
//    grabber.draw(0,0);
    ofBackground(255);
//    thresImg.draw(grabber.getWidth(), 0);
    
    ofSetColor(255);
    
//    finder.draw();
    fbo.begin();
    ofClear(255, 255, 255, 255);
    ofSetColor(242, 238, 230);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    
//    ofSetColor(255, 232, 0);

//    for (int i = 0; i < thresImg.getWidth(); i+=10) {
//        for (int j = 0; j < thresImg.getHeight(); j+=10) {
////            cout << i << " " << j << endl;
//            if (thresImg.getColor(i, j).getBrightness() > 100) {
//                ofPushMatrix();
//                ofDrawCircle(-i*2 + 1280, j*2, 10);
//                ofPopMatrix();
//            }
//        }
//    }
    //thresImg.draw(thresImg.getWidth()*2, 0, -thresImg.getWidth()*2, thresImg.getHeight()*2);
    
//    thresImg.getColor(i,j).getBrightness();
    
    int gap = 20;
    
    vector <ofPoint> within;
    ofPolyline within_line;
    within.clear();
    within_line.clear();
    for (int x = 0; x < thresImg.getWidth(); x+= 1) {
        for (int y = 0; y < thresImg.getHeight(); y+= 1) {
            if (thresImg.getColor(x, y).getBrightness() > 100) {
                if (ofRandomf() > .985) {
                    within.push_back(ofPoint(x, y));
                }
            }
        }
    }
//
//    random_shuffle(within.begin(), within.end());
//    ofPushMatrix();
//    ofTranslate(1280,0);
//    ofScale(-2,2);
//    ofSetColor(0, 157, 165);
//    for (int i = 0; i < within.size(); i++) {
//        for (int n = 0; n < within.size(); n++) {
//            float distance = (within[n] - within[i]).length();
//            if (distance < 30) {
//                ofSetColor(0, 157, 165);
//                ofDrawLine(within[n], within[i]);
////                break;
//            }
//        }
//    }
//
//    ofPopMatrix();
    int counter_limit = 10;
    
    if (finder.size() > 0){
        for (int k = 0; k < finder.size(); k++) {
            ofPolyline original = finder.getPolyline(k);
            ofPolyline line_0;
            ofPolyline line_1;
            ofPolyline line_2;
            ofPolyline line_3;
            ofPolyline line_4;
            ofPolyline line_5;
            ofPolyline line_6;

            vector <ofPoint> points_0;
            vector <ofPoint> points_1;
            vector <ofPoint> points_2;
            vector <ofPoint> points_3;
            vector <ofPoint> points_4;
            vector <ofPoint> points_5;
            vector <ofPoint> points_6;
            
            
//            cout << original.getBoundingBox() << endl;

            // full body
            
//            points_0.clear();

            for (int j = 0; j < original.size(); j+= 2) {
                points_0.push_back(original[j]);
            }
            
            
            random_shuffle(points_0.begin(), points_0.end());
            ofPushMatrix();
            ofTranslate(1280,0);
            ofScale(-2,2);
            
            
            for (int i = 0; i < points_0.size(); i++) {
                 int counter = 0;
                 ofPolyline line_temp;
                 line_temp.addVertex(points_0[i]);
                 for (int n = 0; n < points_0.size(); n++) {
                     float distance = (points_0[n] - points_0[i]).length();
                     if (distance < 100) {
                         line_temp.curveTo(points_0[n]);
                         counter++;
                         if (counter > counter_limit) {
                             break;
                             counter = 0;
                         }
                     }
                        
                 }
                 ofSetColor(255, 232, 0);
                 line_temp.draw();
             }
            
            
//            for (int j = 0; j < points_0.size(); j++) {
//                line_0.curveTo(points_0[j].x, points_0[j].y);
//            }
//            ofSetColor(255, 232, 0);
//            line_0.draw();
//
//        // section 1
//
            for (int i = -original.size()/6; i < original.size()/6; i+= 2) {
                points_1.push_back(original[i]);
            }
            
            random_shuffle(points_1.begin(), points_1.end());
            
//            for (int i = 0; i < points_1.size(); i++) {
//                for (int n = 0; n < points_1.size(); n++) {
//                    float distance = (points_1[n] - points_1[i]).length();
//                    if (distance < 100) {
//                        ofSetColor(0, 157, 165);
//                        ofDrawLine(points_1[n], points_1[i]);
//                        break;
//                    }
//                }
//            }
            for (int i = 0; i < points_1.size(); i++) {
                ofSetColor(0, 157, 165);
                int counter = 0;
                int node_og = 0;
                ofPolyline line_temp;
                line_temp.addVertex(points_1[i]);
                for (int n = 0; n < points_1.size(); n++) {
                    float distance = (points_1[n] - points_1[i]).length();
                    if (distance < 50) {
                        line_temp.curveTo(points_1[n]);
                        counter++;
                        if (counter > counter_limit) {
                            break;
                            counter = 0;
                        }
                    }
                }
                for (int n = 0; n < within.size(); n++) {
                    float distance = (within[n] - points_1[i]).length();
                    if (distance < 50) {
//                        line_temp.curveTo(points_1[n]);
                        line_temp.curveTo(within[n]);
                        counter++;
                        if (counter > counter_limit) {
                            break;
                        }
                    }
                }

                line_temp.draw();
            }
//              for (int j = 0; j < points_1.size(); j++) {
//                line_1.curveTo(points_1[j].x, points_1[j].y);
////                line_6.curveTo(points_6[j+gap].x, points_6[j+gap].y);
//            }
////
////        // section 2
//
            for (int i = 0; i < 2*original.size()/6; i+= 2) {
                points_2.push_back(original[i]);
            }

            random_shuffle(points_2.begin(), points_2.end());
                
            for (int i = 0; i < points_2.size(); i++) {
                ofSetColor(250, 18, 230);
                int counter = 0;
                ofPolyline line_temp;
                line_temp.addVertex(points_2[i]);
                for (int n = 0; n < points_2.size(); n++) {
                    float distance = (points_2[n] - points_2[i]).length();
                    if (distance < 50) {
                        line_temp.curveTo(points_2[n]);

                        counter++;
                        if (counter > counter_limit) {
                            break;
                            counter = 0;
                        }
                    }
                }
                for (int n = 0; n < within.size(); n++) {
                    float distance = (within[n] - points_2[i]).length();
                    if (distance < 50) {
//                        line_temp.curveTo(points_2[n]);
                        line_temp.curveTo(within[n]);
//                        ofDrawLine(points_2[i], within[n]);
                        counter++;
                        if (counter > counter_limit) {
                            break;
                        }
                    }
                }
                
                line_temp.draw();
            }

//
//        // section 3
//
            for (int i = 1*original.size()/6; i < 3*original.size()/6; i+= 2) {
                points_3.push_back(original[i]);
            }
            random_shuffle(points_3.begin(), points_3.end());
                    
            for (int i = 0; i < points_3.size(); i++) {
                ofSetColor(0, 204, 100);
                ofPolyline line_temp;
                int counter = 0;
                line_temp.addVertex(points_3[i]);
                for (int n = 0; n < points_3.size(); n++) {
                    float distance = (points_3[n] - points_3[i]).length();
                    if (distance < 50) {
                        line_temp.curveTo(points_3[n]);
                        counter++;
                        if (counter > counter_limit) {
                            break;
                            counter = 0;
                        }
                    }
                }
                for (int n = 0; n < within.size(); n++) {
                    float distance = (within[n] - points_3[i]).length();
                    if (distance < 50) {
//                        line_temp.curveTo(points_3[n]);
//                        ofDrawLine(points_3[i], within[n]);
                        line_temp.curveTo(within[n]);
                        counter++;
                        if (counter > counter_limit) {
                            break;
                        }
                    }
                }
                
                line_temp.draw();
            }

//        // section 4
//
            for (int i = 2*original.size()/6; i < 4*original.size()/6; i+= 2) {
                points_4.push_back(original[i]);
            }
            random_shuffle(points_4.begin(), points_4.end());

            for (int i = 0; i < points_4.size(); i++) {
                int counter = 0;
                ofPolyline line_temp;
                ofSetColor(50, 150, 250);
                line_temp.addVertex(points_4[i]);
                for (int n = 0; n < points_4.size(); n++) {
                    float distance = (points_4[n] - points_4[i]).length();
                    if (distance < 50) {
                        
//                        ofDrawLine(points_4[n], points_4[i]);
                        line_temp.curveTo(points_4[n]);
                        counter++;
                        if (counter > counter_limit) {
                            break;
                            counter = 0;
                        }
                    }
                }
                for (int n = 0; n < within.size(); n++) {
                    float distance = (within[n] - points_4[i]).length();
                    if (distance < 50) {
//                        ofDrawLine(points_4[i], within[n]);
//                        line_temp.curveTo(points_4[n]);
                        line_temp.curveTo(within[n]);
                        counter++;
                        if (counter > counter_limit) {
                            break;
                        }
                    }
                }
                line_temp.draw();
            }
////
//        // section 5
//
            for (int i = 3*original.size()/6; i < 5*original.size()/6; i+= 2) {
                points_5.push_back(original[i]);
            }
            random_shuffle(points_5.begin(), points_5.end());

            for (int i = 0; i < points_5.size(); i++) {
                ofSetColor(255, 150, 0);
                int counter = 0;
                ofPolyline line_temp;
                line_temp.addVertex(points_5[i]);
                for (int n = 0; n < points_5.size(); n++) {
                    float distance = (points_5[n] - points_5[i]).length();
                    if (distance < 50) {
                        line_temp.curveTo(points_5[n]);
                        counter++;
                        if (counter > counter_limit) {
                            break;
                            counter = 0;
                        }
//                        ofDrawLine(points_5[n], points_5[i]);
                    }
                }
                for (int n = 0; n < within.size(); n++) {
                    float distance = (within[n] - points_5[i]).length();
                    if (distance < 50) {
//                        line_temp.curveTo(points_5[n]);
//                        ofDrawLine(points_5[i], within[n]);
                        line_temp.curveTo(within[n]);
                        counter++;
                        if (counter > counter_limit) {
                            break;
                        }
                    }
                }
                
                line_temp.draw();
            }
//
//        // section 6
//
            for (int i = 4*original.size()/6; i < original.size(); i+= 2) {
                points_6.push_back(original[i]);
            }
            random_shuffle(points_6.begin(), points_6.end());
            
            for (int i = 0; i < points_6.size(); i++) {
                int counter = 0;
                ofSetColor(150, 0, 250);
                ofPolyline line_temp;
                line_temp.addVertex(points_6[i]);
                for (int n = 0; n < points_6.size(); n++) {
                    float distance = (points_6[n] - points_6[i]).length();
                    if (distance < 50) {
                        
                        line_temp.curveTo(points_6[n]);
                        counter++;
                        if (counter > counter_limit) {
                            break;
                            counter = 0;
                        }
//                        ofDrawLine(points_6[n], points_6[i]);
                    }
                }
                for (int n = 0; n < within.size(); n++) {
                    float distance = (within[n] - points_6[i]).length();
                    if (distance < 50) {
//                        line_temp.curveTo(points_6[n]);
//                        ofDrawLine(points_6[i], within[n]);
                        line_temp.curveTo(within[n]);
                        counter++;
                        if (counter > counter_limit) {
                            break;
                        }
                    }
                }
//                ofSetColor(150, 0, 250);
                line_temp.draw();
            }
            
//            for (int j = 0; j < points_6.size(); j++) {
//                line_6.curveTo(points_6[j].x, points_6[j].y);
////                line_6.curveTo(points_6[j+gap].x, points_6[j+gap].y);
//            }
//
//            ofPushMatrix();
//            ofTranslate(1280,0);
//            ofScale(-2,2);
//            ofSetColor(255, 232, 0);
//            ofSetColor(0, 157, 165);
//            within.draw();
//            line_0.draw();
//            ofSetColor(0, 157, 165);
//            line_1.draw();
//            ofSetColor(250, 18, 230);
//            line_2.draw();
//            ofSetColor(0, 204, 100);
//            line_3.draw();
//            ofSetColor(50, 150, 250);
//            line_4.draw();
//            ofSetColor(255, 150, 0);
//            line_5.draw();
//            ofSetColor(150, 0, 250);
//            line_6.draw();
////
        
            ofSetColor(140, 90, 75);
            ofSetLineWidth(7);
    
            original.draw();
            ofPopMatrix();
        }
    }
    fbo.end();
    
//    fbo.draw(0,0);
    
    ofSetColor(255);
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
//    shader.setUniform2f("mouse", mouseX, mouseY);
    shader.setUniformTexture("rockImg", rock, 0);
    shader.setUniformTexture("lineImg", fbo, 1);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    shader.end();
    
//    rock.draw(0,0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
