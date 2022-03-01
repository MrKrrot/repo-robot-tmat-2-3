#include "Componentes.h"

void vexcodeInit( void ) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain Inertial
  wait(200, msec);
  DrivetrainInertial.calibrate();
  Brain.Screen.print("Calibrating Inertial for Drivetrain");
  // wait for the Inertial calibration process to finish
  while (DrivetrainInertial.isCalibrating()) {
    wait(25, msec);
  }
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1,1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}

void clean(){
  BAzul.resetRotation();
  BRosa.resetRotation();
}
void detener(){
  Drivetrain.stop(hold);
  BAzul.stop(hold);
  BRosa.stop(hold);
}
void velocidad(){
  Drivetrain.setDriveVelocity(100,pct);
  BAzul.setVelocity(100,pct);
  BRosa.setVelocity(100,pct);
  Banda.setVelocity(100,pct);
}
void torqe(){
  LeftDriveSmart.setMaxTorque(100, pct);
  RightDriveSmart.setMaxTorque(100, pct);
  BAzul.setMaxTorque(100,pct);
  BRosa.setMaxTorque(100,pct);
}

void avanzar(int direccion, int velocidad, int distancia){
  if(direccion==1){
    Drivetrain.setDriveVelocity(velocidad,pct);
    Drivetrain.driveFor(forward,distancia,inches);
  }
  else if(direccion==2){
    Drivetrain.setDriveVelocity(velocidad,pct);
    Drivetrain.driveFor(reverse,distancia,inches);
  }
  else{
    Drivetrain.stop(hold);
  }
}

void girar(int grados){
  Drivetrain.turnFor(grados, degrees);
}

void girarA(int grados){
  Drivetrain.turnToRotation(grados,degrees);
}

void Brosas(int grados){
    BRosa.spinFor(grados, degrees);
}

void Bazules(int grados){
    BAzul.spinFor(grados, degrees);
}

int bajarBrazos() {
  int count = 0;
  BRosa.setVelocity(100,percent);
  BRosa.spinFor(-400,degrees);//300
    this_thread::sleep_for(30);// 25
  return 0;
}
