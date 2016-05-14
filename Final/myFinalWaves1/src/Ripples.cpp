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
    float n = 56.5; // 360/n sets the number of vertex's
    r2 += 4; // expands for movement
    ofSetLineWidth(40);
    
    //Creating the circles
    xoff = 5.0;
    // change opacity of ripples depending on how close to the edges it is
    ofSetColor(0, 255, 0, ofMap(r2, 0, ofGetWidth()/2, 255, 0));
    ofBeginShape();
    for (float i = 0; i<360; i+=360/n){
        //adds noise to movement
        float noise = ofMap(ofNoise(xoff,yoff), 0, 1, 0, 100.0);
        //movement
        x = posX+cos(i/n)*r2;
        y = posY+sin(i/n)*r2;
        
        // z = ofRandom(-70, 70);

        ofNoFill();
        ofVertex(x+noise, y+noise);
    
        
        xoff += 0.1;
        
        
    }
    ofEndShape(true);
    yoff += 0.01;
    
    
    
    
    
}