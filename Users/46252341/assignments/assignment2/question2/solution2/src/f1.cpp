#include <file.h>
void process_display_exit_code(int);
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
				process_display_exit_code(status);
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
				process_display_exit_code(status);
				cout<<"\n Child exited with signal: "<<WTERMSIG(status)<<endl;
			}
		}		
	else if(pid == 0)
		{
			cout<<"\nChild Created!\n";
			cout<<"Child's Process Id: "<<getpid()<<endl;
			cout<<"Parent's Process Id: "<<getppid()<<endl;
			file.open(filename,ios::trunc | ios::out);
			if(file.is_open())
			{
				cout<<"\nWriting to file [Child Process]...\n";
				cout<<"(Enter \"-1\" to exit)"<<endl;
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

//function definition
void process_display_exit_code(int status)
{
	int exit_status = WEXITSTATUS(status);
	cout<<"\nChild exited with status: "<<exit_status;
}

