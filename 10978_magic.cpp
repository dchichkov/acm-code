#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
char cards[52][3];
int c;
/*global variables*/

void dump()
{
    //dump data
    REP(i, c)
    {
        printf("%d[%s] ", i+1, cards[i]);
    }
    puts("");
}

bool getInput()
{
    //get input
    int j = 0, k;
    scanf("%d ", &c);
    if (c == 0) return false;
    char cs[2], word[20];
    REP(i, c)
    {
        scanf("%2s %20s\n ", cs, word);
        debug(cs, TAB); debug(word, TAB);
        k = strlen(word);
        while (k-- > 0)
        {
            j %= c;
            ++j;
            while(strlen(cards[j-1]) != 0) { j %= c;  ++j;}
        }
        debug(j, endl);
        strcpy(cards[(j-1)], cs);
        dbg( dump(); );
    }
    
    return true;
}

void process()
{
    //process input
    printf("%s", cards[0]);
    FOR(i, 1, c)
    {
        printf(" %s", cards[i]);        
    }
    puts("");
}

int main()
{
    CL2d(cards, 0, 52, 3);
    while (getInput())
    {
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL2d(cards, 0, 52, 3);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
