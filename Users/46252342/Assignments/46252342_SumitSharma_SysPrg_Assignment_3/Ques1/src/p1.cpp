/*
FILE INFORMATION
*/

#include <myHeader.h>

// Signal handler 
void signal_handler (int signum)
{
	// Signal Handling using switch case
	switch(signum)
	{
		case SIGUSR1:
			cout<<"Welcome User"<<endl;
			break;
		case SIGSEGV:
			cout<<"Signal_Handler for signal: "<<signum<<" invoked"<<endl;
			cout<<"Segmentation Fualt occured"<<endl;
			exit(EXIT_FAILURE);
			break;
		default:
			cout<<"\nSignal "<<signum<<" can't be handled."<<endl;
			exit(EXIT_FAILURE);
	}	
}

// Function definition of mystrcat()
void mystrcat()
{
	char str1[30], str2[30];

	// Prompt
	cout<<"Enter String 1: ";
	cin>>str1;
	cout<<"Enter String 2: ";
	cin>>str2;

	char *ptr1=NULL;	//to remove seg fault - ptr1=new char[strlen(str1)+1];
	char *ptr2=NULL; 	//to remove seg fault - ptr2=new char[strlen(str2)+1];

	// Since we can't copy a string to null pointer
	// Below statement leads to segmentation fault
	strcpy(ptr1,str1);
	strcpy(ptr2,str2);
	
	cout<<ptr1<<endl<<ptr2<<endl;
}

// Driver Code
int main()
{

	// register for SIGINT to handle later
	sighandler_t ret=signal(SIGINT,signal_handler);
	
	// If a signal is invalid 
	if (ret==SIG_ERR)
	{
		perror("singal() error");
		exit(EXIT_FAILURE);
	}
	
	// System call for usr1
	signal(SIGUSR1,signal_handler);

	// To raise the signal SIGUSR1
	if(raise(SIGUSR1)!=0)
	{
		perror("raise() error");
		exit(EXIT_FAILURE);
	}


	// System call in case of segmentation fault
	signal(SIGSEGV,signal_handler);
	
	// System call if process is paused
	signal(SIGTSTP,signal_handler);

	// Function call to mystrcat()
	mystrcat();

	// An infinte loop 
	while(1)
	{
		sleep(1);
		cout<<"signal demo: while loop\n";
	}
	return EXIT_SUCCESS;
}
