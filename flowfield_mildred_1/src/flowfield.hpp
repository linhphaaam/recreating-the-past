//
//  flowfield.hpp
//  flowfield_mildred_1
//
//  Created by Linh Pham on 10/4/20.
//

#ifndef flowfield_hpp
#define flowfield_hpp

#include <stdio.h>
#include "ofMain.h"

class Flowfield {
public:
    void draw();
    void init();
    void print();
    void flowfield(int r);
    void drawVector(ofVec2f v, float x, float y, float scale);
    ofVec2f lookup(ofVec2f pos);
    
    // variables
    int resolution;
    int cols;
    int rows;
    vector < vector < ofVec2f > > field;
    
    Flowfield();
    
};

#endif /* flowfield_hpp */
