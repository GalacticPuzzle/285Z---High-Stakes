#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"
#include "subsystems/intake.hpp"
#include "subsystems/drive.hpp"
#include "subsystems/tilter.hpp"
#include "../../init/initRobot.hpp"
#include "../../init/helpers.hpp"




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

    // Create the Intake and Tilter objects
    Intake intake;
    Tilter tilter;

    // Start the intake and tilter tasks in the initialization phase
    pros::Task intake_task(intake_task_fn, &intake, "Intake Task");
    pros::Task tilter_task(tilter_task_fn, &tilter, "Tilter Task");

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
    pros::Task screen_task([&]() {
        while (true) {
            cycleAutonMode(); // Check limit switch for mode cycling
            pros::delay(20);
        }
    });
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
    setAutonMode();
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
    while (true) {
        tankDrive();  // Call tankDrive function (assuming this is defined elsewhere)
        pros::delay(20); // Add a delay to prevent resource exhaustion
    }
}

