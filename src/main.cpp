#include "ofApp.h"
#include "ofAppGlutWindow.h"

int main() {
	ofAppGlutWindow window;
    ofSetupOpenGL(&window, 1500, 200, OF_WINDOW);
	ofRunApp(new ofApp());
}
