#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <sstream>

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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vi one, two;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    stringstream str;
    string a, b;
    getline(cin, a);
    getline(cin, b);

    int n;
    str.str(a);
    while (str >> n)
        one.push_back(n);

    str.clear();
    str.str(b);
    while ((str >> n))
        two.push_back(n);

    scanf(" ");
    return true;
}

void process()
{
    //process input
    int cnt1 = 0, cnt2 = 0;
    REP(i, one.size())
        if (find(two.begin(), two.end(), one[i]) != two.end())
            cnt2++;

    REP(i, two.size())
        if (find(one.begin(), one.end(), two[i]) != one.end())
            cnt1++;
                    
    if (cnt2 == one.size() && cnt1 == two.size())
        printf("A equals B");
    else if (cnt2 == 0 && cnt1 == 0)
        printf("A and B are disjoint");
    else if (cnt2 == one.size())
        printf("A is a proper subset of B");
    else if (cnt1 == two.size())
        printf("B is a proper subset of A");
    else if (cnt1 != two.size() && cnt2 != one.size())
        printf("I'm confused!");

    puts("");  
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        one.clear();
        two.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
