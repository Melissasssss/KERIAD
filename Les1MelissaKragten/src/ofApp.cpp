#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	x = ofRandom(0, ofGetWidth());
	y = ofRandom(0, ofGetHeight());
	speedX = ofRandom(-10, 10);
	speedY = ofRandom(-10, 10);
	color = RGB(0, 0, 0);
	radius = ofRandom(1,20);

	x2 = ofRandom(0, ofGetWidth());
	y2 = ofRandom(0, ofGetHeight());
	speedX2 = ofRandom(-10, 10);
	speedY2 = ofRandom(-10, 10);
	color2 = RGB(0, 0, 0);
	radius2 = ofRandom(1, 20);
}

//--------------------------------------------------------------
void ofApp::update(){


	if (x <= 0) {
		x = 0;

		speedX = -speedX;
		color = RGB(ofRandom(1, 225), 0, 0);
	}
	else if (x >= ofGetWidth()) {
		x = ofGetWidth();
		speedX = -speedX;
		color = RGB(ofRandom(1, 225), 0, 0);
	}

	if (y <= 0) {
		y = 0;
		speedY = -speedY;
		color = RGB(ofRandom(1, 225), 0, 0);
	}
	else if (y >= ofGetHeight()) {
		y = ofGetHeight();
		speedY = -speedY;
		color = RGB(ofRandom(1, 225), 0, 0);
	}

	x += speedX;
	y += speedY;
	radius = y /50;

	if (x2 <= 0) {
		x2 = 0;

		speedX2 = -speedX2;
		color2 = RGB(ofRandom(1, 225), 0, 0);
	}
	else if (x2 >= ofGetWidth()) {
		x2 = ofGetWidth();
		speedX2 = -speedX2;
		color2 = RGB(ofRandom(1, 225), 0, 0);
	}

	if (y2 <= 0) {
		y2 = 0;
		speedY2 = -speedY2;
		color2 = RGB(ofRandom(1, 225), 0, 0);
	}
	else if (y2 >= ofGetHeight()) {
		y2 = ofGetHeight();
		speedY2 = -speedY2;
		color2 = RGB(ofRandom(1, 225), 0, 0);
	}

	x2 += speedX2;
	y2 += speedY2;
	radius2 = x / 60;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(color);
	ofDrawCircle(x, y, radius);
	ofSetColor(color2);
	ofDrawCircle(x2, y2, radius2);
}

