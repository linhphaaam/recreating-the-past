//
//  vehicle.hpp
//  flowfield_mildred_1
//
//  Created by Linh Pham on 10/4/20.
//

#ifndef vehicle_hpp
#define vehicle_hpp

#include <stdio.h>
#include "ofMain.h"
#include "flowfield.hpp"

class Vehicle {
public:
    void setup(float x, float y);
    void arrive(ofVec2f target);
    void separate(vector < Vehicle > vehicles);
    void applyForce(ofVec2f force);
    void update();
    void print();
    void follow(Flowfield flow);
    void draw(ofColor color, float size);
    
    // variables
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    float maxspeed;
    float maxforce;
    
    Vehicle();
    
private:
    
};

#endif /* vehicle_hpp */
