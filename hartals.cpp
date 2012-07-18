#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

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
int num_cases,
    sim_days,
    num_parties;
int parties[100];
int days[3650];
int days_missed = 0;

/*global variables*/

void process()
{
    //process input

    for (int i = 0; i < num_parties; ++i)
        for (int j = parties[i]; j < sim_days+1; j += parties[i])
                days[j-1] = 1;

    //cancel out weekends :/
    for (int h = 6; h < sim_days+1; h += 7)
    {
        days[h-1] = 0;
        days[h] = 0;
    }
    // :\

    for (int i = 0; i < sim_days; ++i)
        if (days[i] == 1)
            days_missed++;

}

int main()
{
    scanf("%d", &num_cases);
    while (num_cases-- > 0)
    {
        CL(parties, 0);//clear parties
        CL(days, 0); //clear days
        days_missed = 0;
        scanf("%d", &sim_days);
        scanf("%d", &num_parties);
        for (int i = 0; i < num_parties; ++i)
            scanf("%d", &parties[i]);
        
        process();

        /*output*/
        printf("%d\n", days_missed);

        /*output*/
    }
}
