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

/*global variables*/

void dump()
{
    //dump data
}

void getInput(string& one, string& two)
{
    //get input
    cin >> one >> two;
}

bool process(string& one, string& two)
{
    //process input
    //thanks to Isaac giving away the answer ;)
    int pos = 0;
    int i = 0;
    while ((pos = two.find_first_of(one[i], pos)) != string::npos && i < one.length())
    {
        pos++;
        i++;
    }
    if (i == one.length())
    {
        return true;
    }

    return false;
}

int main()
{
    //getline(cin, temp);
    bool moreToDo = true;
    string one, two;
    bool success = false;
    while (moreToDo != cin.eof())
    {
        
        one = two = "";
        getInput(one, two);

        /*
           The lines below are necessary because the input file ends with a new line...
           I should rethink the way I break out of my loops because it seems redundant.
        */
        if (cin.eof())
            break;

            
        success = process(one, two);
        /*output*/
        if (success)
        {
            cout << "Yes" << endl;
        }
        else { cout << "No" << endl; }

        /*output*/
    }
}
