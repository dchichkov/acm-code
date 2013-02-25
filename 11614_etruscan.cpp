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
unsigned long long num;
vector<unsigned long long> v;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    cin >> num;
    return true;
}

void fill_upto(unsigned long long n)
{
    while (v.back() <= n) { v.push_back((v.size()+1)*(v.size())/2); }
}

void process()
{
    //process input
    int i;
    fill_upto(num);
    debug(v.size(), TAB); debug(v.back(), endl);
    for (i = 1; num > v[i]; i++);
    printf("%d\n", i);        
}

int main()
{
    v.push_back(1);
    int nc = 0;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
