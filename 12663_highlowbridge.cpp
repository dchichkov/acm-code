#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <iterator>
#include <map>

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
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
//int bridges[100001];
typedef map<int, int> bridge;
bridge bridges;
int counted[100001];
int n, m, k;
char line[100];
char* next;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin)) return false;
    
    //scanf("%d %d %d ", &n, &m, &k);
    fgets(line, 100, stdin);
    n = strtol(line, &next, 10);
    m = strtol(next, &next, 10);
    k = strtol(next, NULL, 10);
    int h;
    REP(i, n)
    {
        scanf("%d ", &h);
        bridges[h]++;
    }

    return true;
}

int ugh(int item)
{
    int first = 0;
    int last = n-1;
    int middle = (first+last)/2;

    while (first <= last)
    {
        if (bridges[middle] < item)
            first = middle+1;
        else if (bridges[middle] == item)
        {
            while (bridges[middle+1] == item)
                middle++;
            return middle;
        }
        else
            last = middle-1;

        middle = (first+last)/2;
    }

    if (first > last)
        return last;
    
    return 0;
}

void process()
{
    //process input
    int counter = 0;
    int a, b;

    //sort(bridges, bridges+n);

    int bound = 1, j;

    REP(i, m)
    {
        scanf("%d %d ", &a, &b);
        /* This causes a runtime error for some reason:
        fgets(line, 100, stdin);
        a = strtol(line, &next, 10);
        b = strtol(next, NULL, 10);
        */
                           

        /*
        j = ugh(a);
        for (; j >= 0; --j)
        {
            if (bridges[j] > bound)
            {
                counted[j] += 1;
            }
            else break;
        }
        */
        j = 0;
        for (bridge::iterator it = bridges.begin();
             it != bridges.end(); ++it, ++j)
        {
            if (it->first > bound)
            {
                if (it->first <= a)
                    counted[j]++;
                else break;
            }
        }
        bound = b;
    }
    j = 0;
    for (bridge::iterator it = bridges.begin();
         it != bridges.end(); ++it, ++j)
    {
        if (counted[j] >= k)
            counter += it->second;
    }
    if (counter == 0)
    {
        fputs("0\n", stdout);
    }
    else
    {
        int offset = log10(counter) + 1;
        char answer[offset];
        for (int i = offset-1; i >= 0; --i)
        {
            answer[i] = (counter % 10) + 0x30;
            counter /= 10;
        }
        fwrite(answer, sizeof(char), offset, stdout);
        //printf("%d\n", counter);
        fputs("\n", stdout);
    }
}

int main()
{
    int nc = 1;
    while (getInput())
    {
        printf("Case %d: ", nc++);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        bridges.clear();
        CL(counted, 0);
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
