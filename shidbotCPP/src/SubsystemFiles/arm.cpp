#include "main.h"


//helper functions
void setArm(int Power) {
    pros::Motor arm(4, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
    arm = Power;
}


//driver control functions
void setArmMotors() {
    //bottom left trigger lowers, top trigger raises
    int Power = 127 * (fuckmecontroller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) - 
    (fuckmecontroller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)));
    setArm(Power);
}