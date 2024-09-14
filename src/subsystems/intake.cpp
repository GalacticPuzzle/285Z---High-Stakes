#pragma once
#include "main.h"
#include "../src\init\initRobot.cpp"
#include "../../include/subsystems/intake.hpp"
#include "lemlib/api.hpp" 
#include "pros/misc.h"


int intakeB = 0;


//void Intake::run(){
//     while (true){
//         if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
//             intakeMotor.move(-127);
//         }
//         if(!(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A))){
//             intakeMotor.brake();
//         }
//         pros::delay(20);
//     }
// }




/*if (intakeButton) {
    // Toggle the intake state on A button press
    intakeB = (intakeB != 1) ? 1 : 0;
  } else if (intakeInButton) {
    // Set intake to forward when R1 is pressed
    intakeB = 1;
  } else if (intakeOutButton) {
    // Set intake to reverse when R2 is pressed
    intakeB = -1;
  } else if (!controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && 
             !controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    // Stop the intake when R1 or R2 are released
    intakeB = 0;
  }

  // Apply the state to the motor
  if (intakeB == 1) {
    intakeMotor.move(127);  // Run intake forward
  } else if (intakeB == -1) {
    intakeMotor.move(-127); // Run intake backward
  } else {
    intakeMotor.move(0);    // Stop the intake
  }
}

*/


