#include "main.h"
#include "drive.hpp"
#include "../../init/initRobot.hpp"
#include "lemlib/api.hpp"
#include "pros/misc.h"

void tankDrive(){
        while (true) {
        // get left y and right y positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightY = -1*(controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));

        // move the robot
        chassis.tank(leftY, rightY);

        // delay to save resources
        pros::delay(20);
    }
}

void arcadeDrive(){
    while (true) {
        // get left y and right x positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        chassis.arcade(leftY, rightX);

        // delay to save resources
        pros::delay(20);
    }
}

void Drive::move(double distance) {
    pros::lcd::set_text(4, "Starting Movement");  // Debugging text

    // Create parameters for moveToPoint using MoveToPointParams
    lemlib::MoveToPointParams params;
    params.forwards = true;      // Move forward
    params.maxSpeed = 100;       // Set maximum speed
    params.minSpeed = 10;        // Set minimum speed to avoid stopping too soon
    params.earlyExitRange = 0;   // No early exit

    // Use chassis's moveToPoint function with correct timeout and params
    chassis.moveToPoint(distance, 0, 3000, params);  // Move the robot with a timeout of 3000 ms

    pros::lcd::set_text(4, "Finished Movement");  // Debugging text
}

void Drive::turn(double targetHeading, int timeout = 5000) { // Default timeout set to 5000 ms
        // Set parameters for turning
        lemlib::TurnToHeadingParams params;
        params.direction = lemlib::AngularDirection::AUTO; // Automatically decide the direction
        params.maxSpeed = 127; // Default maximum speed for turning

        // Start turning to the specified heading
        pros::lcd::set_text(3, "Turning to heading..."); // Debugging text
        chassis.turnToHeading(targetHeading, timeout, params); // Call with timeout and params

        // Wait until the turn is completed (optional)
        pros::lcd::set_text(3, "Turn complete!"); // Debugging text
    }
