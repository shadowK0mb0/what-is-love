#include "main.h"

Controller master(CONTROLLER_MASTER);

void opcontrol() {
	static bool liftMode = false;
	while (true){
		driveOp();
		intakeOp();
		launcherOp();
		liftOp();
		flipperOp();

		if (master.get_digital(DIGITAL_UP) && !competition::is_connected()){
			autonomous();
		} else if (master.get_digital(DIGITAL_UP)) {
			master.rumble("-");
		} else if (master.get_digital(DIGITAL_LEFT)) {
			master.rumble(".");
		}
		master.print(0, 0, "%d", heightIndexGet());
		delay(10);
	}
}
