#include <file.h>
void display_exit(int status)
{
	int exit_status = WEXITSTATUS(status);
	cout<<"\n \n Child exit with status: "<<exit_status;
}	
int main(int argc,char* argv[])
{
	char *filename = argv[1];
	fstream file;
	string line;
	int status;
	int pid = fork();	     
	if(argc!=2)
	{
		cout<<"Invalid Input: give one file name only"<<endl;
	}
	else
	{
		if(pid > 0)
		{
			waitpid(pid,&status,0);
			if(WIFEXITED(status))
			{
				display_exit(status);
				cout<<"\n Reading from file [Parent Process]...\n";
				file.open(filename, ios::in);
				if(!file)
					cout<<"\n No file";
				else
				{
					while(file)
					{
						getline(file,line);
						cout<<line<<endl;
					}			
				}
				file.close();
			}
			if(WIFSIGNALED(status))
			{
				display_exit(status);
				cout<<"\n Child exited with signal: "<<WTERMSIG(status)<<endl;
			}
		}		
	else if(pid == 0)
	{
			cout<<"\nChild Created!\n";
			cout<<"Child Process Id: "<<getpid()<<endl;
			cout<<"Parent Process Id: "<<getppid()<<endl;
			file.open(filename,ios::trunc | ios::out);
			if(file.is_open())
			{
				cout<<"(Enter -1 to exit)"<<endl;
				while(file)
				{	
				getline(cin,line);
				if(line=="-1")
				{
					break;
				}
				file<<line<<endl;
				}
			}
			else
			{
				cout<<"\nNo such file\n";
				exit (EXIT_FAILURE);
			}
			file.close();
		}				
		else
		{
			cout<<"\nFork failed"<<endl;
		}
	}
	return 0;
}
