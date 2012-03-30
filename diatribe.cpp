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
map<char, int> the_map;
int base;
/*global variables*/

typedef vector<pair<char, int> > vp;

void dump()
{
    //dump data
}

bool getInput()
{
    //get input

	cin >> base;
	for (int i = 0; i < base; ++i)
	{
		the_map['A'+i] = 0;
	}
	cin.ignore();
	return true;
}
bool compare(pair<char, int> x, pair<char, int> y)
{
	return y.second < x.second;
}

void process()
{
	string temp;
	getline(cin, temp);
	print(temp, endl);
	for (int i = 0; i < temp.length()-1; ++i)
	{
		if (temp[i] >= 'A'+base) continue;
		else the_map[temp[i]] += 1;
	}
    //process input

	vector<pair<char, int> > mlist;
	int index = 0;
	for (map<char, int>::iterator it = the_map.begin(); it != the_map.end(); ++it)
	{
		pair<char, int> a;
		a.first = it->first;
		a.second = it->second;
		mlist.push_back(a);
		print(it->first, "\t"); print(it->second, endl);
	}

	sort(mlist.begin(), mlist.end(), compare);
	cout << endl;
	for (vp::iterator it = mlist.begin(); it != mlist.end(); ++it)
	{
		print(it->first, "\t"); print(it->second, endl);
	}
	for (int i = 0; i < mlist.size()-1; ++i)
	{

		if (mlist[i].first < mlist[i+1].first && i%2 == 1)
			swap(mlist[i], mlist[i+1]);
		else if (mlist[i].first > mlist[i+1].first && i%2 == 0)
			swap(mlist[i], mlist[i+1]);	   
	}
	cout << endl;
	for (vp::iterator it = mlist.begin(); it != mlist.end(); ++it)
	{
		print(it->first, "\t"); print(it->second, endl);
	}
		
	vp nlist(mlist.size());

	for (int i = 0; i < mlist.size(); ++i)
	{
		if (i%2 == 0)
		{
			nlist[index] = mlist[i];
			index++;
		}
		else
		{
			nlist[mlist.size()-index] = mlist[i];
		}
	}
		
	for (vector<pair<char, int> >::iterator it = nlist.begin(); it != nlist.end(); ++it)
		cout << it->first << " ";
	cout << endl;
	for (vector<pair<char, int> >::iterator it = nlist.begin(); it != nlist.end(); ++it)
		cout << it->second << " ";
	cout << endl;
		
}

int main()
{
    //getline(cin, temp);
    bool moreToDo;
	int index=0,num = 0;
	cin >> num;
	
    while (moreToDo = (index++ < num) && getInput())
    {
		
        process();
        /*output*/
        /*output*/
		the_map.clear();
    }
}
