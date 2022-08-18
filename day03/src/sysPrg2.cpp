#include <myHeader.h>

// int main()
// {
// 	execl("/home/bhima/CapGJul05Batch/day03/hello","hello", (char*)0);
// 	return(EXIT_SUCCESS);
// }

// int main()
// {
// 	execl("/usr/bin/date","date", (char*)0);
// 	return(EXIT_SUCCESS);
// }


// int main()
// {
// 	//execl("/home/bhima/CapGJul05Batch/day03/hello","hello", (char*)0);
// 	char *temp[4];
// 	temp[0] = "hello";
// 	temp[1] = "Bhima";
// 	temp[2] = "shankar";
// 	temp[3] = (char*)0;
// 	execv("/home/bhima/CapGJul05Batch/day03/hello",temp);
// 	return(EXIT_SUCCESS);
// }

// int main()
// {
// 	//execl("/home/bhima/CapGJul05Batch/day03/hello","hello", (char*)0);
// 	char *temp[3];
// 	temp[0] = "ls";
// 	temp[1] = "-la";
// 	temp[2] = (char*)0;
// 	execv("/usr/bin/ls",temp);
// 	return(EXIT_SUCCESS);
// }


int main()
{
	//execl("/home/bhima/CapGJul05Batch/day03/hello","hello", (char*)0);
	char *temp[4];
	temp[0] = "/home/bhima/CapGJul05Batch/day03/hello";
	temp[1] = "Bhima";
	temp[2] = "shankar";
	temp[3] = (char*)0;
	execvp(temp[0],temp);
	return(EXIT_SUCCESS);
}
