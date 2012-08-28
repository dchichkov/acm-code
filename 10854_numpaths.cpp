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
    int count = 0;
    do
    {
        getInput();
        //cout << "count_ifs: \t";
        debug(cur_line, endl);
        if (strcmp(cur_line, "IF") == 0)
        {
            count += count_ifs();
        }
    }
    while (strcmp(cur_line, "ELSE") != 0);
    if (!count) count = 1;
    count += count_else();

    return count;
}

int count_else()
{
    int count = 0;
    do
    {
    again:
        getInput();
        //cout << "count_else: \t";
        debug(cur_line, endl);
        if (strcmp(cur_line, "IF") == 0)
        {
            count += count_ifs();
            goto again;
        }
    }
    while (strcmp(cur_line, "END_IF") != 0);
    if (!count) count = 1;
    return count;
}

unsigned long process()
{
    unsigned long branches = 1;
    do
    {
        getInput();
        //cout << "process: \t";
        debug(cur_line, endl);
        if (strcmp(cur_line, "IF") == 0)
        {
            debug(branches, endl);
            branches *= count_ifs();
        }
    }
    while (strcmp(cur_line, "ENDPROGRAM") != 0);
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
