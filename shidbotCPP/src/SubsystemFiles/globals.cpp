#include "main.h"

//Motors
 pros::Motor arm(4, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
 pros::Motor claw(5, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
 pros::Motor driveleft(1, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
 pros::Motor driveright(3, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);

 //Controller
 pros::Controller fuckmecontroller(pros::E_CONTROLLER_MASTER);

 //Sensors
 pros::ADIGyro gyro (6, 0.95);
 