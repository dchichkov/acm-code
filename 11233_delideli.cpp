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
vector<string> lines;
map<string, string> plural;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (cin.eof()) return false;
    int n, m;
    scanf("%d %d ", &n, &m);
    string word, word2;
    REP(i, n)
    {
        cin >> word >> word2;
        plural[word] = word2;
    }

    REP(i, m)
    {
        cin >> word;
        lines.push_back(word);
    }

    scanf(" ");
    return true;
}

void process()
{
    //process input
    REP(i, lines.size())
    {
        if (plural.find(lines[i]) != plural.end())
            cout << plural[lines[i]];
        else
        {
            if (lines[i][lines[i].length()-1] == 'y')
            {
                debug(lines[i], endl);
                if (lines[i][lines[i].length()-2] != 'a' &&
                    lines[i][lines[i].length()-2] != 'e' &&
                    lines[i][lines[i].length()-2] != 'i' &&
                    lines[i][lines[i].length()-2] != 'o' &&
                    lines[i][lines[i].length()-2] != 'u')
                {
                    debug(lines[i], endl);
                    lines[i][lines[i].length()-2] = 'i';
                    lines[i][lines[i].length()-1] = 'e';
                }
                lines[i].append("s");
            }
            else if (lines[i][lines[i].length()-1] == 'o' ||
                     lines[i][lines[i].length()-1] == 's' ||
                     lines[i][lines[i].length()-1] == 'x' ||
                     (lines[i][lines[i].length()-2] == 'c' && lines[i][lines[i].length()-1] == 'h') ||
                     (lines[i][lines[i].length()-2] == 's' && lines[i][lines[i].length()-1] == 'h'))
                lines[i].append("es");
            else
                lines[i].append("s");

            cout << lines[i];
        }
        
        cout << endl;
    }
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/
        lines.clear();
        plural.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
