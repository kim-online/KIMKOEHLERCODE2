#include "ofApp.h"

// Code influences by Golan Levin, Brannon Dorsey, Daniel Shiffman, Gerardo Bort & Nicole Messier.

//--------------------------------------------------------------
void ofApp::setup(){
    //set false and use transparent rectangle to "eat away" from waves in draw loop instead
    ofSetBackgroundAuto(false);
    ofBackground(25, 25, 25);
    wave1.setup(ofGetHeight());
    wave2.setup(ofGetHeight()+600);
    waveCounter = 0;
    
    
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    
    
    colorImg.allocate(kinect.width, kinect.height);
    greyImg.allocate(kinect.width, kinect.height);
    grayBg.allocate(kinect.width, kinect.height);
    grayDiff.allocate(kinect.width, kinect.height);
    greyThreshFar.allocate(kinect.width, kinect.height);
    greyThreshNear.allocate(kinect.width, kinect.height);
    
    
    bThreshOpenCv = true;
    
    //take a picture of the background as soon as we run the sketch
    bLearnBackground = true;
    
    //set threshold from which we decide how much difference to react to from background picture
    thresholdValue = 80;
    
    //set far and near threshold
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
     
        
        greyThreshNear = greyImg;
        greyThreshFar = greyImg;
        greyThreshNear.threshold(nearThresh);
        greyThreshFar.threshold(farTresh);
        
       

        
        //blends planes into one 3d image yo!
        cvAnd(greyThreshFar.getCvImage(), greyThreshNear.getCvImage(), greyImg.getCvImage());
        
        
        // take a picture of the background , which we compare the difference from later
        if (bLearnBackground == true){
            grayBg = greyImg;
            bLearnBackground = false; // only learn it once.
        }
        
        grayDiff.absDiff(grayBg, greyImg);
        
        // Perform an in-place thresholding of the difference image.
        grayDiff.threshold(thresholdValue);
    }
    
    contourFinder.findContours(grayDiff, 10, (kinect.width*kinect.height)/4, 1, false);
    
    cursors.clear();
    
    for(int i = 0; i < contourFinder.nBlobs; i++){
        //create a point of every center of blob
        ofPoint center = contourFinder.blobs[i].centroid;
        //adjust the placement of the point to the windowsize instead of the kinect window size
        center.x = center.x*2.25;
        center.y = center.y*1.875;
        //push it to vector
        cursors.push_back(center);
    }
    
    if (cursors.size() > 0){
        for(int i = 0; i < cursors.size(); i++){
            //read the distance from last placement of blob to this placement
            float dist = ofDist(last.x, last.y, cursors[i].x, cursors[i].y);
            //if it has moved
            if(dist > 3){
                // wavecounter to decrease the amount of ripples
            if (waveCounter > 20){
                waveCounter = 0;
            }
            if (waveCounter <= 0){
                Ripples tempRipple;							// create the object
                tempRipple.setup();
                tempRipple.setPosition(cursors[i]);         // setup its position based on blob placement
                ripple.push_back(tempRipple);				// add it to the vector
            }
            waveCounter ++;
            //save this placement for next, so we can measure distance
            last = cursors[i];
        }
        }
    }

    // make waves start over
    wave1.update(ofGetHeight()+610);
    wave2.update(ofGetHeight()+610);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //Draw transparent rectangle to give waves shadow/gradient look
    ofSetColor(25, 25, 25, 15);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    wave1.draw();
    wave2.draw();
    
    for (int i = 0 ; i<ripple.size(); i++) {
        ofPushMatrix();
        //this is to calibrate position depending on kinect placement in the room
        ofTranslate(50, -400);
        ripple[i].draw();
        ofPopMatrix();
        //to erase ripples
        if (ripple[i].r2*ripple[i].r2 > ofGetWidth()*ofGetHeight()*2) {
            ripple.erase(ripple.begin()+i);
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
        
    if (waveCounter > 20){
        waveCounter = 0;
    }
    if (waveCounter <= 0){
        Ripples tempRipple;
        tempRipple.setup();
        tempRipple.setPosition(x, y);
        ripple.push_back(tempRipple);
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
