//Dutch National Flag algorithm
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v{0, 1, 1, 2, 0, 2, 0, 0, 1, 0};
    int low=0,mid=0;
    int high = v.size()-1;
    //low denotes ending of 0s
    //high denotes starting of 2s
    //mid used for traversal
    while(mid<=high)
    {
        if(v[mid]==0)
        {
            swap(v[mid],v[low]);
            mid++;
            low++;
        }
        else if(v[mid]==1)
            mid++;
        else
        {
            swap(v[mid],v[high]);
            high--;
        }
    }
    cout<<low<<mid<<high;

    for (int i : v)
    {
        cout << i << " ";
    }
    return 0;
}