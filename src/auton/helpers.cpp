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

void move(double distance) {
    // Set up movement parameters
    lemlib::MoveToPointParams params;
    params.forwards = true;       // Move forward by default
    params.maxSpeed = 127;        // Maximum speed (adjust as needed)
    params.minSpeed = 0;          // Minimum speed (adjust for smoother movement)
    params.earlyExitRange = 0;    // No early exit by default

    // Move the chassis by the specified distance in the X direction
    chassis.moveToPoint(distance, 0, 0, params);  // X = distance, Y = 0, Timeout = 0
}


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


