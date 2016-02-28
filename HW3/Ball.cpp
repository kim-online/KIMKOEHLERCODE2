//
//  Ball.cpp
//  myOOPS
//
//  Created by Kim Köhler on 26/02/16.
//
//

#include "Ball.hpp"

Ball::Ball(){
    
    
}

void Ball::setup(float _x, float _y, float _z, int _dim){
    
    x = _x;
    y = _y;
    z = _z;
    dim = _dim;
    
    
    
    xSpeed = ofRandom(-3, 3);
    ySpeed = ofRandom(-3, 3);
    zSpeed = ofRandom(-10, 10);
    
    //dim = 20;
    
    //color.set(ofRandom(230, 255), ofRandom(230, 255), ofRandom(230, 255), 235);
    
}

void Ball::draw(){
    ofSetColor(ofRandom(0, 10), ofRandom(0, 255), ofRandom(0, 10), 235);
    ofFill();
    ofDrawCircle(x, y, z, dim + change);
}

void Ball::update(){
    if (x < 0){
        x = 0;
        xSpeed *= -1;
    }
    else if (x > ofGetWidth()){
        x = ofGetWidth();
        xSpeed *= -1;
    }
    
    if (y < 0){
        y = 0;
        ySpeed *= -1;
    }
    else if (y > ofGetHeight()){
        y = ofGetHeight();
        ySpeed *= -1;
    }
    
    if (z < -500){
        z = -500;
        zSpeed *= -1;
    }
    else if (z > 500){
        z = 500;
        zSpeed *= -1;
    }
    
    x+= xSpeed;
    y+= ySpeed;
    z+= zSpeed;
    change = cos(ofGetElapsedTimef())*40;
}