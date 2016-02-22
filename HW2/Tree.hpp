//
//  Tree.hpp
//  treeBranch
//
//  Created by Kim Köhler on 21/02/16.
//
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>

#endif /* Tree_hpp */

#include "ofMain.h"


class Tree{
    
public:
    
    Tree();
    
    int r, g, b;
    
    float x1, y1, z1, x2, y2, z2;
    
    void grow();
    
    void reset();
    
    ofColor texture;
    
    bool mousePress;
    
    
};
