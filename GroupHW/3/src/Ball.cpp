//
//  Ball.cpp
//  myTwist
//
//  Created by Kim Köhler on 02/04/16.
//
//

#include "Ball.hpp"

Ball::Ball(){
    x = 0;
    y = 0;
};

void Ball::update(float r){
    
    r = _r +1;
    
    x = cos(ofGetElapsedTimef()*5)*r;
    y = sin(ofGetElapsedTimef()*5)*r;
    _r = r;
}

void Ball::draw(){
    
    ofDrawCircle(x, y, 10);
    
}