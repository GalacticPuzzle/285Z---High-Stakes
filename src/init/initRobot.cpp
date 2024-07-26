#include "main.h"
#include "pros/adi.hpp"
#include "pros/motor_group.hpp"
#include "lemlib/api.hpp" 
#include "/init/initRobot.hpp"

// Drive Motor config
pros::Motor front_left_motor(-19, pros::v5::MotorGears::blue); 
pros::Motor front_right_motor(-11, pros::v5::MotorGears::blue); 
pros::Motor back_top_left_motor(3, pros::v5::MotorGears::blue); 
pros::Motor back_top_right_motor(1, pros::v5::MotorGears::blue);  
pros::Motor back_bottom_left_motor(-10, pros::v5::MotorGears::blue); 
pros::Motor back_bottom_right_motor(-2, pros::v5::MotorGears::blue);

// Intake Motor Config
pros::Motor intakeMotor(20, pros::v5::MotorGears::blue); 

 pros::controller_digital_e_t intakeIn = pros::E_CONTROLLER_DIGITAL_L1;
 pros::controller_digital_e_t liftOut = pros::E_CONTROLLER_DIGITAL_R1;
 pros::controller_digital_e_t liftUp = pros::E_CONTROLLER_DIGITAL_L2;
 pros::controller_digital_e_t liftDown = pros::E_CONTROLLER_DIGITAL_R2;
 pros::controller_digital_e_t tilt = pros::E_CONTROLLER_DIGITAL_A;


//motorgroup config
pros::MotorGroup left_motor_group({-19,3,-10});
pros::MotorGroup right_motor_group({-11,1,-2});

//controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// drivetrain settings
lemlib::Drivetrain drivetrain(&left_motor_group, // left motor group
                              &right_motor_group, // right motor group
                              11, // 10 inch track width
                              lemlib::Omniwheel::NEW_4, // using new 4" omnis
                              300, // drivetrain rpm is 360
                              2 // horizontal drift is 2 (for now)
);


// imu
pros::Imu imu(16);


pros::adi::DigitalIn autonSelector ('A');

int aut = 0;
const int numAutons = 5;


// horizontal tracking wheel encoder
// pros::Rotation horizontal_encoder(9);
// // vertical tracking wheel encoder
// pros::ADIEncoder vertical_encoder('C', 'D', true);
// // horizontal tracking wheel
// lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, lemlib::Omniwheel::NEW_275, -5.75);
// // vertical tracking wheel
// lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, lemlib::Omniwheel::NEW_275, -2.5);

// odometry settings
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr,// horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);


// lateral PID controller
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

// angular PID controller
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

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);


