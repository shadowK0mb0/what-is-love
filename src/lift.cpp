#include "main.h"


Motor lift1(LIFT, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES);

/**************************************************/
//basic control
void lift(int vel){
  if (vel == 0){
    lift1.set_brake_mode(MOTOR_BRAKE_HOLD);
  }
  lift1.move(vel);
}

void setLiftAsync(int sp){
  sp *= 5; // gear ratio compensation
  lift1.move_absolute(sp, 200);
}

void setLift(int sp){
  setLiftAsync(sp);
  int sv = lift1.get_position();
  while(sv != sp) delay(20);
}

/**************************************************/
//operator control
void liftOp(){
  static int vel;

  /*if(master.get_digital(DIGITAL_))
    setLiftAsync(179);
  else
    lift(vel);*/

  if(master.get_digital(DIGITAL_L1)){
    //if(lift1.get_position() < 500)
    vel = 127;
    //else
    //vel = 60;
  }else if(master.get_digital(DIGITAL_L2) && lift1.get_raw_position(NULL) > 0){
    vel = -127;
  }
  else{
    vel = 0;
  }
  lift(vel);
}
