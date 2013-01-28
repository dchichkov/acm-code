/*
  whitespace in input files? no problem.

 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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
vector<string> rules;
int num_words;
int num_rules;
string x;
char zeroes[100000000][7];

int max_fact;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    scanf(" ");
    if (feof(stdin)) return false;
    //get input
    
    scanf("%d ", &num_words);
    REP(i, num_words)
    {
        getline(cin, x);
        words.push_back(x);
    }
    
    scanf("%d ", &num_rules);
    REP(i, num_rules)
    {
        getline(cin, x);
        rules.push_back(x);
    }
    return true;
}

void fill_upto(int fact)
{
    int j = (int)pow(10, max_fact);
    int k = (int)pow(10, fact);
    //pre-generate zeroes
    FOR(i, max_fact, fact)
    {
        zeroes[i][0] = '0' + (i / 1000000);
        zeroes[i][1] = '0' + (i / 100000) % 10;
        zeroes[i][2] = '0' + (i / 10000) % 10;
        zeroes[i][3] = '0' + (i / 1000) % 10;
        zeroes[i][4] = '0' + (i / 100) % 10;
        zeroes[i][5] = '0' + (i / 10) % 10;
        zeroes[i][6] = '0' + (i % 10);
    }
    max_fact = fact;
}

void process()
{
    int z_cnt = 0;
    
    REP(i, num_rules)
    {

        REP(j, num_words)
        {
            z_cnt = count(rules[i].begin(), rules[i].end(), '0');
            int iter = (int)pow(10, z_cnt);
            if (iter > max_fact) fill_upto(iter);
            for (int k = 0; k < iter; ++k)
            {
                for (int m = 0, zc = 7-z_cnt; m < rules[i].length(); ++m)
                {
                    if (rules[i][m] == '#')
                        printf("%s", words[j].c_str());
                    else
                    {
                        printf("%c", zeroes[k][zc++]);
                    }
                }
                printf("\n");
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
