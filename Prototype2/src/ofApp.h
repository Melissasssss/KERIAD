#pragma once

#include "ofMain.h"

#include "ofxGif.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		string msg;
		float komcheck;
		float komtimer;
		bool soundcheck;
		ofSoundPlayer geluid;
		ofSerial serial;
		
		ofxGIF::fiGifLoader gifloader;
		ofxGIF::fiGifLoader gifloader2;
		int frame;
};
