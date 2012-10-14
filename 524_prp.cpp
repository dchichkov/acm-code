#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
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
#define FOR(i,a,b) for (int  i = (a); i < (b); i++)    
#define REP(i,n) FOR(i,0,n)    
#define CL(a,b) memset(a,b,sizeof(a))
#define CL2d(a,b,x,y) memset(a, b, sizeof(a[0][0])*x*y)

/*global variables*/
int N;
set<int> primes;
vector<int> ring;
/*global variables*/

void dump()
{
    //dump data
}

bool getInput()
{
    //get input
    if (feof(stdin) ||
        scanf("%d", &N) == EOF) return false;

    REP(i, N)
    {
        ring.push_back(i+1);
    }
    
    return true;
}

bool is_prime(int num)
{
    if (primes.find(num) != primes.end())
        return true;
    return false;
}
/*
void get_prime_pair(vector<int> r)
{
    if (r.size() == 0) return;
    
    int t = r[0];
    FOR(i, 1, r.size()/2)
    {
        if (is_prime(t+r[i]))
        {
            printf("%d %d ", t, r[i]);
            vector<int> ri(r);
            ri.erase(ri.begin()+i);
            ri.erase(ri.begin());
            get_prime_pair(ri);
        }
    }
    printf("\n");
}

void process()
{
    //process input
    get_prime_pair(ring);
    printf("\n");
}
*/

void process()
{
    vector<int> rn(ring.begin(), ring.end());
    vector<int> ri(rn);
    do
    {
        rn.insert(rn.begin(), ring.begin(), ring.end());
        ri.insert(ri.begin(), rn.begin(), rn.end());
        reverse(ri.begin(), ri.end());
        rn.insert(rn.begin(), ri.begin(), ri.end()-1);
        rn.insert(rn.end(), 1);
        bool prime = true;
        FOR(i, 1, rn.size()-1)
        {
            if (!is_prime(rn[i] + rn[i-1]) || !is_prime(rn[i] + rn[i+1]))
                prime = false;
        }

        if (prime)
        {
            rn.erase(rn.end()-1);
            rn.erase(rn.begin(), rn.begin()+rn.size()/2);
            printf("%d", rn[0]);
            FOR(i, 1, rn.size())
            {
                printf(" %d", rn[i]);
                
            }
            printf("\n");
        }
        ri.clear();
        rn.clear();

    } while (next_permutation(ring.begin()+1, ring.end()));

    printf("\n");
}

int main()
{
    primes.insert(3);
    primes.insert(5);
    primes.insert(7);
    primes.insert(11);
    primes.insert(13);
    primes.insert(17);
    primes.insert(19);
    int count = 0;
    while (getInput())
    {
        printf("Case %d:\n", ++count);
        process();

        /*CLEAR GLOBAL VARIABLES!*/
        ring.clear();
        /*CLEAR GLOBAL VARIABLES!*/
    }

    return 0;
}
