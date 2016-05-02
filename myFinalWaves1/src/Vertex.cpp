//
//  Point.cpp
//  myWavesTest1
//
//  Created by Kim Köhler on 18/04/16.
//
//

#include "Vertex.hpp"

Vertex::Vertex(){
    
}

void Vertex::draw(){
    
    
    
    // Set the vertex
    ofSetColor(0, 255, 0);
    
    ofVertex(x, y+ypos, z);
    
    
    
}