#include "main.h"
#include "lemlib/chassis/chassis.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "subsystems/intake.hpp"
#include "subsystems/drive.hpp"
#include "subsystems/tilter.hpp"
#include "../../init/initRobot.hpp"
#include "../../init/helpers.hpp"
ASSET(Auton1_txt);




// Function for running the intake task
void intake_task_fn(void* param) {
    Intake* intake = static_cast<Intake*>(param);
    
    while (true) {
        intake->run(param);  // This should handle button inputs for controlling the intake
        pros::delay(20); // Small delay to prevent resource exhaustion
    }
}

// Function for running the tilter task
void tilter_task_fn(void* param) {
    Tilter* tilter = static_cast<Tilter*>(param);
    
    while (true) {
        tilter->grab(param);  // This should handle button inputs for controlling the tilter
        pros::delay(20); // Small delay to prevent resource exhaustion
    }
}

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    pros::lcd::initialize();
    chassis.calibrate(); // Calibrate sensors
    pistonSolenoid.set_value(false);  


    // Create the Intake and Tilter objects


    // Start the intake and tilter tasks in the initialization phase


    // Task for printing robot position to the brain screen
    
}


/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
   if (limitSwitch.get_new_press()) {
        aut = (aut + 1) % numAutons; // Cycle through autonomous modes
        pros::lcd::set_text(1, "Auton Mode: " + autons[aut]); // Display current mode
    }
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    chassis.calibrate(); // Calibrate sensors
    chassis.setPose(0, 0, 0);
    // lookahead distance: 15 inches
    // timeout: 2000 ms
    // follow the next path, but with the robot going backwards
    // // set position to x:0, y:0, heading:0
    chassis.setPose(0, 0, 0);
    // // turn to face heading 90 with a very long timeout
    chassis.turnToHeading(90, 100000);

    // SLEW
    // chassis.setPose(0,0,0);
    // chassis.moveToPoint(0, 48, 10000);

    //AUTON TEST?
//    chassis.setPose(58, 24, 5000);
// chassis.moveToPoint(25, 24, 5000, {.forwards = false}, false);
// //clampFunction();
// pros::delay(50);
// chassis.turnToHeading(0, 5000);
// chassis.moveToPoint(25, 50, 5000);
// chassis.turnToHeading(130, 5000);
// //clampFunction();
// chassis.moveToPoint(47, -47, 5000);
// chassis.moveToPoint(25, -24, 5000, {.forwards = false}, false);
// //clampFunction();
// pros::delay(50);
// chassis.moveToPoint(25, -47, 5000, {.forwards = false}, false);
// chassis.turnToHeading(340, 5000);
// chassis.moveToPoint(25, -47, 5000);

}




/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

// Function for running the intake task


void opcontrol() {
    Intake intake;   // Definition for intake
    Tilter tilter;   // Definition for tilter

    // Create tasks for intake and tilter once, outside the while loop
    pros::Task intake_task(intake_task_fn, &intake, "Intake Task");
    pros::Task tilter_task(tilter_task_fn, &tilter, "Tilter Task");

    while (true) {
        tankDrive();  // Call tankDrive function (assuming this is defined elsewhere)
        pros::delay(20); // Add a delay to prevent resource exhaustion
    }
}


