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