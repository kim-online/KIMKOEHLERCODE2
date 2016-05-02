#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(25, 25, 25);
    wave1.setup(ofGetHeight());
    wave2.setup(ofGetHeight()+600);
    waveCounter = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    wave1.update(ofGetHeight()+610);
    wave2.update(ofGetHeight()+610);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(25, 25, 25, 10);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    wave1.draw();
    wave2.draw();
    
    for (int i = 0 ; i<ripple.size(); i++) {
        ripple[i].draw();
        
        if (ripple[i].r2*ripple[i].r2 > ofGetWidth()*ofGetHeight()*2) {
            ripple.erase(ripple.begin()+i); // we need to use an iterator/ reference to the vector position we want to delete
        }
        
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    
    if (waveCounter > 100){
        waveCounter = 0;
    }
    if (waveCounter <= 0){
        Ripples tempRipple;							// create the ball object
        tempRipple.setup();
        tempRipple.setPosition(x, y);	// setup its initial state
        ripple.push_back(tempRipple);				// add it to the vector
    }
    waveCounter ++;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
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
