#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

	private:
		float x;
		float y;
		float speedX;
		float speedY;
		int radius;
		ofColor color;

		float x2;
		float y2;
		float speedX2;
		float speedY2;
		int radius2;
		ofColor color2;
};
