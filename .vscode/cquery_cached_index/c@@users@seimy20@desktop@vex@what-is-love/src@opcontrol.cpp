#include "main.h"

Controller master(CONTROLLER_MASTER);

void opcontrol() {
	static bool liftMode = false;
	while (true){
		driveOp();
		intakeOp();
		launcherOp();

		if (master.get_digital(DIGITAL_UP)) {
			liftMode = false;
		} else if (master.get_digital(DIGITAL_DOWN)) {
			liftMode = true;
		}

		if (liftMode){
			liftOp();
		} else {
			flipperOp();
		}

		if (master.get_digital(DIGITAL_RIGHT) && !competition::is_connected()){
			autonomous();
		}
		delay(10);
	}
}
