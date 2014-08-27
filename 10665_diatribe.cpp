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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int N;
string line;
map<char, int> ltrs;
vector<char> ltr;
vector<pair<char, int> > lts;

struct srt
{
    bool operator() (const pair<char, int>& a, const pair<char, int>& b)
    {
        return a.second > b.second;
    }
};
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d ", &N);
    getline(cin, line);
    debug(line, endl);
    return true;
}

void process()
{
    //process input
    REP(i, N)
    {
        debug((char)(0x41 + i), endl);
        ltrs[0x41 + i] = 0;
    }
    
    REP(i, line.length()-1)
    {
        if (line[i] - 0x41 < N)
        {
            ltrs[line[i]]++;
            debug(ltrs[line[i]], endl);
        }
    }
    pair<char, int> a;
    for (map<char, int>::iterator it = ltrs.begin(); it != ltrs.end(); ++it)
    {
        a.first = it->first;
        a.second = it->second;
        debug(it->first, TAB); debug(it->second, endl);
        lts.push_back(a);
    }
    sort(lts.begin(), lts.end(), srt());
    debug(lts.size(), endl);
    ltr.resize(N);
    int j = 0;
    REP(i, (lts.size()/2))
    {
        debug(lts[j].first, TAB); debug(lts[j+1].first, endl);
        if (ltrs[lts[j].first] == ltrs[lts[j+1].first])
        {
            if (lts[j].first < lts[j+1].first)
            {
                ltr[i] = lts[j].first;
                ltr[ltr.size()-i-1] = lts[j+1].first;
            }
            else
            {
                ltr[i] = lts[j+1].first;
                ltr[ltr.size()-i-1] = lts[j].first;
            }
        }
        else
        {
            ltr[i] = lts[j].first;
            ltr[ltr.size()-i-1] = lts[j+1].first;
        }
        j += 2;
    }
    dbg(
        REP(i, lts.size())
        {
            cout << lts[i].first << TAB;
        }
        cout << endl;

        );
    debug(lts.size()/2, TAB);
    debug(lts[lts.size()/2].first, endl);
    if (lts.size()%2 == 1)
    {
        ltr[((ltr.size())/2)] = lts[lts.size()-1].first;
    }
    
    REP(i, ltr.size())
    {
        printf("%c ", ltr[i]);
    }
    puts("");
    REP(i, ltr.size())
    {
        printf("%d ", ltrs[ltr[i]]);
    }
    puts("");
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        ltrs.clear();
        ltr.clear();
        lts.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
