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

		if (master.get_digital(DIGITAL_X) && !competition::is_connected()){
			autonomous();
		}
		master.print(0, 0, "%d", heightIndexGet());
		delay(10);
	}
}
