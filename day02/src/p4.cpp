/*

fork() -> create child process with its own pid
it will duplicate all the excution steps after it is called

*/

#include <myHeader.h>

int main()
{
	int pid;
	long int i,j;

	pid = fork();
	if(pid > 0)
	{
		wait(0);
		for(i=0;i<1000;i++){
			cout<<"i="<<i<<endl;
			//sleep(1);
		}
	}

	else if(pid == 0)
	{
		if(fork() == 0){
		for(j=0;j<1000;j++)
			cout<<"j="<<j<<endl;
		}
		else
		{
			wait(0);
			cout<<"Child died"<<endl;
		}
	}				
	else
		cout<<"Fork failed"<<endl;

	return 0;
}