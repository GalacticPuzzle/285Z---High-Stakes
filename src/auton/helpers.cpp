#pragma once
#include "main.h"
#include "../../init/helpers.hpp"
#include "../../init/initRobot.hpp"
#include "lemlib/api.hpp"
#include "../include/subsystems/intake.hpp"
#include "../include/subsystems/tilter.hpp"
#include "pros/misc.h"

int aut = 0;

// Global variables for autonomous mode and limit switch
extern const std::vector<std::string> autons; // Autonomous names
extern pros::ADIButton limitSwitch('A'); // Limit switch

// Function to run the Intake::run() method for a specified number of seconds
void intakeIn(int seconds) {
    Intake intake;  // Create an instance of the Intake class

    // Create a task to run the intake
    pros::Task intakeTask([&]() {
        intake.run(nullptr);  // Call the run() function
    });

    // Run the intake for the specified seconds
    pros::delay(seconds * 1000);  // Convert seconds to milliseconds

    // Stop the intake task (you can manage the stopping mechanism in the run() method)
    intakeB = 0;  // Example: Stop the intake
}

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
            noAuton();
            break;
        case 1:
            matchLoadSide();
            break;
        case 2:
            goalSide6();
            break;
        case 3:
            goalSide4();
            break;
        case 4:
            skillsAuton();
            break;
        default:
            noAuton();
            break;
    }
}


void noAuton(); 
void matchLoadSide(); 
void goalSide6(); 
void goalSide4(); 
void skillsAuton(); 
void noAuton(); 


