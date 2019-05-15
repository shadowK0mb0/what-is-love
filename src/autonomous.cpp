#include "main.h"



//definition of a tile in encoder ticks
#define TL *635

ADIDigitalIn bypass('A');

/**helper stuff**/

void getBack() {
  drive(-1 TL);
  turn(-106);

  // line up with wall
  driveAsync(-2.3 TL);
  while(drivePos() > -1.9 TL) delay(20);
  setSpeed(40);
  while(isDriving()) delay(20);

  // get to alliance park
  drive(.22 TL);
  turn(111);
  driveAsync(-0.7 TL);
  while (!trackerTriggered()) delay(20);
  drive(0);
  drive(-1.5 TL);
  // turn and bang wall to align
  turn(-113);
  drive(-.4 TL);
  drive(1.4 TL);
  //alliance park
  intake(127);
  //alliance park
  driveAsync(1.5 TL);
  while(drivePos() < .9 TL) delay(20);
  while(isDriving()) delay(20);
  setSpeed(40);
  while(isDriving()) delay(20);
  //center park
  driveAsync(1.52 TL);
  while(drivePos() < .85 TL) delay(20);
  drive(-1);
  reset();
}

/*********************************************************/


void bigBoiDelay(){
  int startTime = millis();
  //intake ball under the nearest cap
  intakeBall();
  driveAsync(1.96 TL);
  while(drivePos() < 1.77 TL) delay(20);
  setSpeed(40);
  while(isDriving()) delay(20);

  delay(100);

  //back up against wall
  drive(-2.1 TL);

  //align with flags
  drive(.22 TL);
  turn(105);

  intakeStop();
  drive(0.3 TL);
  //launch the balls
  while(!isFired()) {
    cataThrow();
  }
  cataLoadAsync();
  //toggle low flag
  turn(13);
  intakeBall();
  driveAsync(2.25 TL);
  while(drivePos() < 1.7 TL) delay(20);
  setSpeed(40);
  while(isDriving()) delay(20);

  //backup to align with next cap
  drive(-1.1 TL);



  //line up with the wall

  turn(-103);
  drive(-.5 TL);
  intake(-120);
  //flip next cap
  //flipperDownAsync();
  drive(1.2 TL);

  //shoot flags in the center


  turn(57);
  while(millis() - startTime < 14500) delay(20);
  while(!isFired()) {
    cataThrow();
  }
  cataLoadAsync();

}

void bigScrapBoi() {
  int startTime = millis();
  //intake ball under the nearest cap
  intakeBall();
  drive(1.95 TL);
  while(drivePos() < 1.77 TL) delay(20);
  setSpeed(40);
  while(isDriving()) delay(20);
  drive(-2.1 TL);
  intakeStop();

  //align with flags
  drive(.22 TL);
  turn(105);

  intakeStop();
  drive(0.3 TL);
  //launch the balls
  while(!isFired()) {
    cataThrow();
  }
  cataLoadAsync();
  //toggle low flag
  turn(13);

  driveAsync(1.4 TL);
  while(drivePos() < 1.2 TL) delay(20);
  flip(-100);
  while(isDriving()) delay(20);
  flip(100);
  //backup to align with next cap
  drive(-1.55 TL);
  flip(0);

  turn(-65);
  //flip next cap
  driveAsync(0.75 TL);
  while(drivePos() < 0.4) delay(20);
  setSpeed(60);

  while(isDriving()) delay(20);

  flip(-120);
  delay(280);

  driveAsync(-0.5 TL);

  intake(120);
  delay(100);
  flip(100);
  while(drivePos() > -0.4) delay(20);
  delay(100);
  flip(0);

  //intake(0);
  intake(0);
  delay(80);
  intake(120);
  delay(1300);
  driveAsync(1.1 TL);
  while (drivePos() < 0.77) delay(20);
  intake(-120);
  while(isDriving()) delay(20);

  //driveAsync(0.35 TL);
  //setSpeed(40);
  //while(isDriving()) delay(20);
  /*drive(0.2 TL);
  flipperUpAsync();
  delay(2000);*/

  //delay(2000);
  //intake(-30);


  while (millis() - startTime < 14750) delay(20);
  while(!isFired()) {
    cataThrow();
  }
  cataLoadAsync();

  //shoot flags in the center
  /*intakeStop();

  turn(50);
  while(!isFired()) {
    cataThrow();
  }
  cataLoadAsync();
  intake(0);
  driveAsync(1.5 TL);
  while(drivePos() < .6 TL) delay(20);
  setSlant(35);
  delay(450);*/

}

