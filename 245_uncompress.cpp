#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cctype>

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
typedef vector<int> vi; //?
typedef vector<point> vp; //?

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
vector<string> words;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    char word[52], word2[52];
    CL(word2, 0);
    int num;
    scanf("%s ", word);
    int i = -18;
    while (strcmp(word, "0") != 0)
    {
        if ((i++) == 5) break;

        //words.push_back(word);
        num = -1;
        debug(word, TAB);
        if (isdigit(word[0]))
        {
            sscanf(word, "%d", &num);
            words.push_back(*(words.end()-num-1));
        }
        else
        {
            sscanf(word, "%[^123456789]%d", word2, &num);
            if (num != -1)
            {
                words.push_back(word2);
                words.push_back(*(words.end()-num));
            }
            else words.push_back(word2);
        }
        debug(word2, TAB); debug(num, endl);

        scanf("%s ", word);
        debug(word, endl);
    }
    return true;
}

void process()
{
    //process input
    REP(i, (int)words.size())
    {
        debug(i, TAB); debug(words[i], endl);
    }
    puts("");
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
