#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
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
set<string> excuses;
int m;
const char delim[] = {'\n', '"', '.', ',', '!', '?', ' '};
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    int n;
    scanf("%d %d ", &n, &m);
    char word[100];
    REP(i, n)
    {
        scanf("%s ", word);
        excuses.insert(word);
    }
    
    return true;
}

void process()
{
    //process input
    char line[100];
    multimap<int, string> lines;
    int mx = 0, cnt = 0;
    char* token;
    pair<int, string> a;
    string l2;
    REP(i, m)
    {
        cnt = 0;
        fgets(line, 100, stdin);
        l2 = line;
        token = strtok(line, delim);
        while (token != NULL)
        {
            REP(i, strlen(token))
                token[i] = tolower(token[i]);
            if (excuses.find(token) != excuses.end()) ++cnt;
            token = strtok(NULL, delim);
        }
        a.first = cnt;
        a.second = l2;
        lines.insert(a);
        mx = max(cnt, mx);
    }

    for (multimap<int, string>::iterator it = lines.begin(); it != lines.end(); ++it)
        if (it->first == mx)
        {
            printf("%s", it->second.c_str());
            if (it->second[it->second.length()-1] != '\n')
                puts("");
        }
    puts("");
}

int main()
{
    int cnt = 0;
    while (getInput())
    {
        printf("Excuse Set #%d\n", ++cnt);
        process();
        /*CLEAR GLOBAL VARIABLES!*/
        excuses.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
