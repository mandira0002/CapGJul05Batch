#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main()
{

	int pid, status=101;
	cout<<"Welcome"<<endl;
	pid = fork();
	if(pid > 0){
		cout<<"b status: "<<status<<"\tAddress :"<<&status<<endl;
		wait(&status);
		cout<<"parent pid: "<<getpid()<<endl;
		cout<<"PID : "<<pid<<endl;
		cout<<"a status: "<<status/256<<"\tAddress :"<<&status<<endl;
	}
	else
	{
		cout<<"Child its pid: "<<getpid()<<endl;
		cout<<"Parent pid: "<<getppid()<<endl;
		cout<<"before status: "<<status<<"\tAddress :"<<&status<<endl;	
		status = 10;
		cout<<"PID : "<<pid<<endl;
		cout<<"after status: "<<status<<"\tAddress :"<<&status<<endl;
		exit(status);	
	}

	return (EXIT_SUCCESS);
}
