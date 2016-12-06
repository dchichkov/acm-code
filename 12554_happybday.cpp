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
char song[16][9] = {"Happy", "birthday", "to", "you",
                    "Happy", "birthday", "to", "you",
                    "Happy", "birthday", "to", "Rujia",
                    "Happy", "birthday", "to", "you" };
vector<string> names;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int nn;
    string s;
    scanf("%d ", &nn);
    REP(i, nn)
    {
        getline(cin, s);
        names.push_back(s);
    }
    return true;
}

void process()
{
    //process input
    int i;
    for (i = 0; i < names.size(); ++i)
    {
        printf("%s: %s\n", names[i].c_str(), song[i%16]);
    }
    if (i % 16 < 16)
    {
        int j = i%16;
        for (; j < 16; ++j, i++)
        {
            i %= names.size();
            printf("%s: %s\n", names[i].c_str(), song[j%16]);
        }
    }
}

int main()
{
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
