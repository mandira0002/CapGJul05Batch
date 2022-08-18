#ifndef __FILE_H
#define __FILE_H

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fstream>
#include <cstring>

using namespace std;

class myClass
{
	public:
		myClass();
		void childprocess(string);
		void parentprocess(string);
		void process_display_exit_code(int);
		void merge(string);	
		~myClass();
};
#endif

