#pragma once

#include "ofMain.h"
#include <ofxOpenCv.h>
#define HUE_MARGGIN 5

static const int GRABBER_HEIGT = 240;
static const int GRABBER_WITDH = 320;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		ofVideoGrabber grabber;
		ofxCvColorImage rgbImage;
		ofxCvColorImage hsvImage;
		ofxCvGrayscaleImage hue;
		ofxCvGrayscaleImage saturation;
		ofxCvGrayscaleImage brightness;
		ofxCvGrayscaleImage filtered;
		ofxCvContourFinder contours;
		int selectedHue;
		int selectedHue2;
};
