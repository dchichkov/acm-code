/**
 * Author: Matthew Gavin
 * Date: 9/25/2012
 * Problem: 10855 Rotated Squares
 * Description: The rotation algorithm is pretty tricky... just try to model it out
 *              on paper first and go through the steps (e.g.):
 *                       temp = {1, 2,
 *                               3, 4}
 *                       for i = 0 to 1
 *                           for j = 0 to 1
 *                               m[i][j] = temp[1][0];
 *                               m[i][j] = temp[0][0];
 *                               m[i][j] = temp[1][1];
 *                               m[i][j] = temp[0][1];
 *
 *              so, m[i][j] = temp[M-j-1][i]; 
 *
 * Prof. Isaac Traxler
 * Compiled with: g++ 10855_rs.cpp -o 10855
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
int N, M;
//char** n, **m;
char n[100][100], m[100][100];
int ans[4];
/*global variables*/

void dump()
{
    //dump data
    REP(i, N)
    {
        REP(j, N)
        {
            printf("%c", n[i][j]);
        }
        cout << endl;
    }

    REP(i, M)
    {
        REP(j, M)
        {
            printf("%c", m[i][j]);
        }
        cout << endl;
    }
}

bool getInput()
{
    //get input
    scanf("%d %d ", &N, &M);
    debug(N, TAB); debug(M, endl);
    if (N == 0 && M == 0) return false;
    /*
    n = new char*[N];
    REP(i, N) { n[i] = new char[N]; }
    m = new char*[M];
    REP(i, M) { m[i] = new char[M]; }
    */
    
    REP(i, N)
        REP(j, N)
    {
        scanf("%c%*[\r\n ]", &n[i][j]);
    }

    REP(i, M)
        REP(j, M)
    {
        scanf("%c%*[\r\n ]", &m[i][j]);
    }
    
    return true;
}

void check(int x)
{
    REP(i, N-M+1)
    {
        REP(j, N-M+1)
        {
            if (n[i][j] == m[0][0])
            {
                REP(k, M)
                {
                    REP(l, M)
                    {
                        if (n[i+k][j+l] != m[k][l])
                        {
                            debug(n[i+k][j+l], TAB);
                            debug(m[k][l], endl);
                            goto next;
                        }
                    }
                }
                ans[x]++;
            next:
                0;
            }
        }
    }
}

void rotate()
{
    /*char** temp = new char*[M];
      REP(i, M) { temp[i] = new char[M]; }*/
    char temp[100][100];

    REP(i, M)
        REP(j, M)
            temp[i][j] = m[i][j];

    REP(i, M)
    {
        REP(j, M)
        {
            m[i][j] = temp[M-j-1][i];
        }
    }
    //dump();

    /*
    //delete
    REP(i, M) { delete[] temp[i]; }
    delete[] temp;
    temp = 0;
    */
}

void process()
{
    //process input
    REP(i, 4)
    {
        check(i);
        rotate();
    }

    printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
}

int main()
{

    while (getInput())
    {
        //dump();
        process();

        /*output*/

        /*{
            REP(i, N) { delete[] n[i]; }
            REP(i, M) { delete[] m[i]; }
            delete[] n;
            delete[] m;*/
        {
            CL2d(m, 0, 100, 100);
            CL2d(n, 0, 100, 100);
            CL(ans, 0);
        }
        /*output*/
    }

    return 0;
}
