#include "main.h"
#include "../../init/initRobot.hpp"
#include "intake.hpp"
#include "lemlib/api.hpp"
#include "pros/misc.h"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"

// Global variable for intake state
int intakeB = 0;
int intakeA = 0;

void Intake::run(void* param) {
    while (true) {
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            intakeB = 1; 
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            intakeB = -1;  
        } else {
            intakeB = 0; 
        }

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
            intakeB = (intakeB != 1) ? 1 : 0;
        }

        if (intakeB == 1) {
            IntakeMotor.move(127); 
            ConveyorMotor.move(127); 
        } else if (intakeB == -1) {
            IntakeMotor.move(-127); 
            ConveyorMotor.move(-127); 
        } else {
            IntakeMotor.move(0); 
            ConveyorMotor.move(0);
        }

        pros::delay(20);
    }



    
}


void Intake::runAutonIn(int seconds) {
    pros::lcd::set_text(3, "Starting Autonomous Intake"); // Debugging text

    // Start the intake and conveyor motors at full speed
    IntakeMotor.move(127);  // Run the intake motor at 100% speed
    ConveyorMotor.move(127);  // Run the conveyor motor at 100% speed

    // Keep running the motors for the specified duration
    int startTime = pros::millis();  // Get the current time in milliseconds
    while (pros::millis() - startTime < seconds * 1000) {
        // This loop will keep the motors running at full speed
        IntakeMotor.move(127);  // Continuously run the intake motor at full speed
        ConveyorMotor.move(127);  // Continuously run the conveyor motor at full speed
    }

    // Stop the intake and conveyor motors after the loop ends
    IntakeMotor.move(0);  // Stop the intake motor
    ConveyorMotor.move(0);  // Stop the conveyor motor
    pros::lcd::set_text(4, "Intake & Conveyor Motors Stopped"); // Debugging text
}

void Intake::runAutonOut(int seconds) {
    pros::lcd::set_text(3, "Starting Autonomous Intake"); // Debugging text

    // Start the intake and conveyor motors at full speed
    IntakeMotor.move(-127);  // Run the intake motor at 100% speed
    ConveyorMotor.move(-127);  // Run the conveyor motor at 100% speed

    // Keep running the motors for the specified duration
    int startTime = pros::millis();  // Get the current time in milliseconds
    while (pros::millis() - startTime < seconds * 1000) {
        // This loop will keep the motors running at full speed
        IntakeMotor.move(-127);  // Continuously run the intake motor at full speed
        ConveyorMotor.move(-127);  // Continuously run the conveyor motor at full speed
    }

    // Stop the intake and conveyor motors after the loop ends
    IntakeMotor.move(0);  // Stop the intake motor
    ConveyorMotor.move(0);  // Stop the conveyor motor
    pros::lcd::set_text(4, "Intake & Conveyor Motors Stopped"); // Debugging text
}







void stopAuton() {
    pros::lcd::set_text(4, "Stopping Intake Motor");  // Debugging text
    pros::Motor intakeMotor(1);  // Assuming motor is on port 1
    intakeMotor.move_velocity(0);  // Stop the intake motor
}

void intakeIn(int seconds) {
    pros::Task intakeTask([]() {
        Intake intake;  // Create an instance of the Intake class
        intake.run(nullptr);  // Call the run() function
    });

    pros::delay(seconds * 1000);  // Convert seconds to milliseconds
    intakeA = 0;  // Stop the intake
}
