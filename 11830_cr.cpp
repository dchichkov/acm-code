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
string rol;
int digit;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input

    scanf("%d ", &digit);
    getline(cin, rol);
    
    if (digit == 0 && rol == "0") return false;
    return true;
}

void process()
{
    //process input
    bool hit_nonz = false;

    REP(i, rol.length())
    {
        if (rol[i] != ('0' + digit))
        {
            if (rol[i] != '0')
                hit_nonz = true;
            if (hit_nonz)
                fputc(rol[i], stdout);
        }
    }
    if (!hit_nonz)
        fputc('0', stdout);
    puts("");
    
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
