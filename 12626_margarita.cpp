#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
string in;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    getline(cin, in);
    return true;
}

void process()
{
    //process input

    //M A R G A R I T A
    //A - 3
    //M - 1
    //R - 2
    //I - 1
    //G - 1
    //T - 1

    int As = count(in.begin(), in.end(), 'A') / 3;
    int Rs = count(in.begin(), in.end(), 'R') / 2;
    int Ms = count(in.begin(), in.end(), 'T');
    int Is = count(in.begin(), in.end(), 'G');
    int Gs = count(in.begin(), in.end(), 'I');
    int Ts = count(in.begin(), in.end(), 'M');

    vi letters;
    letters.push_back(As);
    letters.push_back(Rs);
    letters.push_back(Ms);
    letters.push_back(Is);
    letters.push_back(Gs);
    letters.push_back(Ts);

    SORT(letters);
    cout << letters[0] << endl;
}

int main()
{
    int nc;
    cin >> nc;
    cin.ignore(1, '\n');
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
