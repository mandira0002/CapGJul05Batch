#include <myHeader.h>

int main(int argc, char *argv[])
{
	for(int i=1;i<argc;i++)
		cout<<"Argv["<<i<<"] : "<<argv[i]<<endl;
	cout<<"\n\nHello Program"<<endl;
	return (EXIT_SUCCESS);
}