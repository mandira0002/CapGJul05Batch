#include<iostream>
#include<sys/types.h>
#include<unistd.h>
using namespace std;
int main(int argc,char *argv[])
{
	cout<<argv[1]<<"\t"<<argv[2]<<endl;
	return EXIT_SUCCESS;
}
