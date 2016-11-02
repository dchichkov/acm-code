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
vector<string> validw;
vector<string> titles;
vector<string> ignorel;
/*global variables*/

struct cmp2
{
    bool operator()(string a, string b)
    {
        REP(i, a.length())
        {
            a[i] = toupper(a[i]);
        }
        REP(j, b.length())
        {
            b[j] = toupper(b[j]);
        }
        return a.compare(b) == 0;
    }
};
        

struct cmp
{
    bool operator()(string a, string b)
    {
        REP(i, a.length())
        {
            a[i] = toupper(a[i]);
        }
        REP(j, b.length())
        {
            b[j] = toupper(b[j]);
        }
        return a < b;
    }
};
        

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    string line;
    //get list of words to ignore

    getline(cin, line);
    while (line.compare("::") != 0)
    {
        ignorel.push_back(line);
        getline(cin, line);
    }

    //get titles

    getline(cin, line);
    while (line.length() != 0)
    {
        debug(line, endl);
        REP(i, line.length())
        {
            line[i] = tolower(line[i]);
        }
        titles.push_back(line);
        if (cin.eof()) break;
        getline(cin, line);
    }
    return true;
}

void process()
{
    //process input
    istringstream inp;
    string word, vw;
    //get valid words
    REP(i, titles.size())
    {
        inp.str(titles[i]);
        while (inp >> word) 
        {
            if (find(ignorel.begin(), ignorel.end(), word) == ignorel.end())
            {
                validw.push_back(word);
            }
        }
        inp.clear();
    }

    sort(validw.begin(), validw.end(), cmp());
    
    validw.erase(unique(validw.begin(), validw.end(), cmp2()), validw.end());
    
    string::size_type beg;
    string tline, argh;

    REP(i, validw.size())
    {
        debug(validw[i], endl);
        beg = -1;
        vw = validw[i];
        REP(j, vw.length())
        {
            vw[j] = toupper(vw[j]);
        }

        REP(k, titles.size())
        {
            tline = titles[k];
            while ((beg = tline.find(validw[i], beg+1)) != string::npos)
                   
            {
                argh = tline.substr(beg, tline.find(" ", beg+1)-beg);
                debug(argh, TAB); debug(validw[i], endl);
                if (argh != validw[i] || (beg != 0 && tline[beg-1] != ' ')) continue;
                tline.replace(beg, vw.length(), vw);
                cout << tline << endl;
                tline = titles[k];
            }
        }
    }
}

int main()
{
    //while (getInput())
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
