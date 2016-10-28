#include "ofApp.h"
//int for storing the byte data from Arduino.
int byteData;
//--------------------------------------------------------------
void ofApp::setup() {

	//loading all the bin files
	plaatje.load("stijn.jpg");
	geluid.loadSound("fluit.wav");
	kin.load("stijnklein.jpg");
	kin.resize(2880,1620);

	//General setup of look of window.
	ofBackground(255);
	komcheck = 0;
	komtimer = 0;

	//serial port setup. using COM3 for Windows port.
	//Also using baud rate 9600, same in Arduino sketch.
	serial.setup("COM3", 9600);
}
//--------------------------------------------------------------
void ofApp::update() {
	//see if the hand has been close enough
	if (komcheck == 0 && byteData >= 1 && byteData <= 8 && komtimer > 250) {
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
			komtimer+=1;
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
void ofApp::draw() {
	plaatje.draw(0,0);
	if (komcheck == 2) {

		kin.draw(-400, -200);
	}



	//drawing the string version pf byteData on oF window.
	ofDrawBitmapString(msg, 50, 100);
	ofDrawBitmapString(komcheck, 100, 100);
	ofDrawBitmapString(komtimer, 150, 100);
	//printing byteData into console.
	cout << byteData << endl;
}