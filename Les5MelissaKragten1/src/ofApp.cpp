#include "ofApp.h"

#define PIN_BUTTON 11
#define PIN_POTMETER 1
#define PIN_LDR 0

void ofApp::setup() {
	gui.setup("Instellingen", "settings.xml");
	gui.add(radius.set("Radius", 50, 10, 200));
	gui.add(speedX.set("SpeedX", 0, 0, 30));
	gui.add(speedY.set("SpeedY", 0, 0, 30));
	gui.add(distance.set("distance", 0, 0, 30));
	gui.add(rotateSpeedX.set("Rotationx", 0, 0, 30));
	gui.add(rotateSpeedY.set("Rotationy", 0, 0, 30));
	gui.add(rotateSpeedZ.set("Rotationz", 0, 0, 30));
	gui.add(colour.set("Colour", ofColor::blue));

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.connect("/dev/arduino");
	arduino.sendFirmwareVersionRequest();

	ofSetLogLevel(OF_LOG_NOTICE);
	//    ofSetLogLevel(OF_LOG_VERBOSE);
}

void ofApp::update() {
	arduino.update();
	for (unsigned int i = 0; i < balls.size(); i++) {
		balls[i].update();
	}
}

void ofApp::draw() {
	gui.draw();

	for (unsigned int i = 0; i < balls.size(); i++) {
		balls[i].draw();
	}
}

void ofApp::keyPressed(int key) {
	addBall();
}

void ofApp::addBall() {
	Ball newBall;
	newBall.setup(speedX, speedY, radius, colour, distance, rotateSpeedX, rotateSpeedY, rotateSpeedZ, rotationX, rotationY, rotationZ);
	balls.push_back(newBall);
}

void ofApp::mousePressed(int x, int y, int button) {
	if (balls.size() > 0) {
		balls.pop_back();
	}
}

void ofApp::setupArduino(const int& version) {
	ofLogNotice() << "Arduino initialized" << endl;
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	arduino.sendDigitalPinMode(PIN_BUTTON, ARD_INPUT);
	arduino.sendAnalogPinReporting(PIN_POTMETER, ARD_ANALOG);
	arduino.sendAnalogPinReporting(PIN_LDR, ARD_ANALOG);

	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pin) {
	int value = arduino.getDigital(pin);
	ofLogVerbose() << "Digital pin" << pin << " changed to " << value << endl;
	if (pin == PIN_BUTTON && value == 1) {
		addBall();
	}
}

void ofApp::analogPinChanged(const int& pin) {
	int value = arduino.getAnalog(pin);
	ofLogVerbose() << "Analog pin" << pin << " changed to " << value << endl;
	if (pin == PIN_POTMETER) {
		radius = ofMap(value, 0, 1024, radius.getMin(), radius.getMax());
	}
	else if (pin == PIN_LDR) {
		float colorHue = ofMap(value, 0, 1025, 0, 255);
		ofLogVerbose() << "hue: " << colorHue << endl;
		ofColor newColour = ofColor(colour.get());
		newColour.setHue(colorHue);
		colour = newColour;
	}
}