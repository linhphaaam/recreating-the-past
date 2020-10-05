//
//  vehicle.cpp
//  flowfield_mildred_1
//
//  Created by Linh Pham on 10/4/20.
//

#include "vehicle.hpp"
#include "ofMain.h"
#include "flowfield.hpp"

Vehicle::Vehicle() {
    
}

void Vehicle::setup(float x, float y) {
    pos = ofVec2f(x, y);
    vel = ofVec2f(0, 0);
    acc = ofVec2f(0, 0);
    maxspeed = 20;
    maxforce = 20;
    
}

void Vehicle::applyForce(ofVec2f force) {
    acc += force;
}

void Vehicle::separate(vector < Vehicle > vehicles) {
    for (int i = 0; i < vehicles.size(); i++) {
        float dis = vehicles[i].pos.distance(pos);
        if (dis < 30) {
            ofVec2f desired = vehicles[i].pos - pos;
            desired.limit(maxspeed);
            ofVec2f steering = desired - vel;
            steering.limit(maxforce);
            applyForce(-steering);
        }
    }
}

void Vehicle::follow(Flowfield flow) {
    ofVec2f desired = flow.lookup(pos);
    desired.getNormalized().scale(maxspeed);
    ofVec2f steering = desired - vel;
//    steering.limit(maxforce);
    applyForce(steering);
    
}

void Vehicle::print() {
    cout << vel << endl;
}

void Vehicle::arrive(ofVec2f target) {
    // steering = desired - velocity
    
    ofVec2f desired = target - pos;
    desired.limit(maxspeed);
    ofVec2f steering = desired - vel;
    steering.limit(maxforce);
    applyForce(steering);
}

void Vehicle::update() {
    vel += acc;
//    vel.limit(maxspeed);
    pos += vel;
    acc.set(0, 0);
}

void Vehicle::draw(ofColor color, float size) {
    ofSetColor(color);
    ofDrawCircle(pos.x, pos.y, size);
}
