#include "../../include/Copter.h"
using namespace std;

int main(){

	Copter copter;
	int i = 0;

	//ios_base::fixed 			设置cout为定点输出格式
	//ios_base::floatfield  	设置输出时按浮点格式，小数点后有6位数字
	cout.setf(ios_base::boolalpha);

	cout << "start:\n";
	while (true){ 
		if (clock() % 2000 == 0){
			cout << "index " << ++i << " :" << endl;
			copter.rc_loop();
			cout << copter.ap.new_radio_frame << endl
				<< copter.ap.throttle_zero << endl
				<< copter.failsafe.radio << endl
				<< copter.rc_input.roll_control_in << endl
				<< copter.rc_input.pitch_control_in << endl
				<< copter.rc_input.yaw_control_in << endl
				<< copter.rc_input.throttle_control_in << endl
				<< "---------------------------\n";
		}
	}
	
	return 0;
}