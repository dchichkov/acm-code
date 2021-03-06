#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <climits>

using namespace std;

#define DEBUG //comment this line to pull out print statements
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
set<string> words;
map<string, int> dist;
vector<string> di;
char line[200];
char miw[200], wh[200];
/*global variables*/

void dump()
{

}

void normalize(char* s)
{
    REP(i, strlen(s))
    {
        if (s[i] == '\n')
            s[i] = 0;
        else
        if (!isalpha(s[i]))
            s[i] = ' ';
    }

}

bool getInput()
{
    //get input
    int pos = 0, n = 0;
    
    char* lin;
    fgets(line, 200, stdin);
    normalize(line);    
    while (strcmp(line, "END") != 0)
    {
        lin = line;
        n = 0;
        debug(lin, endl);
        while (sscanf(lin, "%s%n ", wh, &n) != EOF)
        {
            debug(wh, endl);
            pos++;
            if (words.find(wh) == words.end())
            {
                words.insert(wh);
                strcpy(miw, wh);
                dist[miw] = pos;
                debug(miw, endl);
            }
            if (di.size())
            {
                for ( vector<string>::reverse_iterator it = di.rbegin();
                      it != di.rend(); ++it)
                {
                    if (it->compare(miw) == 0)
                        continue;
                    if (dist[miw] < pos)
                        dist[*it] = max(dist[miw]-pos, dist[*it]);
                    else
                        dist[*it] = min(dist[miw]-pos, dist[*it]);
                    debug(*it, TAB); debug(dist[*it], endl);
                }
            }
            debug(dist[wh],TAB); debug(pos,TAB); debug(wh, endl);
            di.push_back(wh);
            lin += n;

        }
        fgets(line, 200, stdin);
        normalize(line);
    }
}

void process()
{
    //process input
    int x = INT_MAX, y = 0;

    for (map<string, int>::iterator it = dist.begin(); it != dist.end(); ++it)
    {
        x = min(dist[miw]+it->second, x);
        y = max(dist[miw]+it->second, y);
    }
    
    printf("%d %d\n", x, y);
}

int main()
{
    int nc;
    int count = 0;
    scanf("%d\n", &nc);
    while (nc-- > 0)
    {
        printf("Document %d: ", ++count);
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        dist.clear();
        di.clear();
        words.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
