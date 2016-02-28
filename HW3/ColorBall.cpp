//
//  ColorBall.cpp
//  myOOPS
//
//  Created by Kim Köhler on 27/02/16.
//
//

#include "ColorBall.hpp"


void ColorBall::draw(){
    ofSetColor(ofColor(ofRandom(255), ofRandom(10), ofRandom(10), 200));
    ofFill();
    ofDrawCircle(x, y, z, dim + change);
}