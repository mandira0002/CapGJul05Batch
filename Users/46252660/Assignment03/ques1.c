//Demo code for signal handler
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<errno.h>
#include<unistd.h>
 
//signal handler
void signal_handler(int signum)
{
	printf("signal_handler for signal : %d invoked\n", signum);
}
void mystrcat()
{
	char str1[100];
	char str2[100];

	printf("Enter String 1: ");
	scanf("%s",str1);
	printf("Enter String 2: ");
	scanf("%s",str2);

	char *ptr1=NULL;
	char *ptr2=NULL;
	ptr1 =  new char [strlen(str1)+1];
	ptr2 =  new char [strlen(str2)+1];

	strcpy(ptr1,str1);
	strcpy(ptr2,str2);

	printf("%s %s\n",ptr1,ptr2);
}
int main()
{
	int sigret = 0;
	mystrcat();


	__sighandler_t ret=signal(SIGINT,signal_handler);
	if (ret==SIG_ERR){
		printf("SIGINT set error %d\n", errno);
		return EXIT_FAILURE;
	}
	__sighandler_t usr=signal(SIGUSR1,signal_handler);
	if(usr!=SIG_ERR){
		printf("Welcome User\n");
		return EXIT_SUCCESS;
	}
	signal(SIGSEGV,signal_handler);
	while(1){
		sleep(1);
		printf("signal demo: while loop \n");
	}
	return EXIT_SUCCESS;
}
