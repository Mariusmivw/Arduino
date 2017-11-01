// door Marius
#include "MeMCore.h"

MeUltrasonicSensor ultraSensor(PORT_3);
MeLineFollower lineFinder(PORT_2);
MeDCMotor motor1(M1);
MeDCMotor motor2(M2);

void setup(){
  Serial.begin(9600);
}

void loop() {
  //loop
  //int val = lineFinder.readSensors();
  int val = ultraSensor.distanceCm();
  Serial.println(val);
  /*switch(val)
  {
    case S1_IN_S2_IN: Serial.println("Sensor 1 and 2 are inside of black line"); break; motor1.
    case S1_IN_S2_OUT: Serial.println("Sensor 2 is outside of black line"); break;
    case S1_OUT_S2_IN: Serial.println("Sensor 1 is outside of black line"); break;
    case S1_OUT_S2_OUT: Serial.println("Sensor 1 and 2 are outside of black line"); break;
    default: break;
  }*/
  delay(200);
}

