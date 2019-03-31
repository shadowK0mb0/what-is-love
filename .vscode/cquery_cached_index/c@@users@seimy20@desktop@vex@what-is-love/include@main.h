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
#include "flipper.hpp"
#include "pros/apix.h"
#include "gui.hpp"

//ports
#define LEFTFRONT 3
#define LEFTREAR 2
#define RIGHTFRONT 4
#define RIGHTREAR 1
#define LAUNCHER 10
#define LIFT 5
#define INTAKE 8
#define FLIPPER 6
#define VISION_PORT 7
#define GREEN_SIG 3
#define POTENTIOMETER_PORT 'A'


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
