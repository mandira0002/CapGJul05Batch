#ifndef _LIST_MAP_
#define D "UNINTERRUPTABLE_SLEEP"
#define R "RUNNING & RUNNABLE"
#define S "INTERUPTABLE_SLEEP"
#define T "STOPPED"
#define Z "ZOMBIE"

#include<iostream>
#include<string>
#include<stdexcept>
#include<map>
#include<bits/stdc++.h>

using namespace std;

class Mock
{
	public:
	       Mock();
	       bool validate(string);
	       void addMap(string);
	       void displayMap();
	       void validState();
	       ~Mock();
	private:
	       map<int,string> map1;
};

#endif

