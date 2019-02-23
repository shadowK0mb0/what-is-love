#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES

#define PROS_USE_LITERALS

#include "api.h"
#include "drive.hpp"
#include "intake.hpp"
#include "launcher.hpp"
//#include "adjuster.hpp"
#include "lift.hpp"
#include "pros/apix.h"
#include "gui.hpp"

//ports
#define LEFTFRONT 9
#define LEFTREAR 10
#define RIGHTFRONT 20
#define RIGHTREAR 8
#define LAUNCHER 13
#define ADJUSTER 18
#define LIFT 1
#define INTAKE 2
#define VISION_PORT 19
#define GREEN_SIG 3


using namespace pros;
using namespace pros::literals;

extern Controller master;
extern bool mirror;
extern int auton;

#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
