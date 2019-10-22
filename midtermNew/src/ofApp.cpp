#include "ofApp.h"

//-------------------------------------------------    -------------
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

    //automatic loading sound
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
    
    //manually loading sound: pentatonic scale
    //guitar
    sounds[0].load("sounds/guitar/7.mp3");
    sounds[1].load("sounds/guitar/6.mp3");
    sounds[2].load("sounds/guitar/4.mp3");
    sounds[3].load("sounds/guitar/3.mp3");
    sounds[4].load("sounds/guitar/2.mp3");
    sounds[5].load("sounds/guitar/0.mp3");
    //sounds[6].load("sounds/guitar/6.mp3");
    //sounds[7].load("sounds/guitar/4.mp3");
    //sounds[8].load("sounds/guitar/8.mp3");
    //sounds[9].load("sounds/guitar/9.mp3");
    
    //percussion
    //sounds[0].load("sounds/rhythm/0.mp3");
    //sounds[1].load("sounds/rhythm/1.mp3");
    //sounds[2].load("sounds/rhythm/2.mp3");
    //sounds[3].load("sounds/rhythm/0.mp3");
    //sounds[4].load("sounds/rhythm/1.mp3");
    //sounds[5].load("sounds/rhythm/2.mp3");
    //sounds[6].load("sounds/rhythm/0.mp3");
    //sounds[7].load("sounds/rhythm/1.mp3");
    //sounds[8].load("sounds/rhythm/2.mp3");
    // sounds[9].load("sounds/rhythm/0.mp3");

    //serial setup
    nBytesRead = 0;
    memset(onOff, 0, numSensors);
    memset(inByte, 0, 2);
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
    //read 2 bytes
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
        onOff[0] = inByte[0] >> 7 & 0x01;
        onOff[1] = inByte[0] >> 6 & 0x01;
        onOff[2] = inByte[0] >> 5 & 0x01;
        onOff[3] = inByte[0] >> 4 & 0x01;
        onOff[4] = inByte[0] >> 3 & 0x01;
        onOff[5] = inByte[0] >> 2 & 0x01;
        onOff[6] = inByte[0] >> 1 & 0x01;
        onOff[7] = inByte[0] & 0x01; // mask for just the right most bit

        //SECOND BYTE
        onOff[8] = inByte[1] >> 1 & 0x01; //bitshift left one spot
        onOff[9] = inByte[1] & 0x01; //bitshift left 2 spots

        // tell arduino we're ready for some more info
        bSendSerialMessage = true;
    }

    ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw() {
    //playing sound from sensor readings
    //debugging
    for (auto o : onOff)
        cout << o <<" ";
    cout << endl;
    
    //SONAR 1
    if (onOff[0] == 1 && section1Trigger == false) {
        section1Trigger = true;
        sounds[0].play();
        section1Timer = ofGetElapsedTimeMillis() + 1000; //1 second, change this number according to how short the audio file is
    }

    if (sounds[0].isPlaying() == false && ofGetElapsedTimeMillis() > section1Timer) {
        section1Trigger = false;
    }

    //SONAR 2
    if (onOff[1] == 1 && section2Trigger == false) {
        section2Trigger = true;
        sounds[1].play();
        section2Timer = ofGetElapsedTimeMillis() + 1000; //1 second, change this number according to how short the audio file is
    }

    if (sounds[1].isPlaying() == false && ofGetElapsedTimeMillis() > section2Timer) {
        section2Trigger = false;
    }
    
    //SONAR 3
    if (onOff[2] == 1 && section3Trigger == false) {
        section3Trigger = true;
        sounds[2].play();
        section3Timer = ofGetElapsedTimeMillis() + 1000;
    }

    if (sounds[2].isPlaying() == false && ofGetElapsedTimeMillis() > section3Timer) {
        section3Trigger = false;
    }

    //SONAR 4
    if (onOff[3] == 1 && section4Trigger == false) {
        section4Trigger = true;
        sounds[3].play();
        section4Timer = ofGetElapsedTimeMillis() + 1000;
    }

    if (sounds[3].isPlaying() == false && ofGetElapsedTimeMillis() > section4Timer) {
        section4Trigger = false;
    }
    
    //SONAR 5
    if (onOff[4] == 1 && section5Trigger == false) {
        section5Trigger = true;
        sounds[4].play();
        section5Timer = ofGetElapsedTimeMillis() + 1000;
    }

    if (sounds[4].isPlaying() == false && ofGetElapsedTimeMillis() > section5Timer) {
        section5Trigger = false;
    }
    
    //SONAR 6
    if (onOff[5] == 1 && section6Trigger == false) {
        section6Trigger = true;
        sounds[5].play();
        section6Timer = ofGetElapsedTimeMillis() + 1000;
    }

    if (sounds[5].isPlaying() == false && ofGetElapsedTimeMillis() > section6Timer) {
        section6Trigger = false;
    }
    
    //SONAR 7
    if (onOff[6] == 1 && section7Trigger == false) {
        section7Trigger = true;
        sounds[6].play();
        section7Timer = ofGetElapsedTimeMillis() + 1000;
    }

    if (sounds[6].isPlaying() == false && ofGetElapsedTimeMillis() > section7Timer) {
        section7Trigger = false;
    }
    
    //SONAR 8
    if (onOff[7] == 1 && section8Trigger == false) {
        section8Trigger = true;
        sounds[7].play();
        section8Timer = ofGetElapsedTimeMillis() + 1000;
    }

    if (sounds[7].isPlaying() == false && ofGetElapsedTimeMillis() > section8Timer) {
        section8Trigger = false;
    }
    
    //SONAR 9
    if (onOff[8] == 1 && section9Trigger == false) {
        section9Trigger = true;
        sounds[8].play();
        section9Timer = ofGetElapsedTimeMillis() + 1000;
    }

    if (sounds[8].isPlaying() == false && ofGetElapsedTimeMillis() > section9Timer) {
        section9Trigger = false;
    }
    ofBackground(0);
    ofSetColor(255, 50);
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
