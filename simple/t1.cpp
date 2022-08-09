#include <iostream>
using namespace std;

//#define DEBUG

#define MIN(a,b) (((a)<(b)) ? a : b)

int main()
{
	int i,j;

	#ifdef TESTING
		i=10;
		j=35;
	#else
		i=20;
		j=40;
	#endif


	#ifdef DEBUG
		cerr<<"Trace: Inside the main Function"<<endl;
	#endif

	#if 0
		cout<<"Hello World"<<endl;
	#endif

	cout<<"The Min of (a,b) "<<MIN(i,j)<<endl;

	#ifdef DEBUG
		cerr<<"Trace: Coming out of main Function"<<endl;
	#endif

	return 0;
}


