//use set for O(n) time complexity
//check "https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/" for median quickselect 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Call by reference
int partition(vector<int> &v, int l, int h)
{
    int pivot=v[h];
    int i=l;
    //sorting pivot element(left of pivot < pivot < right of pivot)
    for(int j=l;j<h;j++)
    {
        if(pivot>=v[j])
        {
            swap(v[i],v[j]);
            i++;
        }
    }
    swap(v[i],v[h]);
    return i;
}

int quickSelect(vector<int> &v,int l, int h, int k)
{
    int m;
    k--;
    while(l<=h && k>=l && k<=h)
    {
        m=partition(v,l,h);
        if(m==k)
            return v[k];
        else if(m<k)
            l=m+1;
        else
            h=m-1;
    }
}
int main()
{
    vector<int> v{8, 3, 6, 7, 10, 38, 2, 1};
    int k = 3;
    cout<<quickSelect(v,0,v.size()-1,k);
    return 0;
}