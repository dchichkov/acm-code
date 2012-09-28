#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>

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
string corr[100];
string given[100];

int n, m, counter = 1;

enum status { ac, pe, wa };
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input

    scanf("%d", &n);
    if (n == 0) return false;
    cin.ignore();

    REP(i, n)
        getline(cin, corr[i]);

    scanf("%d", &m);
    cin.ignore();
    REP(i, m)
        getline(cin, given[i]);
    
    return true;
}

void process()
{
    //process input
    status x = wa;
    string num_str1, num_str2;

    if (m == n)
    {
        //check ac
        x = ac;
        REP(i, n)
        {
            if (corr[i].compare(given[i]) != 0)
            {
                debug(corr[i], TAB); debug(given[i], endl);
                x = wa;
                break;
            }
        }
    }
    if ( x != ac )
    {
        REP(i, n)
        {
            REP(j, corr[i].length())
                if (isdigit(corr[i][j]))
                    num_str1 += corr[i][j];
        }
        
        REP(i, m)
        {
            REP(j, given[i].length())
                if (isdigit(given[i][j]))
                    num_str2 += given[i][j];
        }

        if (num_str1.compare(num_str2) == 0)
        {
            debug(num_str1, TAB); debug(num_str2, endl);
            x = pe;
        }
        else
            x = wa;
    }


    string verdict;
    switch (x)
    {
    case ac:
        verdict = "Accepted";
        break;
    case pe:
        verdict = "Presentation Error";
        break;
    case wa:
        verdict = "Wrong Answer";
        break;
    }

    printf("Run #%d: %s\n", counter++, verdict.c_str());
                    
}

int main()
{
    while (getInput())
    {

        process();

        /*output*/


        /*output*/
    }

    return 0;
}
