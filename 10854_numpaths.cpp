#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
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
char cur_line[25];
int count = 1;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%s\n", cur_line);
    return true;
}

int process()
{
    int branches = 0;
    do
    {
        getInput();
        if (strcmp("IF", cur_line) == 0 || strcmp("ELSE", cur_line) == 0)
        {
            branches += 1;
            branches += process();
        }
        else if (strcmp("END_IF", cur_line) == 0)
            break;

    }while (strcmp("ENDPROGRAM", cur_line) != 0);
    return branches;
}

int main()
{
    int nc;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        count += process();

        /*output*/
        printf("%d\n", count);
        
        count = 1;
        /*output*/
    }

    return 0;
}
