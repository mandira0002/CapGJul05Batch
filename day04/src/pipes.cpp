/*
		  pipe
process A ---->   Process B
pipe with fd[2]

pipe(fd) -> 2 descriptors
fd[0]-> always ment for reading 
fd[1]-> always ment for writing



*/

#include <myHeader.h>

#define MAXBUFF 1024

int main()
{
	int fd[2];
	int pid;
	int n;

	char line[MAXBUFF];

	if(pipe(fd) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	if((pid = fork())< 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if( pid > 0)
	{
		close(fd[0]);
		//wait(0);
		char *msg = "Hello World";
		write(fd[1], msg,strlen(msg));
	}

	else
	{
		close(fd[1]);
		sleep(1);
		n = read(fd[0], line, MAXBUFF);
		cout<<"Read from pipe\n"<<line<<endl;
		cout<<"No of byte read: "<<n<<endl;

	}

	return 0;

}