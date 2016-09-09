#pragma once
#include "ofMain.h"


class BouncyBall : public ofBaseApp {

public:
	x = ofRandom(0, ofGetWidth());
	y = ofRandom(0, ofGetHeight());
	speedX = ofRandom(-10, 10);
	speedY = ofRandom(-10, 10);
	color = RGB(0, 0, 0);
	radius = ofRandom(1, 20);