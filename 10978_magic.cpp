#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
char cardarr[52][2];
int taken[52];
int N;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d", &N);
    if (N == 0) return false;
    return true;
}

void process()
{
    int pos = -1, w = 0;
    string card, word;
    //process input
    REP(i, N)
    {
        cin >> card >> word;
        pos = (pos + word.length()) % N;
        while (taken[pos]) pos = (pos + 1) % N;
        debug(card, TAB); debug(word, TAB); debug(pos, endl);
        cardarr[pos][0] = card[0];
        cardarr[pos][1] = card[1];
        taken[pos] = 1;

    }
    printf("%s", cardarr[0]);
    FOR(i, 1, N)
    {
        printf(" %s", cardarr[i]);
    }
    printf("\n");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(cardarr, 0, 52, 2);
        CL(taken, 0);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
