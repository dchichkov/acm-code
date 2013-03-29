#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>

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

//typedef pair<int, int> point;
struct point
{ int x, y, z; };
        
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
struct Q_compare
{
    bool operator() (const point& a, const point& b)
    {
        debug(a.x, TAB); debug(a.y, endl);
        debug(b.x, TAB); debug(b.y, endl);
        if (b.y == a.y)
            return a.x > b.x;
        else
            return a.y > b.y;

    }
};

typedef priority_queue<point, vector<point>, Q_compare> pq;
pq registers;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    if (cin.eof()) return false;
    
    //get input
    string reg_word;
    point x;
    while (true)
    {
        cin >> reg_word;
        debug(reg_word, endl);
        if (reg_word.compare("#") == 0) break;
        if (cin.eof()) return false;

        cin >> x.x >> x.y;
        x.z = x.y;
        registers.push(x);
    }
    return true;
}

void process()
{
    //process input
    int k = 0;
    cin >> k;
    debug(k, endl);
    point x;
    REP(i, k)
    {
        cout << registers.top().x << endl;
        //pq::reference t = registers.top();
        //t.second += t.second;
        x.x = registers.top().x;
        x.y = registers.top().y + registers.top().z;
        x.z = registers.top().z;
        registers.pop();
        registers.push(x);
        x.x = 0;
        x.y = 0;
        x.z = 0;
    }
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        while (!registers.empty())
            registers.pop();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
