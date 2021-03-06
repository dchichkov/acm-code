#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
int nl;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d", &nl);
    cin.ignore(); //IGNORE NEW LINE IS THE ONLY WAY! ZOMG SCANF!
    return true;
}

void sp(string& s)
{
    size_t pos, pos2;
    pos = s.find_first_of(" ");
    while (pos != string::npos)
    {
        pos2 = s.find_first_not_of(" ", pos);
        if (pos2 - pos > 1)
            s.replace(pos, pos2-pos, " ");
        pos = s.find_first_of(" ", pos+1);
    }

    
}

void process()
{
    //process input
    string line;
    REP(i, nl)
    {
        getline(cin, line);
        sp(line);
        cout << line << endl;
    }
}

int main()
{
    int nc, count = 0;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        printf("Case %d:\n", ++count);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
        if (nc != 0)
            cout << endl;
    }

    return 0;
}
