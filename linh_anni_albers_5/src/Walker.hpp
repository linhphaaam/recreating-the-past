//
//  Walker.hpp
//  linh_random_walk
//
//  Created by Linh Pham on 9/7/20.
//

#ifndef Walker_hpp
#define Walker_hpp

#include <stdio.h>
#include "ofMain.h"

class Walker {
public:
    void setup();
    void update(float x, float y, float z);
    void draw(ofColor color, float t);
    
    // variables
    
    ofVec3f pos;
    ofVec3f vel;
    ofVec3f acc;
    ofVec3f acc_temp;
    
    ofColor color;
    
    Walker();
    
private:
    
    
};


#endif /* Walker_hpp */
