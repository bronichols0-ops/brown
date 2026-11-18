#include "main.h"
#include "pros/misc.h"
#include "subsystems.hpp"





void setLiftPos(short position){
    liftPosition = liftPositions[position - 1];
}

Pid_Tuning liftTuning = {1.0, 0.0, 0.0};
// This calculates the lift motor power for a target position.
float controlLift(float setPoint){
    float error = setPoint - lift.get_position();
    float output = liftTuning.kP * error;

    if (output > 127) {
        return 127;
    }
    if (output < -127) {
        return -127;
    }
    if (output > -5 && output < 5) {
        return 0;
    }
    return output;
}