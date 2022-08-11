/*

fork() -> create child process with its own pid
it will duplicate all the excution steps after it is called

*/

#include <myHeader.h>

int main()
{
	int pid;

	pid = fork();
	if(pid == 0)
	{
		cout<<"This is child process"<<endl;
		cout<<"pid from fork = "<<pid<<endl;
		cout<<"PID : "<<getpid()<<endl;
		cout<<"PPID : "<<getppid()<<endl;
	}
	else
	{
		cout<<"This is a parent process"<<endl;
		cout<<"pid from fork = "<<pid<<endl;
		cout<<"PID : "<<getpid()<<endl;
		cout<<"PPID : "<<getppid()<<endl;
	}

	cout<<"Hello World"<<endl;

	return 0;
}