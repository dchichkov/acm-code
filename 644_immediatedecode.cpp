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
vector<string> codes;
string line;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    char code[1000];
    scanf("%s ", code);
    while (code[0] != '9')
    {
        if (feof(stdin)) return false;
        codes.push_back(code);
        scanf("%s ", code);
    }
    return true;
}

void process()
{
    //process input
    //SORT(codes);
    bool decodable = true;
    REP(i, codes.size())
    {
        FOR(j, 0, codes.size())
        {
            if (j == i) continue;
            if (codes[j].substr(0, codes[i].length()).compare(codes[i]) == 0)
            {
                decodable = false;
                goto end;
            }
        }
    }
end:
    printf("is %simmediately decodable\n", decodable ? "" : "not ");
}

int main()
{
    int count = 0;
    while (getInput())
    {
        printf("Set %d ", ++count);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        codes.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
