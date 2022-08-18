#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
int create(char *pgm, char *argv[])
{
	int pid;
	execvp(pgm,argv);
	pid = fork();
//	execvp(pgm,argv);
	if (pid == 0)
	{
	//	execvp(pgm,argv);/* executes pgm searching for the path in “PATH” environment variable 
	//	perror("execvp"); /* the execvp function returns only if an error occurs 
		printf("Child process");
		exit(0);
	}
	else
	{
		wait(NULL);
		printf("Inside parent process\n");
	}
}
int main()
{
	char *argv[]={"ls","-l",NULL}; /*List of NULL terminated arguments */
	create("ls",argv);
	return 0;
}