void scrapBoi2 () {
  int startTime = millis();
  //intake ball under the nearest cap
  intakeBall();
  driveAsync(1.92 TL);
  while(drivePos() < 1.77 TL) delay(20);
  setSpeed(40);
  while(isDriving()) delay(20);
  delay(100);
  drive(-2 TL);
  drive(0.5 TL);
  turn(-50);
  driveAsync(0.45 TL);
  while(drivePos() < 0.4) delay(20);
  setSpeed(40);
  while(isDriving()) delay(20);
  while(!isFired()) {
    cataThrow();
  }
  cataLoadAsync();
  flip(-100);

  delay(250);
  flip(0);
  drive(-0.6 TL);
  intakeBallAsync();
  intake(120);
  delay(1000);
  intake(120);
  drive(-0.34 TL);
  intake(120);
  delay(1000);
  //intake(0);
  intake(120);
  drive(-0.5 TL);
}

void biggestBoi() {
  //intake ball under the nearest cap
  intakeBall();
  drive(2 TL);

  //back up against wall
  drive(-2.1 TL);

  //align with flags
  drive(.22 TL);
  turn(106);
  intakeStop();
  //launch the balls
  while(!isFired()) {
    cataThrow();
  }
  cataLoadAsync();
  //toggle low flag
  turn(13);
  intakeBall();
  driveAsync(2.3 TL);
  while(drivePos() < 1.7 TL) delay(20);
  setSpeed(40);
  while(isDriving()) delay(20);

  //backup to align with next cap
  drive(-1.1 TL);
  intakeStop();
  //line up with the wall
  turn(-109);
  drive(-.5 TL);

  //flip next cap
  intakeBall();

  driveAsync(.9 TL); // down from 1.5
  while(drivePos() < .8 TL) delay(20);
  setSpeed(80);
  flipperDownAsync();
  setSpeed(50);

  while(isDriving()) delay(20);
  intake(0);

  drive(-.3 TL); // down from -0.3

  //shoot flags in the center
  turn(50);
  while(!isFired()) {
    cataThrow();
  }
  cataLoadAsync();

  driveAsync(1.5 TL);
  while(drivePos() < .6 TL) delay(20);
  setSlant(25);
  delay(400);
}

void flagAndPlat(){
  //intake ball under the nearest cap
  intakeBall();
  drive(2 TL);

  //back up against wall
  drive(-2.1 TL);

  //align with flags
  drive(.22 TL);
  turn(108);
  intakeStop();
  delay(500);
  //launch the balls
/*  while(!isFired()) {
    cataThrow();
  }
  cataLoadAsync();*/
  //toggle low flag
  turn(13);
  intakeBall();
  driveAsync(2.3 TL);
  while(drivePos() < 1.7 TL) delay(20);
  setSpeed(40);
  while(isDriving()) delay(20);

  //backup to align with alliance park
  drive(-3.3 TL);
  intakeStop();
  // turn and bang wall to align
  turn(-113);
  drive(-.4 TL);
  drive(1.4 TL);
  //alliance park
  driveAsync(1.5 TL);
  while(drivePos() < .9 TL) delay(20);
  drive(-1);
}

void adi(){
  //intake ball under the nearest cap
  uint32_t startTime = millis();
  uint32_t currTime = millis();
  while(currTime - startTime < 15000) {
    delay(100);
    currTime = millis();
  }
  drive(-1);
}




