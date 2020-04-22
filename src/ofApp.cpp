#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	sound0.load("wind1.wav");
	sound1.load("D4 - Wah Tine.wav");
	sound2.load("E4 - Wah Tine.wav");
	sound3.load("F#4 - Wah Tine.wav");
	sound4.load("A4 - Wah Tine.wav");
	sound5.load("B4 - Wah Tine.wav");
	sound6.load("C#5 - Wah Tine.wav");

	ofSetBackgroundColor(ofColor::aliceBlue);

	gui.setup();
	gui.add(volume.set("volume", 0.5, 0.0, 1.0));
	gui.add(decay.set("decay", 0.5, 0.0, 1.0));

	fft = new float[128];
	for (int i = 0; i < 128; i++) {
		fft[i] = 0;

	}

	bands = 64;
}

//--------------------------------------------------------------
void ofApp::update(){

	x = ofRandom(0, 600);
	y = ofRandom(0, 600);
	ofSoundUpdate();

	sound1.setVolume(volume);
	sound2.setVolume(volume);
	sound3.setVolume(volume);
	sound4.setVolume(volume);
	sound5.setVolume(volume);
	sound6.setVolume(volume);

	soundSpectrum = ofSoundGetSpectrum(bands);
	for (int i = 0; i < bands; i++)
	{
		fft[i] *= decay;
		if (fft[i] < soundSpectrum[i])
		{
			fft[i] = soundSpectrum[i];

		}

	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(ofColor::black);
	ofDrawBitmapString("Press '0' key to generate wind!", 100, 100);
	gui.draw();

	if (sound1.isPlaying()) {


		for (int i = 0; i < bands; i++)
		{
			ofSetColor(ofColor::lightBlue);
			ofDrawCircle(200, ofGetHeight() / 2, fft[i] * 100);
		}
	}

	if (sound2.isPlaying()) {
		for (int i = 0; i < bands; i++)
		{
			ofSetColor(ofColor::aquamarine);
			ofDrawCircle(300, ofGetHeight() / 2, fft[i] * 100);
		}
	}

	if (sound3.isPlaying()) {
		for (int i = 0; i < bands; i++)
		{
			ofSetColor(ofColor::mediumAquaMarine);
			ofDrawCircle(400, ofGetHeight() / 2, fft[i] * 100);
		}
	}

	if (sound4.isPlaying()) {
		for (int i = 0; i < bands; i++)
		{
			ofSetColor(ofColor::mediumBlue);
			ofDrawCircle(500, ofGetHeight() / 2, fft[i] * 100);
		}
	}

	if (sound5.isPlaying()) {
		for (int i = 0; i < bands; i++)
		{
			ofSetColor(ofColor::cadetBlue);
			ofDrawCircle(600, ofGetHeight() / 2, fft[i] * 100);
		}
	}

	if (sound6.isPlaying()) {
		for (int i = 0; i < bands; i++)
		{
			ofSetColor(ofColor::darkBlue);
			ofDrawCircle(700, ofGetHeight() / 2, fft[i] * 100);
		}
	}


}
void ofApp::playChimes() {

	int a = 0;

	sound0.play();
	for (int i = 0; i < 15; i++)
	{

		int R = ofRandom(0, 7);
		if (a == R)
			continue;
		a = R;
		Sleep(500);


		if (R == 1)
			sound1.play();
		if (R == 2)
			sound2.play();
		if (R == 3)
			sound3.play();
		if (R == 4)
			sound4.play();
		if (R == 5)
			sound5.play();
		if (R == 6)
			sound6.play();

	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	switch (key) {
	case 'f':
		ofToggleFullscreen();
		break;
	}

	switch (key) {
	case '0':
		playChimes();
		break;


	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
