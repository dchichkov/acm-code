/* Class:   CSC 2700 Programming Competitions
 * Prof:    Isaac Traxler
 * Name:    Matthew Gavin
 * Problem: 640 - Self Numbers
 *
 * Note: Finally. Output all numbers less than or equal to 1000000 that are self numbers.
 *       Mitchell's single loop inspired me when I tried to do a sieve double loop and
 *       it took way too long.
 */ 

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define DEBUG  //comment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#define dbg(end) end
#else
#define debug(a, end)
#define dbg(end)
#endif

typedef pair<int, int> point;
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
bool numbers[1000001];
/*global variables*/

void dump()
{
    //dump data
}

int d(int num)
{
    int r = num;
    do r += (num%10); while ((num /= 10) != 0);
    return r;
}

bool getInput()
{
    //get input
    return true;
}

void process()
{
    //process input
    //sieve


    for (int i = 1, j = d(i); i < 1000001; i++, j = d(i))
    {
        if (j < 1000001)
            numbers[j] = 0;
    }

    FOR(i, 1, 1000001)
    {
        if (numbers[i]) cout << i << endl;
    }
}

int main()
{
    CL(numbers, 1); //set all to true
    //while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
