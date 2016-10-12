#include "../../include/Copter.h"
#include "../../include/ServerSocket.h"
#include "../../include/SupportClass.h"

using namespace std;

pthread_t socket_thread;

int main(){
	int i = 0;
	int res = -1;
	void *thread_result = NULL;

	//1.创建所需的对象
   	SupportClass supt;
   	supt.index = 0;
   	Copter copter;
   	copter.supt = supt;
   	// copter.supt.supParam.testCaseMap.insert(pair<string,string>("yaw_pwm","1"));
   	ServerSocket serverSocket;

   	//2.创建子线程传输控制模块
   	res = pthread_create(&socket_thread, NULL,serverSocket.serverReceive,&supt.supParam);
   	supt.supParam.totalSem.ShowError(res);

   	//3.等待子线程结束
    	res = pthread_join(socket_thread, &thread_result);
   	supt.supParam.totalSem.ShowError(res);

	while (true){
		if (clock() % 5000000 == 0){
			cout << "index " << ++i << " :" << endl;
			copter.rc_loop();
			cout << copter.ap.new_radio_frame << endl
				<< copter.ap.throttle_zero << endl
				<< copter.failsafe.radio << endl
				<< copter.rc_input.roll_control_in << endl
				<< copter.rc_input.pitch_control_in << endl
				<< copter.rc_input.yaw_control_in << endl
				<< copter.rc_input.throttle_control_in << endl;
				cout<<copter.supt.showPath()<<endl<< "---------------------------\n";
				copter.supt.cleanPath();
			if(i == 5){
				cout<<"程序结束"<<endl;
				break;
			}
		}
	}

	return 0;
}
