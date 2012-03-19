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

using namespace std;

/*global variables*/
vector<int> list;
int num_items = 0;
/*global variables*/

void dump()
{
    //dump data
}

void getInput()
{
    //clear list
    list.clear();
    
    //get input
    cin >> num_items;
    int next_item = 0;
    for (int i = 0; i < num_items; ++i)
    {
        cin >> next_item;
        list.push_back(next_item);
    }
}

template <typename T>
T process()
{  
    T result = 0;
    sort(list.begin(), list.end());
    for (int i = 0; list.size() > 1;)
    {
        //for (vector<int>::iterator it = list.begin(); it != list.end(); ++it)
        //    print(*it, " ");
        //print(list[i], "\t");
        //print(result, endl);
        list[i] += list[i+1];
        result += list[i];
        list.erase(list.begin()+1);
        //STAY SORTED!!
        for (int j = 0; list[j] > list[j+1] && j < list.size()-1; ++j)
            swap(list[j], list[j+1]);
    }

    return result;
}

int main()
{
    //getline(cin, temp);
    bool moreToDo;
    long long result = 0;
    while (moreToDo = !cin.eof())
    {

        getInput();
        if(num_items == 0)
            break;
        result = process<long long>();

        /*output*/
        cout << result << endl;
        
        /*output*/
        result = 0;
    }
}
