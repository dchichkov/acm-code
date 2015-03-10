#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
char a[15], b[15];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%s %s\n", a, b);
    if (strcmp(a, "0") == 0 && strcmp(b, "0") == 0)
        return false;
    return true;
}

void process()
{
    //process input
    int dig1, dig2;
    int num_carries = 0, amt_carried = 0;
    int size = max(strlen(a), strlen(b));
    
    string c = a, d = b;
    if (c.length() > d.length())
        d.insert(0, c.length()-d.length(), '0');
    else if (d.length() > c.length())
        c.insert(0, d.length()-c.length(), '0');

    debug(c, TAB); debug(d, endl);
    for (int i = min(c.length(), d.length())-1; i >= 0; --i)
    {
        dig1 = c[i] - '0';
        dig2 = d[i] - '0';
        if ((dig1 + dig2 + amt_carried) >= 10)
        {
            num_carries++;
            amt_carried = 1;
        } else amt_carried = 0;
        debug(dig1, TAB); debug(dig2, TAB); debug(num_carries, TAB); debug(amt_carried, endl);
    }

    if (num_carries == 0)
        printf("No carry operation.");
    else if (num_carries == 1)
        printf("1 carry operation.");
    else if (num_carries > 1)
        printf("%d carry operations.", num_carries);

    printf("\n");
}

int main()
{
    bool moreToDo;
    while (moreToDo = getInput())
    {
        process();

        /*output*/


        /*output*/
        CL(a, 0);
        CL(b, 0);
    }

    return 0;
}
