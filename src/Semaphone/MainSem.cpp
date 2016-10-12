#include "../../include/MainSem.h"
using namespace std;

//初始化信号量
 void MainSem::initSem(){
    int res = -1;
    //初始驱动子线程的信号量为0
    res = sem_init(&sem_socket, 0, 0);  
    ShowError(res);
    //初始化子线程的信号量为1  
    res = sem_init(&sem_socket_return, 0, 1);  
    ShowError(res);
}


//错误信息
void MainSem::ShowError(int res){
	switch(res){
		case -1:
			 cout<<"信号量初始失败\n";
			 // std::exit(EXIT_FAILURE);  
	           break;
	     // default:
	     // 	 perror("进程创建失败\n");  
      //   		 exit(EXIT_FAILURE);
	}
}

//清理信号量  
void MainSem::deleteSem(){
    sem_destroy(&sem_socket);  
    sem_destroy(&sem_socket_return); 
}

int MainSem::getSem(sem_t s){
    int value;
    sem_getvalue(&s,&value);
    return value;
}
