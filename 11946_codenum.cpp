#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>

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
vector<string> lines;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    string line;
    getline(cin, line);
    while (line != "")
    {
        lines.push_back(line);
        if (cin.eof()) break;        
        getline(cin, line);
    }
    return true;
}

void process()
{
    //process input
    REP(i, lines.size())
    {

        REP(j, lines[i].length())
        {

            switch (lines[i][j])
            {
            case '0':
                lines[i][j] = 'O';
                break;
            case '1':
                lines[i][j] = 'I';
                break;
            case '2':
                lines[i][j] = 'Z';
                break;
            case '3':
                lines[i][j] = 'E';
                break;
            case '4':
                lines[i][j] = 'A';
                break;
            case '5':
                lines[i][j] = 'S';
                break;
            case '6':
                lines[i][j] = 'G';
                break;
            case '7':
                lines[i][j] = 'T';
                break;
            case '8':
                lines[i][j] = 'B';
                break;
            case '9':
                lines[i][j] = 'P';
                break;
            }
        }
    }

    for (vector<string>::iterator it = lines.begin(); it != lines.end(); ++it)
        cout << *it << endl;
}

int main()
{
    int nc;
    scanf("%d\n", &nc);
    
    while (nc-- > 0)
    {
        getInput();
        process();
        if (nc != 0)
            cout << endl;

        /*CLEAR GLOBAL VARIABLES!*/
        lines.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
