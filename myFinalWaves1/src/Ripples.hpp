//
//  Wave.hpp
//  emptyExample
//
//  Created by Kim Köhler on 12/03/16.
//
//

#ifndef Ripples_hpp
#define Ripples_hpp

#include <stdio.h>
#include "ofMain.h"

class Ripples: public ofBaseApp {
public:
    //variables
    
    float r1, r2;
    
    float x, y;
    
    float xoff, yoff;
    
    float posX, posY;
    
    
    //constructor
    
    Ripples();
    
    //methods
    
    void setPosition(float x, float y);
    
    void setup();
    
    void draw();
    
    
    
    
};

#endif /* Wave_hpp */