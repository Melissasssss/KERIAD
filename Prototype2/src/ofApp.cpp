#include "ofApp.h"

int index = 0;
int byteData;
//--------------------------------------------------------------
void ofApp::setup(){
	gifloader.load("stijngif.gif");
	gifloader2.load("stijnkleingif.gif");
	geluid.loadSound("Hallo.wav");
	frame = 0;
	komcheck = 0;
	komtimer = 0;

	serial.setup("COM3", 9600);

}

//--------------------------------------------------------------
void ofApp::update(){
	if (ofGetFrameNum() % 25 == 0) {
		frame++;
		if (frame == gifloader.pages.size()) frame = 0;
	}


	//see if the hand has been close enough
	if (komcheck == 0 && byteData >= 1 && byteData <= 8 && komtimer > 110) {
		komcheck = 1;

	}
	//see if the hand is getting further away, if so 
	if (komcheck == 1 && byteData > 22) {
		komcheck = 2;

		//if statement so that the file will only play once
		if (soundcheck == FALSE) {
			geluid.play();
			soundcheck == TRUE;
		}
	}
	//if statement that puts the picture back and turns the soundcheck off
	if (komcheck == 2 && byteData >= 1 && byteData <= 8) {
		komcheck = 0;
		//soundcheck = FALSE;
		komtimer = 0;

	}
	//puts the timer in motion
	if (komcheck == 0) {
		komtimer += 1;
	}


	//if statement to inform user if Arduino is sending serial messages. 
	if (serial.available() < 0) {
		msg = "Arduino Error";
	}
	else {
		//While statement looping through serial messages when serial is being provided.
		while (serial.available() > 0) {
			//byte data is being writen into byteData as int.
			byteData = serial.readByte();

			//byteData is converted into a string for drawing later.
			msg = "cm: " + ofToString(byteData);
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	ofImage img = gifloader.pages[frame];
	ofPixels pix = img.getPixels();
	img.setFromPixels(pix);
	img.draw(0, 0);

	if (komcheck == 2) {
		ofImage img2 = gifloader2.pages[frame];
		ofPixels pix2 = img2.getPixels();
		img2.setFromPixels(pix2);
		img2.draw(0, 0);
	}
	//drawing the string version pf byteData on oF window.
	ofDrawBitmapString(msg, 50, 100);
	ofDrawBitmapString(komcheck, 100, 100);
	ofDrawBitmapString(komtimer, 150, 100);
	//printing byteData into console.
	cout << byteData << endl;
}