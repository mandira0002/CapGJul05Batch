#ifndef __FILE_H
#define __FILE_H

#include<iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fstream>
#include<cstring>
#include<csignal>

using namespace std;

class myClass
{
	public:
		myClass();
		void childprocess(string);
		void parentprocess(string);
		void signal_handler(int);
		void process_display_exit_code(int);
		void mergeprocess(string);	
		~myClass();
};
#endif

