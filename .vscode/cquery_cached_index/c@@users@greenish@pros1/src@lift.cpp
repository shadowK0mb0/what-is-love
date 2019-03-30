#include "main.h"



const int setHeights[3] = {0, 128, 350};
int heightIndex = 0;


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
  lift1.move_absolute(sp, 100);
}

void setLift(int sp){
  setLiftAsync(sp);
  int sv = lift1.get_position();
  while(sv != sp) delay(20);
}

int heightIndexGet() {
  return heightIndex;
}



/**************************************************/
//operator control
void liftOp(){


  /*if(master.get_digital(DIGITAL_DOWN)){
    //if(lift1.get_position() < 500)
    vel = 127; // go up
    //else
    //vel = 60;
  }else if(master.get_digital(DIGITAL_RIGHT) && lift1.get_raw_position(NULL) > 0){
    vel = -127; // down
  }
  else{
    vel = 0;
  }*/
  if (master.get_digital_new_press(DIGITAL_DOWN) && heightIndex < 2)
    heightIndex++;
    setLiftAsync(setHeights[heightIndex]);

  if (master.get_digital_new_press(DIGITAL_RIGHT) && heightIndex > 0)
    heightIndex--;
    setLiftAsync(setHeights[heightIndex]);




  if (heightIndex == 0) {
    if (lift1.get_raw_position(NULL) > 2)
      lift(-127); // down
    else
      lift(0);
  }




}
