#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

controller Controller1 = controller(primary);
bool RemoteControlCodeEnabled = true;

// VEXcode device constructors
motor l1 = motor(PORT1, ratio6_1, true);
motor l2 = motor(PORT2, ratio6_1, false);
motor l3 = motor(PORT3,ratio6_1,true);
motor l4 = motor(PORT4,ratio6_1,false);
motor_group LeftDriveSmart = motor_group(l1,l2,l3,l4);

motor r1 = motor(PORT5, ratio6_1, false);
motor r2 = motor(PORT6, ratio6_1, true);
motor r3 = motor(PORT7, ratio6_1, false);
motor r4 = motor(PORT8, ratio6_1, true);
motor_group RightDriveSmart = motor_group(r1, r2,r3,r4);

inertial DrivetrainInertial = inertial(PORT12);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainInertial, 299.24, 320, 40, mm, 0.6666666666666666666666666);

motor BRosaMotorA = motor(PORT10, ratio36_1, false);
motor BRosaMotorB = motor(PORT9, ratio36_1, true);
motor_group BRosa = motor_group(BRosaMotorA, BRosaMotorB);
motor BAzulMotorA = motor(PORT18, ratio18_1, false);
motor BAzulMotorB = motor(PORT19, ratio18_1, true);
motor_group BAzul = motor_group(BAzulMotorA, BAzulMotorB);

motor Banda = motor(PORT17,ratio18_1,false);

digital_out actuador = digital_out(Brain.ThreeWirePort.G);
digital_out piston_enfrente = digital_out(Brain.ThreeWirePort.H);