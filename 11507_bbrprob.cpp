#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
int len;
vector<string> operations;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &len);
    if (len == 0) return false;

    char op[3];
    FOR(i, 1, len)
    {
        scanf("%2s ", op);
        operations.push_back(op);
    }
    return true;
}

void process()
{
    char pn[3] = "+x";
    REP(i, len-1)
    {
        if (operations[i] == "+x")
        {
            if (strcmp(pn, "+x") == 0) {}
            else if (strcmp(pn, "-x") == 0) {}
            else if (strcmp(pn, "+y") == 0) {}
            else if (strcmp(pn, "-y") == 0) {}
            else if (strcmp(pn, "+z") == 0) {}
            else if (strcmp(pn, "-z") == 0) {}
        }
        else if (operations[i] == "-x")
        {
            if (strcmp(pn, "+x") == 0) { strcpy(pn, "-x"); }
            else if (strcmp(pn, "-x") == 0) { strcpy(pn, "+x"); }
            else if (strcmp(pn, "+y") == 0) {}
            else if (strcmp(pn, "-y") == 0) //{ strcpy(pn, "-y"); }
            else if (strcmp(pn, "+z") == 0) { strcpy(pn, "-z"); }
            else if (strcmp(pn, "-z") == 0) { strcpy(pn, "+z"); }
        }
        else if (operations[i] == "+y")
        {
            if (strcmp(pn, "+x") == 0) { strcpy(pn, "+y"); }
            else if (strcmp(pn, "-x") == 0) { strcpy(pn, "-y"); }
            else if (strcmp(pn, "+y") == 0) { strcpy(pn, "-x"); }
            else if (strcmp(pn, "-y") == 0) { strcpy(pn, "+x"); }
            else if (strcmp(pn, "+z") == 0) {}
            else if (strcmp(pn, "-z") == 0) {}
        }
        else if (operations[i] == "-y")
        {
            if (strcmp(pn, "+x") == 0) { strcpy(pn, "-y"); }
            else if (strcmp(pn, "-x") == 0) { strcpy(pn, "+y"); }
            else if (strcmp(pn, "+y") == 0) { strcpy(pn, "+x"); }
            else if (strcmp(pn, "-y") == 0) { strcpy(pn, "-x"); }
            else if (strcmp(pn, "+z") == 0) {}
            else if (strcmp(pn, "-z") == 0) {}
        }
        else if (operations[i] == "+z")
        {
            if (strcmp(pn, "+x") == 0) strcpy(pn, "+z");
            else if (strcmp(pn, "-x") == 0) strcpy(pn, "-z");
            else if (strcmp(pn, "+y") == 0) {}
            else if (strcmp(pn, "-y") == 0) {}
            else if (strcmp(pn, "+z") == 0) strcpy(pn, "-x");
            else if (strcmp(pn, "-z") == 0) strcpy(pn, "+x");
        }
        else if (operations[i] == "-z")
        {
            if (strcmp(pn, "+x") == 0) strcpy(pn, "-z");
            else if (strcmp(pn, "-x") == 0) strcpy(pn, "+z");
            else if (strcmp(pn, "+y") == 0) {}
            else if (strcmp(pn, "-y") == 0) {}
            else if (strcmp(pn, "+z") == 0) strcpy(pn, "+x");
            else if (strcmp(pn, "-z") == 0) strcpy(pn, "-x");
        }
        //printf("%s\n", pn);
    }
    printf("%s\n", pn);
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        operations.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
