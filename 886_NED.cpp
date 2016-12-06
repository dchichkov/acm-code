#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cctype>
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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
struct listing
{
    string fname, lname;
    string pnum;
};
vector<listing> listings;
vector<string> dialed;
map<char, string> numpad;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    string in;
    listing p;
    cin >> in;
    while (!cin.eof() || !in.empty())
    {
        if (isalpha(in[0]))
        {
            p.fname = in;
            cin >> in;
            p.lname = in;
            cin >> in;
            p.pnum = in;

            listings.push_back(p);
        }
        else if (isdigit(in[0]))
        {
            dialed.push_back(in);
        }
        in.clear();
        cin >> in;
        debug(in , endl);
    }

    REP(i, dialed.size())
    {
        debug(dialed[i], endl);
    }

    REP(i, listings.size())
    {
        debug(listings[i].fname, TAB);
        debug(listings[i].lname, TAB);
        debug(listings[i].pnum, endl);
    }
    return true;
}

void process()
{
    //process input
    vector<string> pos;
    bool match;
    REP(i, dialed.size())
    {
        REP(j, listings.size())
        {
            match = true;
            if (dialed[i] == listings[j].pnum)
            {
                pos.clear();
                pos.push_back(dialed[i]);
                goto done;
            }
            
            REP(k, dialed[i].length())
            {
                if (k == 0)
                { debug(numpad[dialed[i][k]], TAB); debug(listings[j].fname[k], TAB);
                    debug(numpad[dialed[i][k]].find(listings[j].fname[k]), endl); }
                else
                { debug(numpad[dialed[i][k]], TAB); debug(listings[j].lname[k-1], endl); }
                
                if (k == 0 && numpad[dialed[i][0]].find(toupper(listings[j].fname[0])) == string::npos)
                {
                    match = false;
                    break;
                }
                else if (k != 0 && numpad[dialed[i][k]].find(toupper(listings[j].lname[k-1])) == string::npos)
                {
                    match = false;
                    break;
                }
            }
            if (match)
                pos.push_back(listings[j].pnum);
        }
    done:
        
        if (pos.empty())
            cout << "0";
        else if (pos.size() == 1)
            cout << pos[0];
        else
        {
            cout << pos[0];
            for (int i = 1; i < pos.size(); ++i)
            {
                cout << " " << pos[i];
            }
        }
        pos.clear();
        cout << "\n";
    }
}

int main()
{
    //while ()
    {
        numpad['1'] = "";
        numpad['2'] = "ABC";
        numpad['3'] = "DEF";
        numpad['4'] = "GHI";
        numpad['5'] = "JKL";
        numpad['6'] = "MNO";
        numpad['7'] = "PQRS";
        numpad['8'] = "TUV";
        numpad['9'] = "WXYZ";
        numpad['0'] = "";
        
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        listings.clear();
        dialed.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
