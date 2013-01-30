#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vector<string> dict, dict2;
vector<string> words;
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
    while (line[0] != 'X')
    {
        dict.push_back(line);
        dict2.push_back(line);
        getline(cin, line);
    }
    line.clear();
    getline(cin, line);
    while (line[0] != 'X')
    {
        words.push_back(line);
        getline(cin, line);
    }
    
    return true;
}

void process()
{
    //process input
    bool matches = true;
    int m = 0;
    SORT(dict);
    SORT(dict2);

    REP(i, dict2.size())
    {
        debug(dict[i], TAB);
        SORT(dict2[i]);
        debug(dict2[i], endl);
    }

    REP(i, words.size())
    {
        SORT(words[i]);
        m = 0;
        REP(j, dict2.size())
        {
            if (dict2[j].length() != words[i].length())
                continue;
            
            REP(k, words[i].length())
            {
                if (words[i][k] != dict2[j][k])
                {
                    matches = false;
                    break;
                }
            }

            if (matches)
            {
                cout << dict[j] << endl;
                m++;
            }
            matches = true;
        }
        if (m == 0)
            cout << "NOT A VALID WORD" << endl;
        printf("******\n");
    }
    
}

int main()
{
    getInput();
    process();

    return 0;
}
