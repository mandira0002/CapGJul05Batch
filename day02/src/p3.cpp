/*

fork() -> create child process with its own pid
it will duplicate all the excution steps after it is called

*/

#include <myHeader.h>

int main()
{
	int pid;

	pid = fork();
	if(pid > 0)
	{
		sleep(30);
		cout<<"This is a parent process"<<endl;
		cout<<"pid from fork = "<<pid<<endl;
		cout<<"PID : "<<getpid()<<endl;
		cout<<"PPID : "<<getppid()<<endl;
	}

	else if(pid == 0)
	{

		cout<<"This is a child process"<<endl;
		cout<<"pid from fork = "<<pid<<endl;
		cout<<"PID : "<<getpid()<<endl;
		cout<<"PPID : "<<getppid()<<endl;
		exit(0);
	}
	else
		cout<<"Fork failed"<<endl;

	cout<<"Hello World"<<endl;

	return 0;
}