// door Marius
#include "MeMCore.h"

MeUltrasonicSensor ultraSensor(PORT_3);
MeLineFollower lineFinder(PORT_2);
MeDCMotor motor1(M1); //left
MeDCMotor motor2(M2); //right
int fastness1 = -190;
int fastness2 = -fastness1;
int t;

void setup(){
  Serial.begin(9600);
}

void loop() {
  //loop
  int val = lineFinder.readSensors();
  
  //int val = ultraSensor.distanceCm();
  //Serial.println(val); // l + r = 2 + 1
  if (val == 0){
    Serial.println("Sensor 1 and 2 are inside of black line");
    t = 0;
    motor1.run(fastness1);
    motor2.run(fastness2);
  }
  else if (val == 1){
    Serial.println("Sensor 1 is outside of black line"); //right
    t = 1;
    motor1.run(fastness1);
    motor2.run(fastness2);
  }
  else if (val == 2){
    Serial.println("Sensor 2 is outside of black line"); //left
    t = 2;
    motor1.run(fastness1);
    motor2.run(fastness2);
  }
  else{
    Serial.println("Sensor 1 and 2 are outside of black line");
    if (t == 0 | t == 3){
      t = 3;
      motor1.run(-fastness1/2);
      motor2.run(-fastness2/2);
    }
    else if (t == 1){
      // naar links
      motor1.run(0);
      motor2.run(fastness2);
    }
    else{
      // naar rechts
      motor1.run(fastness1);
      motor2.run(0);
    }
  }
}

