#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
char* line;
size_t max_len = 100001;
unsigned char mem[100];
size_t len;
int nc, count = 0, pos = 0;
char ans[2] = {'0', '0'};
/*global variables*/

void dump()
{
    //dump data
}

int main()
{

    scanf("%d\n", &nc);
    while (nc-- > 0)
    {
        printf("Case %d: ", ++count);
        len = getline(&line, &max_len, stdin);
        REP(i, len-1)
        {
            switch(line[i])
            {
            case '+':
                mem[pos]++;
                break;
            case '<':
                pos -= 1;
                if (pos < 0)
                    pos = 99;
                break;
            case '>':
                pos += 1;
                pos %= 100;
                break;
            case '-':
                mem[pos]--;
                break;
            }
        }

        printf("%02X", mem[0]);
        FOR(i, 1, 100)
        {
            printf(" %02X", mem[i]);
        }
        puts("");

        /*CLEAR GLOBAL VARIABLES!*/
        CL(mem, 0);
        pos = 0;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
