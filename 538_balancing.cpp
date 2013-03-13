#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
int n, q;
map<string, int> transactions;
/*global variables*/

template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p)
{
    return std::pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
std::map<B,A> flip_map(const std::map<A,B> &src)
{
    std::map<B,A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), 
                   flip_pair<A,B>);
    return dst;
}


void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d %d ", &n, &q);
    if (n == 0 and q == 0) return false;
    return true;
}

void process()
{
    //process input
    string name;
    REP(i, n)
    {
        cin >> name;
        transactions[name] = 0;
    }

    string name2;
    int amt;

    REP(i, q)
    {
        cin >> name >> name2 >> amt;
        transactions[name] -= amt;
        transactions[name2] += amt;
    }
    map<int, string> wtf = flip_map(transactions);
    int total = 0;
    for (map<int, string>::reverse_iterator rt(wtf.rbegin()),
             jt = ++wtf.rbegin(); jt != wtf.rend(); rt++, jt++)
    {
        printf("%s %s %d\n", (rt->second).c_str(), (jt)->second.c_str(), (rt->first)+total);
        total += rt->first;
    }
    printf("\n");
}

int main()
{
    int count = 0;
    while (getInput())
    {
        printf("Case #%d\n", ++count);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        transactions.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
