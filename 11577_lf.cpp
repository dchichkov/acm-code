#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
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
map<char, int> ltr_cnt;
string line;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    getline(cin, line);
    return true;
}

void process()
{
    int maxc = 0;
    string fin_ans;
    //process input
    FOR(i, 'a', 'z'+1)
        ltr_cnt[i] = 0;

    REP(i, line.length())
    {
        if (isalpha(line[i]))
            line[i] = tolower(line[i]);
    }
    REP(i, line.length())
    {
        if (ltr_cnt.find(line[i]) != ltr_cnt.end())
            ltr_cnt[line[i]] += 1;
    }

    FOR(i, 'a', 'z'+1)
        maxc = max(maxc, ltr_cnt[i]);

    FOR(i, 'a', 'z'+1)
        if (ltr_cnt[i] == maxc) fin_ans += i;

    SORT(fin_ans);
    cout << fin_ans << endl;
}

int main()
{
    int nc;
    scanf("%d\n", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        ltr_cnt.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
