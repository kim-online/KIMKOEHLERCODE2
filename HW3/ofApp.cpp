#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   /* for (int i = 0; i < NBALLS; i++) {
        
        int size = (i+1) * 10;
        int randomX = ofRandom( 0, ofGetWidth() );
        int randomY = ofRandom( 0, ofGetHeight() );
        
        firstBall[i].setup(randomX, randomY, size);
        
       
    }*/
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
  /*  for (int i = 0; i < NBALLS; i++) {
        firstBall[i].update();
    }*/
    
    for (int i = 0; i<vecBall.size(); i++) {
        vecBall[i].update();
    }
    
    for (int i = 0; i<vecBall2.size(); i++) {
        vecBall2[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
 /*   for (int i = 0; i < NBALLS; i++) {
        firstBall[i].draw();
    }*/
    
    for (int i = 0 ; i<vecBall.size(); i++) {
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        vecBall[i].draw();
        ofSetColor(ofRandom(10), ofRandom(255), ofRandom(10), 150);
        ofFill();
        ofDrawLine(vecBall[i].x, vecBall[i].y, vecBall[i].z, vecBall[i+1].x, vecBall[i+1].y, vecBall[i+1].z);
    }
    
    for (int i = 0 ; i<vecBall2.size(); i++) {
        //ofEnableBlendMode(OF_BLENDMODE_ADD);
        vecBall2[i].draw();
        ofSetColor(ofRandom(255), ofRandom(10), ofRandom(10), 150);
        ofFill();
        ofDrawLine(vecBall2[i].x, vecBall2[i].y, vecBall2[i].z, vecBall2[i+1].x, vecBall2[i+1].y, vecBall2[i+1].z);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'a') {
         vecBall.clear();
    }
    
    if (key == 's') {
        vecBall2.clear();
    }
   

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    Ball tempBall;
    ColorBall tempBall2;
    tempBall.setup(x, y, 0, ofRandom(0, 40));
    tempBall2.setup(x, y, 0, ofRandom(0, 40));
    vecBall.push_back(tempBall);
    vecBall2.push_back(tempBall2);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    for (int i =0; i < vecBall.size(); i++) {
        float distance = ofDist(x,y, vecBall[i].x, vecBall[i].y);
        
        if (distance < vecBall[i].dim) {
            vecBall.erase(vecBall.begin()+i);
        }
    }
    
    for (int i =0; i < vecBall2.size(); i++) {
        float distance = ofDist(x,y, vecBall2[i].x, vecBall2[i].y);
        
        if (distance < vecBall2[i].dim) {
            vecBall2.erase(vecBall2.begin()+i);
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
