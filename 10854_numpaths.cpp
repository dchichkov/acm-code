#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
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
int count = 1;
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
/*
int else_nested_if();

int if_nested_if()
{
    int value = 0;
    bool has_nest = false;
    do
    {
        getInput();
        cout << "if_nested_if: \t";
        debug(cur_line, endl);
        if (strcmp(cur_line, "IF") == 0)
        {
            has_nest = true;
            value = if_nested_if();
        }
        else if (strcmp(cur_line, "ELSE") == 0)
        {
            value = else_nested_if();
            break;
        }
    } while (true);
    debug(has_nest, TAB); debug(value, endl);
    if (!has_nest) return value+2;
    else return value+1;
}

int else_nested_if()
{
    int value = 0;
    bool has_nest = false;
    do
    {
        getInput();
        cout << "else_nested_if: \t";
        debug(cur_line, endl);
        if (strcmp(cur_line, "IF") == 0)
        {
            value = if_nested_if();
            has_nest = true;
        }
    } while (strcmp(cur_line, "END_IF") != 0);

    debug(has_nest, TAB); debug(value, endl);
    if (!has_nest) return value+2;
    else return value+1;
    }*/

int process()
{
    int value = 0;
    do
    {
        getInput();
        cout << "process: \t";
        debug(cur_line, endl);
        if (strcmp(cur_line, "IF") == 0)
        {
            value += if_nested_if();
            count = 0;
        }
    }
    while (strcmp(cur_line, "ENDPROGRAM") != 0);
    debug(value, endl);
    return value;
}

int main()
{
    int nc;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        count += process();

        /*output*/
        printf("%d\n", count);
        
        count = 1;
        /*output*/
    }

    return 0;
}
