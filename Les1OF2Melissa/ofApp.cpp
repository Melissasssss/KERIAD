#include "ofApp.h"

void ofApp::setup(){
	grabber.setup(GRABBER_WITDH,GRABBER_HEIGT,true);
	rgbImage.allocate(GRABBER_WITDH, GRABBER_HEIGT);

	hsvImage.allocate(GRABBER_WITDH, GRABBER_HEIGT);
	brightness.allocate(GRABBER_WITDH, GRABBER_HEIGT);
	saturation.allocate(GRABBER_WITDH, GRABBER_HEIGT);
	hue.allocate(GRABBER_WITDH, GRABBER_HEIGT);
	filtered.allocate(GRABBER_WITDH, GRABBER_HEIGT);;
}


void ofApp::update(){
	grabber.update();
	if (grabber.isFrameNew()) {
		rgbImage.setFromPixels(grabber.getPixels().getData(), GRABBER_WITDH, GRABBER_HEIGT);
		rgbImage.mirror(false, true);

		hsvImage = rgbImage;
		hsvImage.convertRgbToHsv();
		hsvImage.convertToGrayscalePlanarImages(hue, saturation, brightness);
		for (int i = 0; i < GRABBER_WITDH*GRABBER_HEIGT; i++) {
			if (ofInRange(hue.getPixels()[i], selectedHue - HUE_MARGGIN, selectedHue +HUE_MARGGIN) || ofInRange(hue.getPixels()[i], selectedHue2 - HUE_MARGGIN, selectedHue2 + HUE_MARGGIN)) {
				filtered.getPixels()[i] = 255;
			}
			else {
				filtered.getPixels()[i] = 0;
			}
		}
		filtered.flagImageChanged();
	}
}

void ofApp::draw(){
	rgbImage.draw(640,0);
	hsvImage.draw(0, 0);
	hue.draw(0, 240);
	saturation.draw(320, 320);
	brightness.draw(640, 240);
	filtered.draw(0,480);

}


void ofApp::keyPressed(int key){

}



void ofApp::mousePressed(int x, int y, int button) {
	if (button == 0) {
		selectedHue = hue.getPixels()[y * GRABBER_WITDH + x];
		ofLog() << "Selected: " << selectedHue << endl;
	}
	if (button == 2) {
		selectedHue2 = hue.getPixels()[y * GRABBER_WITDH + x];
		ofLog() << "Selected: " << selectedHue2 << endl;
	}
}

