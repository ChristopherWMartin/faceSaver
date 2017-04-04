#include "ofApp.h"

using namespace ofxCv;

void ofApp::setup() {

    //ofSetWindowTitle("of");
    ofSetVerticalSync(true);
	cam.initGrabber(640, 480);
	tracker.setup();
	ofSetBackgroundAuto(false);

    //width = ofGetWidth();
    //height = ofGetHeight();

}
void ofApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
		tracker.update(toCv(cam));
	}
}

void ofApp::draw() {

	// remove after debugging
	//cam.draw(0, 0);

	if(tracker.getFound()) {

	  	// remove after debugging
	  	// tracker.draw();
		  
        //ofMesh savedMesh = tracker.getMeanObjectMesh();

        ofSetupScreenOrtho(1500, 200, -1000, 1000);
        ofTranslate(150+x, y+90);
        ofScale(4,4,4);
		cam.getTexture().bind();
        tracker.getMeanObjectMesh().draw();
        cam.getTexture().unbind();

        if(x <= width - 350){
            x+=170;
        } else {
            std::time_t result = std::time(nullptr);
            img.grabScreen(0, 0 , width, height);
            img.save(ofToString(result) + ".png");
            x = 0;
        }

	    sleep(1);
	}
		
}
