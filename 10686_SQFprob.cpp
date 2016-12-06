#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <sstream>

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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
map<string, vector<string> > wds;
map<string, int> cnt;
map<string, int> score;
vector<string> names;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int nmw;
    scanf("%d ", &nmw);
    string nm, word;
    int amt, sc;
    REP(i, nmw)
    {
        cin >> nm >> amt >> sc;
        debug(nm, TAB); debug(amt, TAB); debug(sc, endl);
        score[nm] = sc;
        names.push_back(nm);
        REP(j, amt)
        {
            cin >> word;
            wds[word];
            wds[word].push_back(nm);
            debug(word, endl);
        }
    }
    return true;
}

string cleanse(string wd)
{
    string out;
    REP(i, wd.length())
    {
        if (isalpha(wd[i]))
        {
            out += wd[i];
        }
    }
    return out;
}

void process()
{
    //process input
    string line;
    stringstream str;
    string word;
    cin.ignore(1, '\n');
    getline(cin, line);
    while (line.length() != 0)
    {
        debug(line, TAB);
        str.str(line);
        while (str >> word)
        {
            word = cleanse(word);
            debug(word, TAB);
            if (wds.find(word) != wds.end())
            {
                REP(i, wds[word].size())
                {
                    cnt[wds[word][i]]++;
                }
            }
            dbg(cout<<endl;);
        }
        
        str.clear();
        if (cin.eof()) line.clear();
        getline(cin, line);
        debug(cin.eof(), endl);
    }
    vector<string> solutions;
    REP(i, names.size())
    {
        if (cnt[names[i]] >= score[names[i]])
            solutions.push_back(names[i]);
    }
    if (solutions.size() > 0)
    {
        cout << solutions[0];
        FOR(i, 1, solutions.size())
        {
            cout << "," << solutions[i];
        }
    }
    else
        cout << "SQF Problem.";
    puts("");
    
}

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        wds.clear();
        cnt.clear();
        score.clear();
        names.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
