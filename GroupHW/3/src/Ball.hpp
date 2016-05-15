//
//  Ball.hpp
//  myTwist
//
//  Created by Kim Köhler on 02/04/16.
//
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include "ofMain.h"

class Ball{
public:
    
    float x, y;
    float _r;
    
    Ball();
    
    void update(float r);
    void draw();
};

#endif /* Ball_hpp */
