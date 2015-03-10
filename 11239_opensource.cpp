#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
#include <cctype>
#include <algorithm>
#include <set>

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
map<string, set<string> > students;
vector<string> projects;
vector<pair<string, int> > totals;

struct cmp
{
    bool operator()(const pair<string, int>& a, const pair<string, int>& b)
    {
        if (a.second == b.second)
            return a.first.compare(b.first) < 0;
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
    string line;
    getline(cin, line);
    while (line != "1" && line != "0")
    {
        if (isupper(line[0]))
        {
            //project
            projects.push_back(line);
        }
        else if (islower(line[0]))
        {
            students[line].insert(projects.back());
        }
        getline(cin, line);
    }

    if (line == "0") return false;
    return true;
}

void process()
{
    //process input
    pair<string, int> p;
    REP(i, projects.size())
    {
        p.first = projects[i];
        p.second = 0;
        for (map<string, set<string> >::iterator it = students.begin(); it != students.end(); ++it)
        {
            if (it->second.size() == 1 &&
                find(it->second.begin(), it->second.end(), projects[i]) != it->second.end())
            {
                p.second++;
            }
        }
        totals.push_back(p);
    }

    sort(totals.begin(), totals.end(), cmp());
    debug(totals.size(), endl);
    REP(i, totals.size())
    {
        printf("%s %d\n", totals[i].first.c_str(), totals[i].second);
    }
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        students.clear();
        projects.clear();
        totals.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