/*********************************************************/
void backSquare(){
  //cap throw
  driveAsync(-1.9 TL);
  while(drivePos() > -1.7 TL) delay(20);
  setLiftAsync(200);
  while(isDriving()) delay(20);
  turn(-135);
  delay(500);


  //retract lift
  lift(-127);
  delay(800);
  lift(0);

  //align with wall
  turn(-35);
  drive(-1.2 TL);
  turn(90);
  drive(-.6 TL);

  //align with cap
  drive(1.1 TL);
  turn(-90);

  //intake ball under the cap
  intakeBallAsync();
  drive(1 TL);

  //align for park
  drive(-.3 TL);
  turn(90);
  drive(.8 TL);

  //alliance park
  driveAsync(1.6 TL);
  while(drivePos() < .9 TL) delay(20);
  drive(-1);
}


/*********************************************************/
void delayShotBack(){
  //intake ball under the nearest cap
  intakeBallAsync();
  drive(1.9 TL);

  //back up against wall
  drive(-2 TL);

  //align with flags
  drive(.2 TL);
  turn(87);
  drive(2.05 TL);
  turn(-90);
  drive(-.5 TL);
  drive(.22 TL);
  turn(84);

  //launch the balls
  shoot();
  ratchetAsync();
  intake(127);
  while(!isLoaded()) delay(20);
  shoot();
  ratchetAsync();

  //toggle low flag
  turn(13);
  loadBallAsync();
  driveAsync(2.3 TL);
  while(drivePos() < 1.7 TL) delay(20);
  setSpeed(40);
  while(isDriving()) delay(20);

  //align for park
  drive(-3 TL);
  turn(-90);

  //alliance park
  intake(127);
  driveAsync(2.9 TL);
  while(drivePos() < 2.4 TL) delay(20);
  setSpeed(20);
  while(isDriving()) delay(20);
  driveAsync(.4 TL);
  setSpeed(40);
  while(isDriving()) delay(20);
}

void backAuton(){
  //intake ball under the nearest cap
  intake(70);
  drive(1.8 TL);
  /*while(drivePos() < 1 TL) delay(20);
  intakeBall();
  while(isDriving()) delay(20);
  intakeStop(); */

  //back up against wall
  intake(45);
  drive(-0.4 TL);
  intake(0);
  turn(115);
  drive(0.4 TL);

  //align with flags
  drive(-0.18 TL);
  turn(-54);
  drive(-0.45 TL);

  //launch the balls
  while(!isFired()) {
    cataThrow();
  }
  cataLoadAsync();

  delay(500);
  intake(-35);
  delay(200);
  intake(127);
  delay(1600);
  intake(0);

  drive(-0.9 TL);
  while(!isFired()) {
    cataThrow();
  }
  cataLoadAsync();
  /*
  shoot();
  ratchetAsync();
  intake(127);
  while(!isLoaded()) delay(20);
  shoot();
  ratchetAsync();

  //toggle low flag
  turn(13);
  loadBallAsync();
  driveAsync(2.3 TL);
  while(drivePos() < 1.7 TL) delay(20);
  setSpeed(40);
  while(isDriving()) delay(20);

  //align for park
  drive(-3 TL);
  turn(-90);

  //alliance park
  intake(127);
  driveAsync(2.9 TL);
  while(drivePos() < 2.4 TL) delay(20);
  setSpeed(20);
  while(isDriving()) delay(20);
  driveAsync(.4 TL);
  setSpeed(40);
  while(isDriving()) delay(20);*/
}

void rightTurn(){
  turn(-40);
}

void leftTurn(){
  turn(-45);
  delay(1000);
  turn(45);
  delay(1000);
  turn(90);
  delay(1000);
  turn(-90);
  delay(1000);
}

