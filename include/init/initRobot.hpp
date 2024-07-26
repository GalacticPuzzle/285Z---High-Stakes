#pragma once
#include "main.h"

#ifndef INITROBOT_HPP
#define INITROBOT_HPP

extern pros::Motor front_left_motor; 
extern pros::Motor front_right_motor; 
extern pros::Motor back_top_left_motor; 
extern pros::Motor back_top_right_motor;  
extern pros::Motor back_bottom_left_motor; 
extern pros::Motor back_bottom_right_motor;

extern pros::Motor IntakeMotor;

extern pros::Motor Lift;

extern pros::Controller controller;

extern pros::MotorGroup left_motor_group;
extern pros::MotorGroup right_motor_group;

extern pros::controller_digital_e_t intakeIn;
extern pros::controller_digital_e_t liftOut;
extern pros::controller_digital_e_t liftUp;
extern pros::controller_digital_e_t liftDown;
extern pros::controller_digital_e_t tilt;



extern void noAuton(); 
extern void matchLoadSide(); 
extern void goalSide6(); 
extern void goalSide4(); 
extern void skillsAuton(); 
extern void noAuton();

#endif
