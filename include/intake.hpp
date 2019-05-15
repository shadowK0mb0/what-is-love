#ifndef _INTAKE_H_
#define _INTAKE_H_

void intake(int vel);

bool hasBall();
bool isLoaded();

void intakeBallAsync();
void loadBallAsync();
void intakeBall();
void intakeStop();
void loadBall();
void intakeBallAsync();

void intakeTask(void* parameter);

void intakeOp();

#endif
