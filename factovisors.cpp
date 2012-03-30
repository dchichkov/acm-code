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
unsigned int a, b;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (cin.eof()) return false;
    cin >> b >> a;
    return true;
}


void process()
{
    //process input
    //get prime factors of b!
    map<int, int> primefacts;
    for (int i = 2; i <= b; ++i)
        primefacts[i] = 0;
        
    for (int i = 2; i <= b; ++i)
        for (int j = 2; j <= i; ++j)
            if (i%j == 0)
                primefacts[j] += 1;

    for (map<int, int>::iterator it = primefacts.begin(); it != primefacts.end(); ++it)
    {
        print(it->first, "\t"); print(it->second, endl);
    }
    
    int n = a;
    for (map<int, int>::iterator it = primefacts.begin(); it != primefacts.end(); ++it)
    {
        if (n % it->first == 0)
        {
            for (int i = 0; i < it->second; ++i)
            {

                if (n%it->first == 0)
                    n /= it->first;
                else
                    break;
            }
        }
    }

    if (n == 1)
        cout << a << " divides " << b << "!" << endl;
    else
        cout << a << " does not divide " << b << "!" << endl;
}

int main()
{
    
    bool moreToDo;
    while (moreToDo = getInput())
    {

        process();

        /*output*/


        /*output*/
    }
}
