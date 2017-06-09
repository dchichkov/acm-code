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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,(int)n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int RAM[1000];
int reg[10];
/*global variables*/

void dump()
{
    //dump data
    REP(i, 15)
    {
        debug(RAM[i], endl);
    }

}

bool getInput()
{
    //get input

    char line[100];
    fgets(line, 100, stdin);
    int i = 0;
    while (!feof(stdin) && line[0] != '\n' && line[0] != 0)
    {
        line[strlen(line)-1] = 0;
        sscanf(line, "%d ", &RAM[i]);
        line[0] = 0;
        fgets(line, 100, stdin);
        ++i;
    }
    
    return true;
}

void set(int a, int b)
{
    //set register a to b
    reg[a] = b;
}

void add(int a, int b)
{
    reg[a] = (reg[a]+b)%1000;
}

void multiply(int a, int b)
{
    reg[a] = (reg[a]*b)%1000;
}

void set_r(int a, int b)
{
    reg[a] = reg[b];
}

void add_r(int a, int b)
{
    reg[a] = (reg[a]+reg[b])%1000;
}

void mult_r(int a, int b)
{
    reg[a] = (reg[a]*reg[b])%1000;
}

void set_rfr(int a, int b)
{
    reg[a] = RAM[reg[b]];
}

void set_ram(int a, int b)
{
    RAM[reg[b]] = reg[a];
}

int go(int a, int b, int sp)
{
    return (reg[b] != 0 ? reg[a] : sp);
}

void process()
{
    dump();
    //process input
    int totalins = 0;
    int a, b, t;
    int sp = 0;
    while (true)
    {
        t = RAM[sp]/100;
        a = RAM[sp]/10%10;
        b = RAM[sp]%10;
        debug(t, TAB); debug(a, TAB); debug(b, TAB);
        ++sp;
        switch (t)
        {
        case 1:
            //halt
            totalins++;
            goto done;
            break;
        case 2:
            //set register a to b
            totalins++;
            set(a, b);
            break;
        case 3:
            //add b to contents of register a
            totalins++;
            add(a, b);
            break;
        case 4:
            //register a becomes register a times b
            totalins++;
            multiply(a, b);
            break;
        case 5:
            //register a's contents are set to register b's
            totalins++;
            set_r(a, b);
            break;
        case 6:
            //add register b to register a's contents
            add_r(a, b);
            totalins++;
            break;
        case 7:
            //multiply register a by the value of register b
            mult_r(a, b);
            totalins++;
            break;
        case 8:
            //set register a to the value in ram from address b
            set_rfr(a, b); //set register from ram
            totalins++;
            break;
        case 9:
            //set location in ram at register b to contents of register a
            set_ram(a, b);
            totalins++;
            break;
        case 0:
            //set the stack pointer to a value in ram specified in register a
            //unless register b in empty
            sp = go(a, b, sp);
            totalins++;
            break;
        }
        debug(sp, endl);
    }
done:
    printf("%d\n", totalins);
}

int main()
{
    int nc;
    scanf("%d ", &nc);
    while (nc-- > 0)
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        CL(RAM, 0);
        CL(reg, 0);
        /*CLEAR GLOBAL VARIABLES!*/
        if (nc != 0) puts("");
    }

    return 0;
}
