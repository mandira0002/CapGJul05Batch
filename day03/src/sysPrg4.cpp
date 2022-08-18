#include <myHeader.h>

void abc(int id)
{
	cout<<"Interrupted by signal: "<<id<<endl;
	exit(EXIT_SUCCESS);

}

void abc1(int id)
{
	cout<<"Interrupted by signal: "<<id<<endl;
	if(id == 8)
	{
		cout<<"Float point exp occured"<<endl;
		exit(EXIT_FAILURE);
	}

}

float div1(int a, int b)
{
	return (a/b);
}


int main()

{
	// char *str;
	// char str2[]="Bhima";
	// str = new char[strlen(str2)+1];
	// strcpy(str,str2);
	// cout<<str<<endl;
	int *p;
	*p = 10;
	cout<<*p<<endl;
	/*int status=0;
	signal(SIGINT, abc);
	signal(SIGQUIT, abc);
	signal(SIGSEGV, abc);
	signal(SIGFPE, abc1);
	if(fork() == 0){
		div1(10,0);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
		cout<<"Parent died: status :"<<status/256<<endl;
	}
	//for(;;);
*/
	return 0;
}

