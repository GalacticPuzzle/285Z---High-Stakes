#pragma once
#include "main.h"
#include "../../init/helpers.hpp"
#include "../../init/initRobot.hpp"
#include "lemlib/api.hpp"
#include "../include/subsystems/intake.hpp"
#include "../include/subsystems/tilter.hpp"
#include "pros/misc.h"

extern int aut = 0;

// Function declarations for autonomous modes
void noAuton();
void matchLoadSide();
void goalSide6(); 
void goalSide4(); 
void skillsAuton(); 

// void move(double distance) {
//     pros::lcd::set_text(4, "Starting Movement");  // Debugging text

//     // Start the motors to move a certain distance
//     front_left_motor.move_relative(distance, 100);  // Move left front motor
//     back_top_left_motor.move_relative(distance, 100);  // Move left back motor
//     back_bottom_left_motor.move_relative(distance, 100);  // Move left bottom motor

//     front_right_motor.move_relative(distance, 100); // Move right front motor
//     back_top_right_motor.move_relative(distance, 100); // Move right back motor
//     back_bottom_right_motor.move_relative(distance, 100); // Move right bottom motor

//     // Wait until all motors finish their movement
//     while (!front_left_motor.is_stopped() || !back_top_left_motor.is_stopped() || !back_bottom_left_motor.is_stopped() ||
//            !front_right_motor.is_stopped() || !back_top_right_motor.is_stopped() || !back_bottom_right_motor.is_stopped()) {
//         pros::delay(20);  // Wait a short time before checking again
//     }

//     pros::lcd::set_text(4, "Finished Movement");  // Debugging text
// }




// Global variables for autonomous mode and limit switch
pros::ADIButton limitSwitch('A'); // Limit switch

// Function to run the Intake::run() method for a specified number of seconds


// Function to activate the piston solenoid
void clampOn() {
    pistonSolenoid.set_value(true);  // Open the solenoid (activate piston)
}

// Function to deactivate the piston solenoid
void clampOff() {
    pistonSolenoid.set_value(false);  // Close the solenoid (deactivate piston)
}




// Function to cycle through autonomous modes
void cycleAutonMode() {
    if (limitSwitch.get_new_press()) {
        aut = (aut + 1) % numAutons; // Cycle through autonomous modes
        pros::lcd::set_text(1, "Auton Mode: " + autons[aut]); // Display current mode
    }
}

// Function to set the autonomous mode based on the current index
void setAutonMode() {
    switch (aut) {
        case 0:
            pros::lcd::set_text(2, "Running No Autonomous");
            noAuton();
            break;
        case 1:
            pros::lcd::set_text(2, "Running Match Load Side");
            matchLoadSide();
            break;
        case 2:
            pros::lcd::set_text(2, "Running Goal Side 6 Ball");
            goalSide6();
            break;
        case 3:
            pros::lcd::set_text(2, "Running Goal Side 4 Ball");
            goalSide4();
            break;
        case 4:
            pros::lcd::set_text(2, "Running Skills Auton");
            skillsAuton();
            break;
        default:
            pros::lcd::set_text(2, "Running Default Autonomous");
            noAuton();
            break;
    }
}


