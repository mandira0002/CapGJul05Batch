#include "file.h"

int main(int argc,char **argv)
{
	myClass mc;
	int len=strlen(argv[1]);
	char *buffer=new char[len+1];
	buffer=argv[1];
	if(argc<1){
		cout<<"Error"<<endl;
	}
	else{
		mc.mergeprocess(buffer);
	}
}
