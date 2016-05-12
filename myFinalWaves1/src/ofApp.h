#pragma once

#include "ofMain.h"
#include "Wave.hpp"
#include "Vertex.hpp"
#include "Ripples.hpp"
#include "ofxOpenCv.h"
#include "ofxKinect.h"


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    Wave wave1;
    Wave wave2;
    Wave wave3;
    
    vector <Ripples> ripple;
    int waveCounter;
    
    ofxKinect kinect;
    int angle;
    ofxCvColorImage colorImg;
    ofxCvGrayscaleImage greyImg;
    ofxCvGrayscaleImage grayBg;
    ofxCvGrayscaleImage grayDiff;
    ofxCvGrayscaleImage greyThreshNear;
    ofxCvGrayscaleImage greyThreshFar;
    
    ofxCvContourFinder contourFinder;
    
    bool bThreshOpenCv;
    int nearThresh;
    int farTresh;
    vector <ofPoint> cursors;
    
    int thresholdValue;
    bool bLearnBackground;
    
    float cameraZoom;
    ofPoint last;
    
  //  ofxPanel gui;
  //  ofxIntSlider treshHoldNear;
  //  ofxIntSlider treshHoldFar;

    
    
    
};
