//
//  Kim.cpp
//  zenoHW
//
//  Created by Sean Hughes on 4/2/16.
//
//

#include "Kim.hpp"

Kim::Kim(){
    catchUpSpeed = 0.02;
}

void Kim::zeno(float catchX, float catchY){
    pos.x = catchUpSpeed * catchX + (1 - catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1 - catchUpSpeed) * pos.y;
}

void Kim::draw(){
    ofSetColor(ofRandom(200), ofRandom(200), ofRandom(200), ofRandom(200));
    ofDrawCircle(pos.x + ofRandom(20), pos.y + ofRandom(20), 10);
        ofSetColor(ofRandom(200), ofRandom(200), ofRandom(200), ofRandom(200));
    ofDrawCircle(pos.x + ofRandom(50), pos.y - ofRandom(50), 10);
        ofSetColor(ofRandom(200), ofRandom(200), ofRandom(200), ofRandom(200));
    ofDrawCircle(pos.x - ofRandom(50), pos.y + ofRandom(50), 10);
}