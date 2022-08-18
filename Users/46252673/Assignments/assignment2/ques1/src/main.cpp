#include<mp.h>
void handler(int signum)
{
	cout<<"Signal number "<<signum<<" is invoked"<<endl;
	exit(signum);
}
int main(int argc,char *argv[])
{
	//class object
	MultiProcess mp;
	int len=strlen(argv[1]);
	char *buffer=new char[len];
	//store the file name in buffer
	buffer=argv[1];	
	signal(SIGINT,handler);
	mp.createProcess(buffer);	
	return 0;
}

