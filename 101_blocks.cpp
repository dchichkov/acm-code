#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <sstream>

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
vi blocks[25];
int bpos[25];
int nb;
/*global variables*/

void dump()
{
    //dump data
    REP(i, nb)
        cout << bpos[i] << " ";
    cout << endl;

    
    REP(i, nb)
    {
        cout << i << ":";
        REP(j, blocks[i].size())
        {
            cout << " " << blocks[i][j];
        }
        cout << endl;
    }
}

bool getInput()
{
    //get input
    scanf("%d ", &nb);
    REP(i, nb)
    {
        blocks[i].push_back(i);
        bpos[i] = i;
    }
    return true;
}

bool can_move(int a, int b)
{
    if (a == b)
        return false;
    if (bpos[a] == bpos[b])
        return false;

    return true;
}

void move_onto(int a, int b)
{
    //move blocks on top of a to their original position
    int block = blocks[bpos[a]].back();
    while (block != a)
    {
        blocks[block].push_back(block);
        bpos[block] = block;
        blocks[bpos[a]].pop_back();
        block = blocks[bpos[a]].back();
    }

    //move blocks on top of b to their original position
    block = blocks[bpos[b]].back();
    while (block != b)
    {
        blocks[block].push_back(block);
        bpos[block] = block;
        blocks[bpos[b]].pop_back();
        block = blocks[bpos[b]].back();
    }

    //move a onto b
    blocks[bpos[b]].push_back(a);
    blocks[bpos[a]].pop_back();
    bpos[a] = bpos[b];
}

void move_over(int a, int b)
{
    //move blocks on top of a to their original position
    int block = blocks[bpos[a]].back();
    while (block != a)
    {
        blocks[block].push_back(block);
        bpos[block] = block;
        blocks[bpos[a]].pop_back();
        block = blocks[bpos[a]].back();
    }

    //move a onto stack of where b is
    blocks[bpos[b]].push_back(a);
    blocks[bpos[a]].pop_back();
    bpos[a] = bpos[b];
}

void pile_onto(int a, int b)
{
    //move blocks on top of b to their original position
    int block = blocks[bpos[b]].back();
    while (block != b)
    {
        blocks[block].push_back(block);
        bpos[block] = block;
        blocks[bpos[b]].pop_back();
        block = blocks[bpos[b]].back();
    }

    vector<int>::iterator it = find(blocks[bpos[a]].begin(), blocks[bpos[a]].end(), a);
    int ppos = bpos[a];
    vector<int>::iterator xt = it;
    vector<int>::iterator jt = blocks[bpos[a]].end();
    for (; it != jt; ++it)
    {
        blocks[bpos[b]].push_back(*it);
        bpos[*it] = bpos[b];

    }
    blocks[ppos].erase(xt, jt);    
    bpos[a] = bpos[b];
}

void pile_over(int a, int b)
{
    vector<int>::iterator it = find(blocks[bpos[a]].begin(), blocks[bpos[a]].end(), a);
    int ppos = bpos[a];
    vector<int>::iterator xt = it;
    vector<int>::iterator jt = blocks[bpos[a]].end();
    for (; it != jt; ++it)
    {
        blocks[bpos[b]].push_back(*it);
        bpos[*it] = bpos[b];

    }
    blocks[ppos].erase(xt, jt);    
    bpos[a] = bpos[b];
}

void process()
{
    //process input
    string line, com, com2;
    istringstream istr;
    int a, b;

    getline(cin, line);
    istr.str(line);
    istr >> com;
    while (com.compare("quit") != 0)
    {
        istr >> a >> com2 >> b;
        debug(com, TAB); debug(a, TAB); debug(com2, TAB); debug(b, endl);
        if (can_move(a, b))
        {
            if (com.compare("move") == 0)
            {
                if (com2.compare("onto") == 0)
                    move_onto(a, b);
                else
                    move_over(a, b);
            }
            else
            {
                if (com2.compare("onto") == 0)
                    pile_onto(a, b);
                else
                    pile_over(a, b);
            }
        }

        istr.str("");
        istr.clear();
        
        getline(cin, line);
        istr.str(line);
        istr >> com;
    }

    REP(i, nb)
    {
        cout << i << ":";
        REP(j, blocks[i].size())
        {
            cout << " " << blocks[i][j];
        }
        cout << endl;
    }
out:
    ;
}

int main()
{
    //while ()
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        REP(i, 25)
            blocks[i].clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
