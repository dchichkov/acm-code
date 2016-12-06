#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#else
#define debug(a, end)
#endif

typedef pair<int, int> point;
typedef long long int64; //for clarity
typedef vector<int> vi; //?
typedef vector<point> vp; //?
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } //change min
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } //change max

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int n, s, e, w, t, b;
int num_rolls;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d", &num_rolls);
    if (num_rolls == 0) return false;
        
    return true;
}

void process()
{
    char line[10];
    int tmp;
    //process input
    REP(i, num_rolls)
    {
        scanf("%10s", line);
        if (strcmp(line, "north") == 0)
        {
            n = t;
            t = s;
            s = b;
            b = 7-t;
        }
        else if (strcmp(line, "east") == 0)
        {
            b = e;
            e = t;
            t = w;
            w = 7-e;
        }
        else if (strcmp(line, "west") == 0)
        {
            w = t;
            t = e;
            e = b;
            b = 7-t;
        }
        else if (strcmp(line, "south") == 0)
        {
            b = s;
            s = t;
            t = n;
            n = 7-s;
        }
        debug(t, TAB); debug(n, TAB); debug(s, TAB); debug(e, TAB); debug(w, TAB); debug(b, endl); 
    }

    printf("%d\n", t);
}

int main()
{
    while (getInput())
    {
        t = 1;
        n = 2;
        w = 3;
        e = 4;
        s = 5;
        b = 6;
        process();

        /*output*/


        /*output*/
    }

    return 0;
}
