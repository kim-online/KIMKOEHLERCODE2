//
//  Wave.hpp
//  myWavesTest1
//
//  Created by Kim Köhler on 17/04/16.
//
//

#ifndef Wave_hpp
#define Wave_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Vertex.hpp"

class Wave{
public:
    
    Wave();
    
    void setup(float start);
    void update(float back);
    void draw();
    
#define NUM2 1445
    
    Vertex vert[NUM2];
    
    float xoff, yoff;
    float acc;
    float keep;
    //  float keep2;
    
    
    // bool go;
    
};

#endif /* Wave_hpp */
