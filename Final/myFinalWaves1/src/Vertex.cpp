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
    //Vertexes positions are all depending on things set in Wave.cpp
    ofVertex(x, y+ypos, z);
    
    
    
}