#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

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
char line1[1005], line2[1005];
int counted[50];
/*global variables*/

void dump()
{
    //dump data
}

int count_char(const char* s, const char& ltr)
{
    int count = 0;
    REP(i, strlen(s))
        if (s[i] == ltr) ++count;

    return count;
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    fgets(line1, 1005, stdin);
    if (feof(stdin)) return false;
    fgets(line2, 1005, stdin);
    
    /*
    string line;
    line.clear();
    REP(i, line1.length())
        if (isalpha(line1[i]) && islower(line1[i]))
            line += line1[i];

    line1 = line;
    line.clear();

    REP(i, line2.length())
        if (isalpha(line2[i]) && islower(line2[i]))
            line += line2[i];

    line2 = line;*/
    return true;
}

void process()
{

    //process input
    line1[strlen(line1)-1] = 0;
    string line = line1;
    UN(line);
    REP(i, line.length())
    {
        counted[line[i]-'a'] = min(count_char(line1, line[i]), count_char(line2, line[i]));
    }
    REP(i, 26)
    {
        if (counted[i] != 0)
        {
            REP(j, counted[i])
            {
                printf("%c", ('a'+i));
            }
        }
    }
    
    printf("\n");
}

int main()
{
    while (getInput())
    {
        CL(counted, 0);
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
