#include "main.h"

Motor flipper(FLIPPER, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES);

bool flipDown = false;
bool flipUp = false;

void flip(int vel){
  if (vel > 0 && flipper.get_position() < 0) {
    flipper.move(vel);
  } else if (vel < 0 && flipper.get_position() > -310) {
    flipper.move(vel);
  } else {
    flipper.move(0);
  }
  if (vel > 0) {
    flipUp = !flipperTooHigh();
  }
  if (vel < 0) {
    flipDown = flipper.get_position() > -310;
  }
}

bool flipperTooHigh() {
  return (flipper.get_position() > - 20);
}

void flipperUpAsync() {
  flipUp = true;
}

void flipperDownAsync() {
  flipDown = true;
}

void flipperTask(void* parameter){
  while(1) {
    if (flipDown) {
      flip(-80);
    } else if (flipUp) {
      flip(110);
    } else {
      flip(0);
    }
    delay(20);
  }
}

void flipperOp(){
  static int vel;
  // up
  if(master.get_digital(DIGITAL_LEFT)){ // checks that the flipper is not dangerously far down
    vel = 110;
  // down
  }else if(master.get_digital(DIGITAL_UP)){ // checks that the flipper is not dangerously far up
    vel = -80;
  }else{
    vel = 0;
  }
  flip(vel);
}
