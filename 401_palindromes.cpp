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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
map<char, char> rev;
string str;
bool nfirst;
/*global variables*/

bool is_palindrome(const string& s)
{
    REP(i, s.length()/2+1)
    {
        debug(s[i], TAB); debug(s[s.length()-i-1], endl);
        if (s[i] != s[s.length()-i-1])
        {
            return false;
        }
    }
    return true;
}

bool is_mirrored(const string& s)
{
    REP(i, s.length()/2+1)
    {
        debug(rev[s[i]], TAB); debug(s[s.length()-i-1], endl);
        if (rev[s[i]] != s[s.length()-i-1])
            return false;
    }
    return true;
}

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    char in[30];
    if (feof(stdin)) return false;
    scanf("%s ", in);
    str.clear();
    str.insert(0, in);
    //if (nfirst) cout << endl;
    //else nfirst = true;
    return true;
}

void process()
{
    //process input
    cout << str << " -- ";
    bool pal = is_palindrome(str);
    bool mir = is_mirrored(str);

    if (!pal)
    {
        if (mir)
        {
            cout << "is a mirrored string.";
        }
        else
        {
            cout << "is not a palindrome.";
        }
    }
    else
    {
        if (mir)
        {
            cout << "is a mirrored palindrome.";
        }
        else
        {
            cout << "is a regular palindrome.";
        }
    }
    cout << endl << endl;
}

int main()
{
    rev['A'] = 'A';
    rev['B'] = ' ';
    rev['C'] = ' ';
    rev['D'] = ' ';
    rev['E'] = '3';
    rev['F'] = ' ';
    rev['G'] = ' ';
    rev['H'] = 'H';
    rev['I'] = 'I';
    rev['J'] = 'L';
    rev['K'] = ' ';
    rev['L'] = 'J';
    rev['M'] = 'M';
    rev['N'] = ' ';
    rev['O'] = 'O';
    rev['P'] = ' ';
    rev['Q'] = ' ';
    rev['R'] = ' ';
    rev['S'] = '2';
    rev['T'] = 'T';
    rev['U'] = 'U';
    rev['V'] = 'V';
    rev['W'] = 'W';
    rev['X'] = 'X';
    rev['Y'] = 'Y';
    rev['Z'] = '5';
    rev['0'] = ' ';
    rev['1'] = '1';
    rev['2'] = 'S';
    rev['3'] = 'E';
    rev['4'] = ' ';
    rev['5'] = 'Z';
    rev['6'] = ' ';
    rev['7'] = ' ';
    rev['8'] = '8';
    rev['9'] = ' ';
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
