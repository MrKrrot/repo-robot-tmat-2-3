/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "Funciones.h"

using namespace vex;

competition Competition;


void pre_auton(void) {
  vexcodeInit();
  // DrivetrainInertial.calibrate();
}

void autonomous(void) {
   thread myThread = thread(bajarBrazos);
   avanzar(2, 100,50);//64 55 53
   piston_enfrente.set(1);//
   BRosa.spinFor(250,degrees);//300
   avanzar(1, 100, 25);//Hola aqui estoy
   girarA(20);
   //Drivetrain.turnFor(left, 20, degrees);
   BAzul.spinFor(250, degrees);
   avanzar(2, 100, 10);
}

void usercontrol(void) {
  clean();
  detener();
  torqe();
  velocidad();
  int x=1,y=3,z=1, g=2;
  while (1) {
    if(Controller1.ButtonRight.pressing()&& g==2){
      g=1;
    }
    else if (Controller1.ButtonRight.pressing()&& g==1) {
      g=2;
    }

    if(g==2){
    LeftDriveSmart.spin(reverse,Controller1.Axis3.value(),percent); 
    RightDriveSmart.spin(reverse,Controller1.Axis2.value(),percent);
    }
    if(g==1){
    LeftDriveSmart.spin(forward,Controller1.Axis3.value(),percent); 
    RightDriveSmart.spin(forward,Controller1.Axis2.value(),percent);
    }


    if(Controller1.ButtonL1.pressing()){
      BRosa.spin(forward);
    }
    else if (Controller1.ButtonL2.pressing()) {
      BRosa.spin(reverse);
    }
    else{
      BRosa.stop(hold);
    }

    if(Controller1.ButtonR1.pressing()){
      BAzul.spin(forward);
    }
    else if (Controller1.ButtonR2.pressing()) {
      BAzul.spin(reverse);
    }
    else{
      BAzul.stop(hold);
    }

    if(Controller1.ButtonB.pressing()&&x==1){
      x=2;
      task::sleep(200);
      actuador.set(0);
    }
    else if(Controller1.ButtonB.pressing()&&x==2){
      x=1;
      task::sleep(200);
      actuador.set(1);
    }

    if(Controller1.ButtonDown.pressing()&&z==1){
      z=2;
      task::sleep(200);
      piston_enfrente.set(0);
    }
    else if(Controller1.ButtonDown.pressing()&&z==2){
      z=1;
      task::sleep(200);
      piston_enfrente.set(1);
    }

    if(Controller1.ButtonA.pressing()){
      y=2;
    }
    else if (Controller1.ButtonX.pressing()) {
      y=1;
    }
    else if(Controller1.ButtonY.pressing()){
      y=3;
    }


    if(y==1){
      Banda.spin(forward);
    }
    else if(y==2){
      Banda.spin(reverse);
    }
    else{
      Banda.stop(hold);
    }

    wait(20, msec); 
  }
}



int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
