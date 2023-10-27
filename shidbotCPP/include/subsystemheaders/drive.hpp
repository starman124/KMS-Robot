#include "main.h"

//Helper functions
void setDrive(int driveleft, int driveright);

void resetDriveEncoders();

double avgDriveEncoderValue();

//Driver control functions
void setDriveMotors();

//Autonomous functions
void translate(int units, int voltage);

void rotate(int degrees, int voltage);