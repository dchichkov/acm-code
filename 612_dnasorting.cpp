#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#define dbg(end) end
#else
#define debug(a, end)
#define dbg(end)
#endif

typedef pair<int, int> point;
typedef long long int64; //for clarity
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
struct cmp
{
    bool operator()(const pair<string, int>& a, const pair<string, int>& b)
    {
        return a.second < b.second;
    }
};

int x, y;
vector<pair<string, int> > dna;
/*global variables*/

void dump()
{
    //dump data
}

int num_bub(string s)
{
    int n_swaps = 0;
    debug(s, endl);
    
    for (int i = s.length(); i > 1; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (s[j] > s[j+1])
            {
                std::swap(s[j], s[j+1]);
                n_swaps++;
            }
        }
    }
    return n_swaps;
}

bool getInput()
{
    //get input
    scanf("%d %d\n", &x, &y);
    pair<string, int> d;
    REP(i, y)
    {
        getline(cin, d.first);
        d.second = num_bub(d.first);
        dna.push_back(d);
    }
    return true;
}

void process()
{
    //process input
    dbg(cout << "derp" << endl);
    sort(dna.begin(), dna.end(), cmp());
    dbg(cout << "derp" << endl);
    for (vector<pair<string, int> >::iterator it = dna.begin(); it != dna.end(); ++it)
        cout << it->first << endl;
}

int main()
{
    int nc;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        dna.clear();
        /*CLEAR GLOBAL VARIABLES!*/
        if (nc != 0)
            printf("\n");
    }

    return 0;
}
