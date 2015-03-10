#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <stack>

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
struct op
{
    char o;
    int pr;
};
stack<op> ops;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    return true;
}

void process()
{
    //process input
    char c[5];
    op o, p;

    while(true)
    {
        fgets(c, 5, stdin);
        if (feof(stdin)) goto out;
        //debug(c, endl);
        switch(c[0])
        {
        case EOF:
        case '\n':
            goto out;
            break;
        case '(':
            o.o = c[0];
            ops.push(o);
            break;
        case ')':
            p = ops.top();
            ops.pop();
            while (p.o != '(')
            {
                printf("%c", p.o);
                if (p.pr < ops.top().pr) break;
                p = ops.top();
                ops.pop();
            }      
            break;
        case '-':
        case '+':
            o.pr = 0;
            o.o = c[0];
            ops.push(o);
            p = ops.top();
            ops.pop();
            if (p.pr < ops.top().pr)
            {
                while (!ops.empty() && p.pr < ops.top().pr)
                {
                    printf("%c", p.o);
                    if (p.pr > ops.top().pr) break;
                    p = ops.top();
                    ops.pop();
                }
            }
            else ops.push(p);
            break;
        case '/':
        case '*':
            o.pr = 1;
            o.o = c[0];
            ops.push(o);

                
            break;
        default:
            printf("%c", c[0]);
            break;
        }
    }
out:
    while (!ops.empty())
    {
        p = ops.top();
        ops.pop();
        if (p.o != '(')
            printf("%c", p.o);
    }
    puts("");
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
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
