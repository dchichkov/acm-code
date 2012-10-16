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
#define dbg(end) end
#else
#define debug(a, end)
#define dbg(end)
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
char *line;
int prices[256];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int items;
    unsigned char c = 0;
    scanf("%d\n", &items);
    debug(items, endl);
    REP(i, items)
    {
        c = 0;
        scanf("%c", &c);
        scanf("%d%*c", &prices[c]);
        debug((int)c, TAB); debug(c, TAB); debug(prices[(unsigned int)c], endl);
    }
    
    
    return true;
}

void process()
{
    //process input
    int num_lines;
    size_t lz = 10000;
    int total = 0;
    scanf("%d%*c", &num_lines);
    debug(num_lines, endl);
    REP(i, num_lines)
    {
        lz = getline(&line, &lz, stdin);
        int count = 0;
        REP(j, lz)
        {
            total += prices[(unsigned char)line[j]];
        }
    }
    printf("%d.%02d$\n", total/100, total%100);
}

int main()
{
    line = (char*)malloc(10005);
    int nc;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        CL(prices, 0);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
