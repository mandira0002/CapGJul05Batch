#include "list.h"

int main(int argc , char *argv[])
{
	Mock ls;
	for(int i=1;i<argc;i++)
	{
		string str=argv[i];
		if(ls.validate(str))
			ls.addMap(str);
		else
		{
			cout<<"Parse error in <input line>"<< endl;
		}

	}
	cout<<"In Map"<<endl;
	ls.displayMap();

	cout<<"After Validating State"<<endl;
	ls.validState();
	ls.displayMap();

}

