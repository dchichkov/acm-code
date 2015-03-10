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

int front1[8];
int right1[8];
int dims;
int building[8][8];
/*global variables*/

void dump()
{
    //dump data
    REP(i, dims)
    {
        REP(j, dims)
        {
            cout << building[i][j] << '\t';
        }
        cout << endl;
    }
}

bool getInput()
{
    //get input
    CL(front1, 0);
    CL(right1, 0);
    scanf("%d ", &dims);

    int a;
    REP(i, dims)
    {
        scanf("%d ", &a);
        front1[i] = a;
    }
    REP(i, dims)
    {
        scanf("%d ", &a);
        right1[i] = a;
    }
  
    return true;
}

void process()
{
    //process input
    int maxa = 0, mina = 0;;

    CL2d(building, 0, 8, 8);
    //finding max
    dbg(cout << "max: " << endl; );
    REP(i, dims)
    {
        REP(j, dims)
        {
            building[i][j] = min(right1[dims-i-1], front1[j]);
        }
    }

    dbg( 
    dump();
    cout << endl; );
    REP(i, dims)
    {
        REP(j, dims)
        {
            maxa += building[i][j];
        }
    }

    CL2d(building, 0, 8, 8);
    REP(i, dims)
    {
        building[dims-1][i] = front1[i];
    }
    REP(i, dims)
    {
        building[i][dims-1] = right1[dims-i-1];
    }
    dbg(
    dump();
    cout << endl; );
    //finding min
    /*
    REP(i, dims)
    {
        REP(j, dims)
        {
            if (front1[i] == right1[j])
            {
                debug(front1[i], TAB); debug(right1[j], endl);
                building[dims-1][i] = 0;
                building[dims-j-1][i] = front1[i];
                break;
            }
        }
    }
    dump();
    dbg( cout << endl );
    REP(i, dims)
    {
        REP(j, dims)
        {
            if (right1[dims-i-1] == front1[dims-j-1])
            {
                building[i][dims-1] = 0;
                building[i][dims-j-1] = right1[dims-i-1];
                break;
            }
        }
    }

    dump();
    REP(i, dims)
    {
        REP(j, dims)
        {

            mina += building[i][j];
        }
    }*/
    int c1[9], c2[9];
    CL(c1, 0);
    CL(c2, 0);
    REP(i, dims)
    {
        c1[front1[i]]++;
        c2[right1[i]]++;
    }
    REP(i, 9)
    {
        if (c1[i] < c2[i])
        {
            mina += (c2[i] * i);
        }
        else
            mina += (c1[i] * i);
    }
    
    debug(mina, TAB); debug(maxa-mina, endl);
    printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", mina, maxa-mina);
}

int main()
{
    int nc = 0;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
