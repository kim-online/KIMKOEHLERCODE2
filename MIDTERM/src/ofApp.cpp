#include "ofApp.h"
ofShader shader;
//--------------------------------------------------------------
void ofApp::setup(){

    ofEnableAlphaBlending();
    
    shader.load("", "shader.frag");

    wave.setup();
    
    
    ofSetBackgroundAuto(false);
    ofBackground(0);
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    shader.begin();
     
     shader.setUniform1f("u_time", ofGetElapsedTimef());
     shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
     shader.setUniform2f("u_mouse", ofGetMouseX(), ofGetHeight() - ofGetMouseY());
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    wave.draw();
    

     shader.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
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