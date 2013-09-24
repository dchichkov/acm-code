#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int nreqs, nprops;

bool nfirst;  
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &nreqs, &nprops);

    if (nreqs == 0 && nprops == 0)
        return false;
    
    if (nfirst) printf("\n");
    return true;
}

void process()
{
    //process input
    string tstr;
    REP(i, nreqs)
    {
        getline(cin, tstr);
    }

    char name[100], tname[100];
    double cost, tcost;
    int nfulf = 0, tfulf;
    dbg(cout << "wtf" << endl);
    REP(i, nprops)
    {
        scanf("%80s %lf %d ", tname, &tcost, &tfulf);
        debug(tname, TAB); debug(tcost, TAB); debug(tfulf, endl);
        REP(i, tfulf)
        {
            getline(cin, tstr);
        }

        if (tfulf > nfulf)
        {
            strcpy(name, tname);
            cost = tcost;
            nfulf = tfulf;
        }
        else if (tfulf == nfulf && tcost < cost)
        {
            strcpy(name, tname);
            cost = tcost;
            nfulf = tfulf;
        }
    }
    
    printf("%s\n", name);
    
}

int main()
{
    int n = 1;
    while (getInput())
    {
        printf("RFP #%d\n", n++);
        process();
        if (n != 0) nfirst = true;
        /*CLEAR GLOBAL VARIABLES!*/
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
