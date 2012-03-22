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
//#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define print(a, end) cout << #a << ": " << a << end
#else
#define print(a, end)
#endif

using namespace std;

/*global variables*/
string num, base;
/*global variables*/

void dump()
{
    //dump data
}

void getInput()
{
    //get input
	cin >> num >> base;
	for (int i = 0; i < num.length(); ++i)
	{
		if(!isdigit(num[i]))
			throw "Error: Check number is not a positive base10 number.";
	}

	for (int i = 0; i < base.length(); ++i)
	{
		if (!isdigit(base[i]))
			throw "Error: Base number is not a positive base10 number.";
	}

	if (cin.peek() != '\n')
		throw "Error: Invalid number of arguments. Expected 2 numbers for input.";

	
	
	cin.ignore(numeric_limits<int>::max(), '\n'); //goto next line
}

bool process()
{
    //process input
	//convert base
	//check palindrome
	stringstream s(num);
	int number, the_base;
	string converted;
	s >> number;
	s << base;
	s >> the_base;
	if (the_base > 62)
		throw "Error: Base " + base + " is an unsupported base system. Maximum Base system is Base 62.";
	
	while (number != 0)
	{
		converted += (number % base)+'0';
		number /= base;
	}
	cout << converted;
	for (int i = 0; i < converted.length()/2; ++i)
	{
		if (converted[i] != converted[converted.length()-i])
			return false;
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
			cout << num << " in base" << base << "is ";
			if (process())
			{
				cout << " - Yes" << endl;
			} else
			{
				cout << " - No" << endl;
			}
		} catch (string& Exception)
		{
			cout << Exception << endl;
		}

        /*output*/


        /*output*/
    }
}
