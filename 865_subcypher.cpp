#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vector<string> lines;
char l1[100], l2[100], l3[100];
map<char, char> mapping;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    
    fgets(l1, 100, stdin);
    fgets(l2, 100, stdin);
    l1[strlen(l1)-1] = 0;
    l2[strlen(l2)-1] = 0;
    REP(i, strlen(l1))
        mapping[l1[i]] = l2[i];
    
    while (fgets(l3, 100, stdin), !feof(stdin) && strcmp(l3, "\n") != 0)
    {
        //read next line and add it to list
        l3[strlen(l3)-1] = 0;
        lines.push_back(l3);
    }
    scanf(" ");
    return true;
}

void process()
{
    //process input
    printf("%s\n", l2);
    printf("%s\n", l1);
    REP(i, lines.size())
    {
        REP(j, lines[i].length())
        {
            if (mapping.find(lines[i][j]) == mapping.end())
                printf("%c", lines[i][j]);
            else
                printf("%c", mapping[lines[i][j]]);
        }
        puts("");
    }
}

int main()
{
    int tc, cnt = 0;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();
        if (tc != 0) puts("");
        /*CLEAR GLOBAL VARIABLES!*/
        lines.clear();
        mapping.clear();
        CL(l3, 0);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
