//Least number of comparisons
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Pair{
    int min;
    int max;
};
int main()
{
    struct Pair minmax;
    vector<int> v{8, 3, 6, 7, 10, 38, 2, 1};
    minmax.max = v[0];
    minmax.min = v[0];
    int n = v.size();
    int i;
    if(n%2==0)
    {
        if(v[0]<v[1]){
            minmax.min = v[0];
            minmax.max = v[1];
        }else{
            minmax.min = v[1];
            minmax.max = v[0];
        }
        i = 2;
    }
    else{
        minmax.min = v[0];
        minmax.max = v[0];
        i = 1;
    }
    for (;i<n;i=i+2)
    {
        if(v[i]<v[i+1])
        {
            if(minmax.min>v[i])
                minmax.min = v[i];
            if(minmax.max<v[i+1])
                minmax.max = v[i+1];
        }
        else
        {
            if(minmax.min>v[i+1])
                minmax.min = v[i+1];
            if(minmax.max<v[i])
                minmax.max = v[i];
        }
        
    }
    cout << "Max-" << minmax.max;
    cout << "Min-" << minmax.min;
    return 0;
}
