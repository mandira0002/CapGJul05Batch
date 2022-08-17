#include <myHeader.h>

int main(int argc, char *argv[])
{
	pid_t cpid,w;
	int status;

	cpid = fork();
	if(cpid == -1)
	{
		cout<<"Unable to create the child process"<<endl;
		exit(EXIT_FAILURE);
	}
	else if(cpid ==0)
	{
		cout <<"Child PID: "<<getpid()<<endl;
		if(argc == 1)
			pause();
		_exit(atoi(argv[1]));
	}
	else{

		do{
			w = waitpid(cpid,&status,WUNTRACED | WCONTINUED);
			if(w == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}

			if(WIFEXITED(status))
				cout<<"Exit status: "<<WEXITSTATUS(status)<<endl;
			else if(WIFSIGNALED(status))
				cout<<"Killed by signal: "<<WTERMSIG(status)<<endl;
			else if(WIFSTOPPED(status))
				cout<<"Stopped by signal: "<<WSTOPSIG(status)<<endl;
			else if(WIFCONTINUED(status))
				cout<<"Continued"<<endl;

		}while(!WIFEXITED(status) && !WIFSIGNALED(status));

		exit(EXIT_SUCCESS);
	}

	return (EXIT_SUCCESS);
}