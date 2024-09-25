#include "pros/adi.hpp" 
#include "main.h"
#include "pros/misc.h"
#include "../../include/init/initRobot.hpp"

// Define the motors here, without extern
pros::Motor front_left_motor(-1, pros::E_MOTOR_GEAR_BLUE); // correct n
pros::Motor front_right_motor(2, pros::E_MOTOR_GEAR_BLUE); // correct
pros::Motor back_top_left_motor(3, pros::E_MOTOR_GEAR_BLUE); // correct
pros::Motor back_top_right_motor(-4, pros::E_MOTOR_GEAR_BLUE); // correct
pros::Motor back_bottom_left_motor(-6, pros::E_MOTOR_GEAR_BLUE); // correct
pros::Motor back_bottom_right_motor(5, pros::E_MOTOR_GEAR_BLUE); // correct

// Define the motor groups
pros::MotorGroup left_motor_group({-1, 3, -6});
pros::MotorGroup right_motor_group({2, -4, 5});

// Define the controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Drivetrain settings
lemlib::Drivetrain drivetrain(&left_motor_group, // left motor group
                              &right_motor_group, // right motor group
                              12.25, // 10 inch track width
                              lemlib::Omniwheel::NEW_4_HALF, // using new 4" omnis
                              300, // drivetrain rpm is 360
                              2 // horizontal drift is 2 (for now)
);

// IMU
pros::Imu imu(10);
// Horizontal tracking wheel encoder
pros::Rotation horizontal_encoder(20);
// Vertical tracking wheel encoder
pros::ADIEncoder vertical_encoder('C', 'D', true);

// Horizontal tracking wheel
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_275, -5.75);

// Vertical tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_275, -2.5);

// Odometry settings
lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2
                            &imu // inertial sensor
);

// Lateral PID controller
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// Angular PID controller
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// Input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttle_curve(3, // joystick deadband out of 127
                                      10, // minimum output where drivetrain will move out of 127
                                      1.019 // expo curve gain
);

// Input curve for steer input during driver control
lemlib::ExpoDriveCurve steer_curve(3, // joystick deadband out of 127
                                   10, // minimum output where drivetrain will move out of 127
                                   1.019 // expo curve gain
);

// Create the chassis
lemlib::Chassis chassis(drivetrain,
                        lateral_controller,
                        angular_controller,
                        sensors,
                        &throttle_curve, 
                        &steer_curve
);
