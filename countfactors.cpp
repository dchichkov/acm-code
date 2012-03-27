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
//#include <algorithm>
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
int number = 1, count = 0;

/*global variables*/

void dump()
{
    //dump data
}

void getInput()
{
    //get input
	cin >> number;
}

void process()
{
    //process input
	vector<int> primes;
	int * a = new int[number];
	//SoE
	for (int i = 0; i < number; ++i) a[i] = i;
	for (int i = 2; i < number; ++i)
	{
		if (a[i] != 0)
		{
			//found prime
			primes.push_back(i);
			for (int j = i*2; j < number; j=j+i) { a[j] = 0; }
		}
	}

	for (vector<int>::iterator it = primes.begin(); it != primes.end(); ++it)
	{
		for (vector<int>::iterator jt = primes.begin(); jt != primes.end(); ++jt)
		   if ((*jt) % (*it) == 0)
				(*jt)++;
		print(*it, "\t");
	}
	
	for (vector<int>::iterator it = primes.begin(); it != primes.end(); ++it)
		if ((*it) == 0)
			count++;
}

int main()
{
    //getline(cin, temp);
    bool moreToDo;
    while (moreToDo = (number != 0))
    {


        getInput();
		if (number == 0) break;
        process();

        /*output*/
		cout << number << " : " << count << endl;

        /*output*/

		count = 0;
    }
}
