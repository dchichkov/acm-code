#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <bitset>
#include <algorithm>

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
//bitset<50> sample;
unsigned long long sample, sample2;
long long a[50000];
int num;
/*global variables*/

void dump()
{
    //dump data
}

bool ispalindrome(string x, size_t n)
{
    string s = x.substr(x.length()-n);
    debug(s, endl);
    for (size_t i = 0; i < s.length()/2; ++i)
    {
        debug(s[i], TAB); debug(s[s.length()-i-1], endl);
        if (s[i] != s[s.length()-i-1])
            return false;
    }

    return true;
}

void longtobinary(long long unsigned int x)
{
    int sizeinbits = sizeof(x)*8;
    string bin_string;
    long long unsigned int ctrl_var = 1;
    for (long long unsigned int i = 0; i < sizeinbits; ++i, ctrl_var = 1)
        bin_string.insert(0, (ctrl_var<<i)&x ? "1" : "0");

    printf("bin_string(longuinttobinary): %s\n", bin_string.c_str());

}

void precompute()
{
    a[0] = 1;
	a[1] = 3;
	int n;
    for (int i = 1, num = i+1; i < 50000 && num < 100; ++num)
    {
        sample &= ~sample; //clear
        sample |= num;
		sample2 &= ~sample2; //clear
		sample2 |= num;
        /*debug(sample.to_string(), endl);
		n = log2(num);
        if ((sample ^ ((sample >> n) << n)) ==
            (sample >> n))
        {
            cout << num << ": " << i << endl;
            a[i++] = num;
			}*/
		if (num%2)
		{ //even numbers
			n = log2(num);
		} else 	n = log2(num)+1;
		
		debug(num, TAB); debug(n, endl);
		sample <<= n;
		debug(sample, TAB); debug(sample2, TAB);
		sample |= sample2;
		debug(sample, endl);
		a[++i] = sample;
		cout << sample << ": " << i << endl;
		longtobinary(sample);
    }
	sort(a, a+50000);
}

bool getInput()
{
    //get input
    if (scanf("%d", &num) == EOF) return false;
    return true;
}

void process()
{
    //process input
    printf("%lld\n", a[num-1]);
}

int main()
{
	CL(a, 0);
    precompute();

    bool moreToDo;
    while (moreToDo = getInput())
    {

        process();

        /*output*/


        /*output*/
    }

    return 0;
}
