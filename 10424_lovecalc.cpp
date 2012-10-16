#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
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
string line1, line2;
bool skipwtf = false, zero = false;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    if (cin.eof()) return false;
    getline(cin, line1);
    getline(cin, line2);

    debug(line1, TAB); debug(line2, endl);
    skipwtf = false;
    if (line1.length() == 0 && line2.length() == 0) skipwtf = true;
    zero = false;
    if (line1.length() == 0 || line2.length() == 0) zero = true;
    int i = 0;
    while (line1[i] != 0)
    {
        if (!isalpha(line1[i]))
            line1.erase(i, 1);
        else
        {
            line1[i] = tolower(line1[i]);
            ++i;
        }
    }

    i = 0;
    while (line2[i] != 0)
    {
        if (!isalpha(line2[i]))
            line2.erase(i, 1);
        else
        {
            line2[i] = tolower(line2[i]);
            ++i;
        }
    }

    debug(line1, TAB); debug(line2, endl);
    
    return true;
}

void process()
{
    //process input
    if (zero)
        cout << "0.00 %" << endl;
    else if (skipwtf)
        cout << endl;
    else
    {
        int suml1 = 0, suml2 = 0;
        REP(i, line1.length())
            suml1 += line1[i]-0x60;

        REP(i, line2.length())
            suml2 += line2[i]-0x60;

        debug(suml1, TAB); debug(suml2, endl);
        suml1 = (suml1%9) ? suml1%9 : 9;
        suml2 = (suml2%9) ? suml2%9 : 9;
        double a = (suml1 > suml2) ?
            (suml2)*1.0/(suml1) :
            (suml1)*1.0/(suml2);
        debug((suml1), TAB); debug((suml2), endl);
        debug(a, endl);
        printf("%0.2lf %%\n", a*100);
    }
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
