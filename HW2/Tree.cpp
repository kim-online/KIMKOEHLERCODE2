//
//  Tree.cpp
//  treeBranch
//
//  Created by Kim Köhler on 21/02/16.
//
//

#include "Tree.hpp"
#include "ofMain.h"


Tree::Tree(){
    
  
    x1 = ofGetWidth()/2;
    x2 = (ofGetWidth()/2) + ofRandom((-3), 3);
    y1 = ofGetHeight();
    y2 = ofGetHeight()-1;
    z1 = 0;
    z2 = 0 + ofRandom(10);
    
   
    
};



//--------------------------------------------------------------
void Tree::grow(){
    
    
    
    if (mousePress == true){
    
    
    cout << "*Growing*" << endl;
    
    texture.r = ofRandom(255);
    texture.b = ofRandom(255);
    texture.g = ofRandom(255);
    
    ofSetColor(texture);
    
    ofFill();
    ofSetLineWidth(2);
    ofDrawLine(x1, y1, z1, x2, y2, z2);
    
    x1 = x2;
    y1 = y2;
    z1 = z2;
    
    x2 = x2 + ofRandom((-7), 7);
    y2 = y2 - 3;
    z2 = z2 + ofRandom(7);
    }
    
    
    
}

void Tree::reset() {
    
    x1 = ofGetWidth()/2;
    x2 = (ofGetWidth()/2) + ofRandom((-3), 3);
    y1 = ofGetHeight();
    y2 = ofGetHeight()-1;
    z1 = 0;
    z2 = 0 + ofRandom(10);
  
}