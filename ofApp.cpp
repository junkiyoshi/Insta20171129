#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofNoFill();
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	float radius = 100;
	float tmp_deg;
	ofColor line_color;

	for (int deg = 0; deg < 360; deg += 10) {
		tmp_deg = deg;
		line_color.setHsb(deg / 360.f * 255, 255, 255);
		ofSetColor(line_color);

	
		ofBeginShape();
		for (int z = -300; z <= 300; z += 10) {
			tmp_deg += ofMap(ofNoise(ofGetFrameNum() * 0.025 + z * 0.005), 0, 1, -5, 5);
			ofVertex(ofVec3f(radius * cos(tmp_deg * DEG_TO_RAD), radius * sin(tmp_deg * DEG_TO_RAD), z));

			if (z == 300 || z == -300) {
				ofDrawSphere(ofVec3f(radius * cos(tmp_deg * DEG_TO_RAD), radius * sin(tmp_deg * DEG_TO_RAD), z), 5);
			}
		}
		ofEndShape(false);

	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
