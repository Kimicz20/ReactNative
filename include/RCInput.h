// Definition of the RCInput class

#ifndef RCInput_class
#define RCInput_class

#include <string>
#include <ctime>
#include <iostream>


class RCInput{
public:

	int roll_pwm;
	int pitch_pwm;
	int yaw_pwm;
	int throttle_pwm;
	int roll_control_in;
	int pitch_control_in;
	int yaw_control_in;
	int throttle_control_in;
	bool has_new_input;

	void send_radio(int roll,int pitch,int yaw,int throttle);
	void set_new_input(bool has_new_input);
	void set_pwm_all();
};

#endif