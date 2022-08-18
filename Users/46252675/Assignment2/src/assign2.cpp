#include"header.h"
void process_display_exit_code(int);
int main(int argc, char *argv[])
{
	string str1,str2;
	ofstream ofs;
	if(argc>1)
        ofs.open(argv[1],ios::app);
	int exitstatus;
	pid_t pid=fork();
	if(pid==0)
	{
		cout<<"The pid and ppid of child are: "<<endl;
		cout<<"PID: "<<getpid()<<endl;
		cout<<"PPID: "<<getppid()<<endl;
		cout<<"Enter two lines to write in file: "<<endl;
	        getline(cin,str1);
	        getline(cin,str2);
	        ofs<<str1<<endl;
		ofs<<str2;
	        ofs.close();
		exit(EXIT_SUCCESS);
	}

	else
	{  
		waitpid(pid, &exitstatus, 0);
		process_display_exit_code(exitstatus);		      
      		cout<<"The PID and PPID of parent are: "<<endl;
		cout<<"PID: "<<getpid()<<endl;
		cout<<"PPID: "<<getppid()<<endl;
		cout<<"The content stored in the file "<<argv[1]<<" are: "<<endl;
		ifstream ifs;
		ifs.open(argv[1],ios::in);
		char ch;
		while(!ifs.eof())
		{
	       		ch = ifs.get();
		      	cout<<ch;
		}
		ifs.close(); 
	}	
}
void process_display_exit_code(int exitstatus)
{   
	    if ( WIFEXITED(exitstatus) )
	    {
	    	cout<<"\nExit status of the child: "<<WEXITSTATUS(exitstatus)<<endl;
		       
	    }	
	    else if(WIFSIGNALED(exitstatus))
	    {
		cout<<"\nChild exited with signal: "<<WTERMSIG(exitstatus)<<endl;
	    }
            

}
