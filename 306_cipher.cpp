#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>

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
int n;
vi nums;
set<string> cycle;
bool first = false;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &n);
    if (n == 0) return false;
    
    int a;
    REP(i, n)
    {
        scanf("%d ", &a);
        nums.push_back(a);
    }
    return true;
}

void process()
{
    //process input
    int k, z;
    string line, newstring;
    pair<set<string>::iterator, bool> c;
    while (scanf("%d ", &k), k != 0)
    {
        getline(cin, line);
        debug(n-line.length(), TAB); debug(line, endl);
        line.append(n-line.length(), ' ');
        newstring.resize(n);
        z = 0;
        if (k == 0)
        {
            newstring = line;
        }
        else
        {
            REP(i, k)
            {
                REP(j, nums.size())
                {
                    newstring[nums[j]-1] = line[j];
                }
                line = newstring;
                z++;
                if (!(c = cycle.insert(line)).second)
                {
                    k %= z;
                }
            }
        }

        printf("%s\n", newstring.c_str());
    }
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        nums.clear();
        cycle.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
