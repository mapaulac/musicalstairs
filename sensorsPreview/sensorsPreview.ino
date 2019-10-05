//try sensors sketch
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

//sensor 4 -- FAULTY SENSOR
#define trigPin4 6
#define echoPin4 7
//int led4 = 11;
int distance4;

//sensor 5
#define trigPin5 8
#define echoPin5 9
int led5 = 18;
int distance5;

//sensor 6 -- FAULTY 
#define trigPin6 10
#define echoPin6 11
int led6 = 19;
int distance6;

//sensor 7 -- FAULTY 
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
//  pinMode(led,OUTPUT);
//  pinMode(led1,OUTPUT);
//  pinMode(led2,OUTPUT);
//  pinMode(led3,OUTPUT);
//  pinMode(led4,OUTPUT);
//    pinMode(led5,OUTPUT);
//    pinMode(led6,OUTPUT);
    pinMode(led,OUTPUT);
}

void loop() {
//  delay(29);
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
      
  Serial.println(distance1);

  if ((5 < distance5) && (distance5 < 100)){
    digitalWrite(led,HIGH);
//    Serial.println("PLAY");
   }
   else{
//    Serial.println("NOTHING"); 
  digitalWrite(led,LOW);
   }

}
