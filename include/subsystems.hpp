#pragma once

#include "EZ-Template/api.hpp" // IWYU pragma: keep   

#include "api.h" // IWYU pragma: keep   
#include "main.h" // IWYU pragma: keep

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

inline pros::Motor claw(17);

inline pros::Motor rotator(2);


inline pros::Motor llift(3);
inline pros::Motor rlift(-6);
inline pros::Rotation liftrot(16);
inline short liftPosition = 0; // start at 0
inline float set_lift(int setPoint) {
  float kp = 1.0;

  // Calculate P
  float output = (setPoint - liftrot.get_position()) * kp;

  return output;
}

inline pros::Motor intake(4);


inline pros::Rotation clawrot(15);


inline int get_lift_position() {
  return liftrot.get_position() / -150000;
}



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
inline void rotator_driver() {
if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
    rotator.move(127);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
    rotator.move(-127);
  } else {
    rotator.brake();
  }
}




inline void lift_driver() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      llift.move(80);
      rlift.move(80);
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      llift.move(-80);
      rlift.move(-80);
    }
    else {
  llift.move(0);
  rlift.move(0);
}
  } 
  else {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    llift.move(127);
    rlift.move(127);
  } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    llift.move(-127);
    rlift.move(-127);
  } 
  else {
  llift.move(0);
  rlift.move(0);
}
}
}