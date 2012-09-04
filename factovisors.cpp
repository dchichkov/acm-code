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
    int n;
    int m = a;
    for (int i = 2; i <= b; ++i)
    {
        if (a%i == 0)
        {
            n = a/i;
            a /= n*i;
        }
    }

    if (a == 1)
        cout << m << " divides " << b << "!" << endl;
    else
        cout << m << " does not divide " << b << "!" << endl;
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
