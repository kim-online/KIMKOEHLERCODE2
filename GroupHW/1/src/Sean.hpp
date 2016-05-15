//
//  Sean.hpp
//  mySean
//
//  Created by Kim Köhler on 28/03/16.
//
//

#ifndef Sean_hpp
#define Sean_hpp

#include <stdio.h>
#include "ofMain.h"

class Sean{
public:
    
    //variables
    ofPoint A;
    ofPoint B;
    float somethingX;
    float somethingY;
    float somethingElseX;
    float somethingElseY;
    float theY;

    
    
    //constructor
    Sean();
    
    //methods
    void interpolate(float myPct);
    void draw();
    
};

#endif /* Sean_hpp */
