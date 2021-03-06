#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

public:
	void setup();

	void update();

	void draw();

	void keyPressed(int key);

	void mousePressed(int x, int y, int button);

private:
	vector<Ball> balls;

	ofxPanel gui;
	ofParameter<int> radius;
	ofParameter<int> speedX;
	ofParameter<int> speedY;
	ofParameter<ofColor> colour;
	ofParameter<float> distance;
	ofParameter<float> rotateSpeedX;
	ofParameter<float> rotateSpeedY;
	ofParameter<float> rotateSpeedZ;



	float rotationX;
	float rotationY;
	float rotationZ;


	ofArduino arduino;

	void setupArduino(const int& version);

	void digitalPinChanged(const int& pin);

	void analogPinChanged(const int& pin);

	void addBall();
};
