/*
 
FILE INFORMATION

*/

#include <myHeader.h>

// Function to display process exit code 
void process_display_exit_code(int);

// Driver Code
int main(int argc,char* argv[])
{
	try
	{
		if(argc!=2)
			throw("Command Line Error: Invalid Input, must give one file name only");
		else
		{

			// Store filename in buffer
			char *filename = argv[1];
			
			// Object of fstream
			fstream file;
			string line;
		
			int status;
			
			pid_t pid = fork();
			
			// Parent Process
			if(pid > 0)	
			{	
				
				// Wait until child process exits or signal is received.
				waitpid(pid,&status,0);

				if(WIFEXITED(status))
				{
					// To display the exit code	
					process_display_exit_code(status);
					
					cout<<"\nReading from file [Parent Process]...\n";
					
					// Open file in read mode
					file.open(filename, ios::in);
				
					if(!file)
						cout<<"\nNo such file";
					else
					{
						while(file)
						{
							// Read a line from file
							getline(file,line);
	
							// Print line in console
							cout<<line<<endl;
						}
					}
		
					// Close the file
					file.close();
				}
					
				if(WIFSIGNALED(status))
				{
					process_display_exit_code(status);
					cout<<"\nChild exited with signal: "<<WTERMSIG(status)<<endl;
				}
			}
			
			// Child Process
			else if(pid == 0)
			{
				
				cout<<"\nChild Created!\n";
				cout<<"Child's Process Id: "<<getpid()<<endl;
				cout<<"Parent's Process Id: "<<getppid()<<endl;
						
				// Open a file in write mode,
				// if it exists then delete all content before open, 
				// if not, it will create a new file
				file.open(filename,ios::trunc | ios::out);
				
				if(file.is_open())
				{
					
					cout<<"\nWriting to file [Child Process]...\n";
					cout<<"(Enter \"-1\" to exit)"<<endl;
					while(file)
					{	
						// Read a line from standard input
						getline(cin,line);
						
						// Press -1 to exit
						if(line=="-1")
						{
							break;
						}
						// Write line in file
						file<<line<<endl;
							
					}
				}
				else
				{
					cout<<"\nNo such file\n";
					exit (EXIT_FAILURE);
				}
				// Close the file
				file.close();
			}				
			else
				cout<<"\nFork failed"<<endl;
		}
	}

	catch(const char* exp)
	{
		cout<<endl<<exp<<endl;
	}

	return 0;
}

// Function Definition
void process_display_exit_code(int status)
{
	int exit_status = WEXITSTATUS(status);
	cout<<"\nChild exited with status: "<<exit_status;
}
