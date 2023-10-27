#include "main.h"

    pros::ADIGyro gyro (6, 0.95);
    
    //helper functions
    void setDrive(int left, int right) {
        driveleft = left;
        driveright = right;

    }

    void resetDriveEncoders() {
        driveleft.tare_position();
        driveright.tare_position();
    }

    double avgDriveEncoderValue() {
        return (fabs(driveleft.get_position()) +
        fabs(driveright.get_position()) / 2);

    }


    //Driver control functions
    void setDriveMotors() {
       int leftJoystick = fuckmecontroller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
       int rightJoystick = fuckmecontroller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
       if(abs(leftJoystick)< 10 )
       leftJoystick = 0;
       if(abs(rightJoystick) < 10)
       rightJoystick = 0;

       setDrive(leftJoystick, rightJoystick);
    }

    //Autonomous functions
    void translate(int units, int voltage)
    {
       // define a direction based on units provided
       int direction = abs(units) / units; // either 1 or -1
       // reset motor encoders
       resetDriveEncoders();
       gyro.reset();
       // drive forward until units are reached
       setDrive(-voltage * direction, voltage * direction);
       while (int(avgDriveEncoderValue) < abs(units))
       {
       pros::delay(10);
       }

       // brief brake
       setDrive(-10 * direction, -10 * direction);
       pros::delay(10);
       // set drive back to neutral
       setDrive(0, 0);
    }

void rotate(int degrees, int voltage) {
    //define direction, based on the units provided
    int direction = abs(degrees) / degrees;
    //resetting the gyro
    gyro.reset();
    //turn until units -5 degrees are reached to compensate for momentum
     setDrive(-voltage * direction, voltage * direction);
    while(fabs(gyro.get_value()) < (degrees * 10) -50) {
        pros::delay(10);
    }

    //letting bot lose momentum
    pros::delay(100);
    //correcting for overshoot or undershoot
    if((fabs(gyro.get_value()) > degrees * 10)) {
        setDrive(0.5* voltage * direction, 0.5* -voltage * direction);
        while ((fabs(gyro.get_value()) > degrees * 10)) {
            pros::delay(10);
        }
        
    }
    else if (fabs(gyro.get_value()) < (degrees * 10)) {
         setDrive(0.5* -voltage * direction, 0.5* voltage * direction);
         while ((fabs(gyro.get_value()) > degrees * 10)) {
            pros::delay(10);
        }
    }
    //reset drive to zero
setDrive(0, 0);
}