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
map<string, int> nums;
map<char, char> code;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    int k;
    scanf("%d ", &k);
    string line;
    string num;
    REP(i, k)
    {
        getline(cin, line);
        debug(line, TAB);
        REP(j, line.length())
        {
            if (isalpha(line[j])) num += code[line[j]];
            else if (isdigit(line[j])) num += line[j];
        }
        nums[num] = nums[num]+1;
        debug(num, endl);
        num.clear();
    }
    return true;
}

void process()
{
    //process input

    bool dupe = false;

    map<string, int>::iterator it;
    for (it = nums.begin(); it != nums.end(); ++it)
    {
        if (it->second > 1)
        {
            dupe = true;
            printf("%c%c%c-%4s %d\n", it->first[0], it->first[1],
                   it->first[2],
                   it->first.c_str()+3 , it->second);
        }
    }
    if (!dupe)
        printf("No duplicates.\n");
}

int main()
{
    code['A'] = '2';
    code['B'] = '2';
    code['C'] = '2';
    code['D'] = '3';
    code['E'] = '3';
    code['F'] = '3';
    code['G'] = '4';
    code['H'] = '4';
    code['I'] = '4';
    code['J'] = '5';
    code['K'] = '5';
    code['L'] = '5';
    code['M'] = '6';
    code['N'] = '6';
    code['O'] = '6';
    code['P'] = '7';
    code['R'] = '7';
    code['S'] = '7';
    code['T'] = '8';
    code['U'] = '8';
    code['V'] = '8';
    code['W'] = '9';
    code['X'] = '9';
    code['Y'] = '9';

    int nc;
    scanf("%d ", &nc);
    
    while (nc-- > 0)
    {
        getInput();
        process();
        if (nc > 0) puts("");
        /*CLEAR GLOBAL VARIABLES!*/
        nums.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
