#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
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
vi primes;
map<char, int> ltr_count;
string line;
/*global variables*/

void sieve()
{
    //SOE, precompute
    bool pr[2001];
    REP(i, 2001)
        pr[i] = true;

    FOR(i, 2, 2001)
    {
        if (pr[i])
        {
            primes.push_back(i);
            for (int j = i*i; j < 2001; j += i)
            {
                pr[j] = false;
            }
        }
    }
}

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
    vector<char> ans;
    
    //process input
    REP(i, line.length())
        ltr_count[line[i]]++;

    for (map<char,int>::iterator it = ltr_count.begin(); it != ltr_count.end(); ++it)
        if (find(primes.begin(), primes.end(), it->second) != primes.end())
            ans.push_back(it->first);

    if (ans.empty())
        printf("empty");
    else
    {
        SORT(ans);
        REP(i, ans.size())
            printf("%c", ans[i]);
    }
            
    printf("\n");
}

int main()
{
    sieve();
    int nc, count = 0;
    scanf("%d\n", &nc);
    while (nc-- > 0)
    {
        printf("Case %d: ", ++count);
        
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        ltr_count.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
