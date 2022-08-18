#include "file.h"

myClass::myClass()
{
}
void myClass::childprocess(string buffer)
{
	string line;
	cout<<"Child PID: "<<getpid()<<endl;
	
	ofstream ofs;
	ofs.open(buffer,ios::in | ios::trunc);
	for(int i=0;i<2;i++){
		cout<<"Enter line "<<i+1<< ": ";
		if(getline(cin,line)){
			ofs<<line<<endl;
		}
	}
	ofs.close();
}
void myClass::parentprocess(string buffer)
{
	int status;
	string line;
	cout<<"Parent PID: "<<getppid()<<endl;
	
	int wid=wait(&status);
	process_display_exit_code(wid);
	
	cout<<"\nContents of the file (At Parent Process):"<<endl;
	ifstream ifs;
	ifs.open(buffer);
	while(getline(ifs,line)){
		cout<<line<<endl;
	}
	ifs.close();
}
void myClass::process_display_exit_code(int exitstatus)
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
	else if(WIFSIGNALED(exitstatus)){
		exitstatus = WTERMSIG(exitstatus);
		cout<<"Exit Signal Number: "<<exitstatus<<endl;
	}
}
void myClass::merge(string buffer)
{
	int pid = fork();
	if(pid>0){
		parentprocess(buffer);
	}
	else if(pid==0){
		childprocess(buffer);
	}
	else{
		cout<<"Fork Failed!"<<endl;
	}
}
myClass::~myClass()
{
}
