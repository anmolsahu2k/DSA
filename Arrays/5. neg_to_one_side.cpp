#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> A{-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int i = 0;
    int j = A.size() - 1;
    //simpler 2 pointer
    while(i<j)
    {
        while(A[i]<0)
        {
            i++;
        }
        while(A[j]>0)
        {
            j--;
        }
        if(i<j)
            swap(A[i],A[j]);
        i++;
        j--;
    }
    //OR
    // for(int j=0;j<A.size();j++)
    // {
    //     //i denotes starting of negative elements
    //     if(A[j]>0)
    //     {   if(i<j)
    //             swap(A[i],A[j]);
    //         i++;
    //     }
    // }

    for (int i : A)
    {
        cout << i << " ";
    }
    return 0;
}