//
//  Kim.hpp
//  zenoHW
//
//  Created by Sean Hughes on 4/2/16.
//
//

#ifndef Kim_hpp
#define Kim_hpp

#include <stdio.h>
#include "ofMain.h"

#endif /* Kim_hpp */


class Kim{
public:
    ofPoint pos;
    float catchUpSpeed;
    
    Kim();
    
    void zeno(float catchX, float catchY);
    void draw();
};