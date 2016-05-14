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
    
    ofSetColor(250, 120, (225+ofRandom(-25,25))/2,170+ofRandom(-25,45));
    
    ofVertex(x, y+ypos+ofRandom(-5,5), z + 140);
   
   // ofSetColor(120, 225+ofRandom(-25,25), 225+ofRandom(-25,25),90+ofRandom(-25,25));
    
   // ofVertex(x +ofRandom(-25,25), ofRandom(y+ypos)- 40, z);
             
    
    
    
    
}