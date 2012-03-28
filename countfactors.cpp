/**
 * Author: Matthew Gavin
 * Date: 3/28/2012
 * Problem: Count the Factors - 10699
 * Description: Implementing the Sieve of Eratosthenes.
 * Prof. Isaac Traxler
 * Compiled with: g++ countfactors.cpp -o cf
 * Compiler: g++ 4.6.1
 */
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
const int UPPERLIMIT = 1000000;
int number = 1, counter = 0;
vector<int> primes;
int a[UPPERLIMIT];
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
    int num = number;
    for (vector<int>::reverse_iterator jt = primes.rbegin(); jt != primes.rend(); ++jt)
    {
        if (num % *jt == 0)
        {
            print(*jt, endl);
            num /= *jt;
            counter++;
        }
    }
}

int main()
{
	//SoE
	for (int i = 0; i < UPPERLIMIT; ++i) a[i] = i;
	for (int i = 2; i < UPPERLIMIT; ++i)
	{
		if (a[i] != 0)
		{
			//found prime
			primes.push_back(i);
			for (int j = i*2; j < UPPERLIMIT; j=j+i) { a[j] = 0; }
		}
	}
    print(primes.size(), endl);

    
    bool moreToDo;
    while (moreToDo = (number != 0))
    {


        getInput();
		if (number == 0) break;
        process();

        /*output*/
		cout << number << " : " << counter << endl;

        /*output*/

		counter = 0;
    }
}
