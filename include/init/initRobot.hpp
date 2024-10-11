#pragma once

#include "main.h"
#include "lemlib/api.hpp" 

#include <vector>

//  Motor and controller declarations
extern pros::Motor front_left_motor; 
extern pros::Motor front_right_motor; 
extern pros::Motor back_top_left_motor; 
extern pros::Motor back_top_right_motor;  
extern pros::Motor back_bottom_left_motor; 
extern pros::Motor back_bottom_right_motor;


extern pros::Motor Elevate;

 extern pros::Controller controller;

 extern pros::MotorGroup left_motor_group;
 extern pros::MotorGroup right_motor_group;

// extern pros::controller_digital_e_t intakeIn;
// extern pros::controller_digital_e_t liftOut;
// extern pros::controller_digital_e_t liftUp;
// extern pros::controller_digital_e_t liftDown;
extern pros::controller_digital_e_t tilt;


// Autonomous function declarations
// extern void noAuton(); 
// extern void matchLoadSide(); 
// extern void goalSide6(); 
// extern void goalSide4(); 
// extern void skillsAuton(); 

// // Autonomous names vector
// const std::vector<std::string> autons = {
//     "No Autonomous       ",
//     "Match Load Side     ",
//     "Goal Side 6 Ball    ",
//     "Goal Side 4 Ball    ",
//     "Skills Auton        "
// };

// extern pros::ADIButton limitSwitch;


// extern int numAutons;

extern pros::ADIDigitalOut mogoMech;
extern lemlib::Chassis chassis;

