#include<myHeader.h>

int process_display_exit_code(int exitstatus)
{
	//Function Declaration
}

int main(int argc, char *argv[])
{

	string filename;
	ifstream infile;
	cout<<"Enter file name -";
	getline(cin, filename);
	infile.open(filename);

	cout<<"Your file name : "<<filename<<endl;

	int pid;
	pid = fork();
	//cout<<"PID:"<<getpid()<<endl;
	//cout<<"PPID:"<<getppid()<<endl;
	
	cout<<"Hello world"<<endl;

	if(pid==0)
	{
		string str;
		cout<<"This is a child process"<<endl;
		cout<<"PID:"<<getpid()<<endl;
		cout<<"PPID:"<<getppid()<<endl;

		//Reading two lines from user
		cout<<"Enter 2 lines seperated by ':'"<<endl;
		getline(cin, str);

		string words;
		stringstream st(str);
		//Opening the file and writing above two lines in the file
		ofstream write("input_file.txt");
		while(getline(st, words,':'))
		{
			write<<words<<endl;
		}
		exit(0);
	}
	else if (pid>0)
	{
		sleep(30);
		cout<<"PID:"<<getpid()<<endl;
		cout<<"PPID:"<<getppid()<<endl;
		cout<<"This is a parent process"<<endl;

		//opening the input file using constructor
		string str1, str2;
		ifstream read("input_file.txt");
		getline(read, str1);
		getline(read, str2);

		cout<<str1<<endl;
		cout<<str2<<endl;

		//process_display_exit_code();
	}
	else
		cout<<"Fork failed"<<endl;



	return 0;
}
