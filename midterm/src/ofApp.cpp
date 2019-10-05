#include "ofApp.h"

//-------------------------------------------------	-------------
void ofApp::setup() {
	//set number of sounds/sensors
	numSensors = 10;
	ofSetVerticalSync(true);

	bSendSerialMessage = true;
	ofBackground(255);

	serial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();

	int baud = 9600;
	serial.setup(0, baud); //open the first device
	//serial.setup("COM4", baud); // windows example

	//sound
	for (int i = 0; i < numSensors; i++) {
		string filename = "sounds/cello";
		filename += ofToString(i);
		filename += ".mp3"; //CHANGE EXTENSION!
		cout << filename << endl;
		cout << i << endl;
		sounds[i].load(filename);
		sounds[i].setMultiPlay(false);
		sounds[i].play();
	}

	//manual sound load
	//sounds[0].load("sounds/khoisan0.wav");
	//sounds[1].load("sounds/khoisan1.wav");
	//sounds[2].load("sounds/khoisan2.wav");
	//sounds[3].load("sounds/khoisan0.wav");
	//sounds[4].load("sounds/khoisan1.wav");
	//sounds[5].load("sounds/khoisan2.wav");
	//sounds[6].load("sounds/khoisan0.wav");
	//sounds[7].load("sounds/khoisan1.wav");
	//sounds[8].load("sounds/khoisan2.wav");
	//sounds[9].load("sounds/khoisan0.wav");

	//for (int i = 0; i < numSensors; i++) {
	//	sounds[i].play(); 
	//}

	//serial setup
	nBytesRead = 0;
	memset(onOff, 0, numSensors);
}

//--------------------------------------------------------------
void ofApp::update() {
	// (1) write the letter "!" to serial -
	// this will tell the arduino we ready to get data:
	if (bSendSerialMessage) {
		serial.writeByte('!');
		bSendSerialMessage = false;
	}

	// (2) read
	// we try to read 2 bytes

	// clear our variables
	nBytesRead = 0;
	int nRead = 0;  // a temp variable to keep count per read
	memset(inByte, 0, 2);

	// we read as much as possible so we make sure we get the newest data
	while ((nRead = serial.readBytes(inByte, 2)) > 0) {
		nBytesRead = nRead;
	};

	//if we have got everything
	if (nBytesRead == 2) { 
		// turn our byte back into two int's
		//FIRST BYTE
		onOff[0] = inByte[0] >> 1; //bitshift left one spot
		onOff[1] = inByte[0] >> 2; //bitshift left 2 spots
		onOff[2] = inByte[0] >> 3;
		onOff[3] = inByte[0] >> 4;
		onOff[4] = inByte[0] >> 5;
		onOff[5] = inByte[0] >> 6;
		onOff[6] = inByte[0] >> 7;
		onOff[7] = inByte[0] & 0x01; // mask for just the right most bit

		//SECOND BYTE
		onOff[8] = inByte[1] >> 1; //bitshift left one spot
		onOff[9] = inByte[1] & 0x01; //bitshift left 2 spots

		// tell arduino we're ready for some more info
		bSendSerialMessage = true;
	}

	ofSoundUpdate(); //UPDATE SOUND PLAYING SYSTEM, TAKE OUT IF IT DOESN'T WORK!
}

//--------------------------------------------------------------
void ofApp::draw() {
	//trigger sound: only after the value goes back to 112cm (standard)
	//playing sound from sensor readings
	//making sure sound doesn't continuously play when sensor is continuously triggered (MAKE FOR LOOP!!!)
	//something faulty with this code: makes sensor continuously trigger???
	if (onOff[0] == 1 && section1Trigger == false) {
		section1Trigger = true;
		sounds[0].play();
		section1Timer = ofGetElapsedTimeMillis() + 1000; //1 second, change this number according to how short the audio file is
	}

	if (sounds[0].isPlaying() == false && ofGetElapsedTimeMillis() > section1Timer) {
		section1Trigger = false;
	}

	if (onOff[1] == 1 && section2Trigger == false) {
		section2Trigger = true;
		sounds[1].play();
		section2Timer = ofGetElapsedTimeMillis() + 1000; //1 second, change this number according to how short the audio file is
	}

	if (sounds[1].isPlaying() == false && ofGetElapsedTimeMillis() > section2Timer) {
		section2Trigger = false;
	}

	//if (onOff[0] == 1 && !sounds[0].isPlaying()) {
	//	sounds[0].play();
	//}

	//if (onOff[1] == 1 && !sounds[1].isPlaying()) {
	//	sounds[1].play();
	//}

	if (onOff[2] == 1 && !sounds[2].isPlaying()) {
		sounds[2].play();
	}

	if (onOff[3] == 1 && !sounds[3].isPlaying()) {
		sounds[3].play();
	}

	if (onOff[4] == 1 && !sounds[4].isPlaying()) {
		sounds[4].play();
	}

	if (onOff[5] == 1 && !sounds[5].isPlaying()) {
		sounds[5].play();
	}

	if (onOff[6] == 1 && !sounds[6].isPlaying()) {
		sounds[6].play();
	}

	if (onOff[7] == 1 && !sounds[7].isPlaying()) {
		sounds[7].play();
	}

	if (onOff[8] == 1 && !sounds[8].isPlaying()) {
		sounds[8].play();
	}

	if (onOff[9] == 1 && !sounds[9].isPlaying()) {
		sounds[9].play();
	}

	ofBackground(0);
	ofSetColor(255, 50);
	//   string msg = "Tigger 1: " + ofToString(onOff[0]);
	//   msg += "Tigger 2: " + ofToString(onOff[1]);
	   //msg += "Tigger 3: " + ofToString(onOff[2]);
	   //font.drawString(msg, 50, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
