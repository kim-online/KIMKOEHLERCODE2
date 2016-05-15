//
//  Sean.cpp
//  mySean
//
//  Created by Kim Köhler on 28/03/16.
//
//

#include "Sean.hpp"

Sean::Sean(){
    A.x = 0;
    A.y = 0;
    
    B.x = 0;
    B.y = 25;
    
}

void Sean::interpolate(float myPct){
   // theY = ofMap(somethingY, ofGetHeight()/2, 0, 0, 100);
    
    
    
    somethingX = cos(ofGetElapsedTimef()); //Changing between -1 and 1
    
    theY = powf(somethingX, 3);
   // somethingElseX = ofMap(somethingX, -1, 1, 0, ofGetWidth()); // setting an X value between 0 and width
    somethingElseX = (1- somethingX)*ofGetWidth()/2 + somethingX*ofGetWidth();
    cout << theY << endl;

    somethingY = abs(sin(ofGetElapsedTimef())); // toggling between 0 and 1
    somethingElseY = ofMap(somethingY, 0, 1, 0, ofGetHeight()/2); // setting an Y value between zero and half the height
    //cout << somethingY << endl;
    
   // theY = (1 - somethingElseY)*0 + somethingElseY*25;
  
    
}

void Sean::draw(){
    ofDrawCircle(somethingElseX, somethingElseY, 10);
    ofDrawLine(ofGetWidth()/2, 0, somethingElseX, somethingElseY);
    
}