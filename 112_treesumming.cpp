#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

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
int I;
struct bin_tree
{
    bin_tree* left;
    bin_tree* right;
    int value;
    
    int get_sum(bin_tree* node)
    {
        
    }
    void insert(int value)
    {
        
    }

    bool has_sum(int I)
    {

    }
    
    ~bin_tree()
    {
        delete left;
        delete right;
    }
} b_tree;
/*global variables*/

void dump()
{
    //dump data
}

void get_tree()
{
    

}

bool getInput()
{
    //get input
    if (scanf("%d", &I) == EOF) return false;
    return true;
}

int gsum(int k)
{
    char next;
    scanf("("); //get first starting open brace

    next = getchar(stdin);
    if (next == ')')
        return 0;
    else
        k += next-'0';

    if (gsum(k) == I) //left tree
        return I;
    else if (gsum(k) == I) //right tree
        return I;

    return 0;
}

void process()
{
    //process input
    /*get_tree();
      printf("%s\n", (b_tree.has_sum(I)) ? "yes" : "no");*/

    int sum = 0;
    printf("%s\n", (gsum(sum)) ? "yes" : "no");
}

int main()
{
    while (getInput())
    {

        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
