//Musical Stairs by Maria Paula Calderon 
//Using the NewPing library, 6 ultrasonic sensors are used to trigger sounds via a handshake with openFrameworks.

//adding NewPing Library
#include <NewPing.h>

//declaring variables

//sensor 1
#define trigPin  0
#define echoPin  1
//sensor 2
#define trigPin2 2
#define echoPin2 3
//sensor 3
#define trigPin3 4
#define echoPin3 5
//sensor 4
#define trigPin4 14 //6
#define echoPin4 15 //7
//sensor 5
#define trigPin5 6
#define echoPin5 7
//sensor 6
#define trigPin6 10
#define echoPin6 11
//sensor 7 NOT IN USE
#define trigPin7 18
#define echoPin7 19
//sensor 8 NOT IN USE
#define trigPin8 16
#define echoPin8 17
//sensor 9 NOT IN USE
#define trigPin9 20
#define echoPin9 21
//sensor 10 NOT IN USE
#define trigPin10 8
#define echoPin10 9

//maximum reading distance from ultrasonic sensors
#define MAX_DISTANCE 200

int led = 13;
int stairLength = 100;

//declaring arrays for each distance, previous distance, and values for each sensor
float distances[] = {120, 120, 120, 120, 120, 120, 120, 120, 120};
float prevDistances[] = {120, 120, 120, 120, 120, 120, 120, 120, 120};
int vals[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int whichSensor = 0;
float smoothingValue=0.7;//smoothing: lower value makes sensors less sensitive

//toggling between debug and main phase
boolean debug = false;

//setting up pins and maximum distance, one for each sensor
NewPing sonar(trigPin, echoPin, MAX_DISTANCE); 
NewPing sonar2(trigPin2, echoPin2, MAX_DISTANCE);
NewPing sonar3(trigPin3, echoPin3, MAX_DISTANCE);
NewPing sonar4(trigPin4, echoPin4, MAX_DISTANCE);
NewPing sonar5(trigPin5, echoPin5, MAX_DISTANCE);
NewPing sonar6(trigPin6, echoPin6, MAX_DISTANCE);
NewPing sonar7(trigPin7, echoPin7, MAX_DISTANCE);
NewPing sonar8(trigPin8, echoPin8, MAX_DISTANCE);
NewPing sonar9(trigPin9, echoPin9, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  delay(50);// Wait 50ms between pings 
  int val = 0;

  //toggling debug
  if (debug)
    val = '!';
    
  if (Serial.available() > 0) {
    val = Serial.read();
  }
  
  int dist = 0;
  
  //checking triggers for each sensor once openFrameworks is ready
  if (val == '!') {
    //setting previous distance 
    prevDistances[whichSensor] = distances[whichSensor];
    //checking distance value for each sensor and adding smoothing
    switch (whichSensor) {
      case 0:
        dist = sonar.ping_cm();
        if (dist > 5)
          distances[whichSensor] += (dist-prevDistances[whichSensor])*smoothingValue;
        break;
      case 1:
        dist = sonar2.ping_cm();
        if (dist > 5)
          distances[whichSensor] += (dist-prevDistances[whichSensor])*smoothingValue;;
        break;
      case 2:
        dist = sonar3.ping_cm();
        if (dist > 5)
          distances[whichSensor] += (dist-prevDistances[whichSensor])*smoothingValue;;
        break;
      case 3:
        dist = sonar4.ping_cm();
        if (dist > 5)
          distances[whichSensor] += (dist-prevDistances[whichSensor])*smoothingValue;;
        break;
      case 4:
        dist = sonar5.ping_cm();
        if (dist > 5)
          distances[whichSensor] += (dist-prevDistances[whichSensor])*smoothingValue;;
        break;
      case 5:
        dist = sonar6.ping_cm();
        if (dist > 5)
          distances[whichSensor] += (dist-prevDistances[whichSensor])*smoothingValue;;
        break;
      case 6:
        dist = sonar7.ping_cm();
        if (dist > 5)
          distances[whichSensor] += (dist-prevDistances[whichSensor])*smoothingValue;;
        break;
      case 7:
        dist = sonar8.ping_cm();
        if (dist > 5)
          distances[whichSensor] += (dist-prevDistances[whichSensor])*smoothingValue;;
        break;
      case 8:
        dist = sonar9.ping_cm();
        if (dist > 5)
          distances[whichSensor] += (dist-prevDistances[whichSensor])*smoothingValue;;
        break;
    }

    //triggering: send 1 or 0 to openFrameworks to trigger sound
    //sending 1 if the step was previously empty, and someone has now entered the step 
    //sending 0 if this is not the case
    if (distances[whichSensor] < stairLength && prevDistances[whichSensor] > stairLength) {
      vals[whichSensor] = 1;
    } else {
      vals[whichSensor] = 0;
    }

    //only reading the first 6 sensors
    whichSensor = (whichSensor + 1) % 6;

    //debugging
    if (debug) {
      //Serial.println(distances[3]);
      for (int i = 0; i < 9; i++) {
        Serial.print(distances[i]);
        // Serial.print(vals[i]);
        Serial.print(" ");
      }
      Serial.println();
    }
    
    //sending empty value for sensor 10
    int val10 = 0;

    //sending first byte
    unsigned char byteToSend;
    byteToSend = (vals[0] << 7) | (vals[1] << 6) | (vals[2] << 5) | (vals[3] << 4) | (vals[4] << 3) | (vals[5] << 2) | (vals[6] << 1) | (vals[7] & 0x01);

    //sending second byte
    unsigned char byteToSend2;
    byteToSend2 = (vals[8] << 1) | (val10 & 0x01);
    if (!debug) {
      Serial.write(byteToSend);
      Serial.write(byteToSend2);
    }
  }
  Serial.flush();
}
