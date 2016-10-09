#pragma once

#include "ofMain.h"

class Ball {

public:

	Ball();

	void setup(int mySpeedX, int mySpeedY, int myRadius, ofColor myColour, float myDistance, float myrotationSpeedX, float myrotationSpeedY, float myrotationSpeedZ, float myRotationX, float myRotationY, float myRotationZ);

	void update();

	void draw();

	// variables
	float x;
	float y;
	float speedY;
	float speedX;
	int radius;
	ofColor color;
	float distance;




	float rotateSpeedX;
	float rotateSpeedY;
	float rotateSpeedZ;

	float rotationX;
	float rotationY;
	float rotationZ;


private:

};