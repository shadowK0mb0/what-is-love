#include "main.h"

static int launcherTarget = 0;
const int ratchetDistance = 50;
bool cataLoad = false;
bool cataThrowing = false;
int lastPotVal = 0;
int cataStuckCount = 0;
int cataLauncherDist = 1500;
int cataLoadDist = 2150;

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
  return (pot.get_value() < cataLauncherDist);
}

/**************************************************/
//autonomous control
void shootAsync(){
  launcherTarget = 1;
}

void ratchetAsync(){
  launcherTarget = 2;
}

void cataLoadAsync() {
  cataLoad = true;
  cataThrowing = false;
}

void cataThrowAsync() {
  cataLoad = true;
  cataThrowing = true;
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

    /*switch(launcherTarget){
      case 1:
        shoot();
        break;
      case 2:
        ratchet();
        break;
    }

    launcherTarget = 0;*/
    if (cataLoad && !cataThrowing){
      cataLoad = cataSet(cataLoadDist);
    } else if (cataThrowing){
      cataThrowing = cataThrow();
    } else {
      launcher(0);
    }
  }
}

/**************************************************/
//PID
bool cataSet(int dist){
  int potVal = pot.get_value();
  int error = dist - potVal;
  if (potVal > cataLauncherDist+50) {
    if (launcher1.is_over_temp() == 1 || launcher1.is_over_current()) {
      master.rumble("..");
      return false;
    }
    if (lastPotVal - potVal < 1 && potVal > cataLoadDist + 100) {
      cataStuckCount++;
    }
  }
  if (cataStuckCount > 20) {
    cataStuckCount = 0;
    return false;
  }
  double kp = 3;
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
  if (launcher1.is_over_temp() == 1) {
    master.rumble("..");
    return false;
  }
  if (potVal > cataLauncherDist){
    launcher(120);
  }else{
    launcher(0);
  }
  lastPotVal = potVal;
  return(potVal > cataLauncherDist);
}

bool isCatapultLoaded() {
  return (cataLoadDist - pot.get_value()) > 10;
}






/**************************************************/
//operator control
void launcherOp(){
  launcher1.set_current_limit(3000); // SUSSSS
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



  if (master.get_digital(DIGITAL_L2) && !master.get_digital(DIGITAL_L1)){
    cataLoad = true;
  }
  if (master.get_digital(DIGITAL_L1) && !master.get_digital(DIGITAL_L2)){
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
    cataLoad = cataSet(cataLoadDist);
  }
  if (cataThrowing){
    cataThrowing = cataThrow();
  }
}
