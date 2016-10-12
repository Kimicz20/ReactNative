#include "../../include/Copter.h"
#include "../../include/SupportClass.h"
using namespace std;

// rc_loops - reads user input from transmitter/receiver
// called at 100hz
void Copter::rc_loop()
{
	Copter::read_radio();
}

void Copter::set_failsafe_radio(bool b){
	supt.testPath[supt.index++] = "set_failsafe_radio->";
	failsafe.radio = true;
}


void Copter::set_throttle_zero_flag(int throttle_control)
{
	static int last_nonzero_throttle_ms = 0;
	int tnow_ms = clock();

	if (throttle_control > 0) {
		last_nonzero_throttle_ms = tnow_ms;
		ap.throttle_zero = false;
	}
	else if (tnow_ms - last_nonzero_throttle_ms > 150000) {  //³¬¹ý150s
		ap.throttle_zero = true;
	}
	supt.testPath[supt.index++] = "set_throttle_zero_flag->";
}

void Copter::read_radio()
{
	static int last_update_ms = 0;	
	
	supt >> rc_input.roll_pwm ;
	supt>> rc_input.pitch_pwm ;
	supt>> rc_input.yaw_pwm ;
	supt>> rc_input.throttle_pwm ;
	supt>> rc_input.has_new_input;
	int tnow_ms = clock();

	if (rc_input.has_new_input) {
		last_update_ms = tnow_ms;
		ap.new_radio_frame = true;
		rc_input.set_pwm_all();
		supt.testPath[supt.index++] = "set_pwm_all->";
		//set_throttle_and_failsafe(rc_input.throttle_control_in);
		set_throttle_zero_flag(rc_input.throttle_control_in);

	}
	else{
		int elapsed = tnow_ms - last_update_ms;
		if (elapsed >= 180000) {  //180Ãë
			set_failsafe_radio(true);
		}
	}
	supt.testPath[supt.index++] = "read_radio->";
}