/*********************************************************/
void skills(){
  //intake ball and flip cap
  intake(-80);
  driveAsync(2.4 TL);
  while(drivePos() < 2.2 TL) delay(20);
  intakeBallAsync();

  //back up against wall
  drive(-2.5 TL);

  //align with flags
  drive(.2 TL);
  turn(87);
  drive(2.05 TL);
  turn(-90);
  drive(-.5 TL);
  drive(.22 TL);
  turn(84);

  //launch the balls
  shoot();
  ratchetAsync();
  intake(127);

  while(!isLoaded()) delay(20);
  shoot();
  ratchetAsync();

  //toggle low flag
  turn(13);
  loadBallAsync();
  driveAsync(2.3 TL);
  while(drivePos() < 1.7 TL) delay(20);
  setSpeed(40);
  while(isDriving()) delay(20);


  // second flag column =============================

  //backup to align with next cap
  drive(-2.03 TL);
  intake(-127);
  delay(800);
  turn(-90);
  drive(-.5 TL);

  //intake ball and flip cap
  intake(-80);
  driveAsync(2.4 TL);
  while(drivePos() < 2.2 TL) delay(20);
  intakeBallAsync();

  //align with flags
  drive(-.24 TL);
  turn(79);

  //shoot both flags
  shoot();
  ratchetAsync();
  intake(127);
  while(!isLoaded()) delay(20);
  shoot();
  ratchetAsync();

  //toggle the low flag
  turn(12);
  loadBallAsync();
  drive(2.3 TL);

  // third column low flag ============================

  //align with cap
  drive(-1.15 TL);
  turn(88);

  //flip cap
  intake(-80);
  driveAsync(1.25 TL);
  setSpeed(60);
  while(isDriving()) delay(20);

  //flip next cap
  drive(-.3 TL);
  turn(176);
  intake(-60);
  driveAsync(3.1 TL);
  while(drivePos() < 1.5 TL) delay(20);
  setSpeed(80);
  while(drivePos() < 1.9 TL) delay(20);
  setSpeed(60);
  while(isDriving()) delay(20);

  //low flag
  drive(-.2 TL);
  intake(127);
  turn(90);
  driveAsync(1.6 TL);
  while(drivePos() < .5 TL) delay(20);
  setSpeed(60);
  while(isDriving()) delay(20);

  // last flags and park ============================

  //shoot flag
  drive(-2 TL);
  turn(-19);
  shoot();

  //align against the wall
  turn(-81);
  intake(-127);
  drive(1.4 TL);

  //align for park
  drive(-.7 TL);
  turn(-90);
  drive(1.14 TL);
  turn(-90);
  drive(.4 TL);

  //alliance park
  intake(127);
  driveAsync(1.9 TL);
  while(drivePos() < 1.4 TL) delay(20);
  setSpeed(20);
  while(isDriving()) delay(20);
  driveAsync(.4 TL);
  setSpeed(40);
  while(isDriving()) delay(20);

  //center park
  driveAsync(1.6 TL);
  while(drivePos() < .85 TL) delay(20);
  drive(-1);
  reset();
}

void platformAuton() { // gtg
  intakeBall();
  drive(1.9 TL);
  drive(-0.3 TL);
  intakeStop();
  turn(103);
  setSpeed(40);
  while(isDriving()) delay(20);

  drive(1.46 TL);


}

void platAuton()
 {

     intakeBall();
     drive(1.92 TL);
     while(drivePos() < 1.77 TL) delay(20);
     setSpeed(40);
     while(isDriving()) delay(20);
     drive(-0.3 TL);
     intakeStop();
     turn(103);
     setSpeed(40);
     while(isDriving()) delay(20);
     drive(1.46 TL);
 }


void test2() {
  //intake ball and flip cap
  intake(-80);
  driveAsync(2.4 TL);
  while(drivePos() < 2.2 TL) delay(20);
  intakeBallAsync();

  //back up against wall
  drive(-2.5 TL);
}

void test3() {


  flip(-50);
  delay(200);
  flip(0);
  delay(3000);
}

void autonomous() {
  reset(); // reset the drive encoders

  Task drive_task(driveTask);
  Task turn_task(turnTask);
  Task intake_task(intakeTask);
  Task launcher_task(launcherTask);
  Task flipper_task(flipperTask);


  switch(auton){
    case 0:
      bigBoiDelay();
      //rightTurn();
      //delay(2000);
      //leftTurn();
      //bigScrapBoi();

      break;
    case 1:
      platAuton();
      break;
    case 2:
      flagAndPlat();
      break;
    case 3:
      //scrapBoi2();
      leftTurn();
      break;
    case 4:
      bigScrapBoi();
      break;
    case 5:
      backAuton();
      break;
  }

  drive_task.remove();
  turn_task.remove();
  intake_task.remove();
  launcher_task.remove();
  flipper_task.remove();
}
