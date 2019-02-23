#include "main.h"

static int launcherTarget = 0;
const int ratchetDistance = 50;
static bool cataLoad = false;
static bool cataThrowB = false;

//motors
Motor launcher1(LAUNCHER, MOTOR_GEARSET_36, 1, MOTOR_ENCODER_DEGREES);

//line sensors
ADIAnalogIn line('G');
ADIPotentiometer pot (POTENTIOMETER_PORT);

/**************************************************/
//basic control
void launcher(int vel){
  launcher1.move(vel);
}

bool cataSet(int dist){
  int error = dist - pot.get_value();
  double kp = 0.4;
  double propError = 0;
  if (abs(error) > 2){
    error = dist - pot.get_value();
    propError = error * kp;
    if (propError < 0){
      propError = 0;
    }
    launcher((int)propError);
    delay(20);
  }
  return(error > 2);
}

bool cataThrow(){
  int potVal = pot.get_value();
  if (potVal > 1600){
    launcher(100);
  } else {
    launcher(0);
  }
  return(potVal > 1600);
}

/**************************************************/
//feedback
bool isFired(){
  if(line.get_value() < 2000)
    return true;
  else
    return false;
}

/**************************************************/
//autonomous control
void shootAsync(){
  launcherTarget = 1;
}

void ratchetAsync(){
  launcherTarget = 2;
}

void shoot(){
  launcher(127);
  while(!isFired()) delay(20);
  launcher(0);
}

void ratchet(){
  launcher(127);
  while(isFired()) delay(20);
  launcher1.tare_position();
  while(launcher1.get_position() < 50) delay(20);
  launcher(0);
}

/**************************************************/
//task control
void launcherTask(void* parameter){
  while(1){
    delay(20);

    switch(launcherTarget){
      case 1:
        shoot();
        break;
      case 2:
        ratchet();
        break;
    }

    launcherTarget = 0;
  }
}

/**************************************************/
//operator control
void launcherOp(){
  if (master.get_digital(DIGITAL_A)){
    cataLoad = true;
  }
  if (master.get_digital(DIGITAL_B)){
    cataThrowB = true;
    cataLoad = true;
  }
  if (master.get_digital(DIGITAL_X)){
    launcher(85);
    cataLoad = false;
    cataThrowB = false;
  } else {
    launcher(0);
  }
  if (cataLoad){
    cataLoad = cataSet(2200);
  }
  if (cataThrowB) {
    cataThrowB = cataThrow();
    //cataLoad = true;
  }
/*  static int vel = 0;
  static int ready = true;
  static bool first = true;

  launcher(vel);

  if(master.get_digital(DIGITAL_R2)){
    vel = 127;
    first = false;
  }else
    vel = 0;


  static int panic = false;
  if(master.get_digital_new_press(DIGITAL_UP))
    panic = !panic;


  //auto ratcheting
  if(isFired() && !panic && !first){
    ready = false;
    launcher1.tare_position();
  }

  if(launcher1.get_position() > 50)
    ready = true;

  if(!ready)
    vel = 127;
*/


}
