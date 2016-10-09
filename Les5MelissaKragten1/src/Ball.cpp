#include "Ball.h"

Ball::Ball() {

}

void Ball::setup(int mySpeedX, int mySpeedY, int myRadius, ofColor myColour, float myDistance, float myrotationSpeedX, float myrotationSpeedY, float myrotationSpeedZ, float myRotationX, float myRotationY, float myRotationZ)
{
	x = ofRandom(0, ofGetWidth());        // give some random position
	y = ofRandom(0, ofGetHeight());

	speedX = mySpeedX;           // and random speed and direction
	speedY = mySpeedY;

	radius = myRadius;

	color = myColour;
	distance = myDistance;

	rotateSpeedX = myrotationSpeedX;
	rotateSpeedY = myrotationSpeedY;
	rotateSpeedZ = myrotationSpeedZ;
	rotationX = myRotationX;
	rotationY = myRotationY;
	rotationZ = myRotationZ;

}


void Ball::update() {
	if (x < 0) {
		x = 0;
		speedX *= -1;
	}
	else if (x > ofGetWidth()) {
		x = ofGetWidth();
		speedX *= -1;
	}

	if (y < 0) {
		y = 0;
		speedY *= -1;
	}
	else if (y > ofGetHeight()) {
		y = ofGetHeight();
		speedY *= -1;
	}

	x += speedX;
	y += speedY;

	rotationX += rotateSpeedX;
	rotationY += rotateSpeedY;
	rotationZ += rotateSpeedZ;

}

void Ball::draw() {
	ofSetColor(color);
	ofRotateX(rotationX);
	ofRotateY(rotationY);
	ofRotateZ(rotationZ);
	ofDrawCircle(x, y, radius);






}