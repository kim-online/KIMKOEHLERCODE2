#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(25, 25, 25);
    wave1.setup(ofGetHeight());
    wave2.setup(ofGetHeight()+600);
    waveCounter = 0;
    
    
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    
    //angle = 15;
    
    colorImg.allocate(kinect.width, kinect.height);
    greyImg.allocate(kinect.width, kinect.height);
    grayBg.allocate(kinect.width, kinect.height);
    grayDiff.allocate(kinect.width, kinect.height);
    greyThreshFar.allocate(kinect.width, kinect.height);
    greyThreshNear.allocate(kinect.width, kinect.height);
    
  /*  colorImg.allocate(ofGetWidth(), ofGetHeight());
    greyImg.allocate(ofGetWidth(), ofGetHeight());
    grayBg.allocate(ofGetWidth(), ofGetHeight());
    grayDiff.allocate(ofGetWidth(), ofGetHeight());
    greyThreshFar.allocate(ofGetWidth(), ofGetHeight());
    greyThreshNear.allocate(ofGetWidth(), ofGetHeight());*/
    
    bThreshOpenCv = true;
    bLearnBackground = true;
    
    thresholdValue = 80;
    
    nearThresh = 0;
    farTresh = 130;
    
    cameraZoom = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    kinect.update();
    kinect.setCameraTiltAngle(angle);
    
    if(kinect.isFrameNew()){
        greyImg.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);
      //  greyImg.setFromPixels(kinect.getDepthPixels(), ofGetWidth(), ofGetHeight());
        
        greyThreshNear = greyImg;
        greyThreshFar = greyImg;
        greyThreshNear.threshold(nearThresh);
        greyThreshFar.threshold(farTresh);
        
       

        
        //blends planes into one 3d image yo!
        cvAnd(greyThreshFar.getCvImage(), greyThreshNear.getCvImage(), greyImg.getCvImage());
        
        if (bLearnBackground == true){
            grayBg = greyImg; // Note: this is 'operator overloading'
            bLearnBackground = false; // Latch: only learn it once.
        }
        
        grayDiff.absDiff(grayBg, greyImg);
        
        // Perform an in-place thresholding of the difference image.
        grayDiff.threshold(thresholdValue);
    }
    
    contourFinder.findContours(grayDiff, 10, (kinect.width*kinect.height)/4, 1, false);
    
    cursors.clear();
    
    for(int i = 0; i < contourFinder.nBlobs; i++){
        ofPoint center = contourFinder.blobs[i].centroid;
        center.x = center.x*2.25;
        center.y = center.y*1.875;
        cursors.push_back(center);
    }
    
    if (cursors.size() > 0){
        for(int i = 0; i < cursors.size(); i++){
            float dist = ofDist(last.x, last.y, cursors[i].x, cursors[i].y);
            if(dist > 3){
            if (waveCounter > 20){
                waveCounter = 0;
            }
            if (waveCounter <= 0){
                Ripples tempRipple;							// create the ball object
                tempRipple.setup();
               // cout << cursors[i] << endl;
                tempRipple.setPosition(cursors[i]);	// setup its initial state
                ripple.push_back(tempRipple);				// add it to the vector
            }
            waveCounter ++;
            last = cursors[i];
        }
        }
    }

    
    wave1.update(ofGetHeight()+610);
    wave2.update(ofGetHeight()+610);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255, 5);
    for(int i = 0; i < 140; i++){
        ofSetLineWidth(0);
        ofDrawRectangle(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()),10,10);
        
    }
    //ofEnableDepthTest();
    ofSetColor(0, 0, 0, 7);
    ofFill();
    //ofTranslate(0, 0, cameraZoom);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    wave1.draw();
    wave2.draw();
    
    for (int i = 0 ; i<ripple.size(); i++) {
        //ofPushMatrix();
        //ofTranslate(100, -200);
        ripple[i].draw();
        //ofPopMatrix();
        if (ripple[i].r2*ripple[i].r2 > ofGetWidth()*ofGetHeight()*2) {
            ripple.erase(ripple.begin()+i); // we need to use an iterator/ reference to the vector position we want to delete
        }
        
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_UP:
            angle ++;
            
            if (angle > 30)
                angle = 30;
            
            break;
            
        case OF_KEY_DOWN:
            angle --;
            
            if(angle<0) angle = 0;
            
            break;
            
        case 'n':
            bLearnBackground = true;
            
            break;
            
        case OF_KEY_LEFT:
            cameraZoom-=10;
            cout << "cameraZoom: " << cameraZoom << endl;
            break;
            
        case OF_KEY_RIGHT:
            cameraZoom+=10;
            cout << "cameraZoom: " << cameraZoom << endl;
            break;
            
        case 'i':
            nearThresh-=10;
            farTresh-=10;
            cout << "Near: " << nearThresh << endl;
            cout << "Far: " << farTresh << endl;
            break;
            
        case 'o':
            nearThresh+=10;
            farTresh+=10;
            cout << "Near: " << nearThresh << endl;
            cout << "Far: " << farTresh << endl;
            break;
            
        case 'y':
            thresholdValue+=10;
            
            cout << "Threshold: " << thresholdValue << endl;
            
            break;
            
        case 'u':
            thresholdValue-=10;
            
            cout << "Threshold: " << thresholdValue << endl;
            
            break;
            
            
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
   /*
    
    if (waveCounter > 100){
        waveCounter = 0;
    }
    if (waveCounter <= 0){
        Ripples tempRipple;							// create the ball object
        tempRipple.setup();
        tempRipple.setPosition(x, y);	// setup its initial state
        ripple.push_back(tempRipple);				// add it to the vector
    }
    waveCounter ++;*/
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
