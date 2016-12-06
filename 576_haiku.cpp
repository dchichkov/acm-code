#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
char line[300];
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    fgets(line, 300, stdin);
    if (line[strlen(line)-1] == '\n')
        line[strlen(line)-1] = 0;
    if (strcmp(line, "e/o/i") == 0) return false;
    return true;
}

void process()
{
    //process input

    //count continuous vowels
    int whichline = 1;
    char* token;
    token = strtok(line, "/");
    int num_vowels;
    bool iscont = false;
    while (token != NULL)
    {
        debug(token, endl);
        num_vowels = 0;
        iscont = false;
        REP(i, strlen(token))
        {

            if (token[i] == 'a' ||
                token[i] == 'e' ||
                token[i] == 'i' ||
                token[i] == 'o' ||
                token[i] == 'u' ||
                token[i] == 'y')
            {
                if (!iscont)
                    num_vowels++;
                iscont = true;
            }
            else
                iscont = false;
            debug(num_vowels, endl);
        }
        if (whichline == 1 && num_vowels != 5)
        {
            goto done;
        }
        else if (whichline == 2 && num_vowels != 7)
        {
            goto done;
        }
        else if (whichline == 3 && num_vowels != 5)
        {
            goto done;
        }

        token = strtok(NULL, "/");
        whichline++;
    }

    if (whichline > 3 || token == NULL)
        printf("Y");
    else
    done:
        printf("%d", whichline);
    puts("");
        
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
