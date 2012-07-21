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

int magic_number(int N)
{
    int m = 2;
    bool valid = false;
    vi places;
    for (; m < N && !valid; ++m)
    {
        places.clear();
        for (int i = 0; i < N; ++i)
            places.push_back(i+1);
        for (int j = m; ; (j > places.size()-1) ? j %= places.size()  : j += m)
        {
            debug(places.size(), TAB); debug(j, endl);
            
            if (places.size() == 1)
            {
                if (places[0] == 13)
                    valid = true;
                else valid = false;

                break;
            }
            else
                printf("%d\n", *places.erase(places.begin()+(j-1)));
        }
        cout << valid << endl;
    }
    return m;
}

int main()
{
    int N;
    scanf("%d", &N);
    while (N != 0)
    {
        printf("%d\n", magic_number(N));
    }
    return 0;
}
