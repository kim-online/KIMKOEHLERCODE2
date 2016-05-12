//
//  Wave.cpp
//  myWavesTest1
//
//  Created by Kim Köhler on 17/04/16.
//
//

#include "Wave.hpp"

Wave::Wave(){
    
}

void Wave::setup(float start){
    
    yoff = 0.0;
    vert[NUM2].y = start;
    vert[NUM2].x = 0;
    vert[NUM2].z = 0;
    vert[NUM2].ypos= start;
    // go = false;
    
}

void Wave::update(float back){
    if (vert[NUM2].ypos < -620){
        
        vert[NUM2].ypos += back;
    }
}

void Wave::draw(){
    ofEnableSmoothing();
    //  keep = keep2;
    
    float line = ofMap(cos(ofGetElapsedTimef()), -1, 1, 2, 8);
    float osc = ofMap(keep, 0, ofGetHeight(), 50, 100);
    //float start = ofRandomuf();
    
    ofNoFill();
    
    ofBeginShape();
    
    xoff = 5.0;
    
    // Iterate over horizontal pixels
    for (int i = 0; i <= NUM2; i += 16) {
        vert[i].ypos = keep;
        vert[i].x = i;
        
        vert[i].y = ofMap(ofNoise(xoff, yoff), 0, 1, 0, osc); // Option #1: 2D Noise
        // float y = map(noise(xoff), 0, 1, 200,300);    // Option #2: 1D Noise
        
        vert[i].draw();
        
        // Increment x dimension for noise
        xoff += 0.05;
        keep = vert[i].ypos;
        ofSetLineWidth(line);
        
    }
    ofEndShape();
    
    
    keep += 300;
    ofBeginShape();
    for (int j = 0; j <= NUM2; j += 16) {
        vert[j].ypos = keep;
        vert[j].x = j;
        
        vert[j].y = ofMap(ofNoise(xoff, yoff), 0, 1, 0, osc); // Option #1: 2D Noise
        // float y = map(noise(xoff), 0, 1, 200,300);    // Option #2: 1D Noise
        
        vert[j].draw();
        
        // Increment x dimension for noise
        xoff += 0.05;
        keep = vert[j].ypos;
        ofSetLineWidth(line);
        
    }
    ofEndShape();
    
    keep += 300;
    ofBeginShape();
    for (int j = 0; j <= NUM2; j += 16) {
        vert[j].ypos = keep;
        vert[j].x = j;
        
        vert[j].y = ofMap(ofNoise(xoff, yoff), 0, 1, 0, osc); // Option #1: 2D Noise
        // float y = map(noise(xoff), 0, 1, 200,300);    // Option #2: 1D Noise
        
        vert[j].draw();
        
        // Increment x dimension for noise
        xoff += 0.05;
        keep = vert[j].ypos;
        ofSetLineWidth(line);
        
    }
    ofEndShape();
    
    keep -= 600;
    
    // increment y dimension for noise
    yoff += 0.01;
    //acc = ofMap(ofNoise(ofGetElapsedTimef()), 0, 1, 1, 5);
    if (keep>0){
        acc = 2 + keep*0.0065;
    } else{
        acc = 2;
    }
    keep = keep - acc;
    
    
    //ofVertex(ofGetWidth(), ofGetHeight());
    //ofVertex(0, ofGetHeight());
    
    
    /* if (start > 0.5 && keep > 0){
     go = true;
     } else {
     go = false;
     }
     
     if (keep > 0){
     if (go == true){
     //keep = ofGetHeight() + 10;
     
     }
     }
     keep2 = keep;*/
    
}