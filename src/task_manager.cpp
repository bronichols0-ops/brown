#include "main.h"
#include "pros/misc.h"
#include "subsystems.hpp"
#include "computer.hpp"


int lift_controller(){
    while (false){
        while (!usingLift){
            // Get pid output
            float output = controlLift(liftPosition);
            // Set motor power
             lift.move(output);
        

            // Delay lets robot use resources somewhere else
            pros::delay(50);
        }
    }

    return 0;
}

int wrist_controller(){
    float kp = 0.1;
    while (true){
        float currPose = wristMotor.get_position();
        float output = (wristPosition - currPose) * kp;

        wristMotor.move(output);
        pros::delay(20);
    }
    
}

// This starts every task according to need
void start_task_manager(){
    pros::Task LIFT_CONTROLLER(lift_controller);
    wristMotor.set_zero_position(0);
    pros::Task WRIST_CONTROLLER(wrist_controller);
}