#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

using namespace std;

int pid;

void abc()
{
	cout<<"Main Program exited and now cleaning can be done here "<<endl;
	cout<<pid<<endl;
}

void abc2()
{
	cout<<"abc2 is called"<<endl;
}

int main()
{
	atexit(abc);
	pid = fork();

	if(pid == 0)
	{
		cout<<"Child :"<<getpid()<<endl;
	}
	else
	{

		wait(0);
		cout<<"\nHello this is main process pid:"<<getpid()<<endl;
		abc2();
		cout<<"\nEnding up the main process"<<endl;
	}
	return 0;
}