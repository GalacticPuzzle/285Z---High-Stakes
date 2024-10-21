#include "main.h"
#include "../../init/helpers.hpp"
#include "../../init/auton.hpp"
#include "lemlib/api.hpp"

// Define autons as a vector of strings
const std::vector<std::string> autons = {
    "No Autonomous",
    "Match Load Side",
    "Goal Side 6 Ball",
    "Goal Side 4 Ball",
    "Skills Auton"
};

const int numAutons = static_cast<int>(autons.size()); // Number of autonomous modes

void noAuton() {
    pros::lcd::set_text(2, "Running No Autonomous");
    intakeIn(10); // Run intake for 10 seconds
    move(10);     // Move for a specified distance
} 

// Define other autonomous mode functions...



void matchLoadSide() {
    // Code for Match Load Side
}

void goalSide6() {
    // Code for Goal Side 6 Ball
} 

void goalSide4() {
    // Code for Goal Side 4 Ball
} 

void skillsAuton() {
    // Code for Skills Auton
}
