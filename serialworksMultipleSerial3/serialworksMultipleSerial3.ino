#include <NewPing.h>

//sensor 1 
#define trigPin  0
#define echoPin  1
//int led1 = 13; 
int distance1;
//sensor 2
#define trigPin2 2
#define echoPin2 3 
//int led2 = 1;
int distance2;
//sensor 3 
#define trigPin3 4
#define echoPin3 5
int led3 = 8; 
int distance3;

//sensor 4 
#define trigPin4 6
#define echoPin4 7
//int led4 = 11;
int distance4;

//sensor 5
#define trigPin5 8
#define echoPin5 9
int led5 = 18;
int distance5;

//sensor 6
#define trigPin6 10
#define echoPin6 11
int led6 = 19;
int distance6;

//sensor 7
#define trigPin7 14
#define echoPin7 15
int led7 = 20;
int distance7;

//sensor 8
#define trigPin8 16
#define echoPin8 17
//int led8 = 20;
int distance8;

//sensor 9
#define trigPin9 18
#define echoPin9 19
//int led8 = 20;
int distance9;

//sensor 10
#define trigPin10 20
#define echoPin10 21
//int led8 = 20;
int distance10;

#define MAX_DISTANCE 500

int led = 13;

int stairLength = 102;

NewPing sonar(trigPin, echoPin, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar2(trigPin2, echoPin2, MAX_DISTANCE);
NewPing sonar3(trigPin3, echoPin3, MAX_DISTANCE);
NewPing sonar4(trigPin4, echoPin4, MAX_DISTANCE);
NewPing sonar5(trigPin5, echoPin5, MAX_DISTANCE);
NewPing sonar6(trigPin6, echoPin6, MAX_DISTANCE);
NewPing sonar7(trigPin7, echoPin7, MAX_DISTANCE);
NewPing sonar8(trigPin8, echoPin8, MAX_DISTANCE);
NewPing sonar9(trigPin9, echoPin9, MAX_DISTANCE);
NewPing sonar10(trigPin10, echoPin10, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
//  pinMode(led, OUTPUT);
//  pinMode(led1, OUTPUT);
//  pinMode(led2, OUTPUT);
//  pinMode(led3, OUTPUT);
//  pinMode(led4, OUTPUT);
//  pinMode(led5, OUTPUT);
//  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
}

void loop() {
  delay(29);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int distance1 = sonar.ping_cm();
  unsigned int distance2 = sonar2.ping_cm();
  unsigned int distance3 = sonar3.ping_cm();
  unsigned int distance4 = sonar4.ping_cm();
  unsigned int distance5 = sonar5.ping_cm();
  unsigned int distance6 = sonar6.ping_cm();
  unsigned int distance7 = sonar7.ping_cm();
  unsigned int distance8 = sonar8.ping_cm();
  unsigned int distance9 = sonar9.ping_cm();
  unsigned int distance10 = sonar10.ping_cm();
    
  int val = 0;
  if (Serial.available() > 0) {
    val = Serial.read();
  }

  //check if OF wants data
  //if we get a '!' from OF then we should send the values
  if (val == '!') {
    //byte 1
    unsigned char val1 = 0;
    unsigned char val2 = 0;
    unsigned char val3 = 0;
    unsigned char val4 = 0;
    unsigned char val5 = 0;
    unsigned char val6 = 0;
    unsigned char val7 = 0;
    unsigned char val8 = 0;
    //byte 2
    unsigned char val9 = 0;
    unsigned char val10 = 0;
    
    //SENDING BYTE 1
    //SONAR 1
    if ((5 < distance1) && (distance1 < stairLength)) {
//      digitalWrite(led1, HIGH);
      val1 = 1;
    }
    else {
//      digitalWrite(led1, LOW);
      val1 = 0;
    }

    //SONAR 2
    if ((5 < distance2) && (distance2 < stairLength)) {
//      digitalWrite(led2, HIGH);
      val2 = 1;
    }
    else {
//      digitalWrite(led2, LOW);
      val2 = 0;
    }

    //SONAR 3
    if ((5 < distance3) && (distance3 < stairLength)) {
//      digitalWrite(led3, HIGH);
      val3 = 1;
    }
    else {
//      digitalWrite(led3, LOW);
      val3 = 0;
    }

    //SONAR 4
    if ((5 < distance4) && (distance4 < stairLength)) {
//      digitalWrite(led4, HIGH);
      val4 = 1;
    }
    else {
//      digitalWrite(led4, LOW);
      val4 = 0;
    }

    //SONAR 5
    if ((5 < distance5) && (distance5 < stairLength)) {
//      digitalWrite(led5, HIGH);
      val5 = 1;
    }
    else {
//      digitalWrite(led5, LOW);
      val5 = 0;
    }

    //SONAR 6
    if ((5 < distance6) && (distance6 < stairLength)) {
//      digitalWrite(led6, HIGH);
      val6 = 1;
    }
    else {
//      digitalWrite(led6, LOW);
      val6 = 0;
    }

    //SONAR 7
    if ((5 < distance7) && (distance7 < stairLength)) {
//      digitalWrite(led7, HIGH);
      val7 = 1;
    }
    else {
//      digitalWrite(led7, LOW);
      val7 = 0;
    }

    //SENDING BYTE 2
    //SONAR 8
    if ((5 < distance8) && (distance8 < stairLength)) {
//      digitalWrite(led8, HIGH);
      val8 = 1;
    }
    else {
//      digitalWrite(led8, LOW);
      val8 = 0;
    }

    //SONAR 9
    if ((5 < distance9) && (distance9 < stairLength)) {
//      digitalWrite(led8, HIGH);
      val9 = 1;
    }
    else {
//      digitalWrite(led8, LOW);
      val9 = 0;
    }

   if ((5 < distance10) && (distance10 < 100)){
    digitalWrite(led7,HIGH);
    val10 = 1;
//    Serial.println("PLAY");
   }
   else{
//    Serial.println("NOTHING"); 
  digitalWrite(led7,LOW);
    val10 = 0;
   }
   
    //SENDING BYTES
    //FIRST BYTE
    unsigned char byteToSend;
    byteToSend = (val1 << 1) | (val2 << 2) | (val3 << 3) | (val4 << 4) | (val5 << 5) | (val6 << 6) | (val7 << 7) | (val8 & 0x01);

    //SECOND BYTE
    unsigned char byteToSend2;
    byteToSend2 = (val9 << 1) | (val10 & 0x01);
    //      (values[1]<<6) |
    //      (values[2]<<5) |
    //      (values[3]<<4) |
    //      (values[4]<<3) |
    //      (values[5]<<2) |
    //      (values[6]<<1) |
    //      (values[7] & 0x01);

    Serial.write(byteToSend);
    Serial.write(byteToSend2);

    delay(20);
  }
  Serial.flush();
}
