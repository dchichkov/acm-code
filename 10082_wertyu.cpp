#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
char ltrs[256];
char line[2049];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    CL(line, 0);
    if (feof(stdin)) return false;
    fgets(line, 2049, stdin);
    return true;
}

void process()
{
    //process input
    REP(i, strlen(line))
    {
        printf("%c", ltrs[line[i]]);
    }
}

int main()
{
    REP(i, 256)
    {
        ltrs[i] = (char)i;
    }
    
    ltrs['W'] = 'Q';
    ltrs['E'] = 'W';
    ltrs['R'] = 'E';
    ltrs['T'] = 'R';
    ltrs['Y'] = 'T';
    ltrs['U'] = 'Y';
    ltrs['I'] = 'U';
    ltrs['O'] = 'I';
    ltrs['P'] = 'O';
    ltrs['['] = 'P';
    ltrs[']'] = '[';
    ltrs['\\'] = ']';
    ltrs['S'] = 'A';
    ltrs['D'] = 'S';
    ltrs['F'] = 'D';
    ltrs['G'] = 'F';
    ltrs['H'] = 'G';
    ltrs['J'] = 'H';
    ltrs['K'] = 'J';
    ltrs['L'] = 'K';
    ltrs[';'] = 'L';
    ltrs['\''] = ';';
    ltrs['X'] = 'Z';
    ltrs['C'] = 'X';
    ltrs['V'] = 'C';
    ltrs['B'] = 'V';
    ltrs['N'] = 'B';
    ltrs['M'] = 'N';
    ltrs[','] = 'M';
    ltrs['.'] = ',';
    ltrs['/'] = '.';
    ltrs['1'] = '`';
    ltrs['2'] = '1';
    ltrs['3'] = '2';
    ltrs['4'] = '3';
    ltrs['5'] = '4';
    ltrs['6'] = '5';
    ltrs['7'] = '6';
    ltrs['8'] = '7';
    ltrs['9'] = '8';
    ltrs['0'] = '9';
    ltrs['-'] = '0';
    ltrs['='] = '-';

    
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
