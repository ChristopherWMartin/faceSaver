#pragma once

#include <ctime>
#include "ofMain.h"
#include "ofxCv.h"
#include "ofxFaceTracker.h"
//#include "ofxFaceTrackerThreaded.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

    int width = 1500;
    int height = 200;

    int gap = 0;
    int faceDistance = 175;

	int x = 0;
	int y = 0;

	ofImage img;
	
	ofVideoGrabber cam;
	ofxFaceTracker tracker;
	//ofxFaceTrackerThreaded tracker;

	ofEasyCam easyCam;
};
