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
vector<string> rules;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    if (feof(stdin)) return false;
    //get input
    int num_words;
    scanf("%d ", &num_words);
    REP(i, num_words)
    {
        string x;
        getline(cin, x);
        words.push_back(x);
    }

    int num_rules;
    scanf("%d ", &num_rules);
    REP(i, num_rules)
    {
        string x;
        getline(cin, x);
        rules.push_back(x);
    }
    return true;
}

void process()
{
    string word;
    char c[2];
    c[1] = 0;
    //process input
    REP(i, rules.size())
    {
        int cnt_0 = count(rules[i].begin(), rules[i].end(), '0');
        debug(cnt_0, TAB);
        //for each rule;
        word = rules[i];
        REP(j, words.size())
        {
            //for each word
            //go through the rule
            long t = pow(10, cnt_0);
            int p , m;
            for (int k = 0; k < t; ++k)
            {
                p = pow(10, cnt_0), m = pow(10, cnt_0-1);
                debug(word, endl);
                for (int l = 0; l < word.length(); ++l)
                {
                    if (word[l] == '#')
                        fputs(words[j].c_str(), stdout);
                    else
                    {
                        c[0] = '0'+(k/m%p);
                        fputs(c, stdout);
                        m /= 10;
                        p /= 10;
                    }
                }
                fputs("\n", stdout);
            }
        }
    }
}

int main()
{
    while (getInput())
    {
        printf("--\n");
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        words.clear();
        rules.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
