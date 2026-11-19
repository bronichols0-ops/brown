
#include "pros/misc.h"
#include "subsystems.hpp"
#include "computer.hpp"


void updateLift(){
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
        // Move to the selected lift preset.
        usingLift =false;
        wristPosition = -970 * 2;
        liftPosition = 440;
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        // Raise lift
        lift.move(127);
        liftPosition = lift.get_position();
        wristPosition = -800;
        usingLift = true;
        return;
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        // Lower the lift while the button is held.
        lift.move(-127);
        liftPosition = lift.get_position();
        usingLift = true;
        return;
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){
        wristPosition = -300;

    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
        wristPosition = 0;
    }
    

    float output = controlLift(liftPosition);
    if (output == 0) {
        lift.brake();
    } else {
        lift.move(static_cast<int>(output));
    }
}

void updateClaw(){
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        clawInUse = true;
        openClaw = false;
        claw.move(127);
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        clawInUse = true;
        openClaw = true;
        claw.move(-127);
    } else if (openClaw == false) {
        claw.brake();
    } else {
        clawInUse = false;
    }
}

void updateIntake(){
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        intake.move(127);
        claw.move(70);
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        intake.move(-127);
        claw.move(-70);
    } else {
        intake.brake();
        claw.brake();
    }
}