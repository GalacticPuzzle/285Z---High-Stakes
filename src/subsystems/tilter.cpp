#include "main.h"
#include "../../init/initRobot.hpp"
#include "tilter.hpp"
#include "lemlib/api.hpp"
#include "pros/misc.h"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"


pros::ADIDigitalOut pistonSolenoid('H'); // Replace 'A' with your actual port


void Tilter::grab(void* param) {
    bool solenoidState = false;  // false = closed, true = open
    bool bButtonLastState = false;  // To track the previous state of the B button

    while (true) {
        bool bButtonCurrentState = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B);  // Read the current state of the B button

        // If B button is pressed and was not pressed in the last iteration
        if (bButtonCurrentState && !bButtonLastState) {
            // Toggle solenoid state
            solenoidState = !solenoidState;
            
            // Set solenoid according to the new state
            pistonSolenoid.set_value(solenoidState);  // Open/close the solenoid
        }

        // Update last state of B button
        bButtonLastState = bButtonCurrentState;

        // Small delay to prevent CPU overload
        pros::delay(20);
    }
}