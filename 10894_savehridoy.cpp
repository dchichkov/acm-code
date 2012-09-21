/**
 * Author: Matthew Gavin
 * Date: 9/20/2012
 * Problem: 10894 Save Hridoy
 * Description: TEDIOUS TEDIUM! Hmm.. I got 15.
 *
 *              IT TOOK A WHILE BECAUSE I WAS OFF BY ONE SOMEWHERE AND FRIGGEN THE ASCII IS TOUGH TO CHECK OVER
 *              WITH YOUR EYES.
 *
 * Prof. Isaac Traxler
 * Compiled with: g++ 10894_savehridoy.cpp -o 10894
 * Compiler: g++ 4.6.1
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define DEBUG
#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define TAB '\t'
#define debug(a, end) cout << #a << ": " << a << end
#else
#define debug(a, end)
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
int N;

char savehr1[5][62] = {"*****..***..*...*.*****...*...*.*****.*****.***...*****.*...*",
                       "*.....*...*.*...*.*.......*...*.*...*...*...*..*..*...*..*.*.",
                       "*****.*****.*...*.***.....*****.*****...*...*...*.*...*...*..",
                       "....*.*...*..*.*..*.......*...*.*.*.....*...*..*..*...*...*..",
                       "*****.*...*...*...*****...*...*.*..**.*****.***...*****...*.."};

char savehr2[61][6] = {"*****",
                       "*....",
                       "*****",
                       "....*",
                       "*****",
                       ".....",
                       ".***.",
                       "*...*",
                       "*****",
                       "*...*",
                       "*...*",
                       ".....",
                       "*...*",
                       "*...*",
                       "*...*",
                       ".*.*.",
                       "..*..",
                       ".....",
                       "*****",
                       "*....",
                       "***..",
                       "*....",
                       "*****",
                       ".....",
                       ".....",
                       ".....",
                       "*...*",
                       "*...*",
                       "*****",
                       "*...*",
                       "*...*",
                       ".....",
                       "*****",
                       "*...*",
                       "*****",
                       "*.*..",
                       "*..**",
                       ".....",
                       "*****",
                       "..*..",
                       "..*..",
                       "..*..",
                       "*****",
                       ".....",
                       "***..",
                       "*..*.",
                       "*...*",
                       "*..*.",
                       "***..",
                       ".....",
                       "*****",
                       "*...*",
                       "*...*",
                       "*...*",
                       "*****",
                       ".....",
                       "*...*",
                       ".*.*.",
                       "..*..",
                       "..*..",
                       "..*.."};
                   
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    scanf("%d", &N);
    if (!N) return false;

    return true;
}

void process()
{
    //process input
    string line;
    if (N > 0)
    {
        int num_lines = 0;
        //horizontal
        if (N==1)
            for (int i = 0; i < 5; ++i, ++num_lines)
                printf("%s\n", savehr1[i]);
        else
        {
            for (int i = 0; i < 5; ++i)
            {
                line.clear();
                for (int j = 0; j < 61; ++j)
                {
                    for (int k = 0; k < N; ++k)
                        line += savehr1[i][j];
                }
                for (int k = 0; k < N; ++k, ++num_lines)
                    cout << line << endl;
            }
        }
        debug(num_lines, endl);
    }

    if (N < 0)
    {
        int num_lines = 0;
        //vertical
        N = -N;
        if (N == 1)
        {
            for (int i = 0; i < 61; ++i, ++num_lines)
                printf("%s\n", savehr2[i]);
        }
        else
        {

            for (int i = 0; i < 61; ++i)
            {
                line.clear();
                for (int j = 0; j < 5; ++j)
                {
                    for (int k = 0; k < N; ++k)
                        line += savehr2[i][j];
                }
                for (int k = 0; k < N; ++k, ++num_lines)
                    cout << line << endl;
            }
        }
        debug(num_lines, endl);
    }

    printf("\n\n");
}

int main()
{
    bool moreToDo;
    while (moreToDo = getInput())
    {

        process();

        /*output*/


        /*output*/
    }

    return 0;
}
