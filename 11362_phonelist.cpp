#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <csetjmp>

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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vector<string> nums;
bool match = false;
std::jmp_buf jump_buffer;
int cnt;
struct sorter
{
    bool operator()(const string& a, const string& b)
    {
        int c = min(a.length(), b.length());
        int d = a.substr(0,c).compare(b.substr(0, c));
        debug(d, TAB); debug(a.substr(0, c), TAB); debug(b.substr(0, c), endl);
        if (d == 0)
        {
            match = true;
            longjmp(jump_buffer, cnt++);
        }
        else return d < 1;
    }
    
};
/*global variables*/

void dump()
{
    //dump data
    REP(i, nums.size())
        printf("%s\n", nums[i].c_str());
}

bool getInput()
{
    //get input
    string line;
    int a;
    scanf("%d ", &a);
    REP(i, a)
    {
        getline(cin, line);
        nums.push_back(line);
    }
    return true;
}

void process()
{
    //process input
    cnt = setjmp(jump_buffer);
    if (!cnt)
        sort(nums.begin(), nums.end(), sorter());

    dbg( dump() );
    printf("%s\n", match ? "NO" : "YES");
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        cnt = 0;
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        nums.clear();
        match = false;
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
