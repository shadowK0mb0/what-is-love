#include "main.h"

static int launcherTarget = 0;
const int ratchetDistance = 50;
bool cataLoad = false;
bool cataThrowing = false;
int lastPotVal = 0;
int cataStuckCount = 0;

//motors
Motor launcher1(LAUNCHER, MOTOR_GEARSET_36, 1, MOTOR_ENCODER_DEGREES);

//line sensors
ADIAnalogIn line('G');

//potentiometer
ADIPotentiometer pot('A');

/**************************************************/
//basic control
void launcher(int vel){
  launcher1.move(vel);
}

/**************************************************/
//feedback
bool isFired(){
  return(pot.get_value() < 1600);
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
//PID
bool cataSet(int dist){
  int potVal = pot.get_value();
  int error = dist - potVal;
  if (potVal > 1950) {
    if (launcher1.is_over_temp() == 1 || launcher1.is_over_current() == 1) {
      return false;
    }
    if (lastPotVal - potVal < 1) {
      cataStuckCount++;
    }
  }
  if (cataStuckCount > 5) {
    cataStuckCount = 0;
    return false;
  }
  double kp = 0.8;
  double propError = 0;

  if(abs(error) > 2){
    error = dist - potVal;
    propError = error * kp;
    if (propError < 0){
        propError = 0;
    }
    launcher((int)propError);
    delay(20);
  }

  int lastPotVal = potVal;
  return(error > 2);
}



bool cataThrow(){
  int potVal = pot.get_value();
  if (launcher1.is_over_temp() == 1 || launcher1.is_over_current() == 1) {
    return false;
  }
  if (potVal > 1600){
    launcher(120);
  }else{
    launcher(0);
  }
  lastPotVal = potVal;
  return(potVal > 1600);
}

bool isCatapultLoaded() {
  return (2400 - pot.get_value()) > 10;
}






/**************************************************/
//operator control
void launcherOp(){
  launcher1.set_current_limit(2700); // SUSSSS
  /*static int vel = 0;
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
    vel = 127;*/



  if (master.get_digital(DIGITAL_X)){
    cataLoad = true;
  }
  if (master.get_digital(DIGITAL_A)){
    cataThrowing = true;
    cataLoad = true;
  }
  if (master.get_digital(DIGITAL_B)){
    launcher(120);
    cataLoad = false;
    cataThrowing = false;
  }else{
    launcher(0);
  }
  if (cataLoad && !cataThrowing){
    cataLoad = cataSet(2400);
  }
  if (cataThrowing){
    cataThrowing = cataThrow();
  }
}
