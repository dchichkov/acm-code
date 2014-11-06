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
char sentences[105][105];
int i, i2;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    i = i2 = 0;
    while(!feof(stdin))
    {
        fgets(sentences[i], 100, stdin);
        i2 = max((int)strlen(sentences[i])-1, i2);
        if (sentences[i][strlen(sentences[i])-1] == '\n')
            sentences[i][strlen(sentences[i])-1] = 0;
        if (strlen(sentences[i]) == 0) break;
        i++;
    }
    
    debug(i, endl);
    return true;
}

void process()
{
    //process input
    char sentence[105][105];
    CL2d(sentence, 0, 105, 105);
    REP(k, i)
    {
        REP(j, i2)
        {
            if (sentences[k][j] == '\n' ||
                sentences[k][j] == 0)
                sentence[j][i-k-1] = ' ';
            else
                sentence[j][i-k-1] = sentences[k][j];
            debug(j, TAB); debug(i-k-1, TAB); debug(sentence[j][i-k-1], endl);
        }
    }

    REP(k, i2)
    {
        printf("%s\n", sentence[k]);
    }
}

int main()
{
    CL2d(sentences, 0, 105, 105);
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
