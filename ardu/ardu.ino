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
  int val = lineFinder.readSensors();
  //int val = ultraSensor.distanceCm();
  Serial.println(val); // l + r = 2 + 1
  switch(val)
  {
    case 0: Serial.println("Sensor 1 and 2 are inside of black line"); break; motor1.
    case 1: Serial.println("Sensor 2 is outside of black line"); break;
    case 2: Serial.println("Sensor 1 is outside of black line"); break;
    case 3: Serial.println("Sensor 1 and 2 are outside of black line"); break;
    default: break;
  }
  delay(200);
}

