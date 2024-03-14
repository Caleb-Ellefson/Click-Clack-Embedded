
#include <AccelStepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution

// ULN2003 Motor Driver Pins
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define hall_sensor D5
int state = 0;

// initialize the stepper library
AccelStepper stepper(AccelStepper::HALF4WIRE, IN1, IN3, IN2, IN4);

void setup() {
  // initialize the serial port
  Serial.begin(9600);
  
  // set the speed and acceleration
  stepper.setMaxSpeed(300);
  stepper.setAcceleration(100);
  // set target position
}

void loop() {
  // state = digitalRead(hall_sensor);
  // // check current stepper motor position to invert direction
  // if (state == HIGH){
  //   stepper.moveTo(stepper.currentPosition() + stepsPerRevolution);
  //   Serial.print('Moving');
  // }
  // else {
  stepper.moveTo(stepper.currentPosition() + stepsPerRevolution);
  
  // move the stepper motor (one step at a time)
  stepper.run();
}
