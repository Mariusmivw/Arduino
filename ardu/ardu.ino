// door Marius
#include "MeMCore.h"

MeUltrasonicSensor ultraSensor(PORT_3);
MeLineFollower lineFinder(PORT_2);
MeDCMotor motor1(M1); //left
MeDCMotor motor2(M2); //right
uint8_t fastness = 100;

void setup(){
  Serial.begin(9600);
}

void loop() {
  //loop
  int val = lineFinder.readSensors();
  //int val = ultraSensor.distanceCm();
  //Serial.println(val); // l + r = 2 + 1
  if (val == 1){
    Serial.println("Sensor 1 is outside of black line");
    motor1.run(fastness/2);
    motor2.run(fastness/2);
  }
  else if (val == 2){
    Serial.println("Sensor 2 is outside of black line");
    motor1.run(-fastness/2);
    motor2.run(-fastness/2);
  }
  else{
    Serial.println("Sensor 1 and 2 are outside of black line");
    motor1.run(-fastness);
    motor2.run(fastness);
  }
}

