#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
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
bool is_stack,
    is_queue,
    is_pqueue;
stack<int> stack1;
queue<int> queue1;
priority_queue<int> pqueue1;
int num_toscan;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (scanf("%d\n", &num_toscan) == EOF)
        return false;

    return true;
}

void do_stackop(int op, int num)
{
    switch (op)
    {
    case 1: //insert
        stack1.push(num);
        break;
    case 2: //remove and check
        if (!stack1.empty())
        {
            if (stack1.top() != num)
                is_stack = false;
            stack1.pop();
        } else is_stack = false;
        break;
    }
}

void do_queueop(int op, int num)
{
    switch (op)
    {
    case 1: //insert
        queue1.push(num);
        break;
    case 2: //remove and check
        if (!queue1.empty())
        {
            if (queue1.front() != num)
                is_queue = false;
            queue1.pop();
        } else is_queue = false;
        break;
    }

}

void do_pqueueop(int op, int num)
{
    switch (op)
    {
    case 1: //insert
        pqueue1.push(num);
        break;
    case 2: //remove and check
        if (!pqueue1.empty())
        {
            if (pqueue1.top() != num)
                is_pqueue = false;
            pqueue1.pop();
        } else is_pqueue = false;
        break;
    }
}

void process()
{
    //process input
    int op, num;
    int imp_count = 0;
    REP(i, num_toscan)
    {
        scanf("%d %d\n", &op, &num);
        do_stackop(op, num);
        do_queueop(op, num);
        do_pqueueop(op, num);
    }
    if (is_stack)
        imp_count += 1;
    if (is_queue)
        imp_count += 1;
    if (is_pqueue)
        imp_count += 1;

    if (imp_count == 0)
        printf("impossible");
    else if (imp_count > 1)
        printf("not sure");
    else
    {
        (is_queue) ? printf("queue") :
            (is_stack) ? printf("stack") :
            printf("priority queue");
    }
    
    printf("\n");
}

int main()
{
    bool moreToDo;
    while (moreToDo = getInput())
    {
        is_queue = is_stack = is_pqueue = true;
        while (!stack1.empty()) stack1.pop();
        while (!queue1.empty()) queue1.pop();
        while (!pqueue1.empty()) pqueue1.pop();
        process();

        /*output*/


        /*output*/
    }

    return 0;
}
