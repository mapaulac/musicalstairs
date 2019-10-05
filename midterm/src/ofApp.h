#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofTrueTypeFont		font;

	bool                bSendSerialMessage;			// a flag for sending serial
	unsigned char		inByte[2];				// data from serial, we will be trying to read 2
	int                 nBytesRead;					// how much did we read?
	int                 onOff[10];

	int numSensors;
	ofSoundPlayer sounds[10];
	long section1Timer, section2Timer, section3Timer, section4Timer, section5Timer, section6Timer, section7Timer, section8Timer, section9Timer, section10Timer;
	bool section1Trigger, section2Trigger, section3Trigger, section4Trigger, section5Trigger, section6Trigger, section7Trigger, section8Trigger, section9Trigger, section10Trigger;

	ofSerial            serial;
};