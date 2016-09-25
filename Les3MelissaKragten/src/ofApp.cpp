#include "ofApp.h"

void ofApp::setup() {
	gui.setup("Instellingen", "settings.xml");
	gui.add(radius.set("Radius", 50, 10, 200));
	gui.add(speedX.set("SpeedX", 10, 0, 100));
	gui.add(speedY.set("SpeedY", 10, 0, 100));
	gui.add(color.set("Color", ofColor::white));


}

void ofApp::update() {
	//ball.update();
	for (unsigned int i = 0; i < balls.size(); i++) {
		balls[i].update();
	}
	// if the value of the slider is different from the
	// value inside the ball, update the ball
	// (so changes in the slider immediately become visible)
	if (radius != ball.radius) {
		ball.radius = radius;
	}
}

void ofApp::draw() {
	gui.draw();
	for (unsigned int i = 0; i < balls.size(); i++) {
		balls[i].draw();
	}
}

void ofApp::keyPressed(int key) {
	if (key == ' ' && balls.size() > 0) {
		balls.pop_back();

		/*all.setup(ofRandom(ofGetWidth()),
		ofRandom(ofGetHeight()),
		radius,
		speedX,
		speedY,
		color);*/
	}
}

void ofApp::mousePressed(int x, int y, int button) {
	Ball newBall;
	newBall.setup(x,
		y,
		speedX,
		speedY,
		radius,
		color);
	balls.push_back(newBall);
}