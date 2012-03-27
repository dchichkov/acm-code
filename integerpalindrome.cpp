#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <cfloat>
#include <cctype>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue> 
#include <regex.h> 

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define print(a, end) cout << #a << ": " << a << end
#else
#define print(a, end)
#endif

using namespace std;

/*global variables*/
string num, base;
string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
/*global variables*/

void dump()
{
    //dump data
}

void getInput()
{
	num = "0"; base = "0";
    //get input
	stringstream s;
	string ss;
	getline(cin, ss); if (ss.length() == 0) throw 0;
	s.str(ss);
	s >> num >> base;

	print(num, "\t"); print(base, endl);
	for (int i = 0; i < num.length(); ++i)
	{
		if(!isdigit(num[i]))
			throw string("Error: Check number is not a positive base10 number.");
	}

	for (int i = 0; i < base.length(); ++i)
	{
		if (!isdigit(base[i]))
			throw string("Error: Base number is not a positive base10 number.");
	}

	if (num == "0" || base == "0" || !s.eof())
		throw string("Error: Invalid number of arguments. Expected 2 numbers for input.");

	if (atoi(base.c_str()) > 62)
		throw string("Error: Base " + base + " is an unsupported base system. Maximum Base system is Base62.");	//this is wrong in the problem description, and wrong in the expected output... awesome.
	

}

bool process()
{
    //process input
	//convert base
	//check palindrome
	stringstream s(num);
	int number = 0, the_base = 0;
	string converted;
	s >> number; s.clear();
	s.str(base);
	s >> the_base;

	print(number, "\t"); print(the_base, endl);
	while (number != 0)
	{
		converted = digits[(number % the_base)] + converted;
		number /= the_base;
	}
	cout << converted;

	//check palindrome
	int length = converted.length() - 1;
	for (int i = 0; i < converted.length()/2; ++i)
	{
		if (converted[i] != converted[length-i])
		{
			print(converted[i], "\t"); print(converted[length-i], endl);
			return false;
		}
	}

	return true;		   
}

int main()
{
    //getline(cin, temp);
    bool moreToDo;
    while (moreToDo = !cin.eof())
    {
		try
		{
			getInput();
			cout << num << " in base" << base << " is ";
			if (process())
			{
				cout << " - Yes" << endl;
			} else
			{
				cout << " - No" << endl;
			}
		}
		catch (string& e)
		{
			cout << e << endl;
		}
		catch (...)
		{
			//lol; hiding error hackery
		}

        /*output*/


        /*output*/
    }
}
