#include "main.h"

Motor flipper(FLIPPER, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES);

void flip(int vel){
  flipper.move(vel);
}

void flipperOp(){
  static int vel;
  if(master.get_digital(DIGITAL_L1) && flipper.get_raw_position(NULL) > 0) // checks that the flipper is not dangerously far down
    vel = 110;
  else if(master.get_digital(DIGITAL_L2) && flipper.get_raw_position(NULL) < 550) // checks that the flipper is not dangerously far up
    vel = -80;
  else
    vel = 0;
  flip(vel);
}
