/* creates a child process which is executing “ls” executable*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int create(char *pgm, char *argv[])
{
	int pid;
	pid = fork();
	if (0 == pid)
	{
		execvp(pgm,argv); /* executes pgm searching for the path in “PATH” environment variable */
		perror("execvp"); /* the execvp function returns only if an error occurs */
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
