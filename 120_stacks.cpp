#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
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
vector<int> v;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    string line;
    getline(cin, line);
    istringstream s(line);
    int t;
    while (s >> t)
    {
        v.push_back(t);
    }

    return true;
}


void process()
{
    //process input
    printf("%d", v[0]);
    FOR(i, 1, v.size())
        printf(" %d", v[i]);
    cout << endl;
    
    int count = 0;
    for (int j = 0; j < v.size(); ++j)
    {
        if (v[0] > v[1])
        {
            ++count;
            reverse(v.begin(), v.end()-j);

            printf("%d ", count);
        }
    }

    printf("0\n");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        v.clear();
        
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
