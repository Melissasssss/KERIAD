#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(220, 0, 50);
	for (int i = 0; i < 10; i++) {
		balls[i].x = ofRandom(0, ofGetWidth());
		balls[i].y = ofRandom(0, ofGetHeight());
		balls[i].speedX = ofRandom(-10, 10);
		balls[i].speedY = ofRandom(-10, 10);
		balls[i].color = (ofColor(ofRandom(50, 255), ofRandom(50, 255), ofRandom(50, 255)));
		balls[i].radius = ofRandom(1, 20);
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < 10; i++) {

		if (balls[i].x <= 0) {
			balls[i].x = 0;

			balls[i].speedX = -balls[i].speedX;
			balls[i].color = (ofColor(ofRandom(50, 255), ofRandom(50, 255), ofRandom(50, 255)));
		}
		else if (balls[i].x >= ofGetWidth()) {
			balls[i].x = ofGetWidth();
			balls[i].speedX = -balls[i].speedX;
			balls[i].color = (ofColor(ofRandom(50, 255), ofRandom(50, 255), ofRandom(50, 255)));
		}

		if (balls[i].y <= 0) {
			balls[i].y = 0;
			balls[i].speedY = -balls[i].speedY;
			balls[i].color = (ofColor(ofRandom(50, 255), ofRandom(50, 255), ofRandom(50, 255)));
		}
		else if (balls[i].y >= ofGetHeight()) {
			balls[i].y = ofGetHeight();
			balls[i].speedY = -balls[i].speedY;
			balls[i].color = (ofColor(ofRandom(50, 255), ofRandom(50, 255), ofRandom(50, 255)));
		}
		//balls[i].speedY += 1;
		balls[i].x += balls[i].speedX;
		balls[i].y += balls[i].speedY;
		balls[i].radius = balls[i].y / 30+20;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < 10; i++) {
		ofSetColor(balls[i].color);
		ofDrawCircle(balls[i].x, balls[i].y, balls[i].radius);
	}
}

