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
map<string, string> keyv;
map<string, string> keyw;
vector<string> cc, cr, s;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    char str[110];
    fgets(str, 110, stdin);
    string key;
    string key2;
    REP(i, strlen(str))
    {
        if (islower(str[i]))
            key += str[i];
        else if (str[i] - 0x30 >= 0 &&
                str[i] - 0x30 <= 9)
            key2 += str[i];
        if (str[i] == ',' || str[i] == '}')
        {
            keyv[key] = key2;
            key.clear();
            key2.clear();
        }
    }

    fgets(str, 110, stdin);
    REP(i, strlen(str))
    {
        if (islower(str[i]))
            key += str[i];
        else if (str[i] - 0x30 >= 0 &&
                str[i] - 0x30 <= 9)
            key2 += str[i];
        if (str[i] == ',' || str[i] == '}')
        {
            keyw[key] = key2;
            key.clear();
            key2.clear();
        }
    }

    for (map<string,string>::iterator it = keyv.begin(); it != keyv.end(); ++it)
    {
        if (keyw.find(it->first) == keyw.end())
            cr.push_back(it->first);
        else if (keyw[it->first] != it->second)
            s.push_back(it->first);
    }
    for (map<string,string>::iterator it = keyw.begin(); it != keyw.end(); ++it)
    {
        if (keyv.find(it->first) == keyv.end())
            cc.push_back(it->first);
    }
    
    return true;
}

void process()
{
    //process input
    if (cc.size() > 0)
    {
        printf("+");
        REP(i, cc.size())
        {
            printf("%s", cc[i].c_str());
            if (i+1 != cc.size()) printf(",");
        }
        puts("");
    }
    if (cr.size() > 0)
    {
        printf("-");
        REP(i, cr.size())
        {
            printf("%s", cr[i].c_str());
            if (i+1 != cr.size()) printf(",");
        }
        puts("");
    }
    if (s.size() > 0)
    {
        printf("*");
        REP(i, s.size())
        {
            printf("%s", s[i].c_str());
            if (i+1 != s.size()) printf(",");
        }
        puts("");
    }
    if (cc.size() == 0 && cr.size() == 0 && s.size() == 0)
        printf("No changes\n");
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();
        if (nc != 0) puts("");

        /*CLEAR GLOBAL VARIABLES!*/
        keyv.clear();
        keyw.clear();
        cc.clear();
        cr.clear();
        s.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
