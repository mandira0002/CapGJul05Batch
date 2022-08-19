#include "file.h"

myClass::myClass()
{
}
void myClass::childprocess(string buffer)
{
	string line;
	int status;
	cout<<"Child PID: "<<getpid()<<endl;		//pid of child process
	
	ofstream ofs;
	ofs.open(buffer,ios::out | ios::in | ios::trunc);	//opening a file
	if(!ofs){
		cout<<"Error:File Not Found"<<endl;
		exit(EXIT_FAILURE);
	}
	else{
		for(int i=0;i<2;i++){
			cout<<"Enter line "<<i+1<< ": ";
			if(getline(cin,line)){
				ofs<<line<<endl;
			}
		}
	}
	ofs.close();
	signal_handler(status);
}
void myClass::parentprocess(string buffer)
{
	int status;
	string line;
	cout<<"Parent PID: "<<getppid()<<endl;
	

	int wid=wait(&status);			//execute after child process
	process_display_exit_code(wid);

	cout<<"\nContents of the file (At Parent Process):"<<endl;
	ifstream ifs;
	ifs.open(buffer);
	while(getline(ifs,line)){
		cout<<line<<endl;
	}
	ifs.close();
}
void myClass::signal_handler(int signum)
{
	signum = getpid();
	cout<<"\nKilled PID: "<<signum<<endl;
	kill(signum,SIGINT);
	exit(EXIT_SUCCESS);
}
void myClass::process_display_exit_code(int exitstatus)
{
	if(WIFEXITED(exitstatus)){
		exitstatus = WEXITSTATUS(exitstatus);
		cout<<"\nExit Status Code: "<<exitstatus<<endl;
	}
	else if(WIFSIGNALED(exitstatus)){
		exitstatus = WTERMSIG(exitstatus);
		cout<<"\nExit Signal Number: "<<exitstatus<<endl;
	}
	else {
		cout<<"Child Not Exited Properly"<<endl;
	}
}
void myClass::mergeprocess(string buffer)
{
	int pid = fork();
	if(pid>0){			//parent process
		parentprocess(buffer);
		exit(EXIT_SUCCESS);
	}
	else if(pid==0){		//child process
		childprocess(buffer);
		exit(EXIT_SUCCESS);
	}
	else{
		cout<<"Fork Failed!"<<endl;
		exit(EXIT_FAILURE);
	}
}
myClass::~myClass()
{
}
