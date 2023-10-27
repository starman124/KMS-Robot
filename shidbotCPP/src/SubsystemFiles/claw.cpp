#include "main.h"

//Helper functions
void setClaw(int power) {
    claw = power;
}

//Driver functions
void setClawMotors() {
    //bottom left trigger X opens, Y closes
    int clawPower = 127 * (fuckmecontroller.get_digital(pros::E_CONTROLLER_DIGITAL_X) - (fuckmecontroller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)));
    setClaw(clawPower);
}