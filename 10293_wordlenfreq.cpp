#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
string line, lline;
map<int,int> ans;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    getline(cin, line);
    while (line.compare("#") != 0)
    {
        if (line[line.length()-1] == '-' || line[line.length()-1] == '\'')
            lline += line;
        else
            lline += line + " ";
        getline(cin, line);
    }
    return true;
}

void process()
{
    //process input
    debug(lline, endl);
    REP(i, lline.length())
    {
        switch(lline[i])
        {
        case ' ':
        case '?':
        case '!':
        case ',':
        case '.':
            lline[i] = ' ';
            break;
        default:
            break;
        }
        if (lline[i] == '-' || lline[i] == '\'')
            lline.erase(lline.begin()+i);
    }
    char *zoinks = strtok(const_cast<char*>(lline.c_str()), " ");
    while (zoinks != NULL)
    {
        ans[strlen(zoinks)] += 1;
        zoinks = strtok(NULL, " ");
    }

    for (map<int,int>::iterator it = ans.begin(); it != ans.end(); ++it)
        printf("%d %d\n", it->first, it->second);
    puts("");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        ans.clear();
        lline.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
