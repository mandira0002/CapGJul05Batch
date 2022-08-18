#include<signal.h>
#include<errno.h>
#include<iostream>
#include<string.h>
#include<fstream>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

using namespace std;

#ifndef _MULTIPROCESS_
#define _MULTIPROCESS_
class MultiProcess
{
	public:
		//constructor
		MultiProcess();
		//Functions declaration
		void createProcess(string);
		void process_display_exit_code(int);
		//destructor
		~MultiProcess();
	private:
		//data members
		int pid;
		int exitstatus;
		string buffer;
};
#endif
