#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    image.load("image.jpg");
    image.resize(1024, 800);
    
    //pick mesh mode
    //    mesh.setMode(OF_PRIMITIVE_POINTS);
    //    mesh.setMode(OF_PRIMITIVE_LINES);
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    
    mesh.enableColors();
    //    mesh.enableIndices();
    //    mesh.enableTextures();
    
    w = image.getWidth();
    h = image.getHeight();
    
    //generate mesh
    intensityThreshold = 0.0;
    
    //    for (int x=0; x<w; ++x) {
    //        for (int y=0; y<h; ++y) {
    //
    //            ofColor c = image.getColor(x, y);
    //
    //            //            float intensity = c.getLightness();
    //            intensity = c.getSaturation();
    //
    //            if (intensity >= intensityThreshold) {
    //
    //                float saturation = c.getSaturation();
    //                float z = ofMap(saturation, 0, 255, -100, 100);
    //                ofVec3f pos(x, y, z);
    //                mesh.addVertex(pos);
    //                mesh.addColor(c);
    //            }
    //
    //        }
    //    }
    
    meshCopy = mesh;
    
    x=1;
    
    gui.setup();
    gui.add(speed.setup("Change Speed", 10.0, 0, 100.0));
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //animate the mesh
    //control changing speed
    intensityThreshold += speed * x;
    
    if(intensityThreshold > 225){
        
        x = -1;
        
    }else if(intensityThreshold <= 0){
        
        x = 1;
        
        //prevent slowing it down
        mesh = meshCopy;
    }
    
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            
            ofColor c = image.getColor(x, y);
            
            //change mode when space key pressed
            if(pressed){
                intensity = c.getLightness();
            }else{
                intensity = c.getSaturation();
            }
            
            if (intensity >= intensityThreshold) {
                
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -100, 100);
                ofVec3f pos(x, y, z);
                mesh.addVertex(pos);
                mesh.addColor(c);
            }
            
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
//    easyCam.begin();
//    ofPushMatrix();
//    ofTranslate(-ofGetWidth()/2, -ofGetWidth()/2);
//    mesh.draw();
//    ofPopMatrix();
    //    easyCam.end();
    
    mesh.draw();
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //toggle modes
    if(key == ' '){
        if(!pressed){
            
            pressed = true;
        }else{
            pressed = false;
        }
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
