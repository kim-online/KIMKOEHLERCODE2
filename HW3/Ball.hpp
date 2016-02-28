//
//  Ball.hpp
//  myOOPS
//
//  Created by Kim Köhler on 26/02/16.
//
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>


#include "ofMain.h"



class Ball{
    
public:
    
    //constructor
    Ball();
    
    //variabels
    float x, y, z;
    float xSpeed, ySpeed, zSpeed;
    float change;
    int dim;
    ofColor color;
    
    //methods
    void setup(float _x, float _y, float _z, int _dim);
    void update();
    void draw();
    
    
    
};
#endif /* Ball_hpp */