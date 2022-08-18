#include "file.h"

int main(int argc,char **argv)
{
	myClass mc;

	int len=strlen(argv[1]);
	char *buffer=new char[len];
	buffer=argv[1];
	mc.merge(buffer);

	/*int pid = fork();
	if(pid>0){
		mc.parentprocess(buffer);
	}
	else if(pid==0){
		mc.childprocess(buffer);
	}
	else{
		cout<<"Fork Failed!"<<endl;
	}
	return 0;*/
}
