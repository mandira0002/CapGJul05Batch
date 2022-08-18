#include "list.h"

Mock :: Mock(){}

bool Mock :: validate(string s)
{
	int pos=s.find(":");
	string posId=s.substr(0,pos);
	string state=s.substr(pos+1);
	if(posId.empty() || state.empty())
		return false;
	else
		return true;
}
void Mock :: validState()
{
	auto it=map1.begin();
	while(it !=map1.end())
	{
//		cout<<it->first<<endl;
//		cout<<it->second<<endl;
	
		if(it->second !="D" && it->second != "R" && it->second!="S" && it->second !="T" && it->second !="Z")
		{

			cout<<"Invalid State"<<endl;
			map1.erase(it->first);
		}
		
		++it;
	}
}
void Mock :: addMap(string str)
{
		int pos = str.find(":");
		int posId=stoi(str.substr(0,pos));
		string state =str.substr(pos+1);
		map1[posId]=state;

}
void Mock :: displayMap()
{
	for(auto& it:map1)
	{
		string ch = it.second;
		cout<<"PID: "<<it.first<<", "<<"State: "<<ch<<endl;
	}
}
Mock:: ~Mock() {}
