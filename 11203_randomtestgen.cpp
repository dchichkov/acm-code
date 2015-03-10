#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <ctime>

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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
fstream fout;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    return true;
}

void process(fstream& fout)
{
    //process input
    int l, m, r;
    l = rand()%15;
    m = rand()%15;
    r = rand()%15;
    REP(i, l)
        fout << "?";
    fout << "M";
    REP(i, m)
        fout << "?";
    fout << "E";
    REP(i, r)
        fout << "?";
    fout << endl;
}

int main()
{
    srand(std::time(0));
    fout.open("11203_testdata.in", ios::out);
    fout << "1000" << endl;
    //while (getInput())
    {
        REP(i, 1000)
            process(fout);

        /*CLEAR GLOBAL VARIABLES!*/
        
        /*CLEAR GLOBAL VARIABLES!*/
    }
    fout.close();
    return 0;
}
