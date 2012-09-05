/**
 * Author: Matthew Gavin
 * Date: 9/5/2012
 * Problem: 10854 Number of Paths
 * Description: Solution -> For every branch path, count the number of branching paths,
 *                          and return them multiplied together.
 *                          If there is no branching path, return 1.
 *                          Do that instead of trying to count up all the paths as you go along parsing it..
 *                          Although do you count as you go along in the same way a compiler would? Or
 *                          is this the more correct method? Idk
 *                          Never would've thought of this without Andrew's submission..
 *
 * Prof. Isaac Traxler
 * Compiled with: g++ 10854_numpaths.cpp -o 10854
 * Compiler: g++ 4.6.1
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#else
#define debug(a, end)
#endif

typedef pair<int, int> point;
typedef long long int64; //for clarity
typedef vector<int> vi; //?
typedef vector<point> vp; //?
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //change min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //change max

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
char cur_line[25];
/*global variables*/


void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%s\n", cur_line);
    return true;
}

int count_else();

int count_ifs()
{
    int count = 0, total = 1; //the total is 1 for this branch
    //at an if branch
    getInput(); //grab next token
    while (strcmp(cur_line, "ELSE") != 0) //keep going within this branch
    {
        if (strcmp(cur_line, "IF") == 0) //we hit a branch
        {
            count = count_ifs(); //count branching ifs, don't keep a total count, so reset it everytime, the count only represents this branch
            count += count_else(); //count corresponding else branch
            total *= count; //multiply the number of branches
        }
        getInput(); //grab next token
    }

    return total;
}

int count_else()
{
    int count = 0, total = 1; //the total is 1 for this branch
    //at an else branch
    getInput(); //grab next token .. this kind of "hiccups" over the else token, which happens when we count else's at every branch
    while (strcmp(cur_line, "END_IF") != 0) //keep going within this branch
    {
        if (strcmp(cur_line, "IF") == 0) //we hit a branch
        {
            count = count_ifs(); //count branching ifs, don't keep a total count, so reset it everytime, the count only represents this branch
            count += count_else(); //count corresponding else branch
            total *= count; //multiply the number of branches
        }
        getInput(); //grab next token
    }

    return total;
    
}

unsigned long process()
{
    unsigned long branches = 1, count = 0;
    //so this is the main branch
    getInput();
    while (strcmp(cur_line, "ENDPROGRAM") != 0) //make sure we're not at the end
    {
        if (strcmp(cur_line, "IF") == 0)
        {
            //we hit a branch
            //multiply by branching ifs
            count = count_ifs(); //don't keep a total count, so reset it everytime, the count only represents this branch
            //multiply by branching elses , because else's follow ifs and are a separate branch
            count += count_else();
            branches *= count;
        }
        getInput(); //go again if necessary
    }
    debug(branches, endl);
    return branches;
}

int main()
{
    int nc;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        /*output*/
        printf("%ld\n", process());
        /*output*/
    }

    return 0;
}
