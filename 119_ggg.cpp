#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>

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
map<string, int> frenz;
vector<string> friends;
bool first = true;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    scanf(" ");
    if (feof(stdin)) return false;
    else if (!first) puts("");
    else first = false;
    //get input
    int num_ppl;
    scanf("%d ", &num_ppl);
    string n;
    REP(i, num_ppl)
    {
        cin >> n;
        frenz[n] = 0;
        friends.push_back(n);
    }
    return true;
}

void process()
{
    //process input
    string name;
    int spent, div;
    
    REP(i, frenz.size())
    {
        cin >> name >> spent >> div;
        if (div != 0)
        {
            spent /= div;
            frenz[name] -= spent*div;
            REP(j, div)
            {
                cin >> name;
                frenz[name] += spent;
            }
        }
    }

    REP(i, friends.size())
    {
        cout << friends[i] << " " << frenz[friends[i]] << endl;
    }
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        frenz.clear();
        friends.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
