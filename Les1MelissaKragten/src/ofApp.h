#pragma once

#include "ofMain.h"
	
struct Ball {
	float x;
	float y;
	float speedX;
	float speedY;
	int radius;
	ofColor color;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		Ball balls[10];
};
