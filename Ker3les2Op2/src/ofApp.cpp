#include "ofApp.h"

void ofApp::setup() {
	//{"_id":2745912,"name":"Utrecht","country":"NL","coord":{"lon":5.12222,"lat":52.090832}}
	
	ofxJSONElement json;

	string url = "http://api.openweathermap.org/data/2.5/forecast/city?id=2745912&APPID={b462d1e024146c1ea7079de1ef6737d4}";
	//string url = "api.openweathermap.org/data/2.5/weather?id=2745912";
	bool succes = json.open(url);

	if (succes) {
		int temperature = json["main"]["temp"].asInt();
		ofLogNotice("ofApp::setup") << json.getRawString();
	}
	else {
		ofLogNotice("ofApp::setup") << "Failed to parse JSON" << endl;
	}
}

void ofApp::update() {


}

void ofApp::draw() {
	ofBackground(0);

	ofSetHexColor(0x00FF00);

	if (json.isMember("errors"))
	{
		ofDrawBitmapString(json.getRawString(), 10, 14);
	}
	else if (json.isArray())
	{
		const Json::Value& trends = json[0]["trends"];

		for (Json::ArrayIndex i = 0; i < trends.size(); ++i)
		{
			std::string message = trends[i]["query"].asString();
			ofDrawBitmapString(message, 10, 40 * i + 40);
		}
	}
}