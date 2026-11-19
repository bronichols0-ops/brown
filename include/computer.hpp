#pragma once

#include "EZ-Template/api.hpp" // IWYU pragma: keep   

#include "api.h" // IWYU pragma: keep   
#include "main.h" // IWYU pragma: keep


void setLiftPos(short position);
float controlLift(float setPoint);
void start_task_manager();
void updateLift();
void updateClaw();
void updateIntake();
