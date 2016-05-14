//
//  Wave.cpp
//  emptyExample
//
//  Created by Kim Köhler on 06/04/16.
//
//

#include "Ripples.hpp"

Ripples::Ripples(){
    
};

void Ripples::setup(){
    
    r1 = 2; //radiance of small circle object
    r2 = 0.1; // radiance of expanding circle
    yoff = 0.0;
    
    
    
    
}

void Ripples::setPosition(ofPoint point)
{
    posX = point.x;
    posY = point.y;
}

void Ripples::draw(){
    float n = 56.5; // number of circles
    r2 += 2; //
    ofSetLineWidth(15);
    //Creating the circles
    xoff = 5.0;
    ofBeginShape();
    for (float i = 0; i<360; i+=360/n){
        
        //  float noise = ofNoise(i);
        
        float noise = ofMap(ofNoise(xoff,yoff), 0, 1, 0, 100.0);
        
        x = posX+cos(i/n)*r2;
        y = posY+sin(i/n)*r2;
        
        // z = ofRandom(-70, 70);
        
        // ofSetColor(0, 255, 0);
        
        
        // ofSetLineWidth(5);
        ofNoFill();
        //if(i > 0 && i < 351){
        ofVertex(x+noise, y+noise);
        //  } else{
        //  ofVertex(x, y);
        //}
        
        xoff += 0.1;
        
        
    }
    ofEndShape(true);
    yoff += 0.01;
    
    
    
    
    
}