
#include <multi.h>
#define bsize 1024

void func1()
{
	cout<<"\nKilled PID: "<<getpid()<<endl;
	kill(getpid(), SIGUSR1);
}

static void process_display_exit_code(int exitstatus)
{
	cout<<"Interupt Signal ("<<exitstatus<<") received"<<endl;
}

static void signalHandler(int id)
{
	cout<<"Signal ID: "<<id<<endl;
}

void Write2File(char *fn)
{
	string line;
	fstream fs;

	fs.open(fn, ios::out|ios::in);
	if(!fs)
	{
		perror("Unable to open the file: ");
		exit(EXIT_FAILURE);
	}

	for(int i=0;i<2;i++)
	{
		getline(cin, line);
		fs<<line<<endl;
	}
	fs.close();
}


void ReadFromFile(char *fn)
{
	string line;
	fstream fs;

	fs.open(fn, ios::in);
	if(!fs)
	{
		perror("Unable to open the file: ");
		exit(EXIT_FAILURE);

	}

	line="";
	/*
	while(!fs.eof()){
		getline(fs, line)
		cout<<line<<endl;
	}*/

	while(getline(fs, line)){
		cout<<line<<endl;
		//bzero(line.c_str(),bsize);
	}

	fs.close();
}

int main(int argc, char *argv[])
{
	int pid, status;

	time_t t;
	if(argc != 2)
	{
		cout<<"Useage: ./app input.txt"<<endl;
		exit(EXIT_FAILURE);
	}

	char *fname = argv[1];

	pid = fork();

	if(pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0)
	{
		atexit(func1);
		cout<<"Child PID: "<<getpid()<<endl;
		cout<<"Parent PID: "<<getppid()<<endl;
		cout<<"\nEnter two line for the input"<<endl;
		Write2File(fname);
		sleep(2);
		exit(EXIT_SUCCESS);

	}
	
	else
	{
		atexit(func1);

		do{
			if((pid = waitpid(pid, &status, WNOHANG)) == -1)
			{
				signal(SIGCHLD, signalHandler);
				perror("waitpid() error");
			}
			else if( pid == 0)
			{
				time(&t);
				//cout<<"\nChild is still running at: "<<ctime(&t)<<endl;
				sleep(1);

			}
			else{

				signal(SIGCHLD, process_display_exit_code);
				if(WIFEXITED(status))
				{
					cout<<"\nChild exited with status: "<<WEXITSTATUS(status)<<endl;
				}
				else if(WIFSIGNALED(status))
				{
					signal(SIGCHLD, process_display_exit_code);
					cout<<"Signaled: "<<status<<endl;
				}
				else
				{
					cout<<"Child did not exit successfully"<<endl;
				}

				cout<<"Parent pid: "<<getpid()<<endl;
				cout<<"Parent PPID: "<<getppid()<<endl;
				cout<<"\nRead the contents from the file"<<endl;
				ReadFromFile(fname);
			}
		}while(pid == 0);
	}

	return 0;
}
