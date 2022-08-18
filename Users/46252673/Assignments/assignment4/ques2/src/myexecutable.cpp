#include<header.h>
int main(int argc,char *argv[])
{
	char *pgm="/home/ramya/systemprogrammingcpp/assignments/assignment4/ques2/bin/mycmd";
	char *args[]={pgm,argv[2],argv[3],NULL};
	execv(pgm,args);
	return 0;
}
