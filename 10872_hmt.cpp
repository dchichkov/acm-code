/**
 * Author: Matthew Gavin
 * Date: 9/24/2012
 * Problem: 10872 How Many Triangles
 * Description: I cheated and looked up the answer -->
 *              http://www.themathcircle.org/integertriangles.pdf
 *
 * Prof. Isaac Traxler
 * Compiled with: g++ 10872_hmt.cpp -o 10872
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
long long int N;
long long int answer;
int counter;
char line[30];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    fgets(line, 30, stdin);
    //get input
    //scanf("%lld", &N);
    N = strtol(line, NULL, 10);
    if (N == 0) return false;
    return true;
}

void process()
{
    fputs("Case ", stdout);
    if (N%2 == 0)
        answer = (N*N+24)/48; //rounding by adding 1/2
    else
    {
        N += 3;
        answer = ((N)*(N)+24)/48; //same rounding here
    }

    //printf("%lld\n", (N==3) ? 1 : answer);
    sprintf(line, "%d: %lld", counter++, (N==3) ? 1 : answer);
    fputs(line, stdout);
    puts("");
}

int main()
{
    counter = 1;
    while (getInput())
    {

        process();

        /*output*/


        /*output*/
        answer = 0;
    }

    return 0;
}
