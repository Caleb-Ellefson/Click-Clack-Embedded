#pragma once
#include <Arduino_JSON.h>
#include <AccelStepper.h>

// -----StepperMotor + HallSensor PINS----------
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define hall_sensor D5

// Intialize the stepper libary -- Extern is just telling the compiler that the Intializtion is somewhere else
extern AccelStepper stepper;
//2048 = full revolution
const int stepsPerRevolution = 2048; 
int time_index = 0;
void move_once();
void set_index();
void calibration();
//void check_calibration();

// -----StepperMotor Config----------
void stepper_begin (int max_speed, int acceleration, int speed){
    stepper.setMaxSpeed(max_speed);
    stepper.setAcceleration(acceleration);
    stepper.setSpeed(speed);
    calibration();
}

void move_once(){
    stepper.move(400);
    stepper.runToPosition();
    time_index++;
    //check_calibration();
    set_index();
}

void calibration (){
    Serial.print("Calibrating...");
    while (digitalRead(hall_sensor) == 1){
        move_once();
        Serial.print("...");
        delay(15);
    }
    Serial.println("Calibrating done");
    stepper.stop();
}

void set_index(){
    if (digitalRead(hall_sensor) == 0 || time_index > 10){
         time_index = 0;
    }
}

// void check_calibration(){
//     if (digitalRead((hall_sensor) == 0 && time_index =! 0)){
//         Serial.print("Recalibration");
//         calibration();
//   }
// }

