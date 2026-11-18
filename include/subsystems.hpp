#pragma once

#include "EZ-Template/api.hpp" // IWYU pragma: keep   

#include "api.h" // IWYU pragma: keep   
#include "main.h" // IWYU pragma: keep

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

inline pros::Motor claw(10);

inline pros::Motor wristMotor(8);

inline pros::MotorGroup lift({3, -6});

inline pros::Rotation wrist(9);
inline pros::Rotation liftrot(16);
struct Pid_Tuning {
  float kP;
  float kI;
  float kD;
};

inline short liftPosition = 0; // start at 0
inline float set_lift(int setPoint) {
  float kp = 1.0;

  // Calculate P
  float output = (setPoint - liftrot.get_position()) * kp;

  return output;
}

inline pros::Motor intake(4);









// Intake autonomous
inline void set_intake(int input) {
  intake.move(input);
}
// Intake Driver Control
inline void intake_opcontrol() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    set_intake(127);
    claw.move(127);
  } 
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    set_intake(-127);
    claw.move(-127);
  } 
  else {
    set_intake(0);
    claw.move(0);
  }
}
inline float wristPosition = 0; // start at 0
inline float liftPosition = 0; // start at 0
inline float liftPositions[] = {0, 100, 200, 300, 400, 500}; // example positions for the lift
inline bool liftPositioned;
inline short liftSpeed = 127;
inline bool usingLift = false;
inline bool openClaw;
inline bool clawInUse = false;




