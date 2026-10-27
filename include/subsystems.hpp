#pragma once

#include "EZ-Template/api.hpp" // IWYU pragma: keep   

#include "api.h" // IWYU pragma: keep   
#include "main.h" // IWYU pragma: keep

extern Drive chassis;

// Your motors, sensors, etc. should go here.  Below are examples

inline pros::Motor claw(17);

inline pros::Motor rotator(2);

inline pros::MotorGroup lift({3,-6});


inline pros::Motor intake(4);

inline pros::Motor counter(5);

inline pros::Rotation liftrot(16);
inline int get_lift_position() {
  return liftrot.get_position() * 1.3;
}

template <typename Condition>
inline void wait_until(Condition condition) {
  while (!condition()) {
    pros::delay(10);
  }
}

inline void lift_height(int inches) {
  if (get_lift_position() < inches) {
    lift.move(80);
    wait_until([inches] { return get_lift_position() >= inches; });
    lift.move(0);
  }
  else if (get_lift_position() > inches) {
    lift.move(-80);
    wait_until([inches] { return get_lift_position() <= inches; });
    lift.move(0);
  }
  else {
    lift.move(0);
  }
}

inline void claw_position(int degrees) {
  if (rotator.get_position() < degrees) {
    rotator.move(80);
    wait_until([degrees] { return rotator.get_position() >= degrees; });
    rotator.move(0);
  }
  else if (rotator.get_position() > degrees) {
    rotator.move(-80);
    wait_until([degrees] { return rotator.get_position() <= degrees; });
    rotator.move(0);
  }
  else {
    rotator.move(0);
  }
}

// Intake autonomous
inline 

void set_intake(int input) {
  intake.move(input);
}
// Intake Driver Control
inline void intake_opcontrol() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    set_intake(127);
  } 
  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    set_intake(-127);
  } 
  else {
    set_intake(0);
  }
}

inline void scoring_mode() {
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y))  {
  if (get_lift_position() < 5) {
    lift_height(5);
    rotator.move(80);
    wait_until([] { return rotator.get_position() >= 90; });
    rotator.move(0);
  }
  else if (get_lift_position() > 100) {
    lift.move(-80);
    wait_until([] { return get_lift_position() <= 100; });
    lift.move(0);
    rotator.move(80);
    wait_until([] { return rotator.get_position() >= 90; });
    rotator.move(0);
  }
  else {
    rotator.move(80);
    wait_until([] { return rotator.get_position() >= 90; });
    rotator.move(0);
    }
  }
}

inline void lift_down() {
  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    claw_position(150);
    lift_height(0);
    claw_position(0);
  }
}

inline void lift_driver() {
  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
     lift.move(50);
  }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    lift.move(-50);
  }
}
  else { 
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
     lift.move(100);
  }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
    lift.move(-100);
  }
    else {
      lift.move(0);
    }
}
}

