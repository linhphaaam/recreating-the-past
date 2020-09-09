//
//  Walker.cpp
//  linh_random_walk
//
//  Created by Linh Pham on 9/7/20.
//

#include "Walker.hpp"
#include "ofMain.h"

Walker::Walker() {
    
}

void Walker::setup() {
    pos = ofVec3f(-100, 200, 0);
    vel = ofVec3f(0, 0, 0);
    acc_temp = ofVec3f(0, 0, 0);
    
}

void Walker::update(float x, float y, float z) {
    vel = ofVec3f(0, 0, 0) - acc.scale(0.2);
    acc = ofVec3f(x, y, z) - pos;
//    acc_temp = acc * 0.5;
    acc.scale(1.5);
    vel = vel + acc;
//    vel = ofVec3f(x, y, z) - pos;
    pos = pos + vel;
    
}

void Walker::draw(ofColor color,float t) {
    ofPushMatrix();
//    ofTranslate(-993+t, ofGetHeight()/2, 0);
//
//    ofTranslate(0, ofGetHeight()/2, 0);
    ofSetColor(100,68,58);
    ofDrawCircle(ofVec3f(pos.x, pos.y, pos.z-0.2), 5.75);
    ofSetColor(color);
    ofDrawCircle(ofVec3f(pos.x, pos.y, pos.z), 5);
//    ofSetColor(100,68,58);
//    ofDrawCircle(ofVec3f(pos.x, pos.y-4, pos.z+1), 3);
//    ofDrawCircle(ofVec3f(pos.x, pos.y+4, pos.z+1), 3);
//    ofSetColor(100,68,58);
//    ofDrawCircle(ofVec3f(pos.x, pos.y, pos.z-0.2), 17);

    ofPopMatrix();
}
