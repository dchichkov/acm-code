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
char line[1001];
int i;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    char c;
    c = getc(stdin);
    if (c == '\n')
    {
        line[0] = 0;
    }
    else
    {
        ungetc(c, stdin);
        scanf("%1000s", line);
        getc(stdin);
    }
    return true;
}

int len(int l, int r)
{
    if (l == r) //odd length
        return 1;
    else if (l+1 == r) //even length
    {
        if (line[l] == line[r])
            return 2;
        else
            return 1;
    }

    if (line[l] == line[r])
    {
        return 2 + len(l+1, r-1); //add two to greatest of the middle
    }
    else
        return max(len(l+1, r), len(l, r-1)); //move left and right, return max
}

void process()
{
    i = strlen(line);
    if (i == 0)
        printf("0");
    else
        printf("%d", len(0, i));

    printf("\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    int nc;
    scanf("%d\n", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
