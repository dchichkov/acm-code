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
typedef vector<int> vi;
typedef vector<point> vp;

#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())   
#define SORT(c) sort((c).begin(),(c).end())   
#define FOR(i,a,b) for (int  i=(a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
struct student
{
    string name;
    int dd, mm, yyyy;
};

struct student_sort
{
    bool operator() (const student& a, const student& b)
    {
        if (a.yyyy == b.yyyy)
        {
            if (a.mm == b.mm)
            {
                return a.dd < b.dd;
            }
            else return a.mm < b.mm;
        }
        else return a.yyyy < b.yyyy;
    }
};

vector<student> class_;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    char name[20];
    student a;
    int nums;
    scanf("%d ", &nums);
    REP(i, nums)
    {
        scanf("%s %d %d %d ", name, &a.dd, &a.mm, &a.yyyy);
        a.name = name;
        class_.push_back(a);
    }
    return true;
}

void process()
{
    //process input
    sort(class_.begin(), class_.end(), student_sort());
    printf("%s\n%s\n", class_.back().name.c_str(), class_[0].name.c_str());
}

int main()
{
    //while ()
    {
        getInput();
        process();

        /*CLEAR GLOBAL VARIABLES!*/

        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
