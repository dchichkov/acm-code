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

#define ERROR 1e9

/*global variables*/
int k;
int karry[14];
int ppl[28];
/*global variables*/

void dump()
{
    //dump data
}

void preprocess()
{
    int counter, rotate;
    FOR(i, 1, 5)
    {
        REP(l, i)
        {
            ppl[l] = 1;
        }
        FOR(m, i, i+i)
        {
            ppl[m] = -1;
        }
        REP(n, i+i)
        {
            debug(ppl[n], TAB);
        }
        dbg(cout << endl);

        FOR(step, i, ERROR)
        {
            counter = 0;
            rotate = step;
            while (ppl[rotate-1] == -1)
            {
                counter++;
                ppl[rotate-1] = 0;
                debug(rotate, TAB); debug(step, TAB); debug(rotate+step, TAB);
                debug(i+i+1, TAB); debug(((rotate + step) % (i+i+1)), endl);
                rotate = (rotate + step) % (i+i+1);
                debug(ppl[rotate-1], TAB); debug(rotate, endl);
            }
            if (counter == i)
            {
                karry[i-1] = step;
                break;
            }
        }
        debug(counter, endl);
    }
}

bool getInput()
{
    //get input
    scanf("%d ", &k);
    if (k == 0) return false;
    return true;
}

void process()
{
    //process input
    printf("%d\n", karry[k-1]);
}

int main()
{
    preprocess();
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
