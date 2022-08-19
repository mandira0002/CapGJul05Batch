/*
FILE INFORMATION
*/

#include <myHeader.h>

// Function to display process exit code 
static void process_display_exit_code(int,int);

// Signal handler to handle SIGCHLD
static void signal_handler(int signum)
{
	switch(signum)
	{
		// Handling SIGCHLD, raised when a child is terminated.
		case SIGCHLD:
			cout<<"\nsignal_handler for signal "<<signum<<" (SIGCHLD) invoked";
			break;
		default:
			cout<<"\nUndefined! Signal can't be handled.";
	}
		
}


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
			
			// Create a child process using system call fork()
			pid_t pid = fork();
			
			// Parent Process
			if(pid > 0)
			{
				// Registering for SIGCHLD
				sighandler_t ret=signal(SIGCHLD,signal_handler);
				if(ret==SIG_ERR)
				{
					perror("signal()");
					exit(EXIT_FAILURE);
				}

				// To observe the SIGCHLD fucnionality
				sleep(100);

				// Wait until child process exits or signal is received.
				waitpid(pid,&status,0);

				if(WIFEXITED(status))
				{
					// To display the exit code	
					process_display_exit_code(getpid(),status);
					
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
					
				// If process is terminated using signal
				if(WIFSIGNALED(status))
				{
					process_display_exit_code(getpid(),status);
					cout<<"\nChild "<<getpid()<<" exited with signal: "<<WTERMSIG(status)<<endl;
				}
			}
			
			// Child Process
			if(pid == 0)
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
				exit(EXIT_SUCCESS);
			}				
			if(pid < 0)
				perror("fork() failed");

		}
	}

	catch(const char* exp)
	{
		cout<<endl<<exp<<endl;
	}

	return 0;
}

// Function Definition
static void process_display_exit_code(int pid,int status)
{
	int exit_status = WEXITSTATUS(status);
	cout<<"\nChild "<<pid<<" exited with status: "<<exit_status<<endl;
}
