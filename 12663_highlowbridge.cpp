#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <stack>

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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
stack<vi::reverse_iterator> toremove;
vi bridges;
int counted[100001];
int n, m, k;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    
    scanf("%d %d %d ", &n, &m, &k);
    int h;
    
    REP(i, n)
    {
        scanf("%d ", &h);
        bridges.push_back(h);
    }
    return true;
}
int ugh(int item)
{
    debug("in ugh ", TAB); debug(item, endl);
    int first = 0;
    int last = bridges.size()-1;
    int middle = (first+last)/2;

    while (first <= last)
    {
        if (bridges[middle] < item)
            first = middle+1;
        else if (bridges[middle] == item)
        {
            while (bridges[middle+1] == item)
                middle++;
            return middle;
        }
        else
            last = middle-1;

        middle = (first+last)/2;
    }
    debug(first, TAB); debug(last, endl);
    if (first > last)
    {
        /*while (bridges[last] < item)
          last++;*/
        return last;
    }
    
    return 0;
}

int ugh2(int item)
{
    int i;
    for (i = 0; i < bridges.size() && bridges[i] != item; ++i);
    return i;
}           

void process()
{
    //process input
    int counter = 0;
    int a, b;
    //sort(bridges.begin(), bridges.end(), greater<int>());
    SORT(bridges);
    REP(i, bridges.size())
    {
        debug(bridges[i], TAB);
    }
    dbg( cout << endl; );
/*    SORT(bridges);
    vi::reverse_iterator c;

    REP(i, bridges.size())
    {
        debug(bridges[i], TAB);
    }
    dbg ( cout << endl; );
    REP(i, m)
    {
        scanf("%d %d ", &a, &b);
        debug(a, TAB); debug(b, endl);
        c = upper_bound(bridges.rbegin(), bridges.rend(), a);

        for (int i = c - bridges.rbegin();
             c != bridges.rbegin();
             ++c, --i)
        {
            debug(i, TAB);
            debug(*c, endl);
            if (*c > b)
                counted[i]++;
            else
                break;
            if (counted[i] >= k)
            {
                counter++;
                toremove.push(c);
            }
        }
    }

    while (!toremove.empty())
    {
        bridges.erase(toremove.top().base());
        toremove.pop();
    }
*/
    int bound = 0, j;
    REP(i, m)
    {
        scanf("%d %d ", &a, &b);
        j = ugh(a);
        debug(j, endl);
        for(; j >= 0; --j)
        {
            if (bridges[j] > bound)
                counted[j]++;
            else break;
        }
        bound = b;
    }
    dbg( cout << endl; )
    REP(i, n)
    {
        debug(counted[i], endl);
        if (counted[i] >= k)
            counter++;
    }
    printf("%d\n", counter);
}

int main()
{
    int nc = 1;
    bridges.reserve(10000);
    while (getInput())
    {
        printf("Case %d: ", nc++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        bridges.clear();
        CL(counted, 0);
        /*      while (!toremove.empty())
                toremove.pop();*/
        
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
