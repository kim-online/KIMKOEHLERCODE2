//
//  Wave.hpp
//  emptyExample
//
//  Created by Kim Köhler on 12/03/16.
//
//

#ifndef Wave_hpp
#define Wave_hpp

#include <stdio.h>
#include "ofMain.h"

class Wave: public ofBaseApp {
public:
    //variables
    
    float r1, r2, r3, r4, r5;
    
    float x, y, z;
    
    
    //constructor
    
    Wave();
    
    //methods
    void setup();
    
    void draw();
    
    void draw1();
    
    void draw2();
    
    void draw3();

    
};

#endif /* Wave_hpp */
