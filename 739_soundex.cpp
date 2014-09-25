#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vector<string> names;
map<char, int> values;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    string line;
    while (getline(cin, line), !cin.eof())
        names.push_back(line);
    return true;
}

void process()
{
    //process input
    printf("%9s%s%21s%s\n", " ", "NAME", " ", "SOUNDEX CODE");
    string code;
    REP(i, names.size())
    {
        code.clear();
        printf("%9s%s", " ", names[i].c_str());
        FOR(j, 1, names[i].length())
        {
            if (values[names[i][j-1]] == values[names[i][j]] ||
                values[names[i][j]] == 0)
                continue;
            else
                code += values[names[i][j]] + 0x30;
        }
        if (code.length() < 3)
            code.append(3-code.length(), '0');
        code.erase(code.begin()+3, code.end());
        printf("%*s%c%3s\n", 35-((int)names[i].length()+10), " ", names[i].at(0), code.c_str());
    }
    printf("%19s%s\n", " ", "END OF OUTPUT");
}

int main()
{
    values['B'] = 1;
    values['P'] = 1;
    values['V'] = 1;
    values['F'] = 1;
    values['C'] = 2;
    values['S'] = 2;
    values['K'] = 2;
    values['G'] = 2;
    values['J'] = 2;
    values['Q'] = 2;
    values['X'] = 2;
    values['Z'] = 2;
    values['D'] = 3;
    values['T'] = 3;
    values['L'] = 4;
    values['M'] = 5;
    values['N'] = 5;
    values['R'] = 6;
    
    //while ()
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        names.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
