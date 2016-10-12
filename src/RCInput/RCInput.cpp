#include "../../include/RCInput.h"
using namespace std;

void RCInput::set_pwm_all(){
	roll_control_in = roll_pwm;
	pitch_control_in = pitch_pwm;
	yaw_control_in = yaw_pwm;;
	throttle_control_in = throttle_pwm;
}

void RCInput::set_new_input(bool has_new_input){
	has_new_input = has_new_input;
}

void RCInput::send_radio(int roll,int pitch,int yaw,int throttle){
	roll_pwm = roll;
	pitch_pwm = pitch;
	yaw_pwm = yaw;
	throttle_pwm = throttle;
}
