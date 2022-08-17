#include <myHeader.h>
#include <fstream>

void dispEven(fstream &fs)
{

	for(unsigned long long i=0;i<=1000000;i++){
		// if(i%2 == 0)
		// 	cout<<"Even : "<<i<<endl;
		//fs.write(reinterpret_cast<char*>(&i), sizeof(int));
		fs << "Even : "<<i<<endl;
		sleep(1);
	}
}

void dispOdd(fstream &fs)
{
	for(unsigned long long i=0;i<=1000000;i++){
		// if(i%2 != 0)
		// 	cout<<"Odd : "<<i<<endl;
		//fs.write(reinterpret_cast<char*>(&i), sizeof(int));
		fs << "Odd : "<<i<<endl;
	}
}

int main()
{
	fstream fs;
	int status;
	fs.open("out.txt", ios::in|ios::out|ios::app);
	if(!fs)
	{
		cout<<"Unable to open the file";
		exit(EXIT_FAILURE);
	}

	if(fork() == 0)
	{
		cout<<"Child pid: "<<getpid()<<endl;
		dispEven(fs);
		//cout<<"Child Died"<<endl;
		int i;
		cout<<"\nEnter the status: ";
		cin>>i;
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
		cout<<"Parent pid:"<<getpid()<<endl;
		if((status && 0xff) == 0)
			cout<< "Signal interrupted"<<endl;
		cout<<"Child died with the status: "<<status/256<<endl;
		//dispOdd(fs);
		cout<<"Parent Died"<<endl;
	}
	fs.close();
	cout<<"Bye"<<endl;
	return 0;
}