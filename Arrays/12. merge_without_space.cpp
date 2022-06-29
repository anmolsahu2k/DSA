#include <iostream>
#include <algorithm>
using namespace std;
//See O(m+n) time complexity
int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};
    int n = sizeof(arr1) / arr1[0];
    int m = sizeof(arr2) / arr2[0];
    int i = n - 1;
    int j = 0;
    while (i >=0 && j < m)
    {
        if (arr1[i] >= arr2[j])
        {
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        }
        else
            break;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}