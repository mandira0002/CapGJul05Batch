#include <myHeader.h>


int pid;

void abc(int id)
{
	cout<<"Signal interrupted by ID: "<<id<<endl;
}

// int main()
// {
// 	int a=0, b=20;
// 	signal(SIGHUP, abc);
// 	//b = b/a;
// 	for(;;);
// 	return 0;
// }



int main()
{
	
	signal(SIGUSR1, abc);
	pid = fork();

	if(pid == 0)
	{
		
		sleep(1);
		kill(getppid(),SIGUSR1);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(0);
		cout<<"Child PID: "<<pid<<endl;
		for(int i=0;i<5000;i++)
		{
			cout<<"i: "<<i<<endl;
		}
		cout<<"Parent Died"<<endl;
	}

	return 0;
}