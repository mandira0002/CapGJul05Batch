#include<stdio.h>
#include<stdlib.h>
int g_value =10; /* global variable */
int main()
{
	int l_value =5;
	printf("Writing a sample code\n");
	int pid = fork();
       	/* fork() returns 0 to child process and process id of child to parent process*/
	if(pid == 0)
	{
		printf("For child Local variable value=%d\n and global variable value=%d\n",l_value,g_value);
		exit(0);
	}
	else
	{
		printf("For parent Local variable value=%d\n and global variable value=%d\n",l_value,g_value);
	}
	printf("Code common for both parent process and child process\n");
	return 0;
}

