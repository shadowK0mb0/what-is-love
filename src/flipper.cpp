#include "main.h"

Motor flipper(FLIPPER, MOTOR_GEARSET_18, 1, MOTOR_ENCODER_DEGREES);

bool flipDown = false;
bool flipUp = false;
bool counting = false;
int height = 0;
int count = 0;
int lastHeight = 0;
static int lowval = -108;

void flip(int vel){
  if (vel > 0 && flipper.get_position() < 0 ) {
    flipper.move(vel);
  } else if (vel < 0 && flipper.get_position() > lowval*3) {
    flipper.move(vel);
  } else {
    flipper.set_brake_mode(MOTOR_BRAKE_HOLD);
    flipper.move(0);
  }
  if (vel > 0) {
    flipUp = !flipperTooHigh();
  }
  if (vel < 0) {
    flipDown = flipper.get_position() > lowval*3;
  }
}

bool flipperDown() {
  return flipper.get_position() <  -240;
}

bool flipperTooHigh() {
  return (flipper.get_position() > 0);
}

void flipperUpAsync() {
  setFlipperAsync(0);
}

void flipperDownAsync() {
  setFlipperAsync(lowval*3);
}

void setFlipperAsync(int sp) {
  sp *= 3; // gear ratio compensation
  flipper.move_absolute(sp, 200);
}

void flipperTask(void* parameter){
  while(1) {
    /*if (flipDown) {
      flip(-80);
    } else if (flipUp) {
      flip(110);
    } else {
      flip(0);
    }*/
    delay(20);
  }
}

void flipperOp(){
  static int vel;
  /*// up
  if (flipper.get_position() < -310) {
    vel = -40;
  } else if (flipper.get_position() > 0 ) {
    vel = 40;
  }
  if(master.get_digital(DIGITAL_LEFT)){ // checks that the flipper is not dangerously far down
    vel = 110;
  // down
  }else if(master.get_digital(DIGITAL_UP)){ // checks that the flipper is not dangerously far up
    vel = -80;
  }else{
    vel = 0;
  }*/
  if (flipper.get_position() < lowval*3) {
    vel = 40;
  } else if (flipper.get_position() > 0 ) {
  vel = -40;
  } else {
    vel = 0;
  }
  if (master.get_digital_new_press(DIGITAL_UP) && height == 0)
    height = lowval;
    counting = true;

  if (master.get_digital_new_press(DIGITAL_LEFT) && height == lowval)
    height = 0;
    counting = true;

  if (counting) {
    lastHeight = flipper.get_position();
    if (height == 0) {
      flip(127);
    } else if (height == lowval) {
      setFlipperAsync(height);
    }
    if (abs((int) flipper.get_position() - lastHeight) < 4){
      count++;
    }
    if (count == 5){
      counting = false;
      count = 0;
    }
  }
}
