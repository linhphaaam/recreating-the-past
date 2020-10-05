//
//  flowfield.cpp
//  flowfield_mildred_1
//
//  Created by Linh Pham on 10/4/20.
//

#include "flowfield.hpp"
#include "ofMain.h"

Flowfield::Flowfield() {
    
}

void Flowfield::flowfield(int r) {
    resolution = r;
    cols = ofGetWidth() / resolution;
    rows = ofGetHeight() / resolution;
    
    for (int i = 0; i < cols; i++) {
        vector < ofVec2f > array;
        field.push_back(array);
    };
    
    init();
//    print();

}

//ofVec2f Flowfield::lookup(ofVec2f pos) {
//    int col = pos.x / resolution;
//    int row = pos.y / resolution;
//
////    ofVec2f vec_loc = field[col][row];
//    return field[col][row];
//
//}

void Flowfield::init() {
    ofSeedRandom(100);
    float xoff = 0;
    for (int i = 0; i < cols; i++) {
        float yoff = 0;
        for (int j = 0; j < rows; j++) {
            float theta = ofMap(ofNoise(xoff, yoff), 0, 1, 0, TWO_PI);
            field[i].push_back(ofVec2f(cos(theta),sin(theta)));
            yoff += 0.02;
        }
        xoff += 0.02;
    }
}

ofVec2f Flowfield::lookup(ofVec2f pos) {
    int col = ofClamp(pos.x / resolution, 0, cols-1);
    int row = ofClamp(pos.y / resolution, 0, rows-1);
    
    ofVec2f vec_loc = field[col][row];

    return vec_loc;
    
}

void Flowfield::print() {
    for (int i = 0; i < field.size(); i++) {
        for (int j = 0; j < field[i].size(); j++)
            cout << field[i][j] << " ";
        cout << endl;
    }
    
}

void Flowfield::draw() {
    ofSetColor(255);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
//            drawVector(field[i][j], i * resolution, j * resolution, resolution - 2);
            ofVec2f cur_pos = ofVec2f(i * resolution, j * resolution);
            ofVec2f direction = ofVec2f(field[i][j].getNormalized());
            ofVec2f end_p = ofVec2f(cur_pos + (direction * 20));
            ofDrawArrow(ofVec3f(cur_pos.x, cur_pos.y, 0), ofVec3f(end_p.x, end_p.y, 0), 3.0);
        }
    }
}

void Flowfield::drawVector(ofVec2f v, float x, float y, float scale) {
    ofPushMatrix();
    ofTranslate(x, y);
    ofSetColor(255);
    ofRotateDeg(v.angle({1,1}));
    
    float len = v.length()*scale;
    ofDrawLine(0, 0, len, 0);
    ofPopMatrix();
}


