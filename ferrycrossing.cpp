#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <cfloat>
#include <cctype>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue> 
#include <regex.h> 

#define DEBUG
//#undef DEBUG //uncomment this line to pull out print statements
#ifdef DEBUG
#define print(a, end) cout << #a << ": " << a << end
#else
#define print(a, end)
#endif
#define var(q,s) typeof(s) q = s 
#define foreach(q, s) for( var(q,s.begin()); q!=s.end(); q++) 

using namespace std;

/*global variables*/
vector<int> car_times;
int max_carry, trip_time, num_cars;
/*global variables*/


void dump()
{
    //dump variables
}

void getInput()
{
    car_times.clear();
    
    //get input
    cin >> max_carry >> trip_time >> num_cars;
    int car_time = 0;
    for (int i = 0; i < num_cars; ++i)
    {
        cin >> car_time;
        car_times.push_back(car_time);
    }
}


pair<int, int> process()
{
    //process input
    pair<int, int> results;

    int car_time = 0;
    for (int i = 0; i < car_times.size(); ++i)
    {
        print(car_times[i], "\t");
        if ((results.first) > car_times[i])
        {
            car_times[i] += trip_time;
            print(car_times[i], "\t");
        }
        if ((i+1)%max_carry == 0 || (i == car_times.size()-1))
            results.first = car_times[i] + trip_time;
        /*        else if 
                  results.first = car_times[i];*/
        
       
        print(results.first, endl);
    }


    results.second = ceil(num_cars*1.0 / max_carry);

    return results;
}


int main()
{
    //getline(cin, temp);
    bool moreToDo;
    int num_times = 0;
    cin >> num_times;
    while (moreToDo = num_times--)
    {

        getInput();
        
        pair<int, int> results = process();

        /*output*/
        cout << results.first << " " << results.second << endl;
        /*output*/
    }
}
