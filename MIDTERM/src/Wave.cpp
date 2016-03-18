//
//  Wave.cpp
//  emptyExample
//
//  Created by Kim Köhler on 12/03/16.
//
//

#include "Wave.hpp"

Wave::Wave(){
    
};

void Wave::setup(){
    
    r1 = 2; //radiance of small circle object
    r2 = 0.1; // radiance of expanding circle
    r3 = 0.1;
    r4 = 0.1;
    r5 = 0.1;
    
    
    
}

void Wave::draw(){
    float n = 56.5; // number of circles
    r2 += 1; //
    
    //Creating the circles
    ofBeginShape();
    for (float i = 0; i<360; i+=360/n){
        
        float noise = ofNoise(i);
        float noise2 = ofMap(noise, 0, 1, 0.1, 100.0);
        
        x = 0+cos(i/n)*r2+noise2;
        y = 0+sin(i/n)*r2+noise2;
        z = ofNoise(-70, 70)*10;
        // z = ofRandom(-70, 70);
        
        
        ofFill();
        ofDrawCircle(x, y, z, r1);
        
        ofNoFill();
        ofVertex(x, y, z);
        
        
    }
    ofEndShape();
    
    
    
    
    float dist = ofDist(x, y, 0, 0);
    
    if (dist > 300 && dist < 2000 ){
        draw1();
    } if (dist >= 1000){
        r2 = 0.1;
    }
    
    
    
}

 void Wave::draw1(){
 float n = 56.5; // number of circles
 r3 += 1; //
 
 //Creating the circles
 ofBeginShape();
 for (float i = 0; i<360; i+=360/n){
 
 float noise = ofNoise(i);
 float noise2 = ofMap(noise, 0, 1, 0.1, 100.0);
 
 x = 0+cos(i/n)*r3+noise2;
 y = 0+sin(i/n)*r3+noise2;
 z = ofNoise(-70, 70)*10;
 // z = ofRandom(-70, 70);
 
 
 ofFill();
 ofDrawCircle(x, y, z, r1);
 
 ofNoFill();
 ofVertex(x, y, z);
 
 
 }
 ofEndShape();
 
 
 
 
 float dist = ofDist(x, y, 0, 0);
 
 if (dist > 300 && dist < 2000 ){
 draw2();
 } if (dist >= 1000){
 r3 = 0.1;
 }
 
 
 
 }
 
 void Wave::draw2(){
 float n = 56.5; // number of circles
 r4 += 1;
 
 //Creating the circles
 ofBeginShape();
 for (float i = 0; i<360; i+=360/n){
 
 float noise = ofNoise(i);
 float noise2 = ofMap(noise, 0, 1, 0.1, 100.0);
 
 x = 0+cos(i/n)*r4+noise2;
 y = 0+sin(i/n)*r4+noise2;
 z = ofNoise(-70, 70)*10;
 //z = ofRandom(-70, 70);
 
 
 ofFill();
 ofDrawCircle(x, y, z, r1);
 ofNoFill();
 
 ofVertex(x, y, z);
 
 
 
 }
 ofEndShape();
 
 
 
 
 float dist = ofDist(x, y, 0, 0);
 
 if (dist > 300 && dist < 2000 ){
 draw3();
 
 } if (dist >= 1000){
 r4 = 0.1;
 }
 
 
 
 }
 
 void Wave::draw3(){
 float n = 56.5; // number of circles
 r5 += 1;
 
 //Creating the circles
 ofBeginShape();
 for (float i = 0; i<360; i+=360/n){
 float noise = ofNoise(i);
 float noise2 = ofMap(noise, 0, 1, 0.1, 100.0);
 
 
 x = 0+cos(i/n)*r5+noise2;
 y = 0+sin(i/n)*r5+noise2;
 z = ofNoise(-70, 70)*10;
 // z = ofRandom(-70, 70);
 
 ofFill();
 ofDrawCircle(x, y, z,r1);
 ofNoFill();
 
 ofVertex(x, y, z);
 
 
 
 }
 ofEndShape();
 
 
 
 
 float dist = ofDist(x, y, 0, 0);
 
 if (dist > 300 && dist < 2000 ){
 //draw();
 
 } if (dist >= 1000){
 r5 = 0.1;
 }
 
 
 
 }
 
 
