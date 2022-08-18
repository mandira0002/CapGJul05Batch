#include<mp.h>
//constructor
MultiProcess::MultiProcess()
{
}
//Function to create process
void MultiProcess::createProcess(string buffer)
{
	//fork() system call is used to create process
	int pid=fork();
	int exitstatus=10;
	//The pid of child is 0
	if(pid==0)
	{
		char sentence[100];
		cout<<"Child Process:"<<endl;
		//To get pid of child 
		cout<<"PID:"<<getpid()<<endl;
		//To open the file
		ofstream fobj;
		fobj.open(buffer);
		if(!fobj)
		{
			cout<<"File not found"<<endl;
		}
		else
		{
			//To get input from user
			cout<<"Enter the text to written into file:"<<endl;
			for(int i=0;i<2;i++)
			{
				cin.getline(sentence,100);
				//To write the user input to file
				fobj<<sentence<<endl;
			}
		}
		//To close the file
		fobj.close();
		exit(exitstatus);
	}
	else if(pid>0)
	{
		//To make the parent wait until the termination of the child
		int id=waitpid(pid,&exitstatus,0);
		//if error occurs waitpid returns -1
		if(id==-1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
		process_display_exit_code(exitstatus);
		cout<<"Parent Process:"<<endl;
		//To get the parent pid
		cout<<"PID:"<<getpid()<<endl;
		string text;
		ifstream fobj(buffer);
		cout<<"Contents of the file "<<buffer<<" is:"<<endl;
		//Display the file content in command prompt
		while(getline(fobj,text))
		{
			cout<<text<<endl;
		}
		fobj.close();
	}
	else
	{
		cout<<"Fork failed"<<endl;
	}

}
void MultiProcess::process_display_exit_code(int exitstatus)
{
	//Execute if the process existed normally
	if (WIFEXITED(exitstatus)) {
		cout<<"Exit status="<< WEXITSTATUS(exitstatus)<<endl;
	} 
	//Execute if the child is existed using signal
	else if (WIFSIGNALED(exitstatus)) {
		cout<<"killed by signal="<<WTERMSIG(exitstatus)<<endl;
	}  
	//Execute if the child is terminated abnormally
	else
	{
		cout<<"child terminated abnormally"<<endl;
	}
}
//destructor
MultiProcess::~MultiProcess()
{
}
