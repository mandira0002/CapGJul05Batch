/*

	sigaction

*/

#include <myHeader.h>

volatile sig_atomic_t unprocessedSig = 0;

void sigHandler(int signum)
{
	cout<<"Signal interrupted by ID: "<<signum<<endl;
	if(signum == SIGABRT)
		unprocessedSig = 1;
	if(signum == SIGINT)
		unprocessedSig = 1;
	if(signum == SIGSEGV)
		unprocessedSig = 1;
}

int main()
{
	cout<<"\nPID: "<<getpid()<<endl;

	struct sigaction act;

	act.sa_handler = &sigHandler;

	sigfillset(&act.sa_mask);

	act.sa_flags = SA_RESTART;

	if(sigaction(SIGABRT, &act, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if(sigaction(SIGSEGV, &act, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if(sigaction(SIGINT, &act, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	cout<<"\nKill the process using killall -s SIGNAL_NAME process_name"<<endl;

	while(1)
	{
		if(unprocessedSig)
		{
			system("ls");
			unprocessedSig = 0;
			cout<<"\nSIGNAL has occured"<<endl;
		}
	}
	

	return(EXIT_SUCCESS);
}