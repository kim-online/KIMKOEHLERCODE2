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
   
    
}

void Wave::update(float back){
    //make waves start over
    if (vert[NUM2].ypos < -620){
        
        vert[NUM2].ypos += back;
    }
}

void Wave::draw(){
    ofEnableSmoothing();
    
    //line makes the linewidth of the waves change
    float line = ofMap(cos(ofGetElapsedTimef()), -1, 1, 2, 8);
    // osc sets the difference of wavelenght depending on how close to y=0 it is
    float osc = ofMap(keep, 0, ofGetHeight(), 50, 100);
    
    ofNoFill();
    
    ofBeginShape();
    
    xoff = 5.0;
    
    // Iterate over horizontal pixels
    for (int i = 0; i <= NUM2; i += 16) {
        //add movement of keep
        vert[i].ypos = keep;
        vert[i].x = i;
        //wave noise
        vert[i].y = ofMap(ofNoise(xoff, yoff), 0, 1, 0, osc);
    
        vert[i].draw();
        
        // Increment x dimension for noise
        xoff += 0.05;
        //save ypos in keep
        keep = vert[i].ypos;
        ofSetLineWidth(line);
        
    }
    ofEndShape();
    
    //make another wave 300 behind first wave
    keep += 300;
    ofBeginShape();
    for (int j = 0; j <= NUM2; j += 16) {
        //add movement of keep
        vert[j].ypos = keep;
        vert[j].x = j;
        //wave noise
        vert[j].y = ofMap(ofNoise(xoff, yoff), 0, 1, 0, osc);
        
        vert[j].draw();
        
        // Increment x dimension for noise
        xoff += 0.05;
        //save ypos in keep
        keep = vert[j].ypos;
        ofSetLineWidth(line);
        
    }
    ofEndShape();
    //make another wave 300 behind second wave
    keep += 300;
    ofBeginShape();
    for (int j = 0; j <= NUM2; j += 16) {
        //add movement of keep
        vert[j].ypos = keep;
        vert[j].x = j;
         //wave noise
        vert[j].y = ofMap(ofNoise(xoff, yoff), 0, 1, 0, osc);
        
        vert[j].draw();
        
        // Increment x dimension for noise
        xoff += 0.05;
        //save ypos in keep
        keep = vert[j].ypos;
        ofSetLineWidth(line);
        
    }
    ofEndShape();
    //set keep back to first waves number
    keep -= 600;
    
    // increment y dimension for noise
    yoff += 0.01;
   
    //make waves accelerate high in the begging and lower the closer it gets to y=0
    if (keep>0){
        acc = 2 + keep*0.0065;
    } else{
        acc = 2;
    }
    //add acc to keep
    keep = keep - acc;
    
}