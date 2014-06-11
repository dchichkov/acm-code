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
string line;
int matrix[3][3];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    getline(cin, line);
    if (cin.eof()) return false;
    return true;
}

void process()
{
    //process input
    REP(i, line.length())
    {
        switch (line[i])
        {
        case 'a':
            matrix[0][0]++;
            matrix[0][1]++;
            matrix[1][0]++;
            break;
        case 'b':
            matrix[0][1]++;
            matrix[1][1]++;
            matrix[0][0]++;
            matrix[0][2]++;
            break;
        case 'c':
            matrix[0][2]++;
            matrix[0][1]++;
            matrix[1][2]++;
            break;
        case 'd':
            matrix[0][0]++;
            matrix[1][0]++;
            matrix[1][1]++;
            matrix[2][0]++;
            break;
        case 'e':
            matrix[0][1]++;
            matrix[1][0]++;
            matrix[1][1]++;
            matrix[1][2]++;
            matrix[2][1]++;
            break;
        case 'f':
            matrix[0][2]++;
            matrix[1][1]++;
            matrix[1][2]++;
            matrix[2][2]++;
            break;
        case 'g':
            matrix[2][0]++;
            matrix[1][0]++;
            matrix[2][1]++;
            break;
        case 'h':
            matrix[2][0]++;
            matrix[2][1]++;
            matrix[1][1]++;
            matrix[2][2]++;
            break;
        case 'i':
            matrix[1][2]++;
            matrix[2][1]++;
            matrix[2][2]++;
            break;
        }
    }

    
    REP(i, 3)
    {
        printf("%d", matrix[i][0]%10);
        FOR(j, 1, 3)
        {
            printf(" %d", matrix[i][j]%10);
        }
        puts("");
    }
    
}

int main()
{
    int count = 0;
    while (getInput())
    {
        printf("Case #%d:\n", ++count);
        CL2d(matrix, 0, 3, 3);
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
