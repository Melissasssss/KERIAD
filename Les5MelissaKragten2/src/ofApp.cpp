#include "ofApp.h"

#define PIN_BUTTON 11
#define PIN_POTMETER 1
#define PIN_LDR 0

void ofApp::setup() {
	ofSetFrameRate(60);

	ofBackground(30, 30, 30);

	drawGrid = false;

	planet01.setup("planet 1");
	planetParams.add(planet01.planetParamGroup);

	planet02.setup("planet 2");
	planetParams.add(planet02.planetParamGroup);

	planet03.setup("planet 3");
	planetParams.add(planet03.planetParamGroup);

	gui.setup(planetParams);
	gui.add(drawLight.set("Light", false));
	gui.add(drawGrid.set("Grid", false));
	gui.add(useLight.set("Use lighting", true));

	light.setDirectional();
	light.setPosition(-200, -200, -200);
	light.lookAt(ofVec3f(0, 0, 0), ofVec3f(0, 0, 0));
	light.setDiffuseColor(ofColor(255, 255, 255));
	light.enable();

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
	arduino.connect("/COM3");
	arduino.sendFirmwareVersionRequest();

	ofSetLogLevel(OF_LOG_NOTICE);
}

void ofApp::update() {
	arduino.update();
	for (unsigned int i = 0; i < planets.size(); i++) {
		planets[i].update();
	}

	planet01.update();
	planet02.update();
	planet03.update();
}

void ofApp::draw() {
	gui.draw();



	if (useLight) {
		ofEnableLighting();
	}
	else {
		ofDisableLighting();
	}

	ofEnableDepthTest();
	cam.begin();
	for (unsigned int i = 0; i < planets.size(); i++) {
		ofTranslate(planet01.distance, 0);
		planets[i].draw();
	}

	if (drawLight) light.draw();
	if (drawGrid) ofDrawGrid(200);

	planet01.draw();

	ofTranslate(planet01.distance, 0);
	planet02.draw();

	ofTranslate(planet02.distance, 0);
	planet03.draw();

	cam.end();
	ofDisableDepthTest();
}

void ofApp::keyPressed(int key) {
	if (key == 'g') {
		drawGrid = !drawGrid;
	}
	else if (key == 'l') {
		drawLight = !drawLight;
	}
	else if (key == 'k') {
		useLight = !useLight;
	}
	else if (key == ' ') {
		ofTranslate(planet01.distance, 0);
		addPlanet();
	}

}

void ofApp::mousePressed(int x, int y, int button) {
	if (planets.size() > 0) {
		planets.pop_back();
	}
}

void ofApp::addPlanet() {
	Planet newPlanet;
	newPlanet.setup("name");
	newPlanet.rotateSpeed = 2;
	newPlanet.distance = 20;
	planetParams.add(newPlanet.planetParamGroup);
	planets.push_back(newPlanet);
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
		addPlanet();
	}
}

void ofApp::analogPinChanged(const int& pin) {
	int value = arduino.getAnalog(pin);
	ofLogVerbose() << "Analog pin" << pin << " changed to " << value << endl;
	if (pin == PIN_POTMETER) {
		planet01.distance = ofMap(value, 0, 1024, planet01.distance.getMin(), planet01.distance.getMax());
	}
}