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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
char line[100];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    fgets(line, 100, stdin);
    scanf(" ");
    return true;
}

void process()
{
    //process input
    if (line[strlen(line)-1] == '\n') line[strlen(line)-1] = 0;

    bool match;
    int i, j, y = 0;
    char word[100];
    CL(word, 0);
    for (i = 1; i < strlen(line); ++i)
    {
        REP(x, i)
            word[x] = line[x];
        y = strlen(word);
        match = true;
        for (j = i; j < strlen(line); ++j)
        {
            for (int k = j; k+y < strlen(line); ++k)
                if (line[k] != word[k]) match = false;
            if (match) break;
        }
        if (match) break;
    }
    printf("%d\n", i+1);
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();

        if (tc != 0) puts("");
        /*CLEAR GLOBAL VARIABLES!*/
        
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
