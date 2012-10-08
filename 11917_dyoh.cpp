#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>

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
map<string, int> spar;
enum cpbl {yes = 0, no, fnf}; //Yess, Late, DYOH
int nd;
string soah;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int subjects;
    string subj;
    int days;
    scanf("%d", &subjects);
    REP(i, subjects)
    {
        cin >> subj >> days;
        spar[subj] = days;
    }
    scanf("%d", &nd);
    cin >> soah;
    return true;
}

void process()
{
    //process input
    cpbl c;

    if (spar.find(soah) != spar.end())
    {
        if (spar[soah] <= nd)
            c = yes;
        else if (spar[soah] <= nd+5)
            c = no;
        else
            c = fnf;

    }
    else c = fnf;

    switch(c)
    {
    case yes:
        printf("Yesss");
        break;
    case no:
        printf("Late");
        break;
    case fnf:
        printf("Do your own homework!");
        break;
    }
    printf("\n");
}

int main()
{
    int nc, count = 0;
    scanf("%d", &nc);
    while (nc-- > 0)
    {
        printf("Case %d: ", ++count);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        spar.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
