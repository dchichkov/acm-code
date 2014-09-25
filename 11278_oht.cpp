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
map<char, char> dvorak;
char line[1010];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    fgets(line, 1010, stdin);
    if (feof(stdin)) return false;
    return true;
}

void process()
{
    //process input
    REP(i, strlen(line))
        printf("%c", dvorak[line[i]]);
}

int main()
{
    dvorak[' '] = ' ';
    dvorak['\n'] = '\n';
    dvorak['1'] = '1';
    dvorak['2'] = '2';
    dvorak['3'] = '3';
    dvorak['4'] = 'q';
    dvorak['5'] = 'j';
    dvorak['6'] = 'l';
    dvorak['7'] = 'm';
    dvorak['8'] = 'f';
    dvorak['9'] = 'p';
    dvorak['0'] = '/';
    dvorak['-'] = '[';
    dvorak['='] = ']';
    dvorak['q'] = '4';
    dvorak['w'] = '5';
    dvorak['e'] = '6';
    dvorak['r'] = '.';
    dvorak['t'] = 'o';
    dvorak['y'] = 'r';
    dvorak['u'] = 's';
    dvorak['i'] = 'u';
    dvorak['o'] = 'y';
    dvorak['p'] = 'b';
    dvorak['['] = ';';
    dvorak[']'] = '=';
    dvorak['\\'] = '\\';
    dvorak['a'] = '7';
    dvorak['s'] = '8';
    dvorak['d'] = '9';
    dvorak['f'] = 'a';
    dvorak['g'] = 'e';
    dvorak['h'] = 'h';
    dvorak['j'] = 't';
    dvorak['k'] = 'd';
    dvorak['l'] = 'c';
    dvorak[';'] = 'k';
    dvorak['\''] = '-';
    dvorak['z'] = '0';
    dvorak['x'] = 'z';
    dvorak['c'] = 'x';
    dvorak['v'] = ',';
    dvorak['b'] = 'i';
    dvorak['n'] = 'n';
    dvorak['m'] = 'w';
    dvorak[','] = 'v';
    dvorak['.'] = 'g';
    dvorak['/'] = '\'';
    dvorak['`'] = '`';
    dvorak['\t'] = '\t';
                    
    dvorak['!'] = '!';
    dvorak['@'] = '@';
    dvorak['#'] = '#';
    dvorak['$'] = 'Q';
    dvorak['%'] = 'J';
    dvorak['^'] = 'L';
    dvorak['&'] = 'M';
    dvorak['*'] = 'F';
    dvorak['('] = 'P';
    dvorak[')'] = '?';
    dvorak['_'] = '{';
    dvorak['+'] = '}';
    dvorak['Q'] = '$';
    dvorak['W'] = '%';
    dvorak['E'] = '^';
    dvorak['R'] = '>';
    dvorak['T'] = 'O';
    dvorak['Y'] = 'R';
    dvorak['U'] = 'S';
    dvorak['I'] = 'U';
    dvorak['O'] = 'Y';
    dvorak['P'] = 'B';
    dvorak['{'] = ':';
    dvorak['}'] = '+';
    dvorak['|'] = '|';
    dvorak['A'] = '&';
    dvorak['S'] = '*';
    dvorak['D'] = '(';
    dvorak['F'] = 'A';
    dvorak['G'] = 'E';
    dvorak['H'] = 'H';
    dvorak['J'] = 'T';
    dvorak['K'] = 'D';
    dvorak['L'] = 'C';
    dvorak[':'] = 'K';
    dvorak['"'] = '_';
    dvorak['Z'] = ')';
    dvorak['X'] = 'Z';
    dvorak['C'] = 'X';
    dvorak['V'] = '<';
    dvorak['B'] = 'I';
    dvorak['N'] = 'N';
    dvorak['M'] = 'W';
    dvorak['<'] = 'V';
    dvorak['>'] = 'G';
    dvorak['?'] = '"';
    dvorak['~'] = '~';
    dvorak['\t'] = '\t';
    
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
