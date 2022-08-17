/*

fork() -> create child process with its own pid
it will duplicate all the excution steps after it is called

*/

#include <myHeader.h>

int main()
{

	// cout<<"PID : "<<getpid()<<endl;
	// cout<<"PPID : "<<getppid()<<endl;

	fork();
	fork();
	cout<<"PID : "<<getpid()<<endl;
	cout<<"PPID : "<<getppid()<<endl;

	cout<<"Hello world"<<endl;


	return 0;
}