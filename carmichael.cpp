/**
 * Author: Matthew Gavin
 * Date: 3/28/2012
 * Problem: Carmichael Numbers - 10006
 * Description: Implementing the Sieve of Eratosthenes. Also there would have been no
 *              way to meet the time limit knowing the simpler form of modular
 *              exponentiation. You had to know the binary method.
 *              link : http://en.wikipedia.org/wiki/Modular_exponentiation
 *              and I still don't understand it yet.
 * Prof. Isaac Traxler
 * Compiled with: g++ carmichael.cpp -o cm
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
//#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define print(a, end) cout << #a << ": " << a << end
#else
#define print(a, end)
#endif

using namespace std;

/*global variables*/
int number;
const int UPPERLIMIT = 65000;
int a[UPPERLIMIT];
//char c[UPPERLIMIT][UPPERLIMIT-2];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    cin >> number;
    if (number == 0)
        return false;
    else
        return true;
}
/*
  Thinking about Shor's algorithm
void generateLifecycle(vector<int>& list, long long iteration)
{
    list.clear();
    
    int power = 2;
    long long num = iteration;

    list.push_back(num%number);
    num *= iteration;
    do
    {
        list.push_back(num%number);
        num *= iteration;
    } while (list.back() != list.front() && power++ <= number);

    list.erase(list.end()-1);

    }*/
int modular_pow(long long base, int exponent, int modulus)
{
    int c = 1;
    while (exponent > 0)
    {
        if ((exponent & 1) == 1)
            c = (c*base)%modulus;
        exponent >>= 1;
        base = (base*base)%modulus;
        
    }
    return c;
}
            

bool process()
{
    //process input
    if (a[number] != -1)
        return true; 
    else
    {
        //test carmichaelality
        for (int i = 2; i < number; ++i)
        {
            if (modular_pow(i, number, number) != i)
                return true;
        }
    }
    return false;
}

int main()
{
    //SoE
    for (int i = 0; i < UPPERLIMIT; ++i) a[i] = 0;
    for (int i = 2; i < UPPERLIMIT; ++i)
    {
        if (a[i] == 0)
        {
            a[i] = 1;
            for (int j = i+i; j < UPPERLIMIT; j+=i) a[j] = -1;
        }
    }

    /*
    for (int i = 0; i < UPPERLIMIT; ++i)
        for (int j = 2; j < UPPERLIMIT; ++j)
        {
            c[i][j-2] = modular_pow(j, i, i);
        }*/
    
    bool moreToDo;
    while (moreToDo = getInput())
    {

        if (process())
            cout << number << " is normal." << endl;
        else
        {
            cout << "The number " << number << " is a Carmichael number." << endl;
        }

        /*output*/


        /*output*/
    }
}
