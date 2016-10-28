#pragma once

#include "ofMain.h"
class ofApp : public ofBaseApp {
public:
	//Standard oF functions.
	void setup();
	void update();
	void draw();
	ofImage plaatje;
	ofImage kin;
	ofSoundPlayer geluid;
	//Custom variables for on screen string and font.
	string msg;
	float komcheck;
	float komtimer;
	ofTrueTypeFont font;
	//New serial object.
	ofSerial serial;
	bool soundcheck;
};