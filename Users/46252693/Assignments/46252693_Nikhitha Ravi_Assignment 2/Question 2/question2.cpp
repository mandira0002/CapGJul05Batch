#include<iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
using namespace std;

int a=10; /* global variable */

int main()

{

	int pid;
	int b=5;
	cout<<"Writing a sample code"<<endl;
	pid = fork(); /* fork() returns 0 to child process and process id of child to parent process*/

	if(0 == pid)
	{
		cout<<"For child Local variable value and global variable value"<<b<<" \n"<<a<<"\n"<<endl;
		exit(0);
		//sleep(3);
	}
	else
	{
		cout<<"For parent Local variable value and global variable value"<<b<<"\n"<<a<<" \n"<<endl;
		//exit(0);
	}
	cout<<"Code common for both parent process and child process"<<endl;
	return 0;
}
