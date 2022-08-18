#include<iostream>
#include<sys/types.h>
#include<unistd.h>
using namespace std;
int main(int argc,char *argv[])
{
	char *file,*one,*two;
	file = argv[1];
	one = argv[2];
	two = argv[3];
	
	execl(file,argv[1],argv[2],argv[3],NULL);
	return EXIT_SUCCESS;
}
