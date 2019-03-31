#include "main.h"

static int intakeTarget = 0;
static bool intakeIn = false;
static bool intakeOut = false;

//motors
Motor intake1(INTAKE, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES);

//line sensors
ADILineSensor line_L('F');
ADILineSensor line_R('E');
ADILineSensor line_I('H');


/**************************************************/
//basic control
void intake(int vel){
  intake1.move(vel);
}

/**************************************************/
//feedback
bool hasBall(){
  if(line_L.get_value() < 2000 || line_R.get_value() < 2000)
    return true;
  else
    return false;
}

bool isLoaded(){
  if(line_I.get_value() < 2000)
    return true;
  else
    return false;
}

/**************************************************/
//autonomous control
void intakeBallAsync(){
  intakeTarget = 1;
}

void loadBallAsync(){
  intakeTarget = 2;
}

void intakeBall(){
  intake(110);
}

void intakeStop() {
  intake(0);
}

void loadBall(){
  intake(127);
  while(!isLoaded()) delay(20);
  intake(0);
}

/**************************************************/
//task control
void intakeTask(void* parameter){
  while(1){
    delay(20);

    switch(intakeTarget){
      case 1:
        intakeBall();
        break;
      case 2:
        loadBall();
        break;
    }

    intakeTarget = 0;
  }
}

/**************************************************/
//operator control
void intakeOp(){
  static int vel;
  intake1.set_current_limit(2500);

  intake(vel);
  if (!intake1.is_over_temp()) {
    if(master.get_digital(DIGITAL_R1) && !master.get_digital(DIGITAL_R2)) {
      intakeIn = true;
      intakeOut = false;
      vel = 110; // intake
    } else if(master.get_digital(DIGITAL_R2) && !master.get_digital(DIGITAL_R1)) {
      intakeOut = true;
      intakeIn = false;
      vel = -120;
    } else if (master.get_digital(DIGITAL_R1) && master.get_digital(DIGITAL_R2)) {
      if (intakeOut)
        vel = -40;
      else if (intakeIn)
        vel = 40;
    } else {
      intakeOut = false;
      intakeIn = false;
      vel = 0;
    }
  }
}
