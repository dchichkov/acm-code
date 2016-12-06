#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

//#define DEBUG  //comment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#define dbg(end) end
#else
#define debug(a, end)
#define dbg(end)
#endif

typedef pair<int, int> point;
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
char upshift[32];
char downshift[32];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    char c;
    int iss = 0;
    REP(i, 32)
    {
        scanf("%c", &c);
        if (c == ' ')
        {
            if (iss == 2) { downshift[i] = 2; iss = 3; }
            if (iss == 1) { downshift[i] = 1; iss = 2; }
        }
        else downshift[i] = c;
        if (c == ' ' && iss == 0)
        {
            downshift[i] = c;
            iss = 1;
        }
    }
    scanf(" ");

    iss = 0;
    REP(i, 32)
    {
        scanf("%c", &c);
        if (c == ' ')
        {
            if (iss == 2) { upshift[i] = 2; iss = 3; }
            if (iss == 1) { upshift[i] = 1; iss = 2; }
        }
        else upshift[i] = c;
        if (c == ' ' && iss == 0)
        {
            upshift[i] = c;
            iss = 1;
        }
        
    }
    scanf(" ");

    
    return true;
}

void process()
{
    //process input
    char line[500], num[5];
    bool ds;
    long sup;
    fgets(line, 500, stdin);
    while (!feof(stdin))
    {
        ds = true;
        REP(i, strlen(line))
        {
            if (i+1 == strlen(line)) break;
            REP(j, 5)
            {
                num[j] = line[i+j];
            }
            i += 4;
            sup = strtol(num, NULL, 2);
            
            debug(sup, endl);
            debug((int)downshift[sup], TAB); debug((int)upshift[sup], endl);
            if (ds)
            {
                if (downshift[sup] == 1)
                    ds = true;
                else if (downshift[sup] == 2)
                    ds = false;
                else
                    printf("%c", downshift[sup]);
            }
            else
            {
                if (upshift[sup] == 1)
                    ds = true;
                else if (upshift[sup] == 2)
                    ds = false;
                else
                    printf("%c", upshift[sup]);
            }
        }
        puts("");
        fgets(line, 500, stdin);
    }
    
}

int main()
{
    //while ()
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
