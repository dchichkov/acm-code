#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <vector>

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
typedef pair<char, char> pc;
typedef stack<pc> spc;
typedef vector<pc> vpc;

spc cards;
spc cards2;
vpc cards3;
/*global variables*/

void dump()
{
    spc cardlist;
    cardlist = cards;

    while (!cardlist.empty())
    {
        cout << cardlist.top().first << cardlist.top().second << " ";
        cardlist.pop();
    }
    
    
    cout << endl;
}

bool getInput()
{
    pc card;
    //get input
    REP(i, 52)
    {
        scanf("%c%c ", &card.first, &card.second);
        cards.push(card);
    }
    return true;
}

void process()
{
    //process input
    int X, Y = 0;

    pc d;
    REP(i, 25)
    {
        d = cards.top();
        cards2.push(d);
        cards.pop();
    }
    REP(i, 3)
    {
        debug(cards.top().first, endl);
        if (isdigit(cards.top().first))
            X = cards.top().first-'0';
        else
            X = 10;
        REP(j, (10-X)+1)
            cards.pop();

        Y += X;
    }
    debug(Y, endl);
    REP(i, 25)
    {
        d = cards2.top();
        cards.push(d);
        cards2.pop();
    }
    while (!cards.empty())
    {
        d = cards.top();

        debug(d.first, TAB); debug(d.second, endl);
        cards3.push_back(d);
        cards.pop();
    }
    printf("%c%c\n", (cards3.end()-Y)->first, (cards3.end()-Y)->second);
    
}

int main()
{
    int nc, c;
    scanf("%d ", &nc);
    c = nc;
    while (nc-- > 0)
    {
        getInput();
        printf("Case %d: ", c-nc);
        process();

        /*output*/

        while (!cards.empty())
            cards.pop();
        /*output*/
    }

    return 0;
}
