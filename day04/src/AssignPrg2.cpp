
#include <iostream>
#include <signal.h>
#include <cstring>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>
#include <string>
#include <time.h>

#define MAXBUFF 1024

using namespace std;


static void func1(int signum)
{
	//cout<<"Sig Number: "<<signum<<endl;
	switch(signum)
	{
		case SIGSEGV:
			cout<<"Sig Number: "<<signum<<endl;
			cout<<"Seg fault error occured"<<endl;
			exit(EXIT_FAILURE);
			break;

		case SIGUSR1:
			cout<<"Welcome User!"<<endl;
			break;

		case SIGHUP:
			cout<<"SIGNAL HANG UP occured! : "<<signum<<endl;
			break;

		default:
			cout<<"\nUnhandled signal : "<<signum<<endl;

	}
	
}


void mystrcat(char *str1, char *str2)
{
	int i;
	signal(SIGSEGV,func1);
	
	for(i=0;i<strlen(str2);i++)
		str1[i] = str2[i];
	str1[i] = '\0';
}

int main()
{
	sighandler_t ret = signal(SIGUSR1,func1);
	signal(SIGHUP,func1);

	if(ret == SIG_ERR)
	{
		perror("signal() error");
		exit(EXIT_FAILURE);
	}

	if(raise(SIGUSR1) != 0)
	{
		perror("raise() error");
		exit(EXIT_FAILURE);
	}
	char *str1, str2[20];
	cin>>str2;
	char *str3 = NULL;
	str1 = new char[strlen(str2)+1];
	mystrcat(str1, str3);

	cout<<"Str1: "<<str1<<endl;
	cout<<"Str2: "<<str2<<endl;

	return EXIT_SUCCESS;

}