#pragma once
#include "main.h"
#include "../../init/helpers.hpp"
#include "lemlib/api.hpp" 
#include "../include/subsystems/intake.hpp"
#include "../include/subsystems/tilter.hpp"

#include "pros/misc.h"



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



void clampOn() {
    pistonSolenoid.set_value(true);  // Open the solenoid (activate piston)
}

// Function to deactivate the piston solenoid
void clampOff() {
    pistonSolenoid.set_value(false);  // Close the solenoid (deactivate piston)
}
