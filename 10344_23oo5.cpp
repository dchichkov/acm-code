#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <stdlib.h>

using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
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
int nums[5];
int ops[] = {0, 1, 2}; //+ - *
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    int a, b, c, d, e;
    //get input
    scanf("%d %d %d %d %d\n", &a, &b, &c, &d, &e);
    if (a == 0) return false;

    nums[0] = a;
    nums[1] = b;
    nums[2] = c;
    nums[3] = d;
    nums[4] = e;
    
    return true;
}

bool process(vi numa, int num, int total, int op, string b)
{
    /*char k[10];
    sprintf(k, "%d", num);
    switch(op)
    {
    case 0:
        b += "+";
        break;
    case 1:
        b += "-";
        break;
    case 2:
        b += "*";
        break;
    }
    b += k;*/
    //process input
    switch (op)
    {
    case 0:
        total += num;
        break;
    case 1:
        total -= num;
        break;
    case 2:
        total *= num;
    }

    if (numa.size() == 0)
    {
        //debug(total, endl);
        if (total == 23)
        {
            //cout << b << endl;
            return true;
        }
        else
            return false;
    }
    else
    {
        REP(i, numa.size())
        {
            vi numbs(numa.begin(), numa.end());
            int numba = numa[i];
            numbs.erase(numbs.begin()+i);
            REP(j, 3)
            {
                if (process(numbs, numba, total, j, b))
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    bool derp = false;
    while (getInput())
    {

        REP(i, 5)
        {
            string a;
            vi numbs(nums, nums+5);
            int it = numbs[i];
            numbs.erase(numbs.begin()+i);
            derp = process(numbs, it, it, -1, a);
            if (derp) break;
            
        }
        if (derp)
            printf("Possible\n");
        else printf("Impossible\n");
        /*output*/

        derp = false;
        /*output*/
    }

    return 0;
}
