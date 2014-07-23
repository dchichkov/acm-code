#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <cctype>

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
map<char, char> letter;
string str;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    char c;
    scanf("%c", &c);
    while (!feof(stdin))
    {
        debug(c, endl);
        str += letter[tolower(c)];
        scanf("%c", &c);
    }
    return true;
}

void process()
{
    //process input
    printf("%s", str.c_str());
    
}

int main()
{
    letter['q'] = 'q';
    letter['w'] = 'w';
    letter['e'] = 'q';
    letter['r'] = 'w';
    letter['t'] = 'e';
    letter['y'] = 'r';
    letter['u'] = 't';
    letter['i'] = 'y';
    letter['o'] = 'u';
    letter['p'] = 'i';
    letter['['] = 'o';
    letter[']'] = 'p';
    letter['\\'] = '[';
    letter['a'] = 'a';
    letter['s'] = 's';
    letter['d'] = 'a';
    letter['f'] = 's';
    letter['g'] = 'd';
    letter['h'] = 'f';
    letter['j'] = 'g';
    letter['k'] = 'h';
    letter['l'] = 'j';
    letter[';'] = 'k';
    letter['\''] = 'l';
    letter['z'] = 'z';
    letter['x'] = 'x';
    letter['c'] = 'z';
    letter['v'] = 'x';
    letter['b'] = 'c';
    letter['n'] = 'v';
    letter['m'] = 'b';
    letter[','] = 'n';
    letter['.'] = 'm';
    letter['/'] = ',';
    letter[' '] = ' ';
    letter['\n'] = '\n';
    //while ()
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
