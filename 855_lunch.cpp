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
vp friends;
vi a;
vi s;

struct cmp
{
	bool operator()(const point& a, const point& b)
	{
		if (a.first == b.first)
			return a.second < b.second;
		else
			return a.first < b.first;
	}

};


/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    int c, b, d;
	scanf("%d %d %d", &d, &b, &c);
	REP(i, c)
	{
		scanf("%d %d", &d, &b);
        a.push_back(d);
        s.push_back(b);
	}

    //get input
    return true;
}

void process()
{
    //process input

    SORT(a);
    SORT(s);

    int minp;
    if (!(a.size()%2))
        minp = a.size()/2-1;
    else
        minp = a.size()/2;
    
	printf("(Street: %d, Avenue: %d)\n", a[minp], s[minp]);
	
}

int main()
{
	int nc;
	scanf("%d", &nc);
    while (nc-- > 0)
    {
		getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        a.clear();
        s.clear();
		friends.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
