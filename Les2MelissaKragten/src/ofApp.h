#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "ofxGui.h"

#define MAXBALLS 160

class ofApp : public ofBaseApp {

    public:
        void setup();

        void update();

        void draw();

		Ball ball[MAXBALLS];

		int amountBalls = 0;

		void keyPressed(int key);

		void mousePressed(int x, int y, int button);

		ofxPanel gui;
		ofParameter<int> radius;
		ofParameter<float> speedX;
		ofParameter<float> speedY;
		ofParameter<ofColor> color;
};
