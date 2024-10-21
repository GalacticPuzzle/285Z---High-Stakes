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
            ConveyorMotor.move(115); 
        } else if (intakeB == -1) {
            IntakeMotor.move(-127); 
            ConveyorMotor.move(-115); 
        } else {
            IntakeMotor.move(0); 
            ConveyorMotor.move(0);
        }

        pros::delay(20);
    }



    
}

void intakeIn(int seconds) {
    pros::Task intakeTask([]() {
        Intake intake;  // Create an instance of the Intake class
        intake.run(nullptr);  // Call the run() function
    });

    pros::delay(seconds * 1000);  // Convert seconds to milliseconds
    intakeA = 0;  // Stop the intake
}
