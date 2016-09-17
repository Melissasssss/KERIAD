#include "ofApp.h"
#include "Ball.h"

//Ball ball;


void ofApp::setup() {
    //ball.setup();

	for (int i = 0; i < CLAMP(amountBalls, 0, MAXBALLS); i++) {
		ball[i].setup();
	} 
	gui.setup("Instellingen", "settings.xml");
	gui.add(radius.set("Radius", 50, 0, 200));
	gui.add(speedX.set("SpeedX", 20, 0, 200));
	gui.add(speedY.set("SpeedY", 20, 0, 200));
	gui.add(color.set("Color", ofColor::white));

}

void ofApp::update() {
    //ball.update();

	for (int i = 0; i < CLAMP(amountBalls, 0, MAXBALLS); i++) {
		ball[i].update();
	}
}

void ofApp::draw() {
	for (int i = 0; i < CLAMP(amountBalls, 0, MAXBALLS); i++) {
		ofSetColor(color);
		ball[i].draw();
	}

		ofCircle(speedX, speedY, radius);
	//ball.draw();
	gui.draw();
}


void ofApp::keyPressed(int key) {
	if (key == ' ') {
		if (amountBalls > 0)
		{
			amountBalls -= 1;
			ball[amountBalls].setup();
		}
	}
	else if (key == OF_KEY_RETURN) {

	}
}

void ofApp::mousePressed(int x, int y, int button) {
	if (amountBalls < MAXBALLS)
	{ 
		amountBalls += 1;
		ball[amountBalls-1].setup();
		ball[amountBalls-1].radius = radius;
		ball[amountBalls-1].speedX = speedX;
		ball[amountBalls-1].speedY = speedY;
		ball[amountBalls-1].color = color;
	}
}