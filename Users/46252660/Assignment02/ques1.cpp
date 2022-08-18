#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fstream>
#include <cstring>

using namespace std;

void process_display_exit_code(int);

int main(int argc,char **argv)
{
	int len=strlen(argv[1]);
	char *buffer=new char[len];
	buffer=argv[1];
	
	ifstream ifs;
	ofstream ofs;
	string line;
	int status;
	
	int pid = fork();
	if(pid>0){
		cout<<"Parent PID: "<<getppid()<<endl;
		
		int wid=wait(&status);
		process_display_exit_code(wid);
		
		cout<<"\nContents of the file (At Parent Process):"<<endl;
		ifs.open(buffer);
		while(getline(ifs,line)){
			cout<<line<<endl;
		}
		ifs.close();
	}
	else if(pid==0){
		cout<<"Child PID: "<<getpid()<<endl;
		
		ofs.open(buffer,ios::in | ios::trunc);
		for(int i=0;i<2;i++){
			cout<<"Enter line "<<i+1<< ": ";
			if(getline(cin,line)){
				ofs<<line<<endl;
			}
		}
		ofs.close();
	}
	else{
		cout<<"Fork Failed!"<<endl;
	}
	return 0;
}

void process_display_exit_code(int exitstatus)
{
	int pid;
	if(pid=fork()==0){
		exit(1);
	}
	else{
		wait(&exitstatus);
	}
	int wid = waitpid(pid,&exitstatus,1);
	if(WIFEXITED(exitstatus)){
		exitstatus = WEXITSTATUS(exitstatus);
		cout<<"\nExit Status Code: "<<exitstatus<<endl;
	}
	if(WIFSIGNALED(exitstatus)){
		exitstatus = WTERMSIG(exitstatus);
		cout<<"Exit Signal Number: "<<exitstatus<<endl;
	}
}
