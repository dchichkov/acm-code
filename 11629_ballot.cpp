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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
map<string, double> scores;
int np, ng;
#define EPS 1e-9
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    char pn[25];
    double score;
    scanf("%d %d ", &np, &ng);
    REP(i, np)
    {
        scanf("%20s %lf ", pn, &score);
        scores[pn] = score;
    }
    return true;
}

void process()
{
    //process input
    char* tok;
    char line[2000];
    double n;
    int ttl1, n1;
    char pty[25];
    bool correct = false;
    REP(i, ng)
    {
        correct = false;
        ttl1 = 0;
        fgets(line, 2000, stdin);
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = 0;
        tok = strtok(line, " +");
        while (tok != NULL)
        {
            debug(tok, endl);
            if (strcmp(tok, ">") == 0)
            {
                tok = strtok(NULL, " ");
                sscanf(tok, "%lf", &n);
                n1 = n*10;
                if (ttl1 > n1)
                    correct = true;
            }
            else if (strcmp(tok, "<") == 0)
            {
                tok = strtok(NULL, " ");
                sscanf(tok, "%lf", &n);
                n1 = n*10;
                if (ttl1 < n1)
                    correct = true;
            }
            else if (strcmp(tok, "=") == 0)
            {
                tok = strtok(NULL, " ");
                sscanf(tok, "%lf", &n);
                n1 = n*10;
                if (ttl1 == n1)
                    correct = true;
            }
            else if (strcmp(tok, ">=") == 0)
            {
                tok = strtok(NULL, " ");
                sscanf(tok, "%lf", &n);
                n1 = n*10;
                if (ttl1 >= n1)
                    correct = true;
            }
            else if (strcmp(tok, "<=") == 0)
            {
                tok = strtok(NULL, " ");
                sscanf(tok, "%lf", &n);
                n1 = n*10;
                if (ttl1 <= n1)
                    correct = true;
            }
            else
            {
                sscanf(tok, "%s", pty);
                ttl1 += scores[pty]*10;
            }
            tok = strtok(NULL, " +");
        }
        printf("Guess #%d was %scorrect.\n", i+1, correct ? "" : "in");
    }
}

int main()
{
    //while ()
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